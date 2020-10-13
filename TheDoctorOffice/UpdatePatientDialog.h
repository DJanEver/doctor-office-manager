#pragma once

#include <QDialog>
#include "ui_UpdatePatientDialog.h"
#include "Patient.h"


class UpdatePatientDialog : public QDialog, public Ui::UpdatePatientDialog
{
	Q_OBJECT

public:
	UpdatePatientDialog(QWidget *parent = Q_NULLPTR);
	~UpdatePatientDialog();

	Patient* getPatient();

private slots:
	void on_updatePatientPushButton_clicked();

};
