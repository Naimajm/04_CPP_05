/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:42:04 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/18 16:36:27 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	:	AForm("PresidentialPardonForm", 25, 5, "default_target")
{
	std::cout << PRESIDENTAL_ID << CONSTRUCTOR_MSG << this->getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &instance)
	: AForm(instance)
{
	std::cout << PRESIDENTAL_ID << COPY_CONSTRUCTOR_MSG << this->getName() << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator= (const PresidentialPardonForm &instance)
{
	if (this != &instance)
		AForm::operator= (instance);

	std::cout << PRESIDENTAL_ID << ASSIGNMENT_MSG << this->getName() << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << PRESIDENTAL_ID << DESTRUCTOR_MSG << this->getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	:	AForm("PresidentialPardonForm", 25, 5, target)	
{
	std::cout << PRESIDENTAL_ID << NAME_CONSTRUCTOR_MSG << this->getName() << std::endl;	
}


void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->validateExecRequirements(executor))
		std::cout << this->getTarget() << PRESIDENTAL_ACTION << std::endl;
}
