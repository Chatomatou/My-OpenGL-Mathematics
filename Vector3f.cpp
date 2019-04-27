#include "Vector3f.h"

using namespace glm;

/**
* \brief Construit un vecteur dans un plan cartesien a 2 dimension
* \param la projection en x et en y et en z
*/
Vector3f::Vector3f(float x, float y, float z) : Vector2f{x, y}, m_z{z}
{

}

/**
* \brief Accesseur de modification du membre z du vecteur
* \param la nouvelle projection en z
*/
constexpr void Vector3f::setZ(float z) noexcept
{
	m_z = z;
}

/**
* \brief Accesseur de récuperation du membre z du vecteur
* \return la projection en z
*/
constexpr float Vector3f::getZ() const noexcept
{
	return m_z;
}

/**
* \brief Calcul le scalaire a.b
* \param un vecteur a 2 dimension utilise la formule x1*x2 + y1*y2 + z1 * z2
		a.b = ax*bx + ay*by + az*bz(utilisé)
		a.b = ||a||*||b||*cos(theta)
* \return le produit scalaire
*/
constexpr float Vector3f::dotProduct(const Vector3f& vec) const noexcept
{
	return m_x * vec.getX() + m_y * vec.getY() + m_z * vec.getZ();
}

/**
* \brief Récupere la norme du vecteur
* \return retourne la norme du vecteur (Application du théorème de pythagore)
*/
float Vector3f::magnitude() const noexcept  
{
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

/**
* \brief Produit vectoriel entre deux vecteur (a^b, a x b, [a, v])
* \return retourne la norme du vecteur (Application du théorème de pythagore)
*/
Vector3f Vector3f::crossProduct(const Vector3f& vec) const noexcept
{
	Vector3f crossProduct;

	crossProduct.setX(m_y * vec.getZ() - m_z * vec.getY());
	crossProduct.setY(m_z * vec.getX() - m_x * vec.getZ());
	crossProduct.setZ(m_x * vec.getY() - m_y * vec.getX());

	return crossProduct;
}



/**
*
* \brief overload de l'operateur + pour lui additionner un vecteur (sans modification du this)
* \param le vecteur à ajouter
* \return le vecteur A vers B
*/
Vector3f Vector3f::operator+(const Vector3f& vec)
{
	return Vector3f{ m_x + vec.getX(), m_y + vec.getY(), m_z + vec.getZ() };
}

/**
* \brief overload de l'operateur - pour lui soustraire un vecteur (sans modification du this)
* \param le vecteur à soustraire
* \return le vecteur B vers A
*/
Vector3f Vector3f::operator-(const Vector3f& vec)
{
	return Vector3f{ m_x - vec.getX(), m_y - vec.getY(), m_z - vec.getZ() };
}

/**
* \brief overload de l'operateur * pour augmenter la taille du vecteur (sans modification du this)
* \param le coefficient k
* \return le vecteur A aggrandir par le coefficient k
*/
Vector3f Vector3f::operator*(const float length)
{
	return Vector3f{ m_x * length, m_y * length, m_z * length};
}

/**
* \brief overload de l'operateur += pour lui additionner un vecteur (avec modification du this)
* \param le vecteur à ajouter
*/
constexpr void Vector3f::operator+=(const Vector3f& vec)
{
	m_x += vec.getX();
	m_y += vec.getY();
	m_z += vec.getZ();
}

/*
* \brief overload de l'operateur -= pour lui soustraire un vecteur (avec modification du this)
* \param le vecteur à soustraire
*/
constexpr void Vector3f::operator-=(const Vector3f& vec)
{
	m_x -= vec.getX();
	m_y -= vec.getY();
	m_z -= vec.getZ();
}

/**
* \brief overload de l'operateur *= pour augmenter la taille du vecteur (avec modification du this)
* \param le coefficient k
*/
constexpr void Vector3f::operator*=(const float length)
{
	m_x *= length;
	m_y *= length;
	m_z *= length;
}