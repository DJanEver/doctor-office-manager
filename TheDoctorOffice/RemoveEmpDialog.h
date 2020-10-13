#pragma once

#include <QDialog>
#include "ui_RemoveEmpDialog.h"
#include "Employee.h"

class RemoveEmpDialog : public QDialog, public Ui::RemoveEmpDialog
{
	Q_OBJECT

public:
	RemoveEmpDialog(QWidget *parent = Q_NULLPTR);
	~RemoveEmpDialog();

	Employee* getREmpId();

private slots:
	void on_empRemoveButton_clicked();

};
