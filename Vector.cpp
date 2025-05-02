/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:42:52 by samusanc          #+#    #+#             */
/*   Updated: 2025/05/02 14:43:17 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <stdexcept>

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

Vector* Vector::clone() const {
	return new Vector(*this);
}

Vector* Vector::add(const Tensors& other) const {
	const Vector* v = dynamic_cast<const Vector*>(&other);
	if (!v || v->cols != cols)
		throw std::runtime_error("Vector::add: incompatible types or sizes");

	Vector* result = new Vector(cols);
	for (size_t i = 0; i < cols; ++i)
		(*result)[0][i] = _content[0][i] + v->_content[0][i];
	return result;
}

Vector* Vector::substract(const Tensors& other) const {
	const Vector* v = dynamic_cast<const Vector*>(&other);
	if (!v || v->cols != cols)
		throw std::runtime_error("Vector::substract: incompatible types or sizes");

	Vector* result = new Vector(cols);
	for (size_t i = 0; i < cols; ++i)
		(*result)[0][i] = _content[0][i] - v->_content[0][i];
	return result;
}

Vector* Vector::scalar(f32 s) const {
	Vector* result = new Vector(cols);
	for (size_t i = 0; i < cols; ++i)
		(*result)[0][i] = _content[0][i] * s;
	return result;
}

Vector Vector::add(const Vector& a, const Vector& b) {
	return *a.add(b);
}

Vector Vector::substract(const Vector& a, const Vector& b) {
	return *a.substract(b);
}

Vector Vector::scalar(const Vector& a, f32 s) {
	return *a.scalar(s);
}

Matrix Vector::to_matrix() const {
	Matrix m(1, cols);
	for (size_t i = 0; i < cols; ++i)
		m[0][i] = _content[0][i];
	return m;
}

Vector operator+(const Vector& a, const Vector& b) {
	return Vector::add(a, b);
}

Vector operator-(const Vector& a, const Vector& b) {
	return Vector::substract(a, b);
}

Vector operator*(const Vector& a, f32 s) {
	return Vector::scalar(a, s);
}