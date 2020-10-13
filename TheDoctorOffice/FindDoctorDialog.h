#pragma once

#include <QDialog>
#include "ui_FindDoctorDialog.h"
#include "Doctor.h"


class FindDoctorDialog : public QDialog, public Ui::FindDoctorDialog
{
	Q_OBJECT

public:
	FindDoctorDialog(QWidget *parent = Q_NULLPTR);
	~FindDoctorDialog();


	Doctor* getDoctor();
	
	private slots:
	void on_docFindButton_clicked();


};
