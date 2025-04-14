/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:11:19 by efinda            #+#    #+#             */
/*   Updated: 2025/04/14 19:18:47 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class   FragTrap
{
    private:
        
    public:
        FragTrap();
        ~FragTrap();
        FragTrap(const FragTrap &other);
        FragTrap   &operator=(const FragTrap &other);
};

#endif