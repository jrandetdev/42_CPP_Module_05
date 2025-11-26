#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Form", 145, 137, "Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) : AForm("Shrubbery Form", 145, 137, target) {}

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

void	ShrubberyCreationForm::executeFormAction(void)
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
