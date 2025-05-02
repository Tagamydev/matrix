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

#ifndef TENSORS_HPP
# define TENSORS_HPP

# pragma once
# include <string>
# include <iostream>
# include <vector>
# include <climits>

static_assert(sizeof(float) * CHAR_BIT == 32, "float is not 32 bit on this architecture, fix the f32 typedef.");
typedef float f32;

class Tensors {
	public:
		virtual ~Tensors() {}
	
		virtual Tensors* clone() const = 0;
		virtual Tensors* add(const Tensors& other) const = 0;
		virtual Tensors* substract(const Tensors& other) const = 0;
		virtual Tensors* scalar(f32 scalar) const = 0;
	
		virtual void print() const;
		friend std::ostream& operator<<(std::ostream& os, const Tensors& v);
	
		virtual int size() const;
		std::vector<f32>& operator[](size_t index);
		const std::vector<f32>& operator[](size_t index) const;
	
	protected:
		std::vector<std::vector<f32>> _content;
		size_t rows = 0;
		size_t cols = 0;
};

#endif