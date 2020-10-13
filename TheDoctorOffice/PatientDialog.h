#pragma once

#include <QDialog>
#include "ui_PatientDialog.h"
#include <string>
#include <iostream>
#include "Patient.h"
#include <sstream>
using namespace std;


class PatientDialog : public QDialog, public Ui::PatientDialog
{
	Q_OBJECT

public:
	PatientDialog(QWidget *parent = Q_NULLPTR);
	~PatientDialog();
	Patient* getPatient();
	
private slots:
	void on_regPatientButton_clicked();

};
