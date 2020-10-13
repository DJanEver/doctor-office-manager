#include "DoctorDialog.h"

Doctor* pDoctor;

//*******************************************************************************
//
//*******************************************************************************
DoctorDialog::DoctorDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	initialize();
}


void DoctorDialog::initialize()
{
	pDoctor = new Doctor(this);
}


//*******************************************************************************
//
//*******************************************************************************
void DoctorDialog::on_regDocButton_clicked()
{
	DoctorDialog::close();
}// end function 


//*******************************************************************************
//
//*******************************************************************************
Doctor* DoctorDialog::getDcoInfo()
{	
	stringstream sSDocId;
	int dID;

	sSDocId << doctorLineEditD->text().toStdString();
	sSDocId >> dID;
	
	pDoctor->setDocId(dID);
	pDoctor->setDocSpecialty(specComboBox->currentText().toStdString());


	return pDoctor;
}// end function 


//*******************************************************************************
//
//*******************************************************************************
DoctorDialog::~DoctorDialog()
{
}
