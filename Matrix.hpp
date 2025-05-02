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

# include <string>
# include <iostream>
# include <vector>
# include <climits>

static_assert(sizeof(float) * CHAR_BIT == 32, "float is not 32 bit on this architecture, fix the f32 typedef.");
typedef float f32;

class Tensors {
	public:
		Tensors();
		Tensors(const Tensors& other);
		Tensors& operator=(const Tensors& other);
		virtual ~Tensors();

		std::vector<f32>& operator[](size_t index);
		const std::vector<f32>& operator[](size_t index) const;
		friend std::ostream& operator<<(std::ostream& os, const Tensors& v);

		void print();
		int size();

		Tensors	add(const Tensors& a, const Tensors& b);
		Tensors	substract(const Tensors& a, const Tensors& b);
		Tensors scalar(const Tensors& a, const f32 scalar);

		// add and substract
		friend Tensors operator+(const Tensors& a, const Tensors& b);
		friend Tensors operator-(const Tensors& a, const Tensors& b);
		friend Tensors operator*(const Tensors& a, const f32 scalar);

	protected:
		std::vector<std::vector<f32>> _content;
		size_t rows;
		size_t cols;
};

class Vector;

class Matrix : public Tensors {
	public:
		Matrix(size_t r, size_t c);
		bool is_square() const;
		Vector to_vector() const;

	private:
		Matrix();
};

class Vector : public Tensors {
	public:
		Vector(size_t length);
		Vector(const std::vector<f32>& flat);
		Matrix to_matrix() const;
	private:
		Vector();
};

#endif
