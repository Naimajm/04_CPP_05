/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:02:15 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/19 22:29:01 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Intern.hpp"

#include "./include/AForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << INTERN_ID << CONSTRUCTOR_MSG << std::endl;
}

Intern::Intern(const Intern &instance)
{
	if (this != &instance)
		*this = instance;
	std::cout << INTERN_ID << COPY_CONSTRUCTOR_MSG << std::endl;
}

Intern	&Intern::operator= (const Intern &instance)
{
	(void) instance;

	std::cout << INTERN_ID << ASSIGNMENT_MSG << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << INTERN_ID << DESTRUCTOR_MSG  << std::endl;
}

/// MAKEFORM ------------------------

// tipo de dato para punteros a función
typedef AForm*  (*FormConstructor)(const std::string& target);

// FUNCIONES ESTATICAS CREACION FORMULARIOS
static	AForm*	createShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static	AForm*	createRobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static	AForm*	createPresidentialForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string &formName, const std::string &target)
{
	// ARRAY NOMBRE FORMULARIOS 
	const std::string	arrayNames[3] = {
		"shrubbery creation",
        "robotomy request",
        "presidential pardon"
	};

	// ARRAY PUNTEROS FUNCIONES CREADORAS
	const FormConstructor arrayConstructors[3] = {
		createShrubberyForm,		// [0] → crea ShrubberyCreationForm
		createRobotomyForm,			// [1] → crea RobotomyRequestForm
		createPresidentialForm		// [2] → crea PresidentialPardonForm
	};

	// busqueda por nombre en par array nombres-constructores formularios
	for (int index = 0; index < 3; index++)
	{
		if (formName == arrayNames[index])
		{
			std::cout << INTERN_ID << MAKEFORM_OK << formName << std::endl;
			return (arrayConstructors[index](target));
		}
	}
	// nombre formulario no encontrado
	std::cerr << INTERN_ID << MAKEFORM_ERROR << formName << std::endl;
	throw (FormNotExist());
}

const char* Intern::FormNotExist::what(void) const throw()
{
	return (MAKEFORM_EXCEPTION);
}
