#pragma once

#include <QDialog>
#include "ui_RegisterDialog.h"
#include "User.h"
#include <iostream>
#include "User.h"
#include "MysqlDataBase.h"



class RegisterDialog : public QDialog, public Ui::RegisterDialog
{
	Q_OBJECT

public:
	RegisterDialog(QWidget *parent = Q_NULLPTR);
	~RegisterDialog();
	void initalize();
	void setStySheet();
	User* getUserRegInfo();
	void clearRegData();



private slots:
	void on_registerButton_clicked();
};
