#include "UpdateLNClass.h"


//*******************************************************************************
//
//*******************************************************************************
UpdateLNClass::UpdateLNClass(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}


//*******************************************************************************
//
//*******************************************************************************
Employee* UpdateLNClass::getEmpIdU()
{
	Employee* pEmpU = new Employee();


	if (!empULineEdit->text().toStdString().empty() && !newLnameULineEdit->text().toStdString().empty())
	{
		pEmpU->setEmpID(stoi(empULineEdit->text().toStdString()));
		pEmpU->setLname(newLnameULineEdit->text().toStdString());
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
void UpdateLNClass::on_empLastNameUPButton_clicked()
{
	UpdateLNClass::close();
}// end function 

//*******************************************************************************
//
//*******************************************************************************
UpdateLNClass::~UpdateLNClass()
{
}
