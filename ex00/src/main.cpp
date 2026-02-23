/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:35:03 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/10 09:59:34 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		// Invalid inputs
		ScalarConverter::convert("ef");

		// Integers
		ScalarConverter::convert("10");

		// Doubles
		ScalarConverter::convert("0.0");
		ScalarConverter::convert("1.1");
		ScalarConverter::convert("2.12");
		ScalarConverter::convert("42");
		ScalarConverter::convert("3.1001");

		// Floats
		ScalarConverter::convert("0.0f");
		ScalarConverter::convert("1.1f");
		ScalarConverter::convert("-2.12f");

		// Characters
		ScalarConverter::convert("a");
		ScalarConverter::convert("c");
		ScalarConverter::convert("4");
		ScalarConverter::convert("b");

		// Special values
		ScalarConverter::convert("inf");
		ScalarConverter::convert("+inf");
		ScalarConverter::convert("-inf");

		ScalarConverter::convert("inff");
		ScalarConverter::convert("+inff");
		ScalarConverter::convert("-inff");

		ScalarConverter::convert("nan");
		ScalarConverter::convert("nanf");
	}
	else
	{
		for (int i = 1; i < argc; i++)
			ScalarConverter::convert(argv[i]);
	}
	
	return (0);
}
