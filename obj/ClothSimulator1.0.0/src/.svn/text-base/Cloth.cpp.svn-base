#include "include/Cloth.h"m_mPoints


/// @brief a static count for the springsconst
static int m_idCount;

Cloth::Cloth()
{
  m_rowRes = 12;
  int _count = 0;
  m_columnRes = 12;
  m_mPoints.resize(m_rowRes);
  m_gravity.set(0,-.0098,0);
  for (int k=0;k<m_mPoints.size();++k)
  {
    m_mPoints[k].resize(m_columnRes);
  }


    for (int i=0; i<m_rowRes;++i)
    {
        for (int j=0; j<m_columnRes;++j)
        {
          float posa,posb;
          posa= i/2;
          posb = j/2;
          m_mPoints[i][j].setPos(i,j);
          m_mPoints[i][j].setMassPointIndex(_count++);

//            qDebug()<<"position :   ";
//          std::cout<<"Time step "<<m_mPoints[i][j].getPos()<<std::endl;
        }
    }
}




void Cloth::updateCloth(ngl::ShaderLib *shader,
                        ngl::TransformStack &_transformStack, ngl::Camera *_cam)
{
  ngl::Vec3 _forceA(0);
  ngl::Vec3 _accelA(0);
  ngl::Vec3 _posA(0);
  ngl::Vec3 _velA(0);
  ngl::Vec3 _oldPosPin01(m_mPoints[0][m_columnRes-1].getPos());
  ngl::Vec3 _oldPosPin02(m_mPoints[m_rowRes-1][m_columnRes-1].getPos());
  MassPoint *_mp1 = new MassPoint();
  MassPoint *_mp2 = new MassPoint();
  MassPoint *_mp3 = new MassPoint();
  MassPoint *_mp4 = new MassPoint();
  MassPoint *_mp5 = new MassPoint();
  MassPoint *_mp6 = new MassPoint();

//  pinCloth();

for (int i=0; i<m_rowRes;++i)
  {
      for (int j=0; j<m_columnRes;++j)
      {        
        _forceA = m_mPoints[i][j].getForce();
        _accelA =_forceA+ m_gravity;
        _velA=_accelA;
        _posA=m_mPoints[i][j].getPos();
        _posA+=_velA;
        m_mPoints[i][j].setPosVec(_posA);
        m_mPoints[0][m_rowRes-1].setPosVec(_oldPosPin01);
        m_mPoints[m_rowRes-1][m_columnRes-1].setPosVec(_oldPosPin02);

        _forceA,_accelA,_velA,_posA = 0;
      }
    }
  }


void Cloth::updateForce()
{
  for (int i=0; i<m_rowRes;++i)
  {
      for (int j=0; j<m_columnRes;++j)
      {
        m_mPoints[i][j].resetForce();
      }
  }

  for (std::vector<RK4Spring>::iterator iter = m_rkCloth.begin();
            iter != m_rkCloth.end();++iter)
   {
      iter->update();
//    std::cout<<"the cloth is: "<<iter->getId()<<std::endl;
  }
}


void Cloth::calcWind(const ngl::Vec3 &_direction)
{
  ngl::Vec3 _pos1;
  ngl::Vec3 _pos2;
  ngl::Vec3 _pos3;
  ngl::Vec3 _pos4;
  ngl::Vec3 _pos5;
  ngl::Vec3 _pos6;


  ngl::Vec3 _dir1;
  ngl::Vec3 _dir2;
  ngl::Vec3 _dir3;
  ngl::Vec3 _dir4;

  ngl::Vec3 normal1;
  ngl::Vec3 normal2;

  ngl::Vec3 d1 ;
  ngl::Vec3 d2 ;

  ngl::Vec3 _force1;
  ngl::Vec3 _force2;

  for (int i=0; i<m_rowRes-1;++i)
    {
        for (int j=0; j<m_columnRes-1;++j)
        {
          //-----------------------------------------------------
          //force for the first triangle in polygon
          _pos1 = m_mPoints[i+1][j].getPos();
          _pos2 = m_mPoints[i][j].getPos();
          _pos3 = m_mPoints[i][j+1].getPos();

          _dir1 = _pos2-_pos1;
          _dir2 = _pos3-_pos1;

          normal1.cross(_dir1,_dir2);
          d1 = normal1;
          d1.normalize();
          _force1 = normal1*(d1.dot(_direction));

          m_mPoints[i+1][j].setForce(_force1);
          m_mPoints[i][j].setForce(_force1);
          m_mPoints[i][j+1].setForce(_force1);

          //-----------------------------------------------------
          //force for the second triangle in polygon

          _pos4 = m_mPoints[i+1][j+1].getPos();
          _pos5 = m_mPoints[i+1][j].getPos();
          _pos6 = m_mPoints[i][j+1].getPos();

          _dir3 = _pos5-_pos4;
          _dir4 = _pos6-_pos4;

          normal2.cross(_dir3,_dir4);
          d2 = normal2;
          d2.normalize();
          _force2 = normal2*(d2.dot(_direction));

          m_mPoints[i+1][j+1].setForce(_force2);
          m_mPoints[i+1][j].setForce(_force2);
          m_mPoints[i][j+1].setForce(_force2);

        }
    }
}

