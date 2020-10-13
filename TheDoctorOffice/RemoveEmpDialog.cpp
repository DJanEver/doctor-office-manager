#include "RemoveEmpDialog.h"





//*********************************************************************************
//
//*********************************************************************************
RemoveEmpDialog::RemoveEmpDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}


//*********************************************************************************
//
//*********************************************************************************
Employee* RemoveEmpDialog::getREmpId()
{
	Employee* pEmp = new Employee();


	if (!empIDRemoveLineEdit->text().toStdString().empty())
	{
		pEmp->setEmpID(stoi(empIDRemoveLineEdit->text().toStdString()));
	}// end if 
	else
	{
		pEmp = nullptr;
	}


	return pEmp;
}// end function 




//*********************************************************************************
//
//*********************************************************************************
void RemoveEmpDialog::on_empRemoveButton_clicked()
{
	RemoveEmpDialog::close();
}// end function 


//*********************************************************************************
//
//*********************************************************************************
RemoveEmpDialog::~RemoveEmpDialog()
{
}
