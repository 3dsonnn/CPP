/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:58:14 by efinda            #+#    #+#             */
/*   Updated: 2025/06/13 17:24:14 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>
#include <list>

template <class T, class U, class V>
void    print(T t, U u, V v) { std::cout << t << u << v; }

void    subject( void )
{
    print("---------- ", "SUBJECT TEST", " ----------\n");
    MutantStack<int>    mstack;

    print("Push: ", "5", "\n");
    mstack.push(5);
    print("Push: ", "17", "\n");
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    print("Pop: ", mstack.top(), "\n");
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    print("Push: ", "3", "\n");
    mstack.push(3);
    print("Push: ", "5", "\n");
    mstack.push(5);
    print("Push: ", "737", "\n");
    mstack.push(737);

    //[...]

    print("Push: ", "0", "\n");
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    print("---", "---", "\n");
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    print("---", "---", "\n");
    std::stack<int> s(mstack);
}

void    subjectReplacedWithList( void )
{
    print("---------- ", "SUBJECT REPLACED WITH LIST TEST", " ----------\n");
    std::list<int>    mlist;

    print("Push: ", "5", "\n");
    mlist.push_back(5);
    print("Push: ", "17", "\n");
    mlist.push_back(17);
    // std::cout << "Top: " << mlist.top() << std::endl;
    // print("Pop: ", mlist.top(), "\n");
    // mlist.pop();
    std::cout << "Size: " << mlist.size() << std::endl;
    print("Push: ", "3", "\n");
    mlist.push_back(3);
    print("Push: ", "5", "\n");
    mlist.push_back(5);
    print("Push: ", "737", "\n");
    mlist.push_back(737);

    //[...]

    print("Push: ", "0", "\n");
    mlist.push_back(0);
    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();
    ++it;
    --it;
    print("---", "---", "\n");
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    print("---", "---", "\n");
    std::list<int> s(mlist);
}

void    iterators( void )
{
    print("---------- ", "ITERATORS TEST", " ----------\n");
    MutantStack<int, std::vector<int> > mvector;

    print("Push: ", "3", "\n");
    mvector.push(3);
    print("Push: ", "42", "\n");
    mvector.push(42);
    print("Push: ", "21", "\n");
    mvector.push(21);
    print("Push: ", "5", "\n");
    mvector.push(5);
    print("Push: ", "25", "\n");
    mvector.push(25);
    print("Push: ", "0", "\n");
    mvector.push(0);
    std::cout << std::endl << "Size: " << mvector.size() << std::endl;

    print("********** ", "Normal Loop", " **********\n");
    std::vector<int>::iterator itb = mvector.begin();
    std::vector<int>::iterator ite = mvector.end();
    print("First: ", *itb, "\n");
    print("Last: ", *(ite - 1), "\n");
    print("---", "---", "\n");
    while (itb != ite)
    {
        std::cout << *itb << " + 1 = ";
        *itb += 1;
        std::cout << *itb << std::endl;
        ++itb;
    }
    print("---", "---", "\n");

    print("********** ", "Reverse Loop", " **********\n");
    std::vector<int>::const_reverse_iterator revitb = mvector.rbegin();
    std::vector<int>::const_reverse_iterator revite = mvector.rend();
    print("---", "---", "\n");
    while (revitb != revite)
    {
        std::cout << *revitb << std::endl;
        ++revitb;
    }
    print("---", "---", "\n");

    MutantStack<int, std::vector<int> > a(mvector);
    MutantStack<int, std::vector<int> > b;

    b = a;

    std::cout << std::endl << "A_SIZE = " << a.size() << std::endl;
    std::cout << std::endl << "B_SIZE = " << b.size() << std::endl;

    // std::vector<int>::const_iterator itb = mvector.begin();
    // print("---", "Attempt to modify a const iterator", "---\n");
    // *itb = 9;    //Error: cannot modify a const iterator
    // print("First: ", *itb, "\n");
}

int main( void )
{
    subject();
    subjectReplacedWithList();
    iterators();
    return (0);
}
