/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:18:25 by juagomez          #+#    #+#             */
/*   Updated: 2025/12/18 16:28:19 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "./AForm.hpp"

#include <cstdlib>
#include <ctime>

# define ROBOTOMY_ID				"[Robotomy] \t"
# define ROBOTOMY_DRILLING_NOISE	"* BZZZZZT BZZZZZT *"
# define ROBOTOMY_ACTION_OK			" has been robotomized successfully!"
# define ROBOTOMY_ACTION_FAIL		"Robotomy failed on "

class	RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &instance);
		RobotomyRequestForm	&operator= (const RobotomyRequestForm &instance);
		virtual	~RobotomyRequestForm(void);

		RobotomyRequestForm(const std::string &target);

		virtual	void 	execute(const Bureaucrat &executor) const;
};

#endif