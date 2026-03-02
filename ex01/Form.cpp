/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:43:57 by juagomez          #+#    #+#             */
/*   Updated: 2026/03/02 15:32:34 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Form.hpp"
#include "./include/Bureaucrat.hpp"

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
	if (this != &instance)
		this->_isSigned = instance._isSigned;

	std::cout << FORM_ID << ASSIGNMENT_MSG << this->_name << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cout << FORM_ID << DESTRUCTOR_MSG << this->_name << std::endl;
}

Form::Form(const std::string &name, const int signGrade, const int executeGrade)
:	_name(name), 
	_isSigned(false), 
	_signGrade(_validateGrade(signGrade)), 
	_executeGrade(_validateGrade(executeGrade))
{
	std::cout << FORM_ID << NAME_CONSTRUCTOR_MSG << this->_name << std::endl;	
}

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

void		Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_isSigned == true)
		throw (FormAlreadySignedException());

	if (bureaucrat.getGrade() > this->_signGrade)		
		throw (GradeTooLowException());

	this->_isSigned = true;
}

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

int Form::_validateGrade(int grade)
{	
	if (grade < FORM_MAX_GRADE)
		throw (GradeTooHighException());

	if (grade > FORM_MIN_GRADE)
		throw (GradeTooLowException());
	return (grade);
}

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
