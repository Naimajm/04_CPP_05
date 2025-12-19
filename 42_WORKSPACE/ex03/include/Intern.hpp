/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:55 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/19 22:28:52 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	INTERN_HPP
#define 	INTERN_HPP

#include <string>
#include "./AForm.hpp"

# define	INTERN_ID				"[Intern] \t"

# define	CONSTRUCTOR_MSG    		"Default Constructor: object created.\t"
# define	COPY_CONSTRUCTOR_MSG	"Copy Constructor: object created.\t"
# define	ASSIGNMENT_MSG			"Assignment operator: obj created.\t"
# define	DESTRUCTOR_MSG	    	"Destructor: object destroyed.\t"
# define	NAME_CONSTRUCTOR_MSG	"Parametric Constructor: object created.\t"

# define	MAKEFORM_OK				"Intern creates "
# define	MAKEFORM_ERROR 			"Error: Intern could not creates "   // std::cerr (log)
# define 	MAKEFORM_EXCEPTION		"Invalid form name"       			// what() (excepción)

class Intern
{
	public:
		// forma canonica
		Intern(void);
		Intern(const Intern &instance);
		Intern	&operator= (const Intern &instance);
		~Intern(void);
		// forma canonica
		// constructor parametrico -> no

		// metodos propios
		AForm*	makeForm(const std::string &formName, const std::string &target);

		// excepcion form no encontrado
		class	FormNotExist: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
};

# endif