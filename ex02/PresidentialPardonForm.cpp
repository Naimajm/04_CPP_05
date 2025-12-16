/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:42:04 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/16 17:46:01 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./include/PresidentialPardonForm.hpp"

// forma canonica ortodoxa
PresidentialPardonForm::PresidentialPardonForm(void)
	:	AForm("PresidentialPardonForm", 25, 5, "default_target")		// constructor parametrizado
{
	std::cout << PRESIDENTAL_ID << CONSTRUCTOR_MSG << this->getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &instance)
	: AForm(instance)							// llama a constructor clase abstracta
{
	std::cout << PRESIDENTAL_ID << COPY_CONSTRUCTOR_MSG << this->getName() << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator= (const PresidentialPardonForm &instance)
{
	if (this != &instance)
		AForm::operator= (instance);			// llama a constructor clase abstracta

	std::cout << PRESIDENTAL_ID << ASSIGNMENT_MSG << this->getName() << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << PRESIDENTAL_ID << DESTRUCTOR_MSG << this->getName() << std::endl;
}
// forma canonica ortodoxa

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	:	AForm("PresidentialPardonForm", 25, 5, target)	
{
	std::cout << PRESIDENTAL_ID << NAME_CONSTRUCTOR_MSG << this->getName() << std::endl;	
}

/// OVERRIDE METODO VIRTUAL PURO
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->validate_exec_requirements(executor))
	{
		// ACCION ESPECIFICA SEGUN TIPO FORM
		// Informa que <target> ha sido indultado por Zaphod Beeblebrox.
		std::cout  << PRESIDENTAL_ID << "ACCION RobotomyRequestForm" << std::endl;
	}	
}
