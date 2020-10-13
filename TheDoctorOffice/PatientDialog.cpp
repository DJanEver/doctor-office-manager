#include "PatientDialog.h"

//*********************************************************************************
//
//*********************************************************************************
PatientDialog::PatientDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	
}


//*********************************************************************************
//
//*********************************************************************************
Patient* PatientDialog::getPatient()
{
	Patient* pPatient = new Patient(this);
	stringstream piD;
	stringstream diD;
	int docId;
	int patientID;

	piD << idPatientLineEdit->text().toStdString();
	piD >> patientID;
	
	diD << idDoctorLineEdit->text().toStdString();
	diD >> docId;

	pPatient->setPatientID(patientID);
	pPatient->setDocID(docId);
	pPatient->setFname(patientFNameLineEdit->text().toStdString());
	pPatient->setLname(patientLNameLineEdit->text().toStdString());
	pPatient->setDOB(dobLineEdit->text().toStdString());
	pPatient->setPhoneNum(patientPhoneNumLineEdit->text().toStdString());


	if (patientMaleCheckBox->isChecked() && !patientFemaleCheckBox->isChecked())
	{
		pPatient->setGender("Male");
	}// end if 
	else
	{
		if (patientFemaleCheckBox->isChecked() && !patientMaleCheckBox->isChecked())
		{
			pPatient->setGender("Female");
		}// end if 
		else
		{
			pPatient->setGenderCheck(1);
		}// end else
	}// end else
	

	return pPatient;

}// end function 



//*********************************************************************************
//
//*********************************************************************************
void PatientDialog::on_regPatientButton_clicked()
{
	PatientDialog::close();
}// end function 


//*********************************************************************************
//
//*********************************************************************************
PatientDialog::~PatientDialog()
{
}
