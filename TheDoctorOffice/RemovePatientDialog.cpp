#include "RemovePatientDialog.h"


//*********************************************************************************
//
//*********************************************************************************
RemovePatientDialog::RemovePatientDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

//*********************************************************************************
//
//*********************************************************************************
Patient* RemovePatientDialog::getRPatientId()
{
	Patient* pPatient = new Patient(this);


	if (!patientIDRemoveLineEdit->text().toStdString().empty())
	{
		pPatient->setPatientID(stoi(patientIDRemoveLineEdit->text().toStdString()));
	}// end if 
	else
	{
		pPatient = nullptr;
	}


	return pPatient;
}// end function 




//*********************************************************************************
//
//*********************************************************************************
void RemovePatientDialog::on_patientRemoveButton_clicked()
{
	RemovePatientDialog::close();
}// end function 


//*********************************************************************************
//
//*********************************************************************************
RemovePatientDialog::~RemovePatientDialog()
{
}
