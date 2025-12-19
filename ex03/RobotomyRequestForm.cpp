/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:18:42 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/18 16:36:19 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	:	AForm("RobotomyRequestForm", 72, 45, "default_target")
{
	std::cout << ROBOTOMY_ID << CONSTRUCTOR_MSG << this->getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &instance)
	: 	AForm(instance)
{
	std::cout << ROBOTOMY_ID << COPY_CONSTRUCTOR_MSG << this->getName() << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator= (const RobotomyRequestForm &instance)
{
	if (this != &instance)
		AForm::operator= (instance);

	std::cout << ROBOTOMY_ID << ASSIGNMENT_MSG << this->getName() << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << ROBOTOMY_ID << DESTRUCTOR_MSG << this->getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	:	AForm("RobotomyRequestForm", 72, 45, target)	
{
	std::cout << ROBOTOMY_ID << NAME_CONSTRUCTOR_MSG << this->getName() << std::endl;	
}


void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->validateExecRequirements(executor))
	{
		int	randomNumber;
		
		randomNumber = std::rand();
		std::cout << ROBOTOMY_DRILLING_NOISE << std::endl;		
		if (randomNumber % 2 == 0)
			std::cout << this->getTarget() << ROBOTOMY_ACTION_OK << std::endl;
		else
			std::cout << ROBOTOMY_ACTION_FAIL << this->getTarget() << std::endl;
	}	
}
