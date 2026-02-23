/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:36:39 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/18 16:46:31 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data d(-2147);
	uintptr_t ptr;
	Data *raw;

	ptr = Serializer::serialize(&d);
	raw = Serializer::deserialize(ptr);

	std::cout << "&d = " << &d << std::endl;
	std::cout << "serialize : " << ptr << std::endl;
	std::cout << "raw: " << raw << std::endl;
	std::cout << "initial value : "<< d.getVal() << std::endl ;
	std::cout << "serialized then deserialized value : "<< raw->getVal() << std::endl ;
	return (0);
}
