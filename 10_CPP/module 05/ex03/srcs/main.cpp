/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 07:15:46 by alecoutr          #+#    #+#             */
/*   Updated: 2023/09/28 15:43:41 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern		bob;
	Form		*form;
	Bureaucrat	karen("Karen", 50);

	// Test how all forms are created properly execpt for the last one
	try
	{
		form = bob.makeForm("RobotomyRequestForm", "Alice");
		delete form;
		form = bob.makeForm("ShrubberyCreationForm", "Charlie");
		delete form;
		form = bob.makeForm("PresidentialPardonForm", "David");
		delete form;
		form = bob.makeForm("RandomForm", "Elisa");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// Test some Actions with available form
	std::cout << "------------------------------------" << std::endl;
	form = bob.makeForm("ShrubberyCreationForm", "Fred");
	form->beSigned(karen);
	karen.executeForm(*form);
	delete form;
	std::cout << "------------------------------------" << std::endl;
	form = bob.makeForm("PresidentialPardonForm", "Georgia");
	try
	{
		karen.setGrade(form->getGradeRequiredForExecution());
		karen.signForm(*form);
		karen.executeForm(*form);
	} catch( Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Bureaucrat " << karen.getName() << " cannot sign Form " << form->getName() << std::endl;
	}
	delete form;
	return (0);
}
