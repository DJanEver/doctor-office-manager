#pragma once

#include <QDialog>
#include "ui_EmployeeDialog.h"
#include "Employee.h"
#include "sstream"
#include <qmessagebox>
#include <iostream>

using namespace std;



class EmployeeDialog : public QDialog, public Ui::EmployeeDialog
{
	Q_OBJECT

public:
	EmployeeDialog(QWidget *parent = Q_NULLPTR);
	~EmployeeDialog();
	Employee* getEmployeeInfo();

	void setCheckGender(int gender);
	int getCheckGender();

private slots:
	void on_regEmployeeButton_clicked();

private:
	int checkGender;

};
