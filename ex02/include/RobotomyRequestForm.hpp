/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:18:25 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/16 17:39:40 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "./AForm.hpp"

# define ROBOTOMY_ID	"[Robotomy] \t"

class	RobotomyRequestForm: public AForm
{
	public:
		// Forma Canonica
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &instance);
		RobotomyRequestForm	&operator= (const RobotomyRequestForm &instance);
		virtual	~RobotomyRequestForm(void);
		// Forma Canonica

		// Constructor parametrico
		RobotomyRequestForm(const std::string &target);

		// metodos propios
		virtual	void 	execute(const Bureaucrat &executor) const;

		// excepciones
};

#endif