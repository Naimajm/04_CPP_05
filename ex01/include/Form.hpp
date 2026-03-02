/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:12:01 by juagomez          #+#    #+#             */
/*   Updated: 2026/03/02 15:24:06 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

# define	FORM_ID					"[Form] \t\t"

# define	CONSTRUCTOR_MSG    		"Default Constructor: object created.\t"
# define	COPY_CONSTRUCTOR_MSG	"Copy Constructor: object created.\t"
# define	ASSIGNMENT_MSG			"Assignment operator: obj created.\t"
# define	DESTRUCTOR_MSG	    	"Destructor: object destroyed.\t"
# define	NAME_CONSTRUCTOR_MSG	"Parametric Constructor: object created.\t"

# define	FORM_DEFAULT_NAME		"default form"
# define	FORM_DEFAULT_SIGN_GRADE	150
# define	FORM_DEFAULT_EXEC_GRADE	150

# define 	FORM_MIN_GRADE			150
# define 	FORM_MAX_GRADE			1

# define 	FORM_ERROR_HIGH_GRADE	"Error: Form Grade is too high."
# define 	FORM_ERROR_LOW_GRADE	"Error: Form Grade is too low."
# define 	FORM_ERROR_SIGNED		"Error: Form is already signed."

class	Form
{
	public:
		Form(void);									
		Form(const Form &instance);					
		Form	&operator= (const Form &instance);	
		~Form(void);	

		Form(const std::string &name, int signGrade, int executeGrade);

		std::string	getName(void) const;
		bool		getSignedStatus(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;

		void		beSigned(Bureaucrat &bureaucrat);			

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};	
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};		
		class	FormAlreadySignedException : public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
	
	private:
		const std::string	_name;
		bool				_isSigned; 	 	
		const int			_signGrade;		
		const int			_executeGrade;	

		static int			_validateGrade(int grade);
};

std::ostream	&operator<< (std::ostream &stream, const Form &instance);

#endif