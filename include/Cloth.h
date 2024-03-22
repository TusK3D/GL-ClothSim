#ifndef CLOTH_H
#define CLOTH_H

#include "RK4Spring.h"
#include "MassPoint.h"

class Cloth:public MassPoint
{
public:
    Cloth();
    /// @brief constructor for cloth
    Cloth(const float &_length,const float &_k,const float &_damping);
    /// @brief return the row count
    inline int getRowCount() const{return m_rowRes;}
    /// @brief return columnCount
    inline int getColumnCount() const{return m_columnRes;}
    /// @brief return the mass point for the following grid position
    inline MassPoint getMassPoint(const int &_a,const int &_b){
                                         return m_mPoints[_a][_b];
                                         }
    /// @brief return the spring count
    inline int getSpringCount() const{return m_rkCloth.size();}
    /// @brief pin the cloth
    void pinCloth();
    /// @brief initialize the spring forces
    void initialiseSprings();
    void updateCloth();
    void updateGravity(const float &_gravity);
    void resetForce();

    /// @brief draw the springs
    void drawSprings(
              ngl::ShaderLib *shader,
              ngl::TransformStack &_transformStack, ngl::Camera *_cam
              );

    void loadMatricesToShader(ngl::TransformStack &_tx,
                              ngl::Camera *_cam
                              );

    void loadMatricesToColourShader(
                                    ngl::TransformStack &_tx,
                                    ngl::Camera *_cam
                                    );
    /// @brief update the masspoint with the various forces calculated
    void updateForce();
    /// @brief calculate the wind force
    void calcWind(const ngl::Vec3 &_direction);


//    /// @brief update the spring for the cloth
//    inline void updateSpring(const int &_index){m_rkCloth[_index].update();}

private:
    /// @brief vector to store my mass points and its springs
    //----------------------------------------------------------------------------------------------------------------------
    std::vector<RK4Spring> m_rkCloth;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief vector to store my mass points and its springs
    //----------------------------------------------------------------------------------------------------------------------
    std::vector<float> m_springRestLength;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief a vector of vector of masspoints to store the cloth points
    //----------------------------------------------------------------------------------------------------------------------
    std::vector<std::vector<MassPoint> > m_mPoints;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief define the length of the cloth
    //----------------------------------------------------------------------------------------------------------------------
    int m_length;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief define the width of the cloth
    //----------------------------------------------------------------------------------------------------------------------
    int m_width;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief define the number of row edges in the cloth
    //----------------------------------------------------------------------------------------------------------------------
    int m_rowRes;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief define the number of column edges in the cloth
    //----------------------------------------------------------------------------------------------------------------------
    int m_columnRes;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief offset between springs based on res and area
    //----------------------------------------------------------------------------------------------------------------------
    float m_posOffset;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the total count of springs
    //----------------------------------------------------------------------------------------------------------------------
    int m_springCount;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief set up gravity
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_gravity;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief spring generation cycles to avoid recreating the inital length
    //----------------------------------------------------------------------------------------------------------------------
    int m_springCycles;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief idcount for the springs
    //----------------------------------------------------------------------------------------------------------------------
    int m_idCount;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the offset for each masspoint in the row based on the resolution desired
    //----------------------------------------------------------------------------------------------------------------------
    float m_rowOffset;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the offset for each masspoint in the col based on the resolution desired
    //----------------------------------------------------------------------------------------------------------------------
    float m_colOffset;
    //----------------------------------------------------------------------------------------------------------------------


};

#endif // CLOTH_H
