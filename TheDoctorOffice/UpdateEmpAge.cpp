#include "UpdateEmpAge.h"


//*******************************************************************************
//
//*******************************************************************************
UpdateEmpAge::UpdateEmpAge(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}


//*******************************************************************************
//
//*******************************************************************************
Employee* UpdateEmpAge::getEmpAge()
{
	Employee* pEmpU = new Employee();


	if (!newEmPIDULineEdit->text().toStdString().empty() && !newEmpAgeULineEdit->text().toStdString().empty())
	{
		pEmpU->setEmpID(stoi(newEmPIDULineEdit->text().toStdString()));
		pEmpU->setAge(atoi(newEmpAgeULineEdit->text().toStdString().c_str()));
	}// end if 
	else
	{
		pEmpU = nullptr;
	}// end else 

	return pEmpU;
}// end function 



//*******************************************************************************
//
//*******************************************************************************
void UpdateEmpAge::on_newEmpAgeUPButton_clicked()
{
	UpdateEmpAge::close();
}// end function

//*******************************************************************************
//
//*******************************************************************************
UpdateEmpAge::~UpdateEmpAge()
{
}
