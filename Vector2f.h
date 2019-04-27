/**
 * \file          Vector2f.h
 * \author    Biczo Samuel
 * \version   1.0
 * \date       27 Avril 2019
 * \brief       Décrit sous forme de class le vecteur (x, y) en mathématique
 *
 * \details      Accesseur sur ses projection x et y,
				 Produit scalaire(dot product)
				 norme du vecteur(magnitude)
				 angle du vecteur formé par un autre vecteur

				 Surchage de l'opérateur +, -, *, +=, -=, *=

 */

#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
 
namespace glm
{

	class Vector2f
	{
	public:
		/* Constructeur */
		constexpr Vector2f() = default;
		constexpr Vector2f(const Vector2f& vec) = default;
		constexpr Vector2f(float x, float y);
 
		/* Destructeur */
		~Vector2f() = default;


		/* Accesseur */
		void setX(const float x) noexcept;
		void setY(const float y) noexcept;
		constexpr float getX() const noexcept;
		constexpr float getY() const noexcept;

		/* Outils */
		constexpr float dotProduct(const Vector2f& vec) const noexcept;
 		float magnitude() const noexcept;
		constexpr float getAngle(const Vector2f& vec) const noexcept;


		/* Surchage des opérateur */
		Vector2f operator+(const Vector2f& vec);
		Vector2f operator-(const Vector2f& vec);
		Vector2f operator*(const float length);
		constexpr void operator+=(const Vector2f& vec);
		constexpr void operator-=(const Vector2f& vec);
		constexpr void operator*=(const float length);

 
	protected:
		float m_x{};
		float m_y{};
	};
}
 