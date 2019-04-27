/**
 * \file          CartesianCoordinate2D.h
 * \author    Biczo Samuel
 * \version   1.0
 * \date       27 Avril 2019
 * \brief       Décrit un éspace euclidien a 2 dimension X et Y (O, i, j)
 *
 * \details       Décrit l'emplacement d'un objet dans le plan 2D
					surchage opérateur - pour bx - ax et by - ay
 */

#pragma once
 
#include "Vector2f.h"

namespace glm
{
	class CartesianCoordinate2D
	{
	public:
		/* Constructeur */
		constexpr CartesianCoordinate2D() = default;
		constexpr CartesianCoordinate2D(const CartesianCoordinate2D& cartesian) = default;
		CartesianCoordinate2D(float x, float y);

		/* Destructeur */
		~CartesianCoordinate2D() = default;

		/* Accesseur */
		constexpr void setX(float x) noexcept;
		constexpr void setY(float y) noexcept;
		constexpr float getX() const noexcept;
		constexpr float getY() const noexcept;
		 

		/* Surchage des opérateur */
		constexpr Vector2f operator-(const CartesianCoordinate2D& point);
		 
	private:
		float m_x{};
		float m_y{};
	};
}

 