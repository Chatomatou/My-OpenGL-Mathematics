/**
 * \file          PolarCoordinate2D.h
 * \author    Biczo Samuel
 * \version   1.0
 * \date       27 Avril 2019
 * \brief       D�crit sous forme de class une coordonn�e de polaire (r, theta)
 *
 * \details     x = cos(theta) * r, y = sin(theta) * r
				possibiliter de convertir theta en degr�e ou radian 
				possibiliter de revenir en coordonn�e cartesienne
		
 */


#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include "CartesianCoordinate2D.h"
 
namespace glm
{
	class PolarCoordinate2D
	{
	public:
		/* Constructeur */
		constexpr PolarCoordinate2D() = default;
 		PolarCoordinate2D(const float x, const float y);
 
		/* Destructeur */
		~PolarCoordinate2D() = default;

		/* Accesseur */
		void setPolarCoordinate(const float x, const float y) noexcept;
 
		constexpr float getAngle() const noexcept;
		constexpr float getLength() const noexcept;

		/* Outils */
		CartesianCoordinate2D transformCartesianCoordinate() const noexcept;
		constexpr static float toRad(const float thetaDeg) noexcept;
		constexpr static float toDeg(const float thetaRad) noexcept;
	private:
		float m_angle{};
		float m_length{};
	};
}
 