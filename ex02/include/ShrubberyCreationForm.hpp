/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:00:09 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/04 14:11:36 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "./AForm.hpp"			// CLASE BASE

# define	SHRUBB_ID					"[Shrubbery] \t"

class ShrubberyCreationForm: public AForm
{
	public:
		// Forma Canonica
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &instance);
		ShrubberyCreationForm	&operator= (const ShrubberyCreationForm &instance);
		~ShrubberyCreationForm(void);
		// Forma Canonica

		// Constructor parametrico
		ShrubberyCreationForm(const std::string &target);

		// metodos propios
		// virtual -> poliformismo de accion en cada tipo 'form'
		virtual void	execute(const Bureaucrat &executor) const; 

		// excepciones

};

#endif