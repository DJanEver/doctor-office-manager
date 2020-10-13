#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <qmessagebox.h>
#include <sstream>
#include "MysqlDataBase.h"
#include "LoginDialog.h"
#include "RegisterDialog.h"
#include "EmployeeDialog.h"
#include "PatientDialog.h"
#include "DoctorDialog.h"
#include "FindEmployeeDialog.h"
#include "FindPatietnDialog.h"
#include "FindDoctorDialog.h"
#include "RemoveEmpDialog.h"
#include "RemovePatientDialog.h"
#include "RemoveDocDialog.h"
#include "UpdateEmployeeDialog.h"
#include "UpdateLNClass.h"
#include "UpdatePatientDialog.h"

 


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = Q_NULLPTR);
    void setStySheet();
    void initalize();
    void setLoginWidget(QString user);
    void tBSlotandSignalConnect();
    void customTableViewMenu(QPoint pos);
    Employee* getEmpInfo();
    Patient* getPatientInfo();
    Doctor* getDocInfo();

   
private slots:
    void on_actionRegister_triggered();


private slots:
    void on_actionLogin_triggered();


private slots:
    void on_loadTableButton_clicked();

private slots:
    void on_addButton_clicked();
    
private slots:
    void on_Table_clicked(const QModelIndex& index);
    
private slots:
    void on_addNew_triggerd();

private slots:
    void on_edit_triggerd();

private slots:
    void on_delete_triggerd();

private slots:
    void on_actionAddEmployee_triggered();
        
private slots:
    void on_actionAddPatient_triggered();

private slots:
    void on_actionAddDoctor_triggered();

private slots:
    void on_actionEmployeeFind_triggered();

private slots:
    void on_actionPatientFind_triggered();

private slots:
    void on_actionFindDoctor_triggered();

private slots:
    void on_actionEmployeeRemove_triggered();

private slots:
    void on_actionPatientRemove_triggered();

private slots:
    void on_actionRemoveDoctor_triggered();

private slots:
    void on_actionEmployeeUpdate_triggered();

private slots:
    void on_actionPatientUpdate_triggered();

private slots:
    void on_findButton_clicked();


private:
    Ui::MainWindowClass ui;

    
};
