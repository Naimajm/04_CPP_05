/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:55 by juagomez          #+#    #+#             */
/*   Updated: 2026/03/03 12:07:21 by juagomez         ###   ########.fr       */
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
# define	MAKEFORM_ERROR 			"Error: Intern could not creates " 
# define 	MAKEFORM_EXCEPTION		"Invalid form name"  

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &instance);
		Intern	&operator= (const Intern &instance);
		~Intern(void);

		typedef AForm*  (*FormConstructor)(const std::string& target);

		AForm*	makeForm(const std::string &formName, const std::string &target);

		class	FormNotExist: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
};

# endif