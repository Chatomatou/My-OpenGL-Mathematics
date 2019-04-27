#include "Color.h"

using namespace glm;

/**
* \brief Construit une représentation d'une couleur sous format RGBA
* \param la composante de rouge, la composante de vert, la composante de bleu et la transparence
*/
constexpr Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : m_red{r}, m_green{g}, m_blue{b}, m_alpha{a}
{

}

/**
* \brief Accesseur de modification de la couleur rouge
* \param la nouvelle composante de rouge
*/
constexpr void Color::setRed(unsigned char red)
{
	m_red = red;
}

/**
* \brief Accesseur de modification de la couleur verte
* \param la nouvelle composante de vert
*/
constexpr void Color::setGreen(unsigned char green)
{
	m_green = green;
}

/**
* \brief Accesseur de modification de la couleur bleu
* \param la nouvelle composante de bleu
*/
constexpr void Color::setBlue(unsigned char blue)
{
	m_blue = blue;
}

/**
* \brief Accesseur de modification de transparence
* \param la nouvelle composante de transparence
*/
constexpr void Color::setAlpha(unsigned char alpha)
{
	m_alpha = alpha;
}

/**
* \brief Accesseur de récuperation de la composante rouge entre [0, 1]
* \return la composante rouge
*/
constexpr float Color::getRed() const noexcept
{
	return m_red / 255.f;
}

/**
* \brief Accesseur de récuperation de la composante verte entre [0, 1]
* \return la composante verte
*/
constexpr float Color::getGreen() const noexcept
{
	return m_green / 255.f;
}

/**
* \brief Accesseur de récuperation de la composante bleu entre [0, 1]
* \return la composante bleu
*/
constexpr float Color::getBlue() const noexcept
{
	return m_blue / 255.f;
}

/**
* \brief Accesseur de récuperation de la transparence entre [0, 1]
* \return la composante transparence
*/
constexpr float Color::getAlpha() const noexcept
{
	return m_alpha / 255.f;
}