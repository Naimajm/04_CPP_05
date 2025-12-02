/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:18:10 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/02 22:25:32 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Bureaucrat.hpp"

int	main(void)
{
	{	
		std::cout << "\n===== BASIC TEST =====\n" << std::endl;
		
		Bureaucrat	default_Bureau;							// constructor default
		Bureaucrat	name_Bureau	= Bureaucrat("pepe", 24);	// parametric constructor 
		Bureaucrat	copy_Bureau	= Bureaucrat(name_Bureau);	// copy constructor 
		std::cout << std::endl;

		std::cout << name_Bureau;	
		name_Bureau.decrementGrade();
		std::cout << "Grade: " << name_Bureau.getGrade() << std::endl;	
		name_Bureau.incrementGrade();
		std::cout << "Grade: " << name_Bureau.getGrade() << std::endl;	
		std::cout << std::endl;
	}
	{
		std::cout << "\n===== NEGATIVE GRADE TEST =====\n" << std::endl;
		try
		{
			Bureaucrat bob("Bob", -2);
		}
		catch (std::exception &exceptionValue)  // capturamos el objeto excepción y mostramos su mensaje
		{			
			std::cerr << "Exception: " << exceptionValue.what() << std::endl;
		}
	}
	{
		std::cout << "\n===== EXCEPTION HIGH GRADE TEST =====\n" << std::endl;
		try
		{
			Bureaucrat bob("Bob", 2);	
			std::cout << bob;		
			bob.incrementGrade();
			std::cout << bob;
			//bob.incrementGrade(); 			// Intenta pasar a 0 -> LANZA EXCEPCIÓN
			bob.setGrade(0);
		}
		catch (std::exception &exceptionValue) 	// capturamos el objeto excepción y mostramos su mensaje
		{
			std::cerr << "Exception: " << exceptionValue.what() << std::endl;
		}
	}	
	{
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
	}

	return (0);
}