*This project has been created as part of the 42 curriculum by Edson Baptista Finda.*

# Contents

- [Description](#description)
- [Module_00 — Basics of C++](#module_00--basics-of-c)
- [Module_01 — Memory allocation, references & pointers to members](#module_01--memory-allocation-references--pointers-to-members)
- [Module_02 — Ad-hoc polymorphism & the Orthodox Canonical Form](#module_02--ad-hoc-polymorphism--the-orthodox-canonical-form)
- [Module_03 — Inheritance](#module_03--inheritance)
- [Module_04 — Subtype polymorphism, abstract classes & interfaces](#module_04--subtype-polymorphism-abstract-classes--interfaces)
- [Module_05 — Repetition & exceptions](#module_05--repetition--exceptions)
- [Module_06 — C++ casts](#module_06--c-casts)
- [Module_07 — Templates](#module_07--templates)
- [Module_08 — Templated containers, iterators & algorithms](#module_08--templated-containers-iterators--algorithms)
- [Module_09 — STL in practice](#module_09--stl-in-practice)
- [Resources](#resources)

# Description

This repository holds my solutions to the 42 **C++ Piscine**: ten modules (`Module_00` through `Module_09`) that take C++ from "C with classes" to idiomatic, STL-driven **C++98**. Rather than a language tour, each module is built around a small set of exercises that force a specific concept to actually matter — you don't learn what a copy constructor is *for* until an assignment bug silently corrupts an object because you didn't write one.

Every exercise lives in its own `ex0N/` folder with its own `Makefile`, so each one compiles and runs independently. The sections below aren't a file listing — they walk through the C++ concept each module targets and how the exercises inside it were used to apply it.

This wasn't just an isolated language exercise, either. The Orthodox Canonical Form, inheritance and polymorphism (Modules 02–04), exceptions (Module 05), and the STL container/algorithm habits from Modules 08–09 carried straight into [**webserv**](https://github.com/3dsonnn/webserv), where they stopped being toy examples and became the actual class design, error handling, and data structures behind a working HTTP server.

## Module_00 — Basics of C++

[#module_00--basics-of-c](#module_00--basics-of-c)

The entry point into the language: moving off `printf`-style C and into `std::cout`/`std::cin`, member functions, and the class/object split between interface (`.hpp`) and implementation (`.cpp`) files.

- **`ex00` — megaphone**: `std::cout`/streams as a replacement for `printf`, and iterating `argv` to transform and print each argument in uppercase.
- **`ex01` — PhoneBook**: A first real class (`Contact`) wrapped by a manager (`PhoneBook`), with a fixed-size, circular contact buffer (max 8 entries). Establishes the habit of keeping data `private` and exposing behavior through member functions, plus basic input validation on a CLI menu loop.
- **`ex02` — Account**: `static` member variables and functions shared across every instance (a running total of accounts, deposits, and withdrawals), and `const` member functions that guarantee a getter doesn't mutate state.

## Module_01 — Memory allocation, references & pointers to members

[#module_01--memory-allocation-references--pointers-to-members](#module_01--memory-allocation-references--pointers-to-members)

The module where `new`/`delete` replace `malloc`/`free`, and where the distinction between a reference and a pointer to a member stops being academic.

- **`ex00`/`ex01` — Zombie / zombieHorde**: The same class instantiated on the stack (`newZombie`) vs. the heap (`randomChump`) to make the ownership and lifetime differences concrete, then extended to a heap-allocated *array* of objects (`zombieHorde`), reinforcing why array `delete[]` exists.
- **`ex02` — HI THIS IS J**: A pointer and a reference pointed at the same object, used to show they refer to identical memory — setting up the "when do I use one over the other" question the next exercise answers.
- **`ex03` — HumanA / HumanB / Weapon**: `HumanA` holds its `Weapon` by reference (must be initialized at construction, can never be null or reassigned), `HumanB` holds it by pointer (can be swapped or left unset) — a direct, working comparison of the two member-storage strategies.
- **`ex04` — Read, then reload**: File I/O (`ifstream`/`ofstream`) combined with string search-and-replace, using `std::string` methods instead of C string handling.
- **`ex05`/`ex06` — Harl**: Pointers to member functions stored in an array/map and dispatched by index or by a `switch`, so a single call routes to the right member function without a long `if`/`else if` chain.

## Module_02 — Ad-hoc polymorphism & the Orthodox Canonical Form

[#module_02--ad-hoc-polymorphism--the-orthodox-canonical-form](#module_02--ad-hoc-polymorphism--the-orthodox-canonical-form)

Centered on one class, `Fixed` (a fixed-point number implemented over a raw `int`), rebuilt four times to progressively layer on the four canonical member functions every non-trivial C++98 class needs — **default constructor, copy constructor, copy assignment operator, and destructor** — plus operator overloading.

- **`ex00`**: The Orthodox Canonical Form itself: writing all four canonical members explicitly instead of relying on the (often wrong, for classes owning resources) compiler-generated defaults.
- **`ex01`**: Converting between the fixed-point internal representation and `int`/`float`, and overloading `operator<<` so `Fixed` prints like a normal number.
- **`ex02`**: The comparison (`<`, `>`, `<=`, `>=`, `==`, `!=`) and arithmetic (`+`, `-`, `*`, `/`) operators, plus pre/post increment and decrement — `operator++()` vs `operator++(int)` — and `min`/`max` overloads.
- **`ex03`**: Applying `Fixed` and operator overloading to a real problem — a `Point` class and a `bsp` (barycentric coordinate) function that determines whether a point lies inside a triangle, entirely with fixed-point math to avoid floating-point edge cases.

## Module_03 — Inheritance

[#module_03--inheritance](#module_03--inheritance)

A four-exercise chain that adds a level of inheritance each time, ending in a **diamond inheritance** problem and its `virtual` fix.

- **`ex00` — ClapTrap**: The base class: hit points, energy points, and an attack/take-damage/repair loop that every derived class will reuse.
- **`ex01` — ScavTrap**: Single inheritance from `ClapTrap`, overriding behavior (a different attack) while reusing the base constructor/destructor chain, and observing *when* each level's constructor and destructor actually run.
- **`ex02` — FragTrap**: A sibling of `ScavTrap`, reinforcing that inheritance is about sharing a common base, not just extending one specific class.
- **`ex03` — DiamondTrap**: Inherits from *both* `ScavTrap` and `FragTrap`, which both inherit from `ClapTrap` — the classic diamond. Solved with `virtual` inheritance so `ClapTrap`'s data isn't duplicated, and its constructor initialization order made explicit.

## Module_04 — Subtype polymorphism, abstract classes & interfaces

[#module_04--subtype-polymorphism-abstract-classes--interfaces](#module_04--subtype-polymorphism-abstract-classes--interfaces)

Where `virtual` stops being about the diamond problem and becomes the mechanism for runtime polymorphism — calling a derived class's override through a base class pointer or reference.

- **`ex00` — WrongAnimal / WrongCat**: A deliberately *non-virtual* base method, used to show what goes wrong (the base version runs instead of the derived one) when polymorphism is expected but not enabled.
- **`ex01` — Animal / Cat / Dog / Brain**: The fix — a `virtual` destructor and `virtual` methods so a `Animal *` pointing at a `Cat` correctly calls `Cat`'s override. `Brain` demonstrates deep copy: each `Dog`/`Cat` owns its own `Brain*`, so copying an animal must also copy — not share — its brain.
- **`ex02` — AAnimal**: `Animal` becomes an **abstract class** via a pure virtual function (`= 0`), so it can no longer be instantiated directly — only through its concrete subclasses.
- **`ex03` — AMateria / ICharacter / IMateriaSource**: A small RPG-style system combining an abstract base (`AMateria`) with pure-interface classes (`ICharacter`, `IMateriaSource`) that declare behavior with no implementation at all, plus a polymorphic `clone()` pattern so a `Character` can duplicate materia (`Cure`, `Ice`) it doesn't know the concrete type of.

## Module_05 — Repetition & exceptions

[#module_05--repetition--exceptions](#module_05--repetition--exceptions)

C++'s exception mechanism (`throw`/`catch`, `std::exception`) used for real error handling instead of error codes, layered under a small bureaucratic satire.

- **`ex00` — Bureaucrat**: A grade-bounded employee (1–150) that `throw`s custom nested exception classes (`GradeTooHighException`, `GradeTooLowException`, both derived from `std::exception` with an overridden `what()`) instead of silently clamping or failing.
- **`ex01` — Form**: A `Form` that a `Bureaucrat` can only sign or execute above certain grade thresholds, throwing the same style of custom exception when the grade requirement isn't met.
- **`ex02` — AForm / ShrubberyCreationForm / RobotomyRequestForm / PresidentialPardonForm**: `Form` becomes abstract (`AForm`), with three concrete forms each implementing their own `execute()` side effect — reinforcing subtype polymorphism from Module_04 alongside exceptions.
- **`ex03` — Intern**: A simple **factory pattern** — `Intern::makeForm(name, target)` returns the right concrete `AForm` subclass by string name, without the caller needing to know or `new` the concrete type directly.

## Module_06 — C++ casts

[#module_06--c-casts](#module_06--c-casts)

Replacing C-style `(type)value` casts with the four explicit C++ cast operators, each used where it's actually appropriate rather than interchangeably.

- **`ex00` — ScalarConverter**: Parses a `char`/`int`/`float`/`double` literal from a string and converts it to all four types using `static_cast`, handling edge cases (`nan`, `inf`, out-of-range values) explicitly instead of letting them silently misbehave.
- **`ex01` — Serializer**: `reinterpret_cast` used exactly as intended — reversibly converting a pointer to/from an integer type (`uintptr_t`) for serialization, with no change in the underlying bits or type interpretation.
- **`ex02` — A / B / C / Base**: `dynamic_cast` used to identify an object's real type at runtime through a base class pointer/reference — returning `NULL` (pointer form) or throwing `std::bad_cast` (reference form) when the cast doesn't match, which is the whole reason `dynamic_cast` requires a polymorphic (virtual-function-having) base.

## Module_07 — Templates

[#module_07--templates](#module_07--templates)

Where generic programming replaces the class-per-type / function-per-type duplication that would otherwise be needed to support multiple data types.

- **`ex00` — whatever**: Function templates (`swap`, `min`, `max`) that work across any comparable type without overloading by hand for every type used.
- **`ex01` — iter**: A template function that applies another function/functor to every element of an array, regardless of the array's element type or length.
- **`ex02` — Array**: A template *class* — a fixed-size, bounds-checked generic array, including the split between declaration (`.hpp`) and template implementation (`.tpp`) that C++98's lack of a unified compilation model for templates requires.

## Module_08 — Templated containers, iterators & algorithms

[#module_08--templated-containers-iterators--algorithms](#module_08--templated-containers-iterators--algorithms)

The bridge into the STL: using its containers, iterators, and algorithms directly, plus adapting one of them to do something it wasn't originally built for.

- **`ex00` — easyfind**: `std::find` applied generically to any STL container holding `int`s, via iterators rather than index-based access — the pattern the entire STL is built around.
- **`ex01` — Span**: A class wrapping a `std::vector<int>` with a fixed capacity, whose `shortestSpan()`/`longestSpan()` sort the stored numbers (`std::sort`) to find the closest and farthest pair — practice combining a container, an algorithm, and iterators in one exercise.
- **`ex02` — MutantStack**: `std::stack` is built on an underlying container and deliberately hides iteration — `MutantStack` inherits from it and *adds* `begin()`/`end()`, making a normally non-iterable adapter iterable without touching the STL source.

## Module_09 — STL in practice

[#module_09--stl-in-practice](#module_09--stl-in-practice)

Three self-contained programs, each chosen to put a specific STL container or algorithm under real load rather than a toy example.

- **`ex00` — BitcoinExchange**: `std::map<std::string, float>` for fast, sorted date-keyed lookups, parsing a CSV database and an input file with strict, exception-driven validation of dates and values.
- **`ex01` — RPN**: `std::stack<int>` used exactly as its name suggests — evaluating a Reverse Polish Notation expression by pushing operands and popping pairs for each operator.
- **`ex02` — PmergeMe**: An implementation of the **merge-insert sort** (Ford–Johnson algorithm) run over both a `std::vector<int>` and a `std::deque<int>`, timing both to compare container performance directly rather than just asserting one container is faster than another.

# Resources

[#resources](#resources)

I didn't keep a record of every resource I used while working through these modules, but one I leaned on constantly — and still reach for today — is [cplusplus.com](https://cplusplus.com/), particularly its [reference](https://cplusplus.com/reference/) section for the standard library, containers, and algorithms.