/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:43:57 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/03 17:10:00 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Form.hpp"
#include "./include/Bureaucrat.hpp"

// Forma Canonica
Form::Form(void)
	:	_name(FORM_DEFAULT_NAME), 
		_isSigned(false), 
		_signGrade(FORM_DEFAULT_SIGN_GRADE), 
		_executeGrade(FORM_DEFAULT_EXEC_GRADE)
{
	std::cout << FORM_ID << CONSTRUCTOR_MSG << this->_name << std::endl;
}

Form::Form(const Form &instance)
	:	_name(instance._name), 
		_isSigned(instance._isSigned), 
		_signGrade(instance._signGrade), 
		_executeGrade(instance._executeGrade)
{
	std::cout << FORM_ID << COPY_CONSTRUCTOR_MSG << this->_name << std::endl;
}

Form	&Form::operator= (const Form &instance)
{
	// datos constantes no se copian una vez construida la instancia
	// validar autoasignacion
	if (this != &instance)
		this->_isSigned = instance._isSigned;

	std::cout << FORM_ID << ASSIGNMENT_MSG << this->_name << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cout << FORM_ID << DESTRUCTOR_MSG << this->_name << std::endl;
}
// Forma Canonica

// Constructor parametrico
Form::Form(const std::string &name, const int signGrade, const int executeGrade)
:	_name(name), 
	_isSigned(false), 
	_signGrade(signGrade), 
	_executeGrade(executeGrade)
{
	// VALIDACION SIGNGRADE + EXECGRADE
	if (signGrade < FORM_MAX_GRADE || executeGrade < FORM_MAX_GRADE)
		throw (GradeTooHighException());
	if (signGrade > FORM_MIN_GRADE || executeGrade > FORM_MIN_GRADE)
		throw (GradeTooLowException());

	std::cout << FORM_ID << NAME_CONSTRUCTOR_MSG << this->_name << std::endl;	
}

// getters + setters ----------------------------

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool		Form::getSignedStatus(void) const
{
	return (this->_isSigned);
}

int			Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int			Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

// metodos propios-----------------------------------

// Se encarga de la lógica de negocio pura 
// 1 -> validar si burócrata tiene grado suficiente
// 2 -> cambiar estado del formulario. Si no puede, lanza una excepción.
void		Form::beSigned(Bureaucrat &bureaucrat)
{
	// validacion si form ya fue firmado
	if (this->_isSigned == true)
		throw (FormAlreadySignedException());

	// LOGICA NEGOCIO
	if (bureaucrat.getGrade() > this->_signGrade)		
		throw (GradeTooLowException());		// LANZA excepcion -> la gestiona funcion signForm() Bureaucrat

	this->_isSigned = true;		// firmar form	
}

// excepciones ------------------------------------
const char* Form::GradeTooHighException::what(void) const throw()
{
	return (FORM_ERROR_HIGH_GRADE);
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return (FORM_ERROR_LOW_GRADE);
}

const char* Form::FormAlreadySignedException::what(void) const throw()
{
	return (FORM_ERROR_SIGNED);
}

// SOBRECARGA INSERCION -> IMPRESION DATOS INSTANCIA FORM
std::ostream	&operator<< (std::ostream &stream, const Form &instance)
{
	stream	<< FORM_ID << "Name: "	<< instance.getName();

	stream	<< ", Signed Status: ";
	if(instance.getSignedStatus())
		stream << "True";
	else
		stream << "False";

	stream	<< ", Sign Grade: "		<< instance.getSignGrade()
			<< ", Exec Grade: "		<< instance.getExecuteGrade() 
			<< std::endl;
	return (stream);
}