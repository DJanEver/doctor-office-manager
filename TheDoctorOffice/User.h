#pragma once

#include <QObject>
#include <stdbool.h>
#include <iostream>





using namespace std;

class User : public QObject
{
	Q_OBJECT

public:
	User(QObject *parent);
	~User();


	void setUserID(int userid);
	int getUserID();

	void setUsername(string user);
	string getUsername();

	void setFname(string fistName);
	string getFname();

	void setLname(string lastName);
	string getLname();

	void setPassword(string pass);
	string getPassword();

	void setLoginFlag(bool flag);

	bool getLoginFlag();




private:
	int userId;
	string username;
	string fName;
	string lName;
	string password;
	bool loginFlag;


};



