#pragma once

#include <QDialog>
#include "ui_UpdateLNClass.h"
#include "Employee.h"

class UpdateLNClass : public QDialog, public Ui::UpdateLNClass
{
	Q_OBJECT

public:
	UpdateLNClass(QWidget *parent = Q_NULLPTR);
	~UpdateLNClass();
	
	Employee* getEmpIdU();

private slots:
	void on_empLastNameUPButton_clicked();

};
