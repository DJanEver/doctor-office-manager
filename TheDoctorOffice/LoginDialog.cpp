#include "LoginDialog.h"


//*********************************************************************************
//
//*********************************************************************************
LoginDialog::LoginDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}


//*********************************************************************************
//
//*********************************************************************************
void LoginDialog::on_loginButton_clicked()
{

	LoginDialog::close();
}


//*********************************************************************************
//
//*********************************************************************************
User* LoginDialog::getUserLogData()
{	
	User* pUserL = new User(this);

	QString username = usernameLogEdit->text();
	QString password = passwordLogEdit->text();

	pUserL->setUsername(username.toStdString());
	pUserL->setPassword(password.toStdString());

	return pUserL;
}//end function 


//*********************************************************************************
//
//*********************************************************************************
LoginDialog::~LoginDialog()
{
}
