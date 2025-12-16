/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:36:17 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/16 17:44:36 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include "./AForm.hpp"

# define PRESIDENTAL_ID			"[Presidental] \t"

class PresidentialPardonForm:	public AForm
{
	public:
		// Forma Canonica
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &instance);
		PresidentialPardonForm	&operator= (const PresidentialPardonForm &instance);
		virtual	~PresidentialPardonForm(void);
		// Forma Canonica

		// Constructor parametrico
		PresidentialPardonForm(const std::string &target);

		// Metodos propios
		virtual	void	execute(const Bureaucrat &executor) const;

		// excepciones
};

#endif