void Cloth::pinCloth()
{

  m_mPoints[0][0].resetForce();
//          m_rkCloth[l].m_spring.setBFixed(true);
}




void Cloth::initialiseSprings()
{
    m_idCount = 0;
    m_springCount = 0;

    m_rkCloth.erase(m_rkCloth.begin(),m_rkCloth.end());

      for (int i=0; i<m_rowRes-1;++i)
      {
          for (int j=0; j<m_columnRes;++j)
          {
              /// horiz struct spring

              m_rkCloth.push_back(RK4Spring(m_mPoints[i][j],
                                            m_mPoints[i+1][j],
                                            m_idCount++)
                                            );
              m_springCount++;
          }
      }

      for (int i=0; i<m_rowRes;++i)
      {
          for (int j=0; j<m_columnRes-1;++j)
          {
            /// vert struct spring
            m_rkCloth.push_back(RK4Spring(m_mPoints[i][j],
                                          m_mPoints[i][j+1],
                                          m_idCount++)
                                          );
            m_springCount++;
        }
    }

      for (int i=0; i<m_rowRes-1;++i)
      {
          for (int j=0; j<m_columnRes-1;++j)
          {
            /// shear springs diagnol


            m_rkCloth.push_back(RK4Spring(m_mPoints[i][j],
                                          m_mPoints[i+1][j+1],
                                          m_idCount++)
                                          );
            m_springCount++;


            /// shear springs diagnol

            m_rkCloth.push_back(RK4Spring(m_mPoints[i+1][j],
                                          m_mPoints[i][j+1],
                                          m_idCount++)
                                                );
            m_springCount++;
        }
    }

      for (int i=0; i<m_rowRes-2;++i)
      {
          for (int j=0; j<m_columnRes;++j)
          {

            /// flex springs horizontal
            m_rkCloth.push_back(RK4Spring(m_mPoints[i][j],
                                          m_mPoints[i+2][j],
                                          m_idCount++)
                                          );
            m_springCount++;
          }
      }

      for (int i=0; i<m_rowRes;++i)
      {
          for (int j=0; j<m_columnRes-2;++j)
          {
            /// flex springs vertical
            m_rkCloth.push_back(RK4Spring(m_mPoints[i][j],
                                          m_mPoints[i][j+2],
                                          m_idCount++)
                                          );
            m_springCount++;
          }
      }
  }



void Cloth::loadMatricesToShader(ngl::TransformStack &_tx,
                                 ngl::Camera *_cam
                                )
{
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  (*shader)["Phong"]->use();

  ngl::Mat4 MV;
  ngl::Mat4 MVP;
  ngl::Mat3 normalMatrix;
  ngl::Mat4 M;
  M=_tx.getCurrentTransform().getMatrix();
  MV=_tx.getCurrAndGlobal().getMatrix()*_cam->getViewMatrix() ;
  MVP=MV*_cam->getProjectionMatrix();
  normalMatrix=MV;
  normalMatrix.inverse();
  shader->setShaderParamFromMat4("MV",MV);
  shader->setShaderParamFromMat4("MVP",MVP);
  shader->setShaderParamFromMat3("normalMatrix",normalMatrix);
  shader->setShaderParamFromMat4("M",M);
}


void Cloth::loadMatricesToColourShader(
                                           ngl::TransformStack &_tx,
                                           ngl::Camera *_cam
                                         )
{
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  (*shader)["Colour"]->use();
  ngl::Mat4 MV;
  ngl::Mat4 MVP;

  MV=_tx.getCurrAndGlobal().getMatrix()*_cam->getViewMatrix() ;
  MVP=MV*_cam->getProjectionMatrix() ;
  shader->setShaderParamFromMat4("MVP",MVP);

}



//void Cloth::createTriangle(std::vector<ngl::Vec3 &_vec,)
//{
//    for (int i=0; i<m_rowRes-1;++i)
//    {
//        for (int j=0; j<m_columnRes;++j)
//        {
//            _mp1 = m_mPoints[i][j].getPos();
//            _mp1 = m_mPoints[i][j].getPos();
//            _mp1 = m_mPoints[i][j].getPos();
//        }
//    }
//}

