/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:24:27 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/04 13:55:14 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "./include/Bureaucrat.hpp"

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
	if (this != &reference)
		this->_grade 	= reference._grade;

	std::cout << BUREAU_ID << ASSIGNMENT_MSG << this->_name << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << BUREAU_ID << DESTRUCTOR_MSG << this->_name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	:	_name(name)
{	
	if (grade < BUREAU_MAX_GRADE)							
		throw (GradeTooHighException());	
	if (grade > BUREAU_MIN_GRADE)							
		throw (GradeTooLowException());		

	this->_grade = grade;

	std::cout << BUREAU_ID << NAME_CONSTRUCTOR_MSG << this->_name << std::endl;	
}


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
	if (grade < BUREAU_MAX_GRADE)							
		throw (GradeTooHighException());	
	if (grade > BUREAU_MIN_GRADE)							
		throw (GradeTooLowException());		
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade(void)
{	
	if (this->_grade - 1 < BUREAU_MAX_GRADE)			
		throw (GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{	
	if (this->_grade + 1 > BUREAU_MIN_GRADE)			
		throw (GradeTooLowException());
	this->_grade++;	
}


const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (BUREAU_ERROR_HIGH_GRADE);
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (BUREAU_ERROR_LOW_GRADE);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout	<< this->_name << " signed " << form.getName()
					<< std::endl;
	}
	catch (std::exception &exceptValue)
	{
		std::cout 	<< this->_name << " couldn’t sign " << form.getName()
					<< " because " << exceptValue.what()
					<< std::endl;			
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		// msg subject -> <bureaucrat> executed <form>
		std::cout	<< this->_name << " executed " << form.getName()
					<< std::endl;
	}
	catch (std::exception &exceptValue)
	{
		std::cout 	<< this->_name << " couldn’t execute " << form.getName()
					<< " because " << exceptValue.what()
					<< std::endl;			
	}
}

std::ostream	&operator<< (std::ostream &stream, const Bureaucrat &reference)
{
	stream << reference.getName() << BUREAU_DISPLAY_MSG << reference.getGrade() << std::endl;
	return (stream);
}