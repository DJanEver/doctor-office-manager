#pragma once

#include <QDialog>
#include "ui_UpdateEmpAge.h"
#include "Employee.h"

class UpdateEmpAge : public QDialog, public Ui::UpdateEmpAge
{
	Q_OBJECT

public:
	UpdateEmpAge(QWidget *parent = Q_NULLPTR);
	~UpdateEmpAge();

	Employee* getEmpAge();

private slots:
	void on_newEmpAgeUPButton_clicked();

};
