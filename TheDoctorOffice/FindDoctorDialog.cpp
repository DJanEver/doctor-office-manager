#include "FindDoctorDialog.h"




//*********************************************************************************
//
//*********************************************************************************
FindDoctorDialog::FindDoctorDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}


//*******************************************************************************
//
//*******************************************************************************
Doctor* FindDoctorDialog::getDoctor()
{
	Doctor* pFDoctor = new Doctor(this);

	if (!docIDlineEdit->text().toStdString().empty())
	{
		pFDoctor->setDocId(stoi(docIDlineEdit->text().toStdString()));
	}// end if 
	else
	{
		pFDoctor = nullptr;
	}

	return pFDoctor;
}// end function 


//*******************************************************************************
//
//******************************************************************************
void FindDoctorDialog::on_docFindButton_clicked()
{
	FindDoctorDialog::close();

}// end function 


//*********************************************************************************
//
//*********************************************************************************
FindDoctorDialog::~FindDoctorDialog()
{
}
