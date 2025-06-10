/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:37:45 by efinda            #+#    #+#             */
/*   Updated: 2025/06/06 15:32:17 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
    private:
        std::string name;
        int         age;
    public:
        Data();
        ~Data();
        Data(const Data &other);
        Data &operator=(const Data &other);
        Data(std::string name, int age);
};

#endif