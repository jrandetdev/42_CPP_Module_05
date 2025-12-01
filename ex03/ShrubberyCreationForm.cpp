#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137, "Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("shrubbery creation", 145, 137, target) {
	std::cout << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator =(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::executeFormAction(void) const
{
	std::string	fileName;

	fileName = this->getTarget() + "_shrubbery";
	std::ofstream File(fileName.c_str());
	File << "            # #### ####\n";
	File << "         ### \\/#|### |/####\n";
	File << "        ##\\/#/ \\||/##/_/##/_#\n";
	File << "        ###  \\/###|/ \\/ # ###\n";
	File << "      ##_\\_#\\_\\## | #/###_/_####\n";
	File << "     ## #### # \\ #| /  #### ##/##\n";
	File << "      __#_--###`  |{,###---###-~\n";
	File << "                 \\ }{\n";
	File << "                 }}{\n";
	File << "                 }}{\n";
	File << "               ejm  {{}}\n";
	File << "            , -=-~{ .-^- _\n";
	
	File.close();
}
