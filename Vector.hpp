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

#ifndef VECTOR_HPP
# define VECTOR_HPP

# pragma once
# include "Tensors.hpp"
# include "Matrix.hpp"

class Vector : public Tensors {
	public:
		Vector();
		Vector(size_t length);
		Vector(const std::vector<f32>& flat);
	
		Vector* clone() const override;
		Vector* add(const Tensors& other) const override;
		Vector* substract(const Tensors& other) const override;
		Vector* scalar(f32 scalar) const override;
	
		static Vector add(const Vector& a, const Vector& b);
		static Vector substract(const Vector& a, const Vector& b);
		static Vector scalar(const Vector& a, f32 scalar);
	
		Matrix to_matrix() const;
	
		friend Vector operator+(const Vector& a, const Vector& b);
		friend Vector operator-(const Vector& a, const Vector& b);
		friend Vector operator*(const Vector& a, f32 scalar);
};

#endif