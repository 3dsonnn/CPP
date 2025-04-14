/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 10:55:47 by efinda            #+#    #+#             */
/*   Updated: 2025/04/14 19:10:08 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class   ClapTrap
{
    private:
        
    public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap(const ClapTrap &other);
        ClapTrap   &operator=(const ClapTrap &other);
};

#endif
