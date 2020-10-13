#pragma once

#include <QDialog>
#include "ui_UpdateEmployeeDialog.h"
#include "UpdateLNClass.h"
#include "MysqlDataBase.h"
#include <qmessagebox.h>
#include "UpdateEmpPhoneNumDialog.h"
#include "UpdateEmpAddress.h"
#include "UpdateEmpAge.h"

class UpdateEmployeeDialog : public QDialog, public Ui::UpdateEmployeeDialog
{
	Q_OBJECT

public:
	UpdateEmployeeDialog(QWidget *parent = Q_NULLPTR);
	~UpdateEmployeeDialog();
	
private slots:
	void on_editLNameAPushButton_clicked();

private slots:
	void on_editPhoneNumEPushButton_clicked();

private slots:
	void on_editAddressEPushButton_clicked();

private slots:
	void on_editAgeEPushButton_clicked();

};
