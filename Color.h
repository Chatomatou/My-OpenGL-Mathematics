/**
 * \file          Color.h
 * \author    Biczo Samuel
 * \version   1.0
 * \date       27 Avril 2019
 * \brief       Décrit une couleur de manière RGBA
 *
 * \details      Principe de la synthèse additive

 */

#pragma once

namespace glm
{
	class Color
	{
	public:
		/* Constructeur */
		Color() = delete;
		constexpr Color(const Color& color) = default;
		constexpr Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
		
		/* Destructeur */
		~Color() = default;

		/* Accesseur */
		constexpr void setRed(unsigned char red);
		constexpr void setGreen(unsigned char green);
		constexpr void setBlue(unsigned char blue);
		constexpr void setAlpha(unsigned char alpha);
		constexpr float getRed() const noexcept;
		constexpr float getGreen() const noexcept;
		constexpr float getBlue() const noexcept;
		constexpr float getAlpha() const noexcept;
		

	private:
		unsigned char m_red{};
		unsigned char m_green{};
		unsigned char m_blue{};
		unsigned char m_alpha{};
	};
}
 