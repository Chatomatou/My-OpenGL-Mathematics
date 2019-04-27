#include "CartesianCoordinate2D.h"

using namespace glm;

/**
* \brief Construit un point dans un plant cartésien
* \param La coordonnées x et y
*/
CartesianCoordinate2D::CartesianCoordinate2D(float x, float y) : m_x{x}, m_y{y}
{

}

/**
* \brief Accesseur de modification de l'abscice 
* \param la nouvelle abscisse 
*/
constexpr void CartesianCoordinate2D::setX(float x) noexcept
{
	m_x = x;
}

/**
* \brief Accesseur de modification de l'ordonnée
* \param la nouvelle ordonnée
*/
constexpr void CartesianCoordinate2D::setY(float y) noexcept
{
	m_y = y;
}

/**
* \brief Accesseur de récuperation de l'abscice
* \return l'abscice
*/
constexpr float CartesianCoordinate2D::getX() const noexcept
{
	return m_x;
}

/**
* \brief Accesseur de récuperation de l'ordonnée
* \return l'ordonnée
*/
constexpr float CartesianCoordinate2D::getY() const noexcept
{
	return m_y;
}

/**
* \brief Construit un vecteur entre deux point
* \param une coordonnée cartesienne a 2 dimension
* \return un vecteur a deux dimension 
*/
constexpr Vector2f CartesianCoordinate2D::operator-(const CartesianCoordinate2D& point)
{
	return Vector2f{ m_x - point.getX(), m_y - point.getY() };
}
 