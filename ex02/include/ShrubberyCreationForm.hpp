/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:00:09 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/18 13:14:09 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "./AForm.hpp"	// CLASE BASE

#include <fstream>		// entrada/salida archivos (std::ofstream, std::ifstream)

# define	SHRUBB_ID					"[Shrubbery] \t"
# define	SHRUBB_FILE_CREATE			"File created: "
# define	SHRUBB_FILE_ERROR			"Error: could not create file "
# define 	ASCII_TREE 					\
										"        *        \n" \
										"       ***       \n" \
										"      *****      \n" \
										"     *******     \n" \
										"    *********    \n" \
										"   ***********   \n" \
										"  *************  \n" \
										"        ||       \n" \
										"        ||       	"

class ShrubberyCreationForm: public AForm
{
	public:
		// Forma Canonica
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &instance);
		ShrubberyCreationForm	&operator= (const ShrubberyCreationForm &instance);
		virtual	~ShrubberyCreationForm(void);
		// Forma Canonica

		// Constructor parametrico
		ShrubberyCreationForm(const std::string &target);

		// metodos propios
		// virtual -> poliformismo de accion en cada tipo 'form'
		virtual void	execute(const Bureaucrat &executor) const; 

		// excepciones propias ¡¡ ERROR AL GENERAR ARCHIVO
		class	FileCreationException	: public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
};

#endif