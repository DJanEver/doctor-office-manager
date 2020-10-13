#pragma once

#include <QDialog>
#include "ui_DoctorDialog.h"
#include "Doctor.h"
#include <sstream>

//*******************************************************************************
//
//*******************************************************************************
 class  DoctorDialog : public QDialog, public Ui::DoctorDialog
{
	Q_OBJECT

public:
	DoctorDialog(QWidget *parent = Q_NULLPTR);
	~DoctorDialog();
	Doctor* getDcoInfo();
	void initialize();

private slots:
	void on_regDocButton_clicked();
};
