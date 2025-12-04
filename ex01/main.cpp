/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:18:10 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/04 10:11:30 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Bureaucrat.hpp"
#include "./include/Form.hpp"

int	main(void)
{
    {	
        std::cout << "\n===== BASIC FORM TEST =====\n" << std::endl;
        
        Form	defaultForm;
        Form	taxForm("Tax Declaration", 50, 25);
        Form	copyForm(taxForm);
		std::cout << std::endl;
        
        std::cout << defaultForm;
        std::cout << taxForm;
        std::cout << copyForm;
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== SUCCESSFUL SIGN TEST =====\n" << std::endl;
        
        Bureaucrat	director("Director", 30);
        Form		contract("Contract", 40, 20);
		std::cout << std::endl;
        
        std::cout << director;
        std::cout << contract;        
        director.signForm(contract);
        std::cout << contract;
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== FAILED SIGN TEST (Grade too low) =====\n" << std::endl;
        
        Bureaucrat	intern("Intern", 100);
        Form		topSecret("Top Secret", 10, 5);
		std::cout << std::endl;
        
        std::cout << intern;
        std::cout << topSecret;        
        intern.signForm(topSecret);
        std::cout << topSecret;
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== ALREADY SIGNED TEST =====\n" << std::endl;
        
        Bureaucrat	boss("Boss", 1);
        Bureaucrat	assistant("Assistant", 50);
        Form		report("Report", 100, 80);
		std::cout << std::endl;
        
        std::cout << report;        
        boss.signForm(report);
        std::cout << report;        
        assistant.signForm(report);  // Intento de firmar formulario ya firmado
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== FORM GRADE TOO HIGH TEST =====\n" << std::endl;
        try
        {
            Form invalidForm("Invalid", 0, 50);
        }
        catch (std::exception &exceptValue)
        {
            std::cerr << "Exception: " << exceptValue.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== FORM GRADE TOO LOW TEST =====\n" << std::endl;
        try
        {
            Form invalidForm("Invalid", 50, 151);
        }
        catch (std::exception &exceptValue)
        {
            std::cerr << "Exception: " << exceptValue.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== MULTIPLE BUREAUCRATS TEST =====\n" << std::endl;
        
        Bureaucrat	alice("Alice", 20);
        Bureaucrat	bob("Bob", 60);
        Bureaucrat	charlie("Charlie", 5);
        Form		permit("Building Permit", 30, 15);
		std::cout << std::endl;
        
        std::cout << permit;        
        bob.signForm(permit);     // Falla: grado insuficiente
        alice.signForm(permit);   // Éxito: grado suficiente
        charlie.signForm(permit); // Falla: ya firmado        
        std::cout << permit;
        std::cout << std::endl;
    }    
    
    return (0);
}