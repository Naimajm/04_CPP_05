/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:18:10 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/02 13:43:09 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Bureaucrat.hpp"

int	main(void)
{
	{	
		std::cout << "\n===== TEST =====\n" << std::endl;
		
		Bureaucrat	default_Bureau;							// constructor default
		Bureaucrat	name_Bureau	= Bureaucrat("pepe");		// parametric constructor 
		Bureaucrat	copy_Bureau	= Bureaucrat(name_Bureau);	// copy constructor 

		std::cout << name_Bureau<< std::endl;							

		std::cout << std::endl;
	}


	return (0);
}