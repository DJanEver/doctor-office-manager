#pragma once

#include "Employee.h"

class Nurse : public Employee
{
	Q_OBJECT

public:
	Nurse(QObject *parent);
	~Nurse();
	void setNurseSpecialty(string nurseSpecialty);

	string getNurseSpecialty();

private:
	string nurseSpecialty;

};
