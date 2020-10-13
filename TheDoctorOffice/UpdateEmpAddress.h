#pragma once

#include <QDialog>
#include "ui_UpdateEmpAddress.h"
#include "Employee.h"

class UpdateEmpAddress : public QDialog, public Ui::UpdateEmpAddress
{
	Q_OBJECT

public:
	UpdateEmpAddress(QWidget* parent = Q_NULLPTR);
	~UpdateEmpAddress();

	Employee* getEmpAdd();

private slots:
	void on_empAdressUButton_clicked();

};