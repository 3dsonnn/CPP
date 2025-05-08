/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:58:57 by efinda            #+#    #+#             */
/*   Updated: 2025/05/08 15:59:55 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int	main( void )
{
	// Teste 1: Reproduz o exemplo do enunciado
	std::cout << "=== Teste 1: Exemplo do Enunciado ===\n" << std::endl;
	{
		IMateriaSource	*src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter	*me = new Character("me");
		AMateria	*tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter	*bob = new Character("bob");

		me->use(0, *bob); // Esperado: * shoots an ice bolt at bob *
		me->use(1, *bob); // Esperado: * heals bob's wounds *

		delete bob;
		delete me;
		delete src;
	}

	// Teste 2: Inventário cheio
	std::cout << "\n=== Teste 2: Inventário Cheio ===\n" << std::endl;
	{
		ICharacter	*alice = new Character("alice");
		IMateriaSource	*src = new MateriaSource();
		AMateria	*ice;

		src->learnMateria(new Ice());

		for (int i = 0; i < 4; ++i)
		{
			ice = src->createMateria("ice");
			alice->equip(ice);
		}
		ice = src->createMateria("ice");
		alice->equip(ice); // Deve ser ignorado
		delete ice; // Como não foi equipado, deletamos manualmente

		ICharacter *target = new Character("target");

		for (int i = 0; i < 3; ++i)
			alice->use(i, *target); // Esperado: 4x * shoots an ice bolt at target *

		alice->use(4, *target); // Deve ser ignorado

		delete target;
		delete alice;
		delete src;
	}

	// Teste 3: Unequip e gerenciar Materias desequipadas
	std::cout << "\n=== Teste 3: Unequip ===\n" << std::endl;
	{
		ICharacter	*charlie = new Character("charlie");
		IMateriaSource	*src = new MateriaSource();
		ICharacter	*target = new Character("target");

		src->learnMateria(new Cure());

		AMateria *cure1 = src->createMateria("cure");
		AMateria *cure2 = src->createMateria("cure");

		charlie->equip(cure1);
		charlie->equip(cure2);

		// cure1 é desequipado, mas não deletado
		charlie->unequip(0);
		charlie->use(0, *target); // Deve ser ignorado

		//cure é reequipado não deve dar double free
		charlie->equip(cure1);
		charlie->equip(cure1);

		charlie->use(2, *target); // Deve ser ignorado
		charlie->use(1, *target); // Esperado: * heals target's wounds *

		delete target;
		delete charlie;
		delete src;
	}

	// Teste 4: Cópia profunda de Character
	std::cout << "\n=== Teste 4: Cópia Profunda ===\n" << std::endl;
	{
		IMateriaSource	*src = new MateriaSource();

		src->learnMateria(new Ice());

		Character	*original = new Character("original");
		AMateria	*ice = src->createMateria("ice");

		original->equip(ice);

		Character	*copy = new Character(*original);

		copy->use(0, *copy); // Esperado: * shoots an ice bolt at copy *
		copy->unequip(0);
		// Esperado: * shoots an ice bolt at original * pois modificar a cópia não deve afetar o original
		original->use(0, *original);

		Character	*assigned = new Character("assigned");
	
		*assigned = *original;
		assigned->use(0, *assigned); // Esperado: * shoots an ice bolt at assigned *

		delete assigned;
		delete copy;
		delete original;
		delete src;
	}

	// Teste 5: MateriaSource com tipo desconhecido
	std::cout << "\n=== Teste 5: Tipo Desconhecido ===\n" << std::endl;
	{
		IMateriaSource	*src = new MateriaSource();

		src->learnMateria(new Ice());

		AMateria	*unknown = src->createMateria("fire"); // Tipo desconhecido

		if (!unknown)
			std::cout << "Correctly returned NULL for unknown type\n";

		AMateria	*ice = src->createMateria("ice");
		
		if (ice)
		{
			std::cout << "Successfully created ice materia\n";
			delete ice;
		}
		delete src;
	}
	return (0);
}
