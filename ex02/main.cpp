/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:18:10 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/04 14:14:56 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Bureaucrat.hpp"
#include "./include/ShrubberyCreationForm.hpp"

int	main(void)
{
    {	
        std::cout << "\n===== BASIC FORM TEST =====\n" << std::endl;      
        
    }
    {
        std::cout << "\n===== SUCCESSFUL SIGN TEST =====\n" << std::endl;
        
        Bureaucrat	director("Director", 137);
        ShrubberyCreationForm shrub("home");
        std::cout << std::endl;
        
        std::cout << director;
        std::cout << shrub;        
        director.signForm(shrub);
        director.executeForm(shrub);
        std::cout << std::endl;
    }
	{
        std::cout << "\n===== SHRUBBERY CREATION - GRADE TOO LOW TO EXECUTE =====\n" << std::endl;
        
        Bureaucrat	intern("Intern", 145);
        ShrubberyCreationForm shrub("garden");
        std::cout << std::endl;
        
        std::cout << intern;
        std::cout << shrub;        
        intern.signForm(shrub);
        intern.executeForm(shrub);
        std::cout << std::endl;
    }
	{
        std::cout << "\n===== SHRUBBERY CREATION - NOT SIGNED =====\n" << std::endl;
        
        Bureaucrat	boss("Boss", 1);
        ShrubberyCreationForm shrub("park");
        std::cout << std::endl;
        
        std::cout << boss;
        std::cout << shrub;        
        boss.executeForm(shrub);
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== FAILED SIGN TEST (Grade too low) =====\n" << std::endl;
        
        Bureaucrat	trainee("Trainee", 150);
        ShrubberyCreationForm shrub("office");
        std::cout << std::endl;
        
        std::cout << trainee;
        std::cout << shrub;        
        trainee.signForm(shrub);
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== ALREADY SIGNED TEST =====\n" << std::endl;
        
        Bureaucrat	boss("Boss", 1);
        Bureaucrat	assistant("Assistant", 50);
        ShrubberyCreationForm shrub("document");
        std::cout << std::endl;
        
        std::cout << shrub;        
        boss.signForm(shrub);
        std::cout << shrub;        
        assistant.signForm(shrub);  // Intento de firmar ya firmado
        std::cout << std::endl;
    }    
	{
        std::cout << "\n===== SHRUBBERY CREATION - DEFAULT CONSTRUCTOR =====\n" << std::endl;
        
        Bureaucrat	ceo("CEO", 1);
        ShrubberyCreationForm shrub;
        std::cout << std::endl;
        
        std::cout << ceo;
        std::cout << shrub;        
        ceo.signForm(shrub);
        ceo.executeForm(shrub);
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== MULTIPLE BUREAUCRATS TEST =====\n" << std::endl;
        
        Bureaucrat	alice("Alice", 100);
        Bureaucrat	bob("Bob", 137);
        ShrubberyCreationForm shrub("forest");
        std::cout << std::endl;
        
        std::cout << shrub;        
        alice.signForm(shrub);
        alice.executeForm(shrub);
        bob.executeForm(shrub);
        std::cout << std::endl;
    }    
    
    return (0);
}
