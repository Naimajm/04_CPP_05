/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:12:01 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/03 15:56:32 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

//#include "./Bureaucrat.hpp"
class Bureaucrat; 			// Forward declaration: "Prometo que esta clase existirá"

# define	FORM_ID					"[Form] \t"

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

# define 	FORM_ERROR_HIGH_GRADE	"Error: Grade is too high."
# define 	FORM_ERROR_LOW_GRADE	"Error: Grade is too low."

class	Form
{
	public:
		// Forma Canonica
		Form(void);									// constructor por defecto
		Form(const Form &instance);					// constructor copia
		Form	&operator= (const Form &instance);	// sobrecarga asignacion
		~Form(void);	
		// Forma Canonica

		// Constructor parametrico
		Form(const std::string &name, int signGrade, int executeGrade);

		// getters + setters
		std::string	getName(void) const;
		bool		getSignedStatus(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;

		// metodos propios
		void		beSigned(Bureaucrat &bureaucrat);			// firmar form -> cambiar bool

		// excepciones	
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};	
		class	GradeTooLowException : public std::exception
		{
			public:
				// const throw() -> no modificará ningún atributo de la clase y que no lanzará ninguna excepción -> +seguridad
				virtual const char* what(void) const throw();
		};
	
	private:
		const std::string	_name;
		bool				_isSigned; 	 	// booleano que indica si está firmado
		const int			_signGrade;		// nivel mínimo de un burócrata para firmarlo
		const int			_executeGrade;	// nivel mínimo de un burócrata para firmarlo
};

std::ostream	&operator<< (std::ostream &stream, const Form &instance);

#endif