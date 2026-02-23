/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:34:04 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/18 16:50:55 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _intval(42) {}
Data::Data(int val) : _intval(val) {}
Data::~Data() {}
Data::Data(Data &other) : _intval(other._intval) {}

Data &Data::operator=(Data &other)
{
	(void)other;
	return (*this);
}

int Data::getVal() { return (this->_intval);}
int	Data::setVal(int val) { return (this->_intval = val); }
