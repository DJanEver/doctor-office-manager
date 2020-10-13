#pragma once

#include "Patient.h"

class SurgicalPatient : public Patient
{
	Q_OBJECT

public:
	SurgicalPatient(QObject *parent);
	~SurgicalPatient();
};
