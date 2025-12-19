/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:02:51 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/18 16:38:38 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:	AForm("ShrubberyCreationForm", 145, 137, "default_target")
{
	std::cout << SHRUBB_ID << CONSTRUCTOR_MSG << this->getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &instance)
	:	AForm(instance)
{
	std::cout << SHRUBB_ID << COPY_CONSTRUCTOR_MSG << this->getName() << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator= (const ShrubberyCreationForm &instance)
{
	if (this != &instance)
		AForm::operator= (instance);

	std::cout << SHRUBB_ID << ASSIGNMENT_MSG << this->getName() << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << SHRUBB_ID << DESTRUCTOR_MSG << this->getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	:	AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << SHRUBB_ID << NAME_CONSTRUCTOR_MSG << this->getName() << std::endl;	
}


void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->validateExecRequirements(executor))
	{
		std::string	filename;

		filename = this->getTarget() + "_shrubbery";
        std::ofstream file(filename.c_str());        
        if (file.is_open() == false)
            throw	FileCreationException();

        file << ASCII_TREE	<< std::endl;
		file << filename 	<< std::endl;
        
        file.close();
        std::cout << SHRUBB_ID << SHRUBB_FILE_CREATE << filename << std::endl;
	}	
}

const char* ShrubberyCreationForm::FileCreationException::what(void) const throw()
{
	return (SHRUBB_FILE_ERROR);
}
