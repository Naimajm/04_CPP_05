/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:00:09 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/18 16:28:53 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "./AForm.hpp"

#include <fstream>

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
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &instance);
		ShrubberyCreationForm	&operator= (const ShrubberyCreationForm &instance);
		virtual	~ShrubberyCreationForm(void);

		ShrubberyCreationForm(const std::string &target);

		virtual void	execute(const Bureaucrat &executor) const; 

		class	FileCreationException	: public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
};

#endif