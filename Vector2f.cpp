#include "Vector2f.h"

using namespace glm;

/**
* \brief Construit un vecteur dans un plan cartesien a 2 dimension
* \param la projection en x et en y
*/
constexpr Vector2f::Vector2f(float x, float y) : m_x{x}, m_y{y}
{

}

/**
* \brief Accesseur de modification du membre x du vecteur
* \param la nouvelle projection en x
*/
void Vector2f::setX(const float x) noexcept
{
	m_x = x;
}

/**
* \brief Accesseur de modification du membre y du vecteur
* \param la nouvelle projection en y
*/
void Vector2f::setY(const float y) noexcept
{
	m_y = y;
}

/**
* \brief Accesseur de récuperation du membre x du vecteur
* \return la projection en x
*/
constexpr float Vector2f::getX() const noexcept
{
	return m_x;
}

/**
* \brief Accesseur de récuperation du membre y du vecteur
* \return la projection en y
*/
constexpr float Vector2f::getY() const noexcept
{
	return m_y;
}

/**
* \brief Calcul le scalaire a.b
* \param un vecteur a 2 dimension utilise la formule x1*x2 + y1*y2 
		a.b = ax*bx + ay*by (utilisé)
		a.b = ||a||*||b||*cos(theta)
* \return le produit scalaire 
*/
constexpr float Vector2f::dotProduct(const Vector2f& vec) const noexcept
{
	return m_x * vec.getX() + m_y * vec.getY();
}

/**
* \brief Récupere la norme du vecteur
* \return retourne la norme du vecteur (Application du théorème de pythagore)
*/
float Vector2f::magnitude() const noexcept
{
	return std::sqrt(m_x * m_x + m_y * m_y);
}

/**
* \brief Récupere l'angle entre deux vecteur 
	theta = cos-1(a.b / ||a|| * ||b||)
	theta en Radian
	verifier que ||a|| * ||b|| != 0 
* \param un vecteur
*/
constexpr float Vector2f::getAngle(const Vector2f& vec) const noexcept
{
	return (dotProduct(vec) != 0) ? std::acos(dotProduct(vec) / (magnitude() * vec.magnitude())) : std::acos(dotProduct(vec));
}

/**
*  
* \brief overload de l'operateur + pour lui additionner un vecteur (sans modification du this)
* \param le vecteur à ajouter
* \return le vecteur A vers B
*/
Vector2f Vector2f::operator+(const Vector2f& vec)
{
	return Vector2f{m_x + vec.getX(), m_y + vec.getY()};
}

/**
* \brief overload de l'operateur - pour lui soustraire un vecteur (sans modification du this)
* \param le vecteur à soustraire
* \return le vecteur B vers A
*/
Vector2f Vector2f::operator-(const Vector2f& vec)
{
	return Vector2f{ m_x - vec.getX(), m_y - vec.getY() };
}

/**
* \brief overload de l'operateur * pour augmenter la taille du vecteur (sans modification du this)
* \param le coefficient k
* \return le vecteur A aggrandir par le coefficient k 
*/
Vector2f Vector2f::operator*(const float length)
{
	return Vector2f{ m_x * length, m_y * length };
}

/**
* \brief overload de l'operateur += pour lui additionner un vecteur (avec modification du this)
* \param le vecteur à ajouter
*/
constexpr void Vector2f::operator+=(const Vector2f& vec)
{
	m_x += vec.getX();
	m_y += vec.getY();
}

/*
* \brief overload de l'operateur -= pour lui soustraire un vecteur (avec modification du this)
* \param le vecteur à soustraire
*/
constexpr void Vector2f::operator-=(const Vector2f& vec)
{
	m_x -= vec.getX();
	m_y -= vec.getY();
}

/**
* \brief overload de l'operateur *= pour augmenter la taille du vecteur (avec modification du this)
* \param le coefficient k
*/
constexpr void Vector2f::operator*=(const float length)
{
	m_x *= length;
	m_y *= length;
}