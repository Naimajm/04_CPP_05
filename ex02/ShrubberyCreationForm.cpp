/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:02:51 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/04 14:12:01 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ShrubberyCreationForm.hpp"
#include "./include/Bureaucrat.hpp"

// forma canonica ortodoxa
ShrubberyCreationForm::ShrubberyCreationForm(void)
	:	AForm("ShrubberyCreationForm", 145, 137, "default_target")		// constructor parametrizado
{
	std::cout << SHRUBB_ID << CONSTRUCTOR_MSG << this->getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &instance)
	: AForm(instance)													// llama a constructor clase abstracta
{
	std::cout << SHRUBB_ID << COPY_CONSTRUCTOR_MSG << this->getName() << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator= (const ShrubberyCreationForm &instance)
{
	if (this != &instance)
		AForm::operator= (instance);				// llama a constructor clase abstracta

	std::cout << SHRUBB_ID << ASSIGNMENT_MSG << this->getName() << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << SHRUBB_ID << DESTRUCTOR_MSG << this->getName() << std::endl;
}
// forma canonica ortodoxa

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	:	AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << SHRUBB_ID << NAME_CONSTRUCTOR_MSG << this->getName() << std::endl;	
}

/// OVERRIDE METODO VIRTUAL PURO
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->validate_exec_requirements(executor))
	{
		// ACCION ESPECIFICA SEGUN TIPO FORM
		std::cout  << SHRUBB_ID << "ACCION ShrubberyCreationForm" << std::endl;
	}	
}
