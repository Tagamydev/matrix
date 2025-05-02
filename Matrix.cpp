/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:01:24 by samusanc          #+#    #+#             */
/*   Updated: 2025/05/02 14:42:47 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrix.hpp"

#include <stdexcept>

Matrix::Matrix() {}

Matrix::Matrix(size_t r, size_t c) {
	rows = r;
	cols = c;
	_content = std::vector<std::vector<f32>>(r, std::vector<f32>(c, 0.0f));
}

Matrix* Matrix::clone() const {
	return new Matrix(*this);
}

Matrix* Matrix::add(const Tensors& other) const {
	const Matrix* m = dynamic_cast<const Matrix*>(&other);
	if (!m || rows != m->rows || cols != m->cols)
		throw std::runtime_error("Matrix::add: incompatible types or sizes");

	Matrix* result = new Matrix(rows, cols);
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < cols; ++j)
			(*result)[i][j] = _content[i][j] + m->_content[i][j];

	return result;
}

Matrix* Matrix::substract(const Tensors& other) const {
	const Matrix* m = dynamic_cast<const Matrix*>(&other);
	if (!m || rows != m->rows || cols != m->cols)
		throw std::runtime_error("Matrix::substract: incompatible types or sizes");

	Matrix* result = new Matrix(rows, cols);
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < cols; ++j)
			(*result)[i][j] = _content[i][j] - m->_content[i][j];

	return result;
}

Matrix* Matrix::scalar(f32 s) const {
	Matrix* result = new Matrix(rows, cols);
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < cols; ++j)
			(*result)[i][j] = _content[i][j] * s;

	return result;
}

Matrix Matrix::add(const Matrix& a, const Matrix& b) {
	return *a.add(b);
}

Matrix Matrix::substract(const Matrix& a, const Matrix& b) {
	return *a.substract(b);
}

Matrix Matrix::scalar(const Matrix& a, f32 s) {
	return *a.scalar(s);
}

bool Matrix::is_square() const {
	return rows == cols;
}

Vector Matrix::to_vector() const {
	std::vector<f32> flat;
	for (const auto& row : _content)
		flat.insert(flat.end(), row.begin(), row.end());
	return Vector(flat);
}

Matrix operator+(const Matrix& a, const Matrix& b) {
	return Matrix::add(a, b);
}

Matrix operator-(const Matrix& a, const Matrix& b) {
	return Matrix::substract(a, b);
}

Matrix operator*(const Matrix& a, f32 s) {
	return Matrix::scalar(a, s);
}