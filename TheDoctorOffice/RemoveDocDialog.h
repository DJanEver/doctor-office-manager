#pragma once

#include <QDialog>
#include "ui_RemoveDocDialog.h"
#include "Doctor.h"

class RemoveDocDialog : public QDialog, public Ui::RemoveDocDialog
{
	Q_OBJECT

public:
	RemoveDocDialog(QWidget *parent = Q_NULLPTR);
	~RemoveDocDialog();

	Doctor* getRDocId();

private slots:
	void on_docRemoveButton_clicked();
};
