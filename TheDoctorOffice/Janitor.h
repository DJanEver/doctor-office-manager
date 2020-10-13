#pragma once

#include "Employee.h"

class Janitor : public Employee
{
	Q_OBJECT

public:
	Janitor(QObject *parent);
	~Janitor();
	void setJanitorSpecialty(string specialty);

	string getJanitorSpecialty();

private:
	string janitorSpecialty;

};
