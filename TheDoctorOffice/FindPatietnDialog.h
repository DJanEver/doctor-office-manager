#pragma once

#include <QDialog>
#include "ui_FindPatietnDialog.h"
#include "Patient.h"

class FindPatientDialog : public QDialog, public Ui::FindPatietnDialog
{
	Q_OBJECT

public:
	FindPatientDialog(QWidget *parent = Q_NULLPTR);
	~FindPatientDialog();
	Patient* getPatient();

private slots:
	void on_findPatientPushButton_clicked();
};
