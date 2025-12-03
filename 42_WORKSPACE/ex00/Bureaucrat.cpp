/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:24:27 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/03 12:08:35 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "./include/Bureaucrat.hpp"

// forma canonica
Bureaucrat::Bureaucrat(void)
	: _name(BUREAU_DEFAULT_NAME), _grade(BUREAU_DEFAULT_GRADE)
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
	// validar autoreferencia
	if (this != &reference)
	{
		//this->_name	= reference._name;	// _name no se copia porque es const

		// No necesitamos validar nada porque 'reference' ya es un Bureaucrat válido ¡¡¡¡		
		/* if (reference.getGrade() < MAX_GRADE)						// validar limite maximo
			throw (Bureaucrat::GradeTooHighException());		
		if (reference.getGrade() > MIN_GRADE)						// validar limite minimo
			throw (Bureaucrat::GradeTooLowException()); */
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
Bureaucrat::Bureaucrat(const std::string &name, int grade)
	:	_name(name)
{	
	if (grade < BUREAU_MAX_GRADE)							// validar limite maximo
		throw (GradeTooHighException());	
	if (grade > BUREAU_MIN_GRADE)							// validar limite minimo
		throw (GradeTooLowException());		

	this->_grade = grade;

	std::cout << BUREAU_ID << NAME_CONSTRUCTOR_MSG << this->_name << std::endl;	
}

// metodos miembros ---------------------

std::string		Bureaucrat::getName(void) const
{
	return (this->_name);
}

int				Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void			Bureaucrat::setGrade(int grade)
{
	if (grade < BUREAU_MAX_GRADE)							// validar limite maximo
		throw (GradeTooHighException());	
	if (grade > BUREAU_MIN_GRADE)							// validar limite minimo
		throw (GradeTooLowException());		
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade(void)
{	
	if (this->_grade - 1 < BUREAU_MAX_GRADE)			// validar limite maximo
		throw (GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{	
	if (this->_grade + 1 > BUREAU_MIN_GRADE)			// validar limite minimo
		throw (GradeTooLowException());
	this->_grade++;	
}

// CLASS  Excepciones ---------------------------------
// SOBREESCRITURA IMPLEMENTACION METODO HEREDADO WHAT()
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (BUREAU_ERROR_HIGH_GRADE);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (BUREAU_ERROR_LOW_GRADE);
}

// ostream -> clase base flujos salida(cout, cerr, ofstream, ..)- devuelve referencia del mismo objeto para permitir encadenamientos y porque no es copiable
std::ostream	&operator<< (std::ostream &stream, const Bureaucrat &reference)
{
	stream << reference.getName() << BUREAU_DISPLAY_MSG << reference.getGrade() << std::endl;
	return (stream);
}