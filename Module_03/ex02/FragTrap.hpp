/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:11:19 by efinda            #+#    #+#             */
/*   Updated: 2025/04/15 16:12:56 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class   FragTrap :  public ClapTrap
{
    public:
        FragTrap();
        ~FragTrap();
        FragTrap(std::string arg);
        FragTrap(const FragTrap &other);
        FragTrap    &operator=(const FragTrap &other);
        void        highFivesGuys(void);
};

#endif