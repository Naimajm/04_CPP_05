/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:24:27 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/02 13:37:28 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "./include/Bureaucrat.hpp"

// forma canonica
Bureaucrat::Bureaucrat(void)
	: _name("default Bureaucrat"), _grade(150)
{
	std::cout << BUREAU_ID << CONSTRUCTOR_MSG << this->_name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &reference)
	:	_name(reference._name), _grade(reference._grade)
{
	std::cout << BUREAU_ID << COPY_CONSTRUCTOR_MSG << this->_name << std::endl;
}

Bureaucrat	&Bureaucrat::operator= (const Bureaucrat &reference)
{
	// valñidar autoreferencia
	if (this != &reference)
	{
		this->_name		= reference._name;
		this->_grade 	= reference._grade;
	}
	std::cout << BUREAU_ID << ASSIGNMENT_MSG << this->_name << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << BUREAU_ID << DESTRUCTOR_MSG << this->_name << std::endl;
}
// forma canonica

// constructor parametrico 
Bureaucrat::Bureaucrat(const std::string name)
	:	_name(name), _grade(150)
{
	std::cout << BUREAU_ID << NAME_CONSTRUCTOR_MSG << this->_name << std::endl;	
}

// metodos miembros
std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
}

// Excepciones
void	Bureaucrat::GradeTooHighException(void)
{
	
}

void	Bureaucrat::GradeTooLowException(void)
{

}

// ostream -> clase base flujos salida(cout, cerr, ofstream, ..)- devuelve referencia del mismo objeto para permitir encadenamientos y porque no es copiable
std::ostream	&operator<< (std::ostream &stream, const Bureaucrat &reference)
{
	stream << reference.getName() << BUREAU_DISPLAY_MSG << reference.getGrade() << std::endl;
	return (stream);
}