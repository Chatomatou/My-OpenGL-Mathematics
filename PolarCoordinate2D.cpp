#include "PolarCoordinate2D.h"

using namespace glm;

/**
* \brief Construit un point en syst�me de coordonn�e polaire longueur + angle
* \param La coordonn�es x et y
*/
PolarCoordinate2D::PolarCoordinate2D(const float x, const float y) : m_length{std::sqrt(x *x + y * y)}, m_angle(atan2(x, y))
{
	
}
 
/**
* \brief Accesseur de modification de la coordonn�e polaire
* \param coordonn�e cartesien x et y
*/
void PolarCoordinate2D::setPolarCoordinate(const float x, const float y) noexcept
{
	m_length = std::sqrt(x * x + y * y);
	m_angle = std::atan2(x, y);
}

/**
* \brief Accesseur de r�cuperation de l'angle
* \return retourne l'angle en radian
*/
constexpr float PolarCoordinate2D::getAngle() const noexcept
{
	return m_angle;
}

/**
* \brief Accesseur de r�cuperation de la longueur
* \return retourne la longueur
*/
constexpr float PolarCoordinate2D::getLength() const noexcept
{
	return m_length;
}

/**
* \brief Transform la coordonn�e polaire en coordon�e cartesienne
* \return retourne la coordonn�e en syst�me de coordonn�e polaire vers un syst�me de coordonn�e cartesienne
*/
CartesianCoordinate2D PolarCoordinate2D::transformCartesianCoordinate() const noexcept
{
	return CartesianCoordinate2D{ m_length * std::cos(m_angle), m_length * std::sin(m_angle) };
}

/**
* \brief Change l'unit� de l'angle en radian
* \param un angle en degr�e
* \return un angle en radian
*/
constexpr float PolarCoordinate2D::toRad(const float thetaDeg) noexcept
{
	return thetaDeg * static_cast<float>(M_PI) / 180.0f;
}

/**
* \brief Change l'unit� de l'angle en degr�e
* \param un angle en radian
* \return un angle en degr�e
*/
constexpr float PolarCoordinate2D::toDeg(const float thetaRad) noexcept
{
	return thetaRad * 180.0f / static_cast<float>(M_PI);
}