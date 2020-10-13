#include "FindPatietnDialog.h"


//*******************************************************************************
//
//*******************************************************************************
FindPatientDialog::FindPatientDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}



//*******************************************************************************
//
//*******************************************************************************
Patient* FindPatientDialog::getPatient()
{
	Patient* pFPatient = new Patient(this);

	if (!findPatientLineEdit->text().toStdString().empty())
	{
		pFPatient->setPatientID(stoi(findPatientLineEdit->text().toStdString()));
	}// end if 
	else
	{
		pFPatient = nullptr;
	}


	return pFPatient;
}// end function 


//*******************************************************************************
//
//*******************************************************************************
void FindPatientDialog::on_findPatientPushButton_clicked()
{
	FindPatientDialog::close();

}// end function 


//*******************************************************************************
//
//*******************************************************************************
FindPatientDialog::~FindPatientDialog()
{
}