void Cloth::drawSprings(ngl::ShaderLib *shader,
                     ngl::TransformStack &_transformStack,
                     ngl::Camera *_cam)
{
    ngl::Vec3 _dir1;
    ngl::Vec3 _dir2;
    ngl::Vec3 _dir3;
    ngl::Vec3 _dir4;

    ngl::Vec3 normal1;
    ngl::Vec3 normal2;
    for (int i=0; i<m_rowRes-1;++i)
    {
        for (int j=0; j<m_columnRes-1;++j)
        {
//      std::cout<<"drawing a new spring: "<< _spring->getAPosition()<<std::endl;
        _transformStack.pushTransform();
         {
            // get our position values and put in a vector
        std::vector<ngl::Vec3> points(12);
        points[0]=(m_mPoints[i+1][j].getPos());
        points[1]=(m_mPoints[i][j].getPos());
        points[2]=(m_mPoints[i][j+1].getPos());
        points[3]=(m_mPoints[i+1][j+1].getPos());
        points[4]=(m_mPoints[i+1][j].getPos());
        points[5]=(m_mPoints[i][j+1].getPos());
        std::vector<ngl::Vec3> normals(6);
        _dir1 = points[1] -points[0];
        _dir2 = points[2]-points[0];
        _dir3 = points[4]-points[3];
        _dir4 = points[5]-points[3];

        normal1.cross(_dir1,_dir2);
        normal2.cross(_dir3,_dir4);
        normal1.normalize();
        normal2.normalize();
        for(int l=0;l<6;l++)
        {
            if(l<3)
            {
                points[l+6]=(normal1);
            }
            if(l>=3)
            {
                points[l+6]=(normal2);
            }
        }

        shader->setShaderParam4f("Colour",.5,.1,.2,1.0);

        loadMatricesToShader(_transformStack,_cam);
          // load transform stack
        ngl::VertexArrayObject *vao=ngl::VertexArrayObject::createVOA(GL_TRIANGLES);
        vao->bind();
        vao->setData(12*sizeof(ngl::Vec3),points[0].m_x);
        vao->setNumIndices(12);
        vao->setVertexAttributePointer(0,3,GL_FLOAT,0,0);
        vao->setVertexAttributePointer(1,3,GL_FLOAT,0,6);

//        vao->setData(6*sizeof(ngl::Vec3),normals[0].m_x);
//        vao->setNumIndices(6);
//        vao->setVertexAttributePointer(2,3,GL_FLOAT,0,0);
        vao->draw();
        vao->unbind();
        vao->removeVOA();

        }
      _transformStack.popTransform();
    }
}
      // get an instance of the VBO primitives for drawing
//    ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();

//    shader->use("Phong");



//      _transformStack.pushTransform();
//      {
//      shader->setShaderParam4f("Colour",1.0,0.0,0.0,1.0);
//      _transformStack.setScale(0.1,0.1,0.1);
//      _transformStack.setPosition(_spring->getAPosition());
//      loadMatricesToShader(_transformStack,_cam);
//      // draw the cube
////      prim->draw("cube");
//      }
//      _transformStack.popTransform();


//      _transformStack.pushTransform();
//      {
//      shader->setShaderParam4f("Colour",0.0,1.0,0.0,1.0);
//      _transformStack.setScale(0.1,0.1,0.1);
//      _transformStack.setPosition(_spring->getBPosition());
//      loadMatricesToShader(_transformStack,_cam);
//      // draw the sphere
//      prim->draw("cube");
//      }
//      _transformStack.popTransform();
//      // draw the target points
//    shader->setShaderParam4f("Colour",1.0,0.0,0.0,1.0);

//      _transformStack.pushTransform();
//      {
//        shader->setShaderParam4f("Colour",1.0,0.0,0.0,1.0);
//        _transformStack.setScale(0.1,0.1,0.1);
//              _transformStack.setPosition(_spring->getInitialAPointPos());
//        loadMatricesToShader(_transformStack,_cam);
//          // draw the cube
////        prim->draw("sphere");
//      }
//      _transformStack.popTransform();


//      _transformStack.pushTransform();
//      {
//        shader->setShaderParam4f("Colour",0.0,1.0,0.0,1.0);

//              _transformStack.setScale(0.1,0.1,0.1);
//              _transformStack.setPosition(_spring->getInitialBPointPos());
//        loadMatricesToShader(_transformStack,_cam);

//          // draw the sphere
////        prim->draw("sphere");
//      }
//      _transformStack.popTransform();
  }

