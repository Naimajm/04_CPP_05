/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:18:10 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/03 15:52:58 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Bureaucrat.hpp"
#include "./include/Form.hpp"

int	main(void)
{
	{	
		std::cout << "\n===== BASIC TEST =====\n" << std::endl;
		
		Bureaucrat	default_Bureau;							
		Bureaucrat	alma	= Bureaucrat("alma", 2);	
		Bureaucrat	almaCopy		= Bureaucrat(alma);	
		std::cout << std::endl;

		std::cout << alma;	
		alma.decrementGrade();
		std::cout << BUREAU_ID << "Grade: " << alma.getGrade() << std::endl;	
		alma.incrementGrade();
		std::cout << BUREAU_ID << "Grade: " << alma.getGrade() << std::endl;	
		std::cout << std::endl;

		Form	default_form;
		Form	nameForm = Form("form 1", 5, 10);
		std::cout << nameForm;		
		Form	copyForm = Form(nameForm);
		std::cout << copyForm;
		std::cout << std::endl;

		try
		{
			nameForm.beSigned(alma);	
			nameForm.beSigned(alma);			
		}
		catch (std::exception &exceptvalue)
		{
			std::cerr << "Exception: " << exceptvalue.what() << std::endl;
		}
		std::cout << std::endl;
	}
	/* {
		std::cout << "\n===== NEGATIVE GRADE TEST =====\n" << std::endl;
		try
		{
			Bureaucrat bob("Bob", -2);
		}
		catch (std::exception &exceptionValue)  
		{			
			std::cerr << "Exception: " << exceptionValue.what() << std::endl;
		}
	} */
	/* {
		std::cout << "\n===== EXCEPTION HIGH GRADE TEST =====\n" << std::endl;
		try
		{
			Bureaucrat bob("Bob", 2);	
			std::cout << bob;		
			bob.incrementGrade();
			std::cout << bob;
			bob.setGrade(0);
		}
		catch (std::exception &exceptionValue)
		{
			std::cerr << "Exception: " << exceptionValue.what() << std::endl;
		}
	}	 */
	/* {
		std::cout << "\n===== EXCEPTION LOW GRADE TEST =====\n" << std::endl;
		try
		{
			Bureaucrat	jack("Jack", 150);
			std::cout << jack;
			jack.decrementGrade();
		}
		catch (std::exception &exceptionValue)
		{			
			std::cerr << "Exception: " << exceptionValue.what() << std::endl; 
		}
	} */
	return (0);
}