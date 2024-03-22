#include "RK4Spring.h"
#include <QDebug>

RK4Spring::RK4Spring(
                     MassPoint &_a,
                     MassPoint &_b,
                     const int _id
                    )
{
	// ctor sets the initial values
  m_a= new MassPoint();
  m_b= new MassPoint();
  m_a = &_a;
  m_b = &_b;
//	m_initialA=_a;
//	m_initialB=_b;
  m_id = _id;
  m_length=1.0;
  m_k=1.75;
  m_damping=.5;
  m_forceA=0;
  m_forceB=0;
  m_state.m_position=m_b->getPos()-m_a->getPos();
  ngl::Vec3 distance=m_b->getPos()-m_a->getPos();
  float length=distance.length();
  m_state.m_velocity= 0;

    m_timestep=.1;
    m_t=0.0;
    m_aFixed=false;
    m_bFixed=false;
//  std::cout << "created a string from: " << m_a->getMassPointIndex() << "to: " << m_b->getMassPointIndex() << std::endl;

}

void RK4Spring::reset()
{
    // set the timestep to 0 and re-set the position values
    m_t=0;
    *m_a=m_initialA;
    *m_b=m_initialB;
    m_state.m_position=m_b->getPos()-m_a->getPos();
    m_state.m_velocity= 0;


}

void RK4Spring::update()
{
  m_forceA = 0;
  m_forceB = 0;
	// run the RK4 integrator to get the new force values
	integrate(m_t, m_timestep);
	// update the timestep for the next time
	m_t += m_timestep;

	// now  apply to spring points (if they are not fixed)
  if( m_aFixed != true)
	{
        m_forceA=-getState().m_velocity;
        m_a->setForce(m_forceA);
  }
  else
    m_a->setForce(m_forceA);


  if(m_bFixed !=true)
  {
        m_forceB=getState().m_velocity;
        m_b->setForce(m_forceB);
  }
  else
    m_b->setForce(m_forceB);

    //qDebug()<<"Time step "<<m_t;
	//qDebug()<<"k="<<m_k<<" length= "<<m_length<<" damping "<<m_damping;
}


ngl::Vec3 RK4Spring::motionFunction(
																				const State &_state,
																				float _t
																			)
{
  // in the case of the spring we don't need t mark
  // it as unused in this case
  Q_UNUSED(_t);
  /// F = -k(|x|-d)(x/|x|) - bv where
	/// k is the spring constant
	/// |x| is the distance between the two spring points
	/// d is the distance of seperation
	/// b is the coefficient of damping larger b increases the damping force
	/// v is the relative velocity between the spring points
  ngl::Vec3 distance=m_b->getPos()-m_a->getPos();
	float length=distance.length();
	return -m_k*(length-m_length)*(distance/length)-m_damping*_state.m_velocity;

}
