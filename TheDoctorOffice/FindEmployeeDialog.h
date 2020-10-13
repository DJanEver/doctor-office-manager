#pragma once

#include <QDialog>
#include "ui_FindEmployeeDialog.h"
#include "Employee.h"
#include <iostream>
#include "MysqlDataBase.h"

using namespace std;

class FindEmployeeDialog : public QDialog, public Ui::FindEmployeeDialog
{
	Q_OBJECT

public:
	
	FindEmployeeDialog(QWidget* parent = Q_NULLPTR);
	~FindEmployeeDialog();
	
	Employee* getEmpId();
	void init();
private slots:
	void on_empFindButton_clicked();
};
