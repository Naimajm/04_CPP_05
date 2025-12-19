/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:18:10 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/19 22:34:06 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Bureaucrat.hpp"

int main(void)
{
    {
        std::cout << "\n===== BASIC BUREAUCRAT TEST =====\n" << std::endl;
        
        Bureaucrat	defaultBureaucrat;
        Bureaucrat	john("John", 75);
        Bureaucrat	johnCopy(john);
        std::cout << std::endl;
        
        std::cout << defaultBureaucrat;
        std::cout << john;
        std::cout << johnCopy;
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== INCREMENT/DECREMENT GRADE TEST =====\n" << std::endl;
        
        Bureaucrat	alice("Alice", 50);
        std::cout << std::endl;
        
        std::cout << alice;
        alice.incrementGrade();
        std::cout << "After increment: " << alice;
		alice.decrementGrade();
        std::cout << "After decrement: " << alice;
        std::cout << std::endl;
    }    
    {
        std::cout << "\n===== GRADE TOO HIGH EXCEPTION (Constructor) =====\n" << std::endl;
        
        try
        {
            Bureaucrat invalid("Invalid", 0);
        }
        catch (std::exception &exceptValue)
        {
            std::cerr << "Exception: \t" << exceptValue.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== GRADE TOO LOW EXCEPTION (Constructor) =====\n" << std::endl;
        
        try
        {
            Bureaucrat invalid("Invalid", 151);
        }
        catch (std::exception &exceptValue)
        {
            std::cerr << "Exception: \t" << exceptValue.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== GRADE TOO HIGH EXCEPTION (Increment) =====\n" << std::endl;
        
        try
        {
            Bureaucrat topBoss("TopBoss", 1);
            std::cout << std::endl;
            
            std::cout << topBoss;
            topBoss.incrementGrade(); 
        }
        catch (std::exception &exceptValue)
        {
            std::cerr << "Exception: \t" << exceptValue.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== GRADE TOO LOW EXCEPTION (Decrement) =====\n" << std::endl;
        
        try
        {
            Bureaucrat intern("Intern", 150);
            std::cout << std::endl;
            
            std::cout << intern;
            intern.decrementGrade(); 
        }
        catch (std::exception &exceptValue)
        {
            std::cerr << "Exception: \t" << exceptValue.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====\n" << std::endl;
        
        Bureaucrat manager1("Manager A", 40);
        Bureaucrat manager2("Manager B", 80);
        std::cout << std::endl;
        
        std::cout << "Before assignment:" << std::endl;
        std::cout << manager1;
        std::cout << manager2;
        
        manager1 = manager2;
        
        std::cout << std::endl << "After assignment:" << std::endl;
        std::cout << manager1;
        std::cout << manager2;
        std::cout << std::endl;
    }
    {
        std::cout << "\n===== MULTIPLE OPERATIONS TEST =====\n" << std::endl;
        
        try
        {
            Bureaucrat charlie("Charlie", 3);
            std::cout << std::endl;
            
            std::cout << "Initial: " 		<< charlie;            
            charlie.incrementGrade(); 
            std::cout << "After increment: " << charlie;            
            charlie.incrementGrade(); 
            std::cout << "After increment: " << charlie;            
            charlie.incrementGrade(); 
            std::cout << "This line won't be printed" << std::endl;
        }
        catch (std::exception &exceptValue)
        {
            std::cerr << "Exception: \t" << exceptValue.what() << std::endl;
        }
        std::cout << std::endl;
    }    
    
    return (0);
}