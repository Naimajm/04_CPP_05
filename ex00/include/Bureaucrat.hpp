/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:24:17 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/02 13:26:15 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

# include <string>
# include <iostream>

# define	BUREAU_ID				"[Bureaucrat] \t"
# define	BUREAU_DISPLAY_MSG		", bureaucrat grade "

# define	CONSTRUCTOR_MSG    		"Default Constructor: object created.\t"
# define	COPY_CONSTRUCTOR_MSG	"Copy Constructor: object created.\t"
# define	ASSIGNMENT_MSG			"Assignment operator: obj created.\t"
# define	DESTRUCTOR_MSG	    	"Destructor: object destroyed.\t"

# define	NAME_CONSTRUCTOR_MSG	"Parametric Constructor: object created.\t"

class Bureaucrat
{
	public:
		// forma canonica
		Bureaucrat(void);											// constructor poe defecto
		Bureaucrat(const Bureaucrat &reference);					// constructor copia
		Bureaucrat	&operator= (const Bureaucrat &reference);		// sobrecarga asignacion
		~Bureaucrat(void);
		// forma canonica
		
		Bureaucrat(const std::string name); // constructor parametrico 

		// metodos miembros
		std::string	getName(void) const;
		int			getGrade(void) const;

		void		incrementGrade(void);
		void		decrementGrade(void);

		// Excepciones
		void	GradeTooHighException(void);
		void	GradeTooLowException(void);

	private:
		std::string	_name; 
		int			_grade;		// 	[1-150] importancia decreciente

};

/// sobrecarga del operador de inserción («) 
std::ostream	&operator<< (std::ostream &stream, const Bureaucrat &reference);

#endif