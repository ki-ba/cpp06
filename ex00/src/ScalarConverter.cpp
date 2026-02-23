/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:22:11 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/17 17:18:23 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdlib.h>
#include <float.h>
#include "ScalarConverter.hpp"

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
}	t_type;

typedef enum special_values
{
	DNAN = 1,
	PINF,
	NINF,
	NANF,
	PINFF,
	NINFF
}	t_special_values;

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

int	isSpecialValue(std::string val)
{
	std::string values[7] = {"", "nan", "+inf", "-inf", "nanf", "+inff", "-inff"};
	for (int i = 1; i < 7; i++)
	{
		if (val == values[i])
			return (i);
	}
	return (0);
}

void displaySpecialValue(std::string val)
{
	std::string values[3] = {"nan", "+inf", "-inf"};
	std::string valuesf[3] = {"nanf", "+inff", "-inff"};
	size_t i;

	for (i = 0; i < 3; i++)
	{
		if (val == values[i] || val == valuesf[i])
		{
			val = values[i];
			break ;
		}
	}
	std::cout << "float : " << values[i] << "f" << std::endl;
	std::cout << "double : " << values[i] << std::endl;
}

t_type	detectType(std::string str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (CHAR);
	else if ((str.find('.') != std::string::npos || str.c_str()[str.length() - 1] == 'f') || isSpecialValue(str) >= 5)
		return (FLOAT);
	else if (str.find('.') != std::string::npos || (isSpecialValue(str) >= 1 && isSpecialValue(str) <= 4))
		  return (DOUBLE);
	else
		return (INT);
}

int isValidInt(std::string val)
{
	char *endptr;
	strtol(val.c_str(), &endptr, 10);
	return (*endptr == '\0');
}

void displayAsFloatingPoint(std::string val, double double_val, char *endptr)
{
	if (isSpecialValue(val))
	{
		displaySpecialValue(val);
		return ;
	}
	else if (endptr && *endptr != '\0' && *endptr != 'f')
	{
		std::cout << "float : Impossible" << std::endl;
		std::cout << "double : Impossible" << std::endl;
		return ;
	}
	else if (double_val < -FLT_MAX || double_val > std::numeric_limits<double>::max())
	{
		std::cout << "float : Impossible" << std::endl;
		std::cout << "double : Impossible" << std::endl;
		return ;
	}
	else
	{
		std::cout << "float :" << std::fixed << std::setprecision(1) << static_cast<float>(double_val) << "f" << std::endl;
		std::cout << "double : " << std::fixed << std::setprecision(1) << double_val << std::endl;
		return;
	}
}

void displayAsChar(double double_val, char *endptr)
{
	std::cout << "char: ";
	if (endptr && *endptr != '\0')
		std::cout << "Impossible" << std::endl;
	else if (double_val < 0 || double_val > std::numeric_limits<char>::max())
		std::cout << "Impossible" << std::endl;
	else if (double_val < 32 || double_val > 127)
		std::cout << "Not displayable" << std::endl;
	else if (double_val == static_cast<int>(double_val))
		std::cout << "'" << static_cast<char>(double_val) << "'" << std::endl;
	else
		std::cout << "Impossible" << std::endl;
}

void printChar(std::string val)
{
	int		int_val = static_cast<int>(val[0]);

	if (val.length() == 1 && isascii(val[0]))
	{
		std::cout << "char : '" << val[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(val[0]) << std::endl;
	}
	else
		displayAsChar(int_val, NULL);
	displayAsFloatingPoint(val, static_cast<double>(int_val), NULL);
}

void printInt(std::string val)
{
	char *endptr = NULL;
	long int long_val =	strtol(val.c_str(), &endptr, 10);
	int int_val = static_cast<int>(long_val);

	displayAsChar(int_val, endptr);
	std::cout << "int: ";
	if (*endptr != '\0')
		std::cout << "Impossible" << std::endl;
	else if (long_val < std::numeric_limits<int>::min() || long_val > std::numeric_limits<int>::max())
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(int_val) << std::endl;
	displayAsFloatingPoint(val, static_cast<double>(long_val), endptr);
}


void printFloat(std::string val)
{
	char *endptr;
	float	float_val = std::strtof(val.c_str(), &endptr);
	int		int_val = static_cast<int>(float_val);
	std::cout << "int: ";
	if (*endptr != '\0' || isSpecialValue(val))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << int_val << std::endl;
	displayAsChar(int_val, endptr);
	displayAsFloatingPoint(val, float_val, endptr);
}


void printDouble(std::string val)
{

	char	*endptr;
	double	double_val = static_cast<double>(std::strtod(val.c_str(), &endptr));
	int		int_val = static_cast<int>(double_val);
	std::cout << "int: " ;
	if (isSpecialValue(val))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << int_val << std::endl;
	displayAsChar(double_val, endptr);
	displayAsFloatingPoint(val, double_val, endptr);
}

void	ScalarConverter::convert(std::string str)
{

	// first detect type, then create printDouble, printInt etc.
	// Those functions will try to convert the given double, int etc to every other type.

	t_type type = detectType(str);

	// std::cout << "type detected: " << (type == CHAR ? "char" : type == INT ? "int" : type == FLOAT ? "float" : "double") << std::endl;
	switch	(type)
	{
		case CHAR:
			printChar(str);
			break;
		case INT:
			printInt(str);
			break;
		case FLOAT:
			printFloat(str);
			break;
		case DOUBLE:
			printDouble(str);
			break;
	}
	std::cout << "-----------------------------" << std::endl;
}
