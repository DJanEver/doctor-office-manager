#pragma once

#include <QDialog>
#include "ui_UpdateEmpPhoneNumDialog.h"
#include "Employee.h"

class UpdateEmpPhoneNumDialog : public QDialog, public Ui::UpdateEmpPhoneNumDialog
{
	Q_OBJECT

public:
	UpdateEmpPhoneNumDialog(QWidget *parent = Q_NULLPTR);
	~UpdateEmpPhoneNumDialog();

	Employee* getEmpPH();

private slots:
	void on_empPhoneNumUPButton_clicked();

};
