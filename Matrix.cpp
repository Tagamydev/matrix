/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:01:24 by samusanc          #+#    #+#             */
/*   Updated: 2025/05/02 14:41:12 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrix.hpp"

Matrix::Matrix() {
	rows = cols = 0;
}

Matrix::Matrix(size_t r, size_t c) {
	rows = r;
	cols = c;
	_content = std::vector<std::vector<f32>>(r, std::vector<f32>(c, 0.0f));
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

Vector::Vector() {
	rows = 1;
	cols = 0;
}

Vector::Vector(size_t length) {
	rows = 1;
	cols = length;
	_content = { std::vector<f32>(length, 0.0f) };
}

Vector::Vector(const std::vector<f32>& flat) {
	rows = 1;
	cols = flat.size();
	_content = { flat };
}

Matrix Vector::to_matrix() const {
	Matrix mat(1, cols);
	for (size_t i = 0; i < cols; ++i)
		mat[0][i] = _content[0][i];
	return mat;
}

