/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 10:55:47 by efinda            #+#    #+#             */
/*   Updated: 2025/04/12 10:56:52 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

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
