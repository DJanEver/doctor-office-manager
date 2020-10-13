#pragma once

#include <QObject>
#include <iostream>

using namespace std;


class Employee : public QObject
{
	Q_OBJECT

public:
	Employee(QObject *parent);
	Employee();
	~Employee();
	void setEmpID(int empID);
	void setFname(string fName);
	void setLname(string lName);
	void setAge(int age);
	void setStreetAdd(string streetAdd);
	void setSalry(double salary);
	void setGender(string gender);
	void setPhoneNum(string phoneNum);
	void setSpecialty(string empSpecialty);

	string getPhoneNum();
	double getSalary();
	string getStreetAdd();
	int getAge();
	string getLname();
	string getFname();
	int getEmpID();
	string getGender();
	string getSpecialty();

private:

	string phoneNumber;
	string gender;
	int	   employeeID;
	string firstName;
	string lastName;
	int	   age;
	string streetAdress;
	double salary;
	string specialty;

};
