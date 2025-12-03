/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:24:17 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/03 12:09:36 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

# include <string>
# include <iostream>

#include "./Form.hpp"

# define	BUREAU_ID				"[Bureaucrat] \t"

# define	CONSTRUCTOR_MSG    		"Default Constructor: object created.\t"
# define	COPY_CONSTRUCTOR_MSG	"Copy Constructor: object created.\t"
# define	ASSIGNMENT_MSG			"Assignment operator: obj created.\t"
# define	DESTRUCTOR_MSG	    	"Destructor: object destroyed.\t"
# define	NAME_CONSTRUCTOR_MSG	"Parametric Constructor: object created.\t"

# define	BUREAU_DEFAULT_NAME		"default bureaucrat"
# define	BUREAU_DEFAULT_GRADE	150

# define	BUREAU_DISPLAY_MSG		", bureaucrat grade "
# define 	BUREAU_MIN_GRADE		150
# define 	BUREAU_MAX_GRADE		1
# define 	BUREAU_ERROR_HIGH_GRADE	"Error: Grade is too high (maximum is 1)."
# define 	BUREAU_ERROR_LOW_GRADE	"Error: Grade is too low (minimum is 150)."

class Bureaucrat
{
	public:
		Bureaucrat(void);											
		Bureaucrat(const Bureaucrat &reference);					
		Bureaucrat	&operator= (const Bureaucrat &reference);		
		~Bureaucrat(void);
		
		Bureaucrat(const std::string &name, int grade); 

		std::string		getName(void) const;
		int 			getGrade(void) const;
		void			setGrade(int grade);

		void	incrementGrade(void);
		void	decrementGrade(void);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

		// metodo propio firma formulario si tiene 'grade' suficiente. llama a beSigned() de Form
		void	signForm(Form &form);		

	private:
		const	std::string	_name; 
		int					_grade;	
		
		void	displaySignForm(bool status);	// aux para imprimir estado firma Form	
};

std::ostream	&operator<< (std::ostream &stream, const Bureaucrat &reference);

#endif