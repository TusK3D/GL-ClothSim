#include "include/MassPoint.h"
#include <QDebug>

MassPoint::MassPoint()
{
  m_accel = 0;
  m_vel = 0;
  m_force = 0;
}

//void MassPoint::pinMassPoint()
//{
//  for (int l=0;l<m_rkCloth.size();++l)
//  {
//    m_rkCloth[l].m_spring.setAFixed(true);
//    m_rkCloth[l].m_spring.setBFixed(true);
//  }
//}

//void MassPoint::updateForce()
//{
//    springSetup *_tempSpring = new springSetup(m_rkCloth[_count]);
//    _tempSpring->m_spring.update(_forceA,_forceB);
//    _targetA = _tempSpring->target.m_pointA;
//    _targetB = _tempSpring->target.m_pointB;
//}

void MassPoint::move(const ngl::Vec3 &_pos)
{
//  m_pos = _pos;
//  std::cout<<"position again is: "<<m_pos<<std::endl;

}

//void MassPoint::setSpring(const RK4Spring &_spring,
//                          const int &_sourcei, const int &_sourcej,
//                          const int &_targeti, const int &_targetj)
//{
//  springSetup _tempSpring;
//  _tempSpring.m_spring = _spring;
//  _tempSpring.source.m_pointA = _sourcei;
//  _tempSpring.source.m_pointB = _sourcej;
//  _tempSpring.target.m_pointA = _targeti;
//  _tempSpring.target.m_pointB = _targetj;
//  m_rkCloth.push_back(_tempSpring);
//}

//void MassPoint::resetSpringVector()
//{
//  m_rkCloth.erase(m_rkCloth.begin(),m_rkCloth.end());
//}

//void MassPoint::loadMatricesToShader(
//                                     ngl::TransformStack &_tx,
//                                     ngl::Camera *_cam
//                                   )
//{
//  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
//  (*shader)["Phong"]->use();

//  ngl::Mat4 MV;
//  ngl::Mat4 MVP;
//  ngl::Mat3 normalMatrix;
//  ngl::Mat4 M;
//  M=_tx.getCurrentTransform().getMatrix();
//  MV=_tx.getCurrAndGlobal().getMatrix()*_cam->getViewMatrix() ;
//  MVP=MV*_cam->getProjectionMatrix();
//  normalMatrix=MV;
//  normalMatrix.inverse();
//  shader->setShaderParamFromMat4("MV",MV);
//  shader->setShaderParamFromMat4("MVP",MVP);
//  shader->setShaderParamFromMat3("normalMatrix",normalMatrix);
//  shader->setShaderParamFromMat4("M",M);
//}


//void MassPoint::loadMatricesToColourShader(
//                                           ngl::TransformStack &_tx,
//                                           ngl::Camera *_cam
//                                         )
//{
//  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
//  (*shader)["Colour"]->use();
//  ngl::Mat4 MV;
//  ngl::Mat4 MVP;

//  MV=_tx.getCurrAndGlobal().getMatrix()*_cam->getViewMatrix() ;
//  MVP=MV*_cam->getProjectionMatrix() ;
//  shader->setShaderParamFromMat4("MVP",MVP);

//}



//void MassPoint::drawSprings(ngl::ShaderLib *shader,
//                     ngl::TransformStack &_transformStack,
//                     ngl::Camera *_cam)
//{

//  for (int i=0;i<m_rkCloth.size();++i)
//  {
//    RK4Spring *_spring = new RK4Spring(m_rkCloth[i].m_spring);
//    std::cout<<"drawing a new spring: "<< _spring->getAPosition()<<std::endl;
//    _transformStack.pushTransform();
//      {
//          // get our position values and put in a vector
//      std::vector<ngl::Vec3> points(2);
//      points[0]=_spring->getAPosition();
//      points[1]=_spring->getBPosition();
//      shader->setShaderParam4f("Colour",1.0,1.0,1.0,1.0);

//      loadMatricesToColourShader(_transformStack,_cam);
//          // load transform stack
//      ngl::VertexArrayObject *vao=ngl::VertexArrayObject::createVOA(GL_LINES);
//      vao->bind();
//      vao->setData(2*sizeof(ngl::Vec3),points[0].m_x);
//      vao->setNumIndices(2);
//      vao->setVertexAttributePointer(0,3,GL_FLOAT,0,0);
//      vao->draw();
//      vao->unbind();
//      vao->removeVOA();

//    }
//      _transformStack.popTransform();

//      // get an instance of the VBO primitives for drawing
//    ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();

//    shader->use("Phong");



//      _transformStack.pushTransform();
//      {
//      shader->setShaderParam4f("Colour",1.0,0.0,0.0,1.0);
//      _transformStack.setScale(0.1,0.1,0.1);
//      _transformStack.setPosition(_spring->getAPosition());
//      loadMatricesToShader(_transformStack,_cam);
//      // draw the cube
//      prim->draw("cube");
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
//  }
//}
