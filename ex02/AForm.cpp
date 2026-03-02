/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:20:14 by juagomez          #+#    #+#             */
/*   Updated: 2026/03/02 21:54:56 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/AForm.hpp"
#include "./include/Bureaucrat.hpp"

AForm::AForm(void)
	:	_name(AFORM_DEFAULT_NAME), 
		_isSigned(false), 
		_signGrade(AFORM_DEFAULT_SIGN_GRADE), 
		_executeGrade(AFORM_DEFAULT_EXEC_GRADE),
		_target(AFORM_DEFAULT_TARGET)
{
	std::cout << AFORM_ID << CONSTRUCTOR_MSG << this->_name << std::endl;
}

AForm::AForm(const AForm &instance)
	:	_name(instance._name), 
		_isSigned(instance._isSigned), 
		_signGrade(instance._signGrade), 
		_executeGrade(instance._executeGrade),
		_target(instance._target)
{
	std::cout << AFORM_ID << COPY_CONSTRUCTOR_MSG << this->_name << std::endl;
}

AForm	&AForm::operator= (const AForm &instance)
{
	if (this != &instance)
	{
		this->_isSigned = instance.getSignedStatus();
		this->_target	= instance.getTarget();
	}	
	std::cout << AFORM_ID << ASSIGNMENT_MSG << this->_name << std::endl;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << AFORM_ID << DESTRUCTOR_MSG << this->_name << std::endl;
}

AForm::AForm(const std::string &name, const int signGrade, 
				const int executeGrade, const std::string &target)
:	_name(name), 
	_isSigned(false), 
	_signGrade(_validateGrade(signGrade)), 
	_executeGrade(_validateGrade(executeGrade)),
	_target(_validateTarget(target))
{
	std::cout << AFORM_ID << NAME_CONSTRUCTOR_MSG << this->_name << std::endl;	
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool		AForm::getSignedStatus(void) const
{
	return (this->_isSigned);
}

int			AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int			AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

std::string	AForm::getTarget(void) const
{
	return (this->_target);
}

void		AForm::setTarget(const std::string &target)
{
	this->_target = _validateTarget(target);
}


void		AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_isSigned == true)
		throw (AlreadySignedException());

	if (bureaucrat.getGrade() > this->_signGrade)		
		throw (GradeTooLowException());

	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return (AFORM_ERROR_HIGH_GRADE);
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return (AFORM_ERROR_LOW_GRADE);
}

const char* AForm::AlreadySignedException::what(void) const throw()
{
	return (AFORM_ERROR_SIGNED);
}

const char* AForm::NotSignedException::what(void) const throw()
{
	return (AFORM_ERROR_NOT_SIGNED);
}

const char* AForm::InvalidTargetException::what(void) const throw()
{
	return (AFORM_ERROR_TARGET);
}

bool	AForm::validateExecRequirements(const Bureaucrat &executor) const
{
	if (this->_isSigned == false)
		throw (AForm::NotSignedException());

	if (this->_executeGrade < executor.getGrade())
		throw (AForm::GradeTooLowException());
	return (true);
}

int		AForm::_validateGrade(int grade)
{	
	if (grade < AFORM_MAX_GRADE)
		throw (GradeTooHighException());

	if (grade > AFORM_MIN_GRADE)
		throw (GradeTooLowException());
	return (grade);
}

std::string	AForm::_validateTarget(const std::string &target)
{
	if (target.empty() 
		|| target.find("..") != std::string::npos
		|| target.find("/")  != std::string::npos
		|| target.find("\\") != std::string::npos
		)
		throw (InvalidTargetException());

	return (target);
}

std::ostream	&operator<< (std::ostream &stream, const AForm &instance)
{
	stream	<< AFORM_ID << "Name: "	<< instance.getName();

	stream	<< ", Signed Status: ";
	if(instance.getSignedStatus())
		stream << "True";
	else
		stream << "False";

	stream	<< ", Sign Grade: "		<< instance.getSignGrade()
			<< ", Exec Grade: "		<< instance.getExecuteGrade() 
			<< ", Target: "			<< instance.getTarget() 
			<< std::endl;
	return (stream);
}