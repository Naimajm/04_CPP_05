/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:24:17 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/02 22:05:11 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

# include <string>
# include <iostream>

# define	BUREAU_ID				"[Bureaucrat] \t"
# define	CONSTRUCTOR_MSG    		"Default Constructor: object created.\t"
# define	COPY_CONSTRUCTOR_MSG	"Copy Constructor: object created.\t"
# define	ASSIGNMENT_MSG			"Assignment operator: obj created.\t"
# define	DESTRUCTOR_MSG	    	"Destructor: object destroyed.\t"
# define	NAME_CONSTRUCTOR_MSG	"Parametric Constructor: object created.\t"

# define	DEFAULT_NAME			"default name"
# define	DEFAULT_GRADE			150

# define	BUREAU_DISPLAY_MSG		", bureaucrat grade "
# define 	MIN_GRADE				150
# define 	MAX_GRADE				1
# define 	ERROR_HIGH_GRADE_MSG	"Error: Grade is too high (maximum is 1)."
# define 	ERROR_LOW_GRADE_MSG		"Error: Grade is too low (minimum is 150)."

class Bureaucrat
{
	public:
		// forma canonica
		Bureaucrat(void);											// constructor poe defecto
		Bureaucrat(const Bureaucrat &reference);					// constructor copia
		Bureaucrat	&operator= (const Bureaucrat &reference);		// sobrecarga asignacion
		~Bureaucrat(void);
		// forma canonica
		
		Bureaucrat(const std::string &name, int grade); // constructor parametrico 

		// metodos miembros
		std::string		getName(void) const;
		int 			getGrade(void) const;
		void			setGrade(int grade);

		void	incrementGrade(void);
		void	decrementGrade(void);

		// class Exception -> objetos heredados de clase base 'exception'
		// Polimorfismo-> Permite capturar todas las excepciones (estándar y tuyas) en un solo bloque catch (std::exception &e)
		class	GradeTooHighException : public std::exception
		{
			public:
				// Sobrescribimos el metodo virtual 'what'
                // const throw() significa que este metodo NO lanzará excepciones
				virtual const char* what(void) const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

	private:
		const	std::string	_name; 
		int					_grade;		// 	[1-150] importancia decreciente
};

/// sobrecarga del operador de inserción («) 
std::ostream	&operator<< (std::ostream &stream, const Bureaucrat &reference);

#endif