#include "UpdatePatientDialog.h"



//*********************************************************************************
//
//**********************************************************************************
UpdatePatientDialog::UpdatePatientDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}


Patient* UpdatePatientDialog::getPatient()
{
	Patient* pPatient = new Patient(this);

	if (!UpdatePatientIDLineEdit->text().toStdString().empty() && !NewDocIDlineEdit->text().toStdString().empty())
	{
		pPatient->setPatientID(stoi(UpdatePatientIDLineEdit->text().toStdString()));
		pPatient->setDocID(stoi(NewDocIDlineEdit->text().toStdString()));
	}// end if
	else
	{
		pPatient = nullptr;
	}// end else

	return pPatient;
}

//**********************************************************************************
//
//**********************************************************************************
void UpdatePatientDialog::on_updatePatientPushButton_clicked()
{
	UpdatePatientDialog::close();
}

//**********************************************************************************
//
//**********************************************************************************
UpdatePatientDialog::~UpdatePatientDialog()
{
}
