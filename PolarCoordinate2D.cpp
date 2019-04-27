#include "PolarCoordinate2D.h"

using namespace glm;

/**
* \brief Construit un point en système de coordonnée polaire longueur + angle
* \param La coordonnées x et y
*/
PolarCoordinate2D::PolarCoordinate2D(const float x, const float y) : m_length{std::sqrt(x *x + y * y)}, m_angle(atan2(x, y))
{
	
}
 
/**
* \brief Accesseur de modification de la coordonnée polaire
* \param coordonnée cartesien x et y
*/
void PolarCoordinate2D::setPolarCoordinate(const float x, const float y) noexcept
{
	m_length = std::sqrt(x * x + y * y);
	m_angle = std::atan2(x, y);
}

/**
* \brief Accesseur de récuperation de l'angle
* \return retourne l'angle en radian
*/
constexpr float PolarCoordinate2D::getAngle() const noexcept
{
	return m_angle;
}

/**
* \brief Accesseur de récuperation de la longueur
* \return retourne la longueur
*/
constexpr float PolarCoordinate2D::getLength() const noexcept
{
	return m_length;
}

/**
* \brief Transform la coordonnée polaire en coordonée cartesienne
* \return retourne la coordonnée en système de coordonnée polaire vers un système de coordonnée cartesienne
*/
CartesianCoordinate2D PolarCoordinate2D::transformCartesianCoordinate() const noexcept
{
	return CartesianCoordinate2D{ m_length * std::cos(m_angle), m_length * std::sin(m_angle) };
}

/**
* \brief Change l'unité de l'angle en radian
* \param un angle en degrée
* \return un angle en radian
*/
constexpr float PolarCoordinate2D::toRad(const float thetaDeg) noexcept
{
	return thetaDeg * static_cast<float>(M_PI) / 180.0f;
}

/**
* \brief Change l'unité de l'angle en degrée
* \param un angle en radian
* \return un angle en degrée
*/
constexpr float PolarCoordinate2D::toDeg(const float thetaRad) noexcept
{
	return thetaRad * 180.0f / static_cast<float>(M_PI);
}