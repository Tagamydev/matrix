/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tensors.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:41:18 by samusanc          #+#    #+#             */
/*   Updated: 2025/05/02 14:41:29 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tensors.hpp"
#include <stdexcept>

void Tensors::print() const {
	for (const auto& row : _content) {
		for (f32 val : row)
			std::cout << val << " ";
		std::cout << std::endl;
	}
}

int Tensors::size() const {
	return static_cast<int>(rows * cols);
}

std::vector<f32>& Tensors::operator[](size_t index) {
	return _content.at(index);
}

const std::vector<f32>& Tensors::operator[](size_t index) const {
	return _content.at(index);
}

std::ostream& operator<<(std::ostream& os, const Tensors& v) {
	for (size_t i = 0; i < v.rows; ++i) {
		for (size_t j = 0; j < v.cols; ++j) {
			os << v._content[i][j] << " ";
		}
		os << "\n";
	}
	return os;
}