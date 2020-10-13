#pragma once
#include <QObject>
#include <iostream>


using namespace std;

//*********************************************************************************
//
//*********************************************************************************
 class Patient : public QObject
{
	Q_OBJECT

public:
	Patient(QObject* parent);
	~Patient();

	void setPatientID(int patientId);
	void setFname(string fName);
	void setLname(string lName);
	void setGender(string gender);
	void setDOB(string dateOB);
	void setPhoneNum(string phoneNum);
	void setDefect(string defect);
	void setDocID(int doc);
	void setGenderCheck(int check);

	int getGenderCheck();
	string getPhoneNum();
	string getDOB();
	string getGender();
	int getPatientID();
	string getFname();
	string getLname();
	string getDefect();
	int getDocID();




private:
	int patientID;
	int docID;
	string firstName;
	string lastName;
	string gender;
	string DOB;
	string phoneNumber;
	string defect;
	int reCheckGender;

};
