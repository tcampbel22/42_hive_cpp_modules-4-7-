/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:34:42 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/18 11:27:39 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string t);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	~PresidentialPardonForm();
	const PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	void		beSigned(const Bureaucrat& b) override;
	void		PresidentialPardon(const Bureaucrat& b) const;
	void		execute(Bureaucrat const & executor) const override;
	std::string	getTarget();
};