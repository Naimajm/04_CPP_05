/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:46:53 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/16 17:03:05 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

# define	AFORM_ID					"[AForm] \t"

# define	CONSTRUCTOR_MSG    			"Default Constructor: object created.\t"
# define	COPY_CONSTRUCTOR_MSG		"Copy Constructor: object created.\t"
# define	ASSIGNMENT_MSG				"Assignment operator: obj created.\t"
# define	DESTRUCTOR_MSG	    		"Destructor: object destroyed.\t"
# define	NAME_CONSTRUCTOR_MSG		"Parametric Constructor: object created.\t"

# define	AFORM_DEFAULT_NAME			"default form"
# define	AFORM_DEFAULT_SIGN_GRADE	150
# define	AFORM_DEFAULT_EXEC_GRADE	150
# define	AFORM_DEFAULT_TARGET		"default target"

# define 	AFORM_MIN_GRADE				150
# define 	AFORM_MAX_GRADE				1

# define 	AFORM_ERROR_HIGH_GRADE		"Error: Form Grade is too high."
# define 	AFORM_ERROR_LOW_GRADE		"Error: Form Grade is too low."
# define 	AFORM_ERROR_SIGNED			"Error: Form is already signed."
# define 	AFORM_ERROR_NOT_SIGNED		"Error: Form is not signed."

/// CLASE ABSTRACTA FORMULARIO
class AForm
{
	public:
		// forma canonica ortodoxa
		AForm(void);									
		AForm(const AForm &instance);					
		AForm	&operator= (const AForm &instance);	
		virtual ~AForm(void);	
		// forma canonica ortodoxa

		AForm(const std::string &name, int signGrade, int executeGrade, const std::string &target);

		std::string	getName(void) const;
		bool		getSignedStatus(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;

		std::string	getTarget(void) const;
		void		setTarget(std::string &target);

		void		beSigned(Bureaucrat &bureaucrat);

		// virtual PURO-> poliformismo de accion en cada tipo 'form'
		virtual void	execute(const Bureaucrat &executor) const = 0; 

		class	GradeTooHighException 	: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};	
		class	GradeTooLowException 	: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};		
		class	AlreadySignedException 	: public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
		class	NotSignedException 		: public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };

	protected:
		
		bool	validate_exec_requirements(const Bureaucrat &executor) const;	// funcion auxiliar validacion en funcion execute()			
	
	private:
		const std::string	_name;
		bool				_isSigned; 	 	
		const int			_signGrade;		
		const int			_executeGrade;	

		std::string			_target;
};

std::ostream	&operator<< (std::ostream &stream, const AForm &instance);

#endif
