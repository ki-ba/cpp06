/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:21:03 by kbarru            #+#    #+#             */
/*   Updated: 2026/02/18 16:51:05 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
public:
	Data();
	Data(Data &other);
	Data(int val);
	~Data();
	Data &operator=(Data &other);
	int getVal();
private:
	int _intval;
};

#endif
