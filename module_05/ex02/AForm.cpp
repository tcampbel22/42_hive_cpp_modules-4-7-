/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:38:34 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/16 17:58:52 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("AForm"), isSigned(false), gradeSign(0), gradeExec(0) {}

AForm::AForm(std::string newName, bool sign, int newSign, int newExec) 
			: name(newName), isSigned(sign), gradeSign(newSign), gradeExec(newExec) {}

AForm::AForm(const AForm& copy) : name(copy.name), isSigned(copy.isSigned), gradeSign(copy.gradeExec), gradeExec(copy.gradeExec) {}

AForm::~AForm() {}

const AForm&		AForm::operator=(const AForm& other) 
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

const std::string	AForm::getAName() const { return name; }

bool				AForm::getAIsSigned() const { return isSigned; }

int					AForm::getAGradeSign() const { return gradeSign; }

int					AForm::getAGradeExec() const { return gradeExec; }

void				AForm::setSigned(bool sign) { isSigned = sign; }

void				AForm::beSigned(const Bureaucrat& b) 
{
	if (b.getGrade() > getAGradeSign())
		throw GradeTooLowException("Grade to low to sign!");
	isSigned = true;
}

std::ostream& operator<<(std::ostream& stream, AForm const& Aform) 
{
	return stream << "AForm " << Aform.getAName() << " info:\n->Signed status: " << std::boolalpha << Aform.getAIsSigned() 
				<< "\n->Grade required to sign: " << Aform.getAGradeSign() << "\n->Grade required to execute: "
				<< Aform.getAGradeExec() << std::endl;   
}