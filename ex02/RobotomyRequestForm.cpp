/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:18:42 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/18 13:08:54 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/RobotomyRequestForm.hpp"

// forma canonica ortodoxa
RobotomyRequestForm::RobotomyRequestForm(void)
	:	AForm("RobotomyRequestForm", 72, 45, "default_target")		// constructor parametrizado
{
	std::cout << ROBOTOMY_ID << CONSTRUCTOR_MSG << this->getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &instance)
	: AForm(instance)							// llama a constructor clase abstracta
{
	std::cout << ROBOTOMY_ID << COPY_CONSTRUCTOR_MSG << this->getName() << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator= (const RobotomyRequestForm &instance)
{
	if (this != &instance)
		AForm::operator= (instance);			// llama a constructor clase abstracta

	std::cout << ROBOTOMY_ID << ASSIGNMENT_MSG << this->getName() << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << ROBOTOMY_ID << DESTRUCTOR_MSG << this->getName() << std::endl;
}
// forma canonica ortodoxa

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	:	AForm("RobotomyRequestForm", 72, 45, target)	
{
	std::cout << ROBOTOMY_ID << NAME_CONSTRUCTOR_MSG << this->getName() << std::endl;	
}

/// OVERRIDE METODO VIRTUAL PURO
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->validateExecRequirements(executor))
	{
		// ACCION ESPECIFICA SEGUN TIPO FORM
		// Hace ruidos de perforación y luego informa que <objetivo> ha sido robotizado con éxito el 50 % de las veces. De lo contrario, informa que la robotización falló.
		//std::cout  << ROBOTOMY_ID << "ACCION RobotomyRequestForm" << std::endl;
		int	randomNumber;
		
		randomNumber = std::rand();
		std::cout << ROBOTOMY_DRILLING_NOISE << std::endl;		
		if (randomNumber % 2 == 0)
			std::cout << this->getTarget() << ROBOTOMY_ACTION_OK << std::endl;
		else
			std::cout << ROBOTOMY_ACTION_FAIL << this->getTarget() << std::endl;
	}	
}
