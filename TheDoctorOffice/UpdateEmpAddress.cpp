#include "UpdateEmpAddress.h"


//*******************************************************************************
//
//******************************************************************************
UpdateEmpAddress::UpdateEmpAddress(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}



//*******************************************************************************
//
//*******************************************************************************
Employee* UpdateEmpAddress::getEmpAdd()
{
	Employee* pEmpU = new Employee();


	if (!empAddressULineEdit->text().toStdString().empty() && !newEmpAddressULineEdit->text().toStdString().empty())
	{
		pEmpU->setEmpID(stoi(empAddressULineEdit->text().toStdString()));
		pEmpU->setStreetAdd(newEmpAddressULineEdit->text().toStdString());
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
void UpdateEmpAddress::on_empAdressUButton_clicked()
{
	UpdateEmpAddress::close();

}// end function 

//*******************************************************************************
//
//******************************************************************************
UpdateEmpAddress::~UpdateEmpAddress()
{
}
