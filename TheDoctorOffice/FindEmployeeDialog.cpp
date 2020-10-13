#include "FindEmployeeDialog.h"



//*********************************************************************************
//
//*********************************************************************************
FindEmployeeDialog::FindEmployeeDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}




//*********************************************************************************
//
//*********************************************************************************
void FindEmployeeDialog::init()
{


}// end function 



//*********************************************************************************
//
//*********************************************************************************
 Employee* FindEmployeeDialog::getEmpId()
{
	 Employee* pEmp = new Employee();

	
	 if (!empIDlineEdit->text().toStdString().empty())
	 {		
		 pEmp->setEmpID(stoi(empIDlineEdit->text().toStdString()));
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
 void FindEmployeeDialog::on_empFindButton_clicked()
 {
	 FindEmployeeDialog::close();
 }// end function 

//*********************************************************************************
//
//*********************************************************************************
FindEmployeeDialog::~FindEmployeeDialog()
{
}
