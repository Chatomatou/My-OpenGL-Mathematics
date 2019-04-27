#include "Matrix.h"

using namespace glm;

/**
* \brief Construit une matrice a partir de colonne et de ligne 
* \param le nombre de ligne et de colonne
*/
Matrix::Matrix(unsigned int rows, unsigned int columns) : m_rows{rows}, m_columns{columns}
{
	for (decltype(rows) i = 0; i < rows; i++)
	{
		std::vector<float> tmp;

		for (decltype(columns) j = 0; j < columns; j++)
		{
			tmp.push_back(0);
		}
		m_matrix.push_back(std::move(tmp));
	}
}

/**
* \brief Accesseur de récuperation pour le nombre de ligne
* \return le nombre de ligne 
*/
constexpr unsigned int Matrix::getRows() const noexcept
{
	return m_rows;
}

/**
* \brief Accesseur de récuperation pour le nombre de colonne
* \return le nombre de collone
*/
constexpr unsigned int Matrix::getColumns() const noexcept
{
	return m_columns;
}

/**
* \brief Accesseur de modification une donné dans la matrice 
* \param la ligne, la colonne et la valeur a placer 
*/
void Matrix::setValue(const unsigned int row, const unsigned int column, const float value)
{
	assert(column >= 0 && column < m_columns && row >= 0 and row < m_rows && "Index Overflow !");

	m_matrix[row][column] = value;
}

/**
* \brief Accesseur de récuperation de la donné dans la matrice
* \param la ligne, la colonne
* \return la valeur a l'emplacement 
*/
float Matrix::getValue(const unsigned int row, const unsigned int column) const
{
	assert(column >= 0 && column < m_columns && row >= 0 and row < m_rows && "Index Overflow !");
	return m_matrix[row][column];
}

/**
* \brief Accesseur de récuperation de la donné dans la matrice
* \param la ligne, la colonne
* \return la valeur a l'emplacement
*/
void Matrix::displayConsole() const noexcept
{
	for (decltype(m_rows) i = 0; i < m_rows; i++)
	{
		for (decltype(m_columns) j = 0; j < m_columns; j++)
		{
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

/**
* \brief Multiplication de matrice par une autre matrice
* \param la matrice par la quel on va multiplier 
* \return le resultat de la matrice multiplier par le paramètre
*/
Matrix Matrix::operator*(const Matrix& matrix)
{
	assert(matrix.getColumns() == m_columns && matrix.getRows() == m_rows && "Error : rows et columns must be equal !");

	std::vector<std::vector<float>> separe_matrix_by_vector_columns;
	for (decltype(m_columns) j = 0; j < m_columns; j++)
	{
		std::vector<float> vector;
		for (decltype(m_rows) i = 0; i < m_rows; i++)
		{
			vector.push_back(matrix.getValue(i, j));
		}
		separe_matrix_by_vector_columns.push_back(std::move(vector));
	}

 	Matrix output{ m_rows, m_columns };
 
	for (auto n = 0; n < separe_matrix_by_vector_columns.size(); n++)
	{
		for (decltype(m_rows) i = 0; i < m_rows; i++)
		{
			float c = 0.0f;
			for (decltype(m_columns) j = 0; j < m_columns; j++)
			{
				c += m_matrix[i][j] * separe_matrix_by_vector_columns[n][j];

				if (j == m_columns - 1)
					output.setValue(i, n, c);
			}
 		}
	}
 
	return output;
}

/**
* \brief Multiplication de matrice un vecteur 
* \param le vecteur par le quel on multipliera la matrice 
* \return le vecteur resultant 
*/
Vector3f Matrix::operator*(const Vector3f& vector)
{
	assert(m_columns == 3 && m_rows == 3 && "Error : matrix can't be multiply by glm::Vector3f !");
	Vector3f resultVectorByMatrix;

	resultVectorByMatrix.setX(m_matrix[0][0] * vector.getX() + m_matrix[0][1] * vector.getY() + m_matrix[0][2] * vector.getZ());
	resultVectorByMatrix.setY(m_matrix[1][0] * vector.getX() + m_matrix[1][1] * vector.getY() + m_matrix[1][2] * vector.getZ());
	resultVectorByMatrix.setZ(m_matrix[2][0] * vector.getX() + m_matrix[2][1] * vector.getY() + m_matrix[2][2] * vector.getZ());

	return resultVectorByMatrix;
}

/**
* \brief Multiplication de matrice un vecteur
* \param le vecteur par le quel on multipliera la matrice
* \return le vecteur resultant
*/
std::vector<float> Matrix::operator[](int i)
{
	return m_matrix[i];
}