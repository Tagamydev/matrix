/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:06:01 by samusanc          #+#    #+#             */
/*   Updated: 2025/05/02 15:22:06 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrix.hpp"

int	main()
{
	Matrix	matrix1(3, 2);
	Matrix	matrix2(3, 3);

	matrix1[1][2] = 2;
	matrix2[1][2] = 3;

	std::cout << matrix1 + matrix2 << std::endl;

	return (0);
}
