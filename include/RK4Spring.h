#ifndef __RK4SPRING_H__
#define __RK4SPRING_H__

#include "AbstractRK4Integrator.h"

#include <ngl/Colour.h>
#include <ngl/TransformStack.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>
#include "MassPoint.h"


//----------------------------------------------------------------------------------------------------------------------
/// @brief this class implements a simple dampped spring system using RK4 integration
/// the main motionFunction is derived from
/// http://gafferongames.com/game-physics/spring-physics/
//----------------------------------------------------------------------------------------------------------------------

class RK4Spring : public AbstractRK4Integrator
{
public :
    RK4Spring(){;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor
	/// @param[in] _a the start position of spring point a-/\/\/\/
	/// @param[in] _b the start position of spring point -/\/\/\/-b
	/// @param[in] _length the resting length of the spring
	/// @param[in] _k the spring constant from Hooke's law
	/// @param[in] _damping the damping co-efficient of the spring
	//----------------------------------------------------------------------------------------------------------------------
    RK4Spring(
             MassPoint &_a,
             MassPoint &_b,
             const int _id
						);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method calls the integrator to calculate the spring force and updates the spring
	/// points, if the points are fixed then no update is made to the points
	//----------------------------------------------------------------------------------------------------------------------
  void update();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief accessor to set the integration time step (dt)
	/// @param[in] _t the time step value to use
	//----------------------------------------------------------------------------------------------------------------------
	inline void setTimeStep(
													float _t
												 )
													{m_timestep=_t;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief this is going to calculate the spring function
	/// F = -k(|x|-d)(x/|x|) - bv where
	/// k is the spring constant
	/// |x| is the distance between the two spring points
	/// d is the distance of seperation
	/// b is the coefficient of damping larger b increases the damping force
	/// v is the relative velocity between the spring points
	/// @param[in] _state the state of the spring values to calculate
	/// @param[in] _t the current time state
	/// @returns a vector of the force calculated via the RK4 integrator
	//----------------------------------------------------------------------------------------------------------------------
	ngl::Vec3 motionFunction(
														const State &_state,
														float _t
													 );


	//----------------------------------------------------------------------------------------------------------------------
	/// @brief mutator to set the a position of the spring
	/// @param[in] _a the value to set
	//----------------------------------------------------------------------------------------------------------------------
  inline void setAPosition(const ngl::Vec3 &_a){m_a->setPosVec(_a);}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief mutator to set the b position of the spring
	/// @param[in] _b the value to set
	//----------------------------------------------------------------------------------------------------------------------
  inline void setBPosition(const ngl::Vec3 &_b){m_b->setPosVec(_b);}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief accesor for the spring a position
	/// @returns m_a the current spring position
	//----------------------------------------------------------------------------------------------------------------------
  inline ngl::Vec3 getAPosition() const {return m_a->getPos();}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief accesor for the spring b position
	/// @returns m_b the current spring position
	//----------------------------------------------------------------------------------------------------------------------
  inline ngl::Vec3 getBPosition() const {return m_b->getPos();}
	//----------------------------------------------------------------------------------------------------------------------
  inline void setinitialAPos(const ngl::Vec3 _pos){m_initialA = _pos;}
  //----------------------------------------------------------------------------------------------------------------------
  inline void setinitialBPos(const ngl::Vec3 _pos){m_initialB = _pos;}
  //----------------------------------------------------------------------------------------------------------------------
	/// @brief accesor for the spring initial a position
	/// @returns m_initialA the current spring position
	//----------------------------------------------------------------------------------------------------------------------
  inline ngl::Vec3 getInitialAPointPos() const {return m_initialA;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief accesor for the spring initial b position
	/// @returns m_initialB the current spring position
	//----------------------------------------------------------------------------------------------------------------------
  inline ngl::Vec3 getInitialBPointPos() const {return m_initialB;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief mutator to set the spring constant k
	/// @param[in] _k the new k value
	//----------------------------------------------------------------------------------------------------------------------
	inline void setK(float _k){m_k=_k;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief mutator to set the spring resting length
	/// @param[in] _l the new resting length value
	//----------------------------------------------------------------------------------------------------------------------
	inline void setLength(float _l){m_length=_l;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief mutator to set the spring damping co-efficient
	/// @param[in] _d the new damping  value
	//----------------------------------------------------------------------------------------------------------------------
	inline void setDamping(float _d){m_damping=_d;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief mutator to set if the point a is fixed and should not be updated
	/// @param[in] _f the new value for the point a
	//----------------------------------------------------------------------------------------------------------------------
  inline void setAFixed(bool _f){m_aFixed=_f;std::cout<<"spring set to true::::::::::::::::::::::::::::::::::::::::::::::::::"<<std::endl;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief mutator to set if the point b is fixed and should not be updated
	/// @param[in] _f the new value for the point b
	//----------------------------------------------------------------------------------------------------------------------
	inline void setBFixed(bool _f){m_bFixed=_f;}
//    /// @brief draw the springs
//    void draw(const ngl::Shader *shader,const ngl::TransformStack &_transformStack);
//  //----------------------------------------------------------------------------------------------------------------------
//  /// @brief accesor for the spring sorce a point index
//  /// @returns m_pointA the current spring source point
//  inline void getSourceIndex(int _pointIndex[2]) {_pointIndex = m_pointA;}
//  //----------------------------------------------------------------------------------------------------------------------
//  /// @brief accesor for the spring target b point index
//  /// @returns m_pointB the current spring target Point
//  inline int getTargetIndex() const {return m_pointB;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief re-set the simulation, this will return a and b to the initial values and
  /// re-set the time value m_t to 0
	//----------------------------------------------------------------------------------------------------------------------
    /// @brief get the id for the spring
    inline int getId() const{return m_id;}
    //----------------------------------------------------------------------------------------------------

	void reset();

private :
  /// @brief the id for the spring
  //-----------------------------------------
  int m_id;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief the spring constant from Hooke's Law
	//----------------------------------------------------------------------------------------------------------------------
	float m_k;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief a damping force for the spring
	//----------------------------------------------------------------------------------------------------------------------
	float m_damping;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief the displacement of the spring from equilibrium
	//----------------------------------------------------------------------------------------------------------------------
	ngl::Vec3 m_displacement;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief relative velocity of the spring
	//----------------------------------------------------------------------------------------------------------------------
	ngl::Vec3 m_velocity;
	//----------------------------------------------------------------------------------------------------------------------
//  /// @brief the start position of the spring m_a-/\/\/\-m_b
//	//----------------------------------------------------------------------------------------------------------------------
//  ngl::Vec3 m_a;
//	//----------------------------------------------------------------------------------------------------------------------
//  /// @brief the end position of the spring m_a-/\/\/\-m_b
//	//----------------------------------------------------------------------------------------------------------------------
//  ngl::Vec3 m_b;
//	//----------------------------------------------------------------------------------------------------------------------
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the start position of the spring m_a-/\/\/\-m_b
  //----------------------------------------------------------------------------------------------------------------------
  MassPoint *m_a;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the end position of the spring m_a-/\/\/\-m_b
  //----------------------------------------------------------------------------------------------------------------------
  MassPoint *m_b;
  //----------------------------------------------------------------------------------------------------------------------
	/// @brief the initial position of the spring point a
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief flag to indicate if point a is fixed and not needing an update
	//----------------------------------------------------------------------------------------------------------------------
	bool m_aFixed;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief flag to indicate if point b is fixed and not needing an update
	//----------------------------------------------------------------------------------------------------------------------
	bool m_bFixed;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief the length of the spring (distance of seperation) at rest
	//----------------------------------------------------------------------------------------------------------------------
    float m_length;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief the time step used for update default 0.1
	//----------------------------------------------------------------------------------------------------------------------
	float m_timestep;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief the current time
  //----------------------------------------------------------------------------------------------------------------------
  float m_t;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief keep track of spring generation cycles
  //----------------------------------------------------------------------------------------------------------------------
  int m_springGen;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the initial position of the spring point a
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_initialA;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the initial position of the spring point b
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_initialB;
  //----------------------------------------------------------------------------------------------------------------------
  ///@brief force for Source
  ngl::Vec3 m_forceA;
  /// @brief force for target
  ngl::Vec3 m_forceB;
};


#endif
