/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:18:10 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/16 20:19:21 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Bureaucrat.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/PresidentialPardonForm.hpp"

int	main(void)
{
    // ===== SHRUBBERY CREATION FORM TESTS =====
    {	
        std::cout << "\n===== SHRUBBERY - SUCCESSFUL EXECUTION =====\n" << std::endl;
        
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
        std::cout << "\n===== SHRUBBERY - GRADE TOO LOW TO EXECUTE =====\n" << std::endl;
        
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
        std::cout << "\n===== SHRUBBERY - NOT SIGNED =====\n" << std::endl;
        
        Bureaucrat	boss("Boss", 1);
        ShrubberyCreationForm shrub("park");
        std::cout << std::endl;
        
        std::cout << boss;
        std::cout << shrub;        
        boss.executeForm(shrub);
        std::cout << std::endl;
    }

    // ===== ROBOTOMY REQUEST FORM TESTS =====
    {
        std::cout << "\n===== ROBOTOMY - SUCCESSFUL EXECUTION =====\n" << std::endl;
        
        Bureaucrat	surgeon("Surgeon", 45);
        RobotomyRequestForm robot("Bender");
        std::cout << std::endl;
        
        std::cout << surgeon;
        std::cout << robot;        
        surgeon.signForm(robot);
        surgeon.executeForm(robot);
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== ROBOTOMY - GRADE TOO LOW TO EXECUTE =====\n" << std::endl;
        
        Bureaucrat	assistant("Assistant", 72);
        RobotomyRequestForm robot("C-3PO");
        std::cout << std::endl;
        
        std::cout << assistant;
        std::cout << robot;        
        assistant.signForm(robot);
        assistant.executeForm(robot);
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== ROBOTOMY - MULTIPLE ATTEMPTS (50% success) =====\n" << std::endl;
        
        Bureaucrat	doctor("Doctor", 1);
        RobotomyRequestForm robot("R2-D2");
        std::cout << std::endl;
        
        std::cout << robot;        
        doctor.signForm(robot);
        doctor.executeForm(robot);
        doctor.executeForm(robot);
        doctor.executeForm(robot);
        std::cout << std::endl;
    }

    // ===== PRESIDENTIAL PARDON FORM TESTS =====
    {
        std::cout << "\n===== PRESIDENTIAL - SUCCESSFUL EXECUTION =====\n" << std::endl;
        
        Bureaucrat	president("President", 5);
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << std::endl;
        
        std::cout << president;
        std::cout << pardon;        
        president.signForm(pardon);
        president.executeForm(pardon);
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== PRESIDENTIAL - GRADE TOO LOW TO SIGN =====\n" << std::endl;
        
        Bureaucrat	senator("Senator", 30);
        PresidentialPardonForm pardon("Ford Prefect");
        std::cout << std::endl;
        
        std::cout << senator;
        std::cout << pardon;        
        senator.signForm(pardon);
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== PRESIDENTIAL - GRADE TOO LOW TO EXECUTE =====\n" << std::endl;
        
        Bureaucrat	vicePresident("Vice-President", 10);
        Bureaucrat	supreme("Supreme", 1);
        PresidentialPardonForm pardon("Zaphod Beeblebrox");
        std::cout << std::endl;
        
        std::cout << pardon;        
        supreme.signForm(pardon);
        vicePresident.executeForm(pardon);
        std::cout << std::endl;
    }

    // ===== MIXED FORMS TEST =====
    {
        std::cout << "\n===== MIXED - ALL FORMS WITH ONE BUREAUCRAT =====\n" << std::endl;
        
        Bureaucrat	master("Master", 1);
        ShrubberyCreationForm shrub("office");
        RobotomyRequestForm robot("Wall-E");
        PresidentialPardonForm pardon("Marvin");
        std::cout << std::endl;
        
        std::cout << master;
        std::cout << shrub;
        std::cout << robot;
        std::cout << pardon;
        std::cout << std::endl;
        
        master.signForm(shrub);
        master.signForm(robot);
        master.signForm(pardon);
        std::cout << std::endl;
        
        master.executeForm(shrub);
        master.executeForm(robot);
        master.executeForm(pardon);
        std::cout << std::endl;
    }
    
    return (0);
}
