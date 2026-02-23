/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:18:34 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/10 13:42:40 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class ScalarConverter
{
public:
	
	virtual ~ScalarConverter();
	static void	convert(std::string);
	
	
private:
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &other);
	void	toInt(std::string str);
	
};
