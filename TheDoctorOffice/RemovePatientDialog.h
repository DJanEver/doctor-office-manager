#pragma once

#include <QDialog>
#include "ui_RemovePatientDialog.h"
#include "Patient.h"

class RemovePatientDialog : public QDialog, public Ui::RemovePatientDialog
{
	Q_OBJECT

public:
	RemovePatientDialog(QWidget *parent = Q_NULLPTR);
	~RemovePatientDialog();

	Patient* getRPatientId();
	
private slots:
	void on_patientRemoveButton_clicked();
};
