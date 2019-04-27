/**
 * \file          Vector3f.h
 * \author    Biczo Samuel
 * \version   1.0
 * \date       27 Avril 2019
 * \brief       D�crit sous forme de class le vecteur (x, y, z) en math�matique
 *
 * \details      Accesseur sur ses projection x et y,
				 Produit scalaire(dot product)
				 norme du vecteur(magnitude)
				 angle du vecteur form� par un autre vecteur
				 produit vectoriel 
				 Surchage de l'op�rateur +, -, *, +=, -=, *=

 */

#pragma once

#include "Vector2f.h"

namespace glm
{
	class Vector3f : public Vector2f
	{
	public:
		/* Constructeur */
		constexpr Vector3f() = default;
		constexpr Vector3f(const Vector3f& vec) = default;
		Vector3f(float x, float y, float z);

		/* Destructeur */
 		~Vector3f() = default;
		
		/* Accesseur */
		constexpr void setZ(float z) noexcept;
		constexpr float getZ() const noexcept;

		/* Fonctionality */
		constexpr float dotProduct(const Vector3f& vec) const noexcept;
		float magnitude() const noexcept;
		Vector3f crossProduct(const Vector3f& vec) const noexcept;

		/* Surchage des op�rateur */
		Vector3f operator+(const Vector3f& vec);
		Vector3f operator-(const Vector3f& vec);
		Vector3f operator*(const float length);
		constexpr void operator+=(const Vector3f& vec);
		constexpr void operator-=(const Vector3f& vec);
		constexpr void operator*=(const float length);

		/*
			TODO : Implement CartesianCoordinate3D
		*/

	private:
		float m_z{};
	};
}