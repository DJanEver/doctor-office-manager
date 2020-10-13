#pragma once

#include "Employee.h"

class Receptionist : public Employee
{
	Q_OBJECT

public:
	Receptionist(QObject *parent);
	~Receptionist();

	void setRecpSpecialty(string specialty);

	string getRecpSpecialty();

private:

	string recpSpecialty;

};
