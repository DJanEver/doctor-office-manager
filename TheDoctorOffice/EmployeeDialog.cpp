#include "EmployeeDialog.h"


//*******************************************************************************
//
//*******************************************************************************
EmployeeDialog::EmployeeDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	checkGender = 0;
}



//*******************************************************************************
//
//*******************************************************************************
Employee* EmployeeDialog::getEmployeeInfo()
{	
	
	Employee* pEmployee = new Employee(this);
	stringstream sSEmpID, sSEmpDouble, sSEmpAge;
	int empId, empAgeNum;
	bool check;
	QMessageBox msg;
	double empSalarydouble;

	string empID = idLineEdit->text().toStdString();
	string empFirstName = fNameLineEdit->text().toStdString();
	string empLastName = lNameLineEdit->text().toStdString();
	string empAge = ageLineEdit->text().toStdString();
	string empAddress = addressLineEdit->text().toStdString();
	string empSalary = salaryLineEdit->text().toStdString();
	string empPhoneNumber = phoneNumLineEdit->text().toStdString();
	string specialty = comboBox->currentText().toStdString();


	if (maleCheckBox->isChecked() && !femaleCheckBox->isChecked())
	{
		pEmployee->setGender("Male");
	}// end if 
	else
	{
		if (femaleCheckBox->isChecked() && !maleCheckBox->isChecked())
		{
			pEmployee->setGender("Female");
		}// end if 
		else
		{
			if (femaleCheckBox->isChecked() && maleCheckBox->isChecked())
			{
				checkGender = 1;
			}// end if 
		}// end else
	}// end else

	sSEmpID << empID;
	sSEmpID >> empId;

	
	sSEmpAge << empAge;
	sSEmpAge >> empAgeNum;

	sSEmpDouble << empSalary;
	sSEmpDouble >> empSalarydouble;

	pEmployee->setEmpID(empId);
	pEmployee->setFname(empFirstName);
	pEmployee->setLname(empLastName);
	pEmployee->setStreetAdd(empAddress);
	pEmployee->setSalry(empSalarydouble);
	pEmployee->setPhoneNum(empPhoneNumber);
	pEmployee->setSpecialty(specialty);
	pEmployee->setAge(empAgeNum);
	
	return pEmployee;
}// end function 



//*******************************************************************************
//
//*******************************************************************************
void EmployeeDialog::on_regEmployeeButton_clicked()
{	
	 
	 /*idLineEdit->clear();
	 firstNameLineEdit->clear();
	 lastNameLineEdit->clear();
     ageLineEdit->clear();
	 addressLineEdit->clear();
	 salaryLineEdit->clear();
	 phoneLineEdit->clear();
	 comboBox->clear();
	 */
	 EmployeeDialog::close();

	
}// end function 


//*******************************************************************************
//
//*******************************************************************************
void EmployeeDialog::setCheckGender(int gender)
{
	checkGender = gender;
}// end function 


//*******************************************************************************
//
//*******************************************************************************
int EmployeeDialog::getCheckGender()
{
	return checkGender;
}// end function 

//*******************************************************************************
//
//*******************************************************************************
EmployeeDialog::~EmployeeDialog()
{

}
