/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:21:27 by samusanc          #+#    #+#             */
/*   Updated: 2025/05/02 14:11:48 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

# pragma once
# include "Tensors.hpp"
# include "Vector.hpp"

class Vector;

class Matrix : public Tensors {
	public:
		Matrix();
		Matrix(size_t r, size_t c);
	
		Matrix* clone() const override;
		Matrix* add(const Tensors& other) const override;
		Matrix* substract(const Tensors& other) const override;
		Matrix* scalar(f32 scalar) const override;
	
		static Matrix add(const Matrix& a, const Matrix& b);
		static Matrix substract(const Matrix& a, const Matrix& b);
		static Matrix scalar(const Matrix& a, f32 scalar);
	
		bool is_square() const;
		Vector to_vector() const;
	
		friend Matrix operator+(const Matrix& a, const Matrix& b);
		friend Matrix operator-(const Matrix& a, const Matrix& b);
		friend Matrix operator*(const Matrix& a, f32 scalar);
};

#endif