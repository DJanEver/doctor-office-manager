#include "RegisterDialog.h"



User* pUser;
//*********************************************************************************
//
//*********************************************************************************
RegisterDialog::RegisterDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this); 
	initalize();

}


//*********************************************************************************
//
//*********************************************************************************
void RegisterDialog::initalize()
{

	pUser = new User(this);
   
}



//*********************************************************************************
//
//*********************************************************************************
void RegisterDialog::setStySheet()
{
}


//*********************************************************************************
//
//*********************************************************************************
User* RegisterDialog::getUserRegInfo()
{
	stringstream sStream;
	int userIdentification;

	QString userid = userLineEdit->text();
	QString userName = usernameLineEdit->text();
	QString firstName = fNameLineEdit->text();
	QString lastName = lNameLineEdit->text();
	QString pass = passwordLineEdit->text();

	sStream << userid.toStdString();
	sStream >> userIdentification;

	pUser->setUserID(userIdentification);
	pUser->setUsername(userName.toStdString());
	pUser->setFname(firstName.toStdString());
	pUser->setLname(lastName.toStdString());
	pUser->setPassword(pass.toStdString());

	return pUser;
}// end function 



//*********************************************************************************
//
//*********************************************************************************
void RegisterDialog::on_registerButton_clicked()
{
	RegisterDialog::close();
	
}

//*********************************************************************************
//
//*********************************************************************************
void RegisterDialog::clearRegData()
{
	this->userLineEdit->clear();
	this->usernameLineEdit->clear();
	this->fNameLineEdit->clear();
	this->lNameLineEdit->clear();
	this->passwordLineEdit->clear();
}// end function  

//*********************************************************************************
//
//*********************************************************************************
RegisterDialog::~RegisterDialog()
{
}
