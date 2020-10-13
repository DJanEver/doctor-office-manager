#include "RemoveDocDialog.h"



//*********************************************************************************
//
//*********************************************************************************
RemoveDocDialog::RemoveDocDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}


//*********************************************************************************
//
//*********************************************************************************
Doctor* RemoveDocDialog::getRDocId()
{

	Doctor* pDoc = new Doctor(this);


	if (!docIDRemoveLineEdit->text().toStdString().empty())
	{
		pDoc->setDocId(stoi(docIDRemoveLineEdit->text().toStdString()));
	}// end if 
	else
	{
		pDoc = nullptr;
	}


	return pDoc;
}// end function 




//*********************************************************************************
//
//*********************************************************************************
void RemoveDocDialog::on_docRemoveButton_clicked()
{
	RemoveDocDialog::close();
}// end function 


//*********************************************************************************
//
//*********************************************************************************
RemoveDocDialog::~RemoveDocDialog()
{
}
