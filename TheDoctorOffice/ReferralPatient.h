#pragma once

#include "Patient.h"

class ReferralPatient : public Patient
{
	Q_OBJECT

public:
	ReferralPatient(QObject *parent);
	~ReferralPatient();

	void setClinicAdd(string clinicAdd);
	string getClinicAdd();

private:
	string nextClinicAdd;
};
