/**
 * \file          Vector3f.h
 * \author    Biczo Samuel
 * \version   1.0
 * \date       27 Avril 2019
 * \brief       Décrit l'objet mathématique qu'est la matrice 
 *
 * \details      Multiplication de matrice par matrice 
				 Multiplication de matrice par un vecteur 
				 Accesseur 
				 overload de l'operateur []
 */

#pragma once

#include <iostream>
#include <vector>
#include <cassert>
 
#include "Vector3f.h"
 

namespace glm
{
	class Matrix
	{
	public:
		/* Constructeur */
		Matrix() = delete;
		Matrix(unsigned int rows, unsigned int columns);  
		
		/* Destructeur */
		~Matrix() = default;

		/* Accesseur */
		constexpr unsigned int getRows() const noexcept;
		constexpr unsigned int getColumns() const noexcept;
 		void setValue(const unsigned int row, const unsigned int column, const float value);
		float getValue(const unsigned int row, const unsigned int column) const;

		/* Outils */
		void displayConsole() const noexcept;
 
		Matrix operator*(const Matrix& matrix);
		Vector3f operator*(const Vector3f& vector);

		std::vector<float> operator[](int i);
 
	private:
		std::vector<std::vector<float>> m_matrix{};
		unsigned int m_rows{};
		unsigned int m_columns{};
	};
}
 