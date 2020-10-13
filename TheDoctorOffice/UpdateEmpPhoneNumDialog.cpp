#include "UpdateEmpPhoneNumDialog.h"


//*******************************************************************************
//
//*******************************************************************************
UpdateEmpPhoneNumDialog::UpdateEmpPhoneNumDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}


//*******************************************************************************
//
//*******************************************************************************
Employee* UpdateEmpPhoneNumDialog::getEmpPH()
{
	Employee* pEmpU = new Employee();


	if (!empPhoneULineEdit->text().toStdString().empty() && !newEmpPhoneULineEdit->text().toStdString().empty())
	{
		pEmpU->setEmpID(stoi(empPhoneULineEdit->text().toStdString()));
		pEmpU->setPhoneNum(newEmpPhoneULineEdit->text().toStdString());
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
void UpdateEmpPhoneNumDialog::on_empPhoneNumUPButton_clicked()
{
	UpdateEmpPhoneNumDialog::close();
}// end function

//*******************************************************************************
//
//*******************************************************************************
UpdateEmpPhoneNumDialog::~UpdateEmpPhoneNumDialog()
{
}
