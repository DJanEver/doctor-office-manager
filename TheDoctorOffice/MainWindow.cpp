#include "MainWindow.h"
#include "stdafx.h"



MysqlDataBase* pDataBase;
User* pUserMain;
EmployeeDialog* pEmoloyeeDialog;
RegisterDialog* pRegisterD;
PatientDialog* pPatient;
DoctorDialog* pDoctor;
FindEmployeeDialog* pFindDialog;
FindPatientDialog* pFindPatientDialog;
FindDoctorDialog* pFindDoctorDialog;
RemoveEmpDialog* pRemoveEmpDialog;
RemovePatientDialog* pRemovePatientDialog;
RemoveDocDialog* pRemoveDocDialog;
UpdateEmployeeDialog* pUdateEmpDialog;
UpdatePatientDialog* pUpdatePatient;
QSqlQueryModel* MysqlDataBase::pStaticQModel = new QSqlQueryModel();


//*********************************************************************************
//
//*********************************************************************************
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
   
    ui.setupUi(this);
  
    initalize();
   QMessageBox msgBox;

     
    if (!pDataBase->getResult())
    {
        msgBox.warning(this, tr("Connection Failed"), tr("Check Connection"));
        exit(0);
        
    }// end if
    else
    {
        ui.statusLabel->setText("Connected and ready...");
        
    }// end else
    
}




//*********************************************************************************
//
//*********************************************************************************
void MainWindow::initalize()
{
      
      setStySheet();
      
      pRegisterD = new RegisterDialog();
      pEmoloyeeDialog = new EmployeeDialog();
      ui.actionAddEmployee->setEnabled(false);
      ui.actionAddPatient->setEnabled(false);
      ui.actionEmployeeRemove->setEnabled(false);
      ui.actionPatientRemove->setEnabled(false);
      ui.actionEmployeeUpdate->setEnabled(false);
      ui.actionPatientUpdate->setEnabled(false);
      ui.actionAddDoctor->setEnabled(false);
      ui.actionRemoveDoctor->setEnabled(false);
      pDataBase = new MysqlDataBase(this);
      pUserMain = new User(this);
      pPatient = new PatientDialog();
      pDoctor = new DoctorDialog(this);
      pFindDialog = new FindEmployeeDialog(this);
      pFindPatientDialog = new FindPatientDialog(this);
      pFindDoctorDialog = new FindDoctorDialog(this);
      pRemoveEmpDialog = new RemoveEmpDialog(this);
      pRemovePatientDialog = new RemovePatientDialog(this);
      pRemoveDocDialog = new RemoveDocDialog(this);
      pUdateEmpDialog = new UpdateEmployeeDialog(this);
      pUpdatePatient = new UpdatePatientDialog(this);


}

//*********************************************************************************
//  The destructor: house keeping 
//*********************************************************************************

//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_actionEmployeeFind_triggered()
{
    pFindDialog->exec();
    
    QMessageBox msgBox;

    switch (pDataBase->findEmployee(pFindDialog->getEmpId()))
    {

    case QRY_SUCCESS:
       
        ui.tableView->reset();
        ui.tableView->setModel(MysqlDataBase::pStaticQModel);
        break;

    case QRY_FAIL:

        msgBox.critical(this, tr("CRITICAL!!!"),
                        tr("INVALID QUERY."));
        break;

    case EMPTY_FIELD:
        msgBox.warning(this, tr("WARINIG!!!"),
            tr("PLEASE FILL IN THE EMPTY FIELDS."));
        break;

    case INVALID_ID:
        msgBox.warning(this, tr("WARINIG!!!"),
            tr("INVALID ID."));
        break;
    }// end switch 
    

}// end function 



//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_actionPatientUpdate_triggered()
{
    pUpdatePatient->exec();

    QMessageBox msgBox;

    switch (pDataBase->updatePatient(pUpdatePatient->getPatient()))
    {
    case 0:
        msgBox.critical(this, tr("Error"), tr("Query Failed!!!"));
        break;

    case 1:
        msgBox.information(this, tr("SUCCESS"), tr("Patient Updated"));
        break;

    case 2:
        msgBox.warning(this, tr("Warning"), tr("Empty Fields"));
        break;


    case 3:
        msgBox.warning(this, tr("Error"), tr("Please Register The Doctor As An Employee First"));
        break;
    }// end switch 


}//end function 


 //*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_actionRemoveDoctor_triggered()
{
    pRemoveDocDialog->exec();
    QMessageBox msgBox;

    switch (pDataBase->deleteDoctor(pRemoveDocDialog->getRDocId()))
    {

    case QRY_SUCCESS:

        msgBox.information(this, tr("SUCCESS!!!"),
            tr("Employee Deleted"));
        break;

    case QRY_FAIL:

        msgBox.critical(this, tr("CRITICAL!!!"),
            tr("INVALID QUERY."));
        break;

    case EMPTY_FIELD:
        msgBox.warning(this, tr("WARINIG!!!"),
            tr("PLEASE FILL IN THE EMPTY FIELDS."));
        break;

    case INVALID_ID:
        msgBox.warning(this, tr("WARINIG!!!"),
            tr("INVALID ID."));
        break;
    }// end switch 


}//end function 


//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_actionPatientRemove_triggered()
{
    pRemovePatientDialog->exec();
    QMessageBox msgBox;

    switch (pDataBase->deletePatient(pRemovePatientDialog->getRPatientId()))
    {

    case QRY_SUCCESS:

        msgBox.information(this, tr("SUCCESS!!!"),
            tr("Employee Deleted"));
        break;

    case QRY_FAIL:

        msgBox.critical(this, tr("CRITICAL!!!"),
            tr("INVALID QUERY."));
        break;

    case EMPTY_FIELD:
        msgBox.warning(this, tr("WARINIG!!!"),
            tr("PLEASE FILL IN THE EMPTY FIELDS."));
        break;

    case INVALID_ID:
        msgBox.warning(this, tr("WARINIG!!!"),
            tr("INVALID ID."));
        break;
    }// end switch 


}// end function 

//*********************************************************************************
//
//*********************************************************************************
void MainWindow::tBSlotandSignalConnect()
{
    QModelIndex* pIndex = new QModelIndex();
    
        connect(ui.tableView, SIGNAL(clicked(const QModelIndex&)),
        this, SLOT(on_Table_clicked(const QModelIndex&)));
    
         on_Table_clicked(*pIndex);


}


//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_Table_clicked(const QModelIndex& index)

{    
    QPoint pPos;
  
        if(index.isValid())
        {
            //The addNew Action is stationary.
            customTableViewMenu(pPos);
            
        }  
  
}
   


//*********************************************************************************
//
//*********************************************************************************
 void MainWindow::customTableViewMenu(QPoint pos)
{
     QModelIndex pIndex;
     QMenu* pMenu = new QMenu();
  
    
     pIndex = ui.tableView->indexAt(pos);

     pMenu->addAction(QString("Add New"), this, SLOT(on_addNew_triggerd()));
     pMenu->addSeparator();
     pMenu->addAction(QString("Edit"), this, SLOT(on_edit_triggerd()));
     pMenu->addSeparator();
     pMenu->addAction(QString("Delete"), this, SLOT(on_delete_triggerd()));
     pMenu->popup(ui.tableView->viewport()->mapToGlobal(pos));
  



}// end function 


//*********************************************************************************
//
//*********************************************************************************
 void MainWindow::on_actionEmployeeRemove_triggered()
 {
     pRemoveEmpDialog->exec();
     QMessageBox msgBox;

     switch (pDataBase->deleteEmployee(pRemoveEmpDialog->getREmpId()))
     {

     case QRY_SUCCESS:

         msgBox.information(this, tr("SUCCESS!!!"),
             tr("Employee Deleted"));
         break;

     case QRY_FAIL:

         msgBox.critical(this, tr("CRITICAL!!!"),
             tr("INVALID QUERY."));
         break;

     case EMPTY_FIELD:
         msgBox.warning(this, tr("WARINIG!!!"),
             tr("PLEASE FILL IN THE EMPTY FIELDS."));
         break;

     case INVALID_ID:
         msgBox.warning(this, tr("WARINIG!!!"),
             tr("INVALID ID."));
         break;
     }// end switch 
     

}// end function 

//*********************************************************************************
//
//*********************************************************************************
 void MainWindow::on_actionPatientFind_triggered()
 {  
     pFindPatientDialog->exec();
     QMessageBox msgBox;

     switch (pDataBase->findPatient(pFindPatientDialog->getPatient()))
     {

     case QRY_SUCCESS:

         ui.tableView->reset();
         ui.tableView->setModel(MysqlDataBase::pStaticQModel);
         break;

     case QRY_FAIL:

         msgBox.critical(this, tr("CRITICAL!!!"),
             tr("INVALID QUERY."));
         break;

     case EMPTY_FIELD:
         msgBox.warning(this, tr("WARINIG!!!"),
             tr("PLEASE FILL IN THE EMPTY FIELDS."));
         break;

     case INVALID_ID:
         msgBox.warning(this, tr("WARINIG!!!"),
             tr("INVALID ID."));
         break;
     }// end switch 



 }// end function 


//*********************************************************************************
//
//*********************************************************************************
 void MainWindow::on_actionFindDoctor_triggered()
 {
     pFindDoctorDialog->exec();
     QMessageBox msgBox;

     
     switch (pDataBase->findDoctor(pFindDoctorDialog->getDoctor()))
     {

     case QRY_SUCCESS:

         ui.tableView->reset();
         ui.tableView->setModel(MysqlDataBase::pStaticQModel);
         break;

     case QRY_FAIL:

         msgBox.critical(this, tr("CRITICAL!!!"),
             tr("INVALID QUERY."));
         break;

     case EMPTY_FIELD:
         msgBox.warning(this, tr("WARINIG!!!"),
             tr("PLEASE FILL IN THE EMPTY FIELDS."));
         break;

     case INVALID_ID:
         msgBox.warning(this, tr("WARINIG!!!"),
             tr("INVALID ID."));
         break;
     }// end switch 
     


 }// end function 


//*********************************************************************************
//
//*********************************************************************************
 void MainWindow::on_addNew_triggerd()
 {

     int result;
     QMessageBox msgBox;
    
     
     if (0 == ui.tableComboBox->currentIndex())
     {
         pRegisterD->exec();

         result = pDataBase->regUserQuery(pRegisterD->getUserRegInfo());


         if (EMPTY_FIELD == result)
         {
             msgBox.warning(this, tr("WARINIG!!!"),
                 tr("PLEASE FILL IN THE EMPTY FIELDS."));
         }// end fucntion
         else
         {
             if (QRY_FAIL == result)
             {
                 msgBox.critical(this, tr("CRITICAL!!!"),
                     tr("INVALID QUERY."));
             }// end if
             else
             {
                 if (QRY_SUCCESS == result)
                 {
                     msgBox.information(this, tr("SUCCESS!!"),
                         tr("ACCOUNT MADE."));
                     pRegisterD->clearRegData();
                 }

             }// end else
         }// end else

     }// end if 
     else
     {
         if (1 == ui.tableComboBox->currentIndex())
         {
             pEmoloyeeDialog->exec();


         }// end if 
         else
         {
             if (2 == ui.tableComboBox->currentIndex())
             {
                 // Call dialog
             }// end if 
             else
             {
                 if (3 == ui.tableComboBox->currentIndex())
                 {
                     // Call dialog
                 }// end if 
             }// end else 

         }// end else

     }// end else 
     
 }
    
 

 //*********************************************************************************
 //
 //*********************************************************************************
 void MainWindow::on_edit_triggerd()
 {

 }


 //*********************************************************************************
 //
 //*********************************************************************************
 void MainWindow::on_delete_triggerd()
 {


 }


//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_addButton_clicked()
{


}//end function 



//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_actionRegister_triggered()
{

    int result;
    QMessageBox msgBox;
   

   pRegisterD->exec();
   
   result = pDataBase->regUserQuery(pRegisterD->getUserRegInfo());

    
    if (EMPTY_FIELD == result)
    {
        msgBox.warning(this, tr("WARINIG!!!"),
            tr("PLEASE FILL IN THE EMPTY FIELDS."));
    }// end fucntion
    else
    {
        if (QRY_FAIL == result)
        {
            msgBox.critical(this, tr("CRITICAL!!!"),
                tr("INVALID QUERY."));
        }// end if
        else
        {
            if (QRY_SUCCESS == result)
            {
                msgBox.information(this, tr("SUCCESS!!"),
                    tr("ACCOUNT MADE."));
                pRegisterD->clearRegData();
            }
           
        }// end else
    }// end else
    

}// end function 





//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_actionLogin_triggered()
{
    int result;
    QMessageBox msgBox;
    QString userName;

    LoginDialog* pLoginDlg = new LoginDialog();

    pLoginDlg->exec();

    pUserMain = pLoginDlg->getUserLogData();
    result = pDataBase->logUserQuery(pUserMain);


    if (EMPTY_FIELD == result)
    {
        msgBox.warning(this, tr("WARINIG!!!"),
            tr("PLEASE FILL IN THE EMPTY FIELDS."));
    }// end fucntion
    else
    {
        if (QRY_FAIL == result)
        {
            msgBox.critical(this, tr("CRITICAL!!!"),
                tr("INVALID QUERY."));
        }// end if
        else
        {
            if (!pUserMain->getLoginFlag())
            {
                msgBox.warning(this, tr("WARNING!!!"),
                    tr("ACCOUNT DOES NOT EXIST."));
            }
            else
            {
                msgBox.information(this, tr("SUCCESS!!!"),
                    tr("LOGGINED IN."));
                userName = QString::fromStdString(pUserMain->getUsername());
                setLoginWidget(userName);

            }// end else
        }// end else
    }// end else

}// end function 



//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_actionAddDoctor_triggered()
{
    pDoctor->exec();
    QMessageBox msgBox;


    switch (pDataBase->docAddQuery(pDoctor->getDcoInfo()))
    {
    case 0:
        msgBox.critical(this, tr("Error"), tr("Query Failed!!!"));
        break;

    case 1:
        msgBox.information(this, tr("SUCCESS"), tr("Doctor registered"));
        break;

        case 2:
            msgBox.warning(this, tr("Warning"), tr("Empty Fields"));
            break;

    case 3:
        msgBox.warning(this, tr("Error"), tr("Please Register The Doctor As An Employee First"));
        break;
    }// end switch 
}


//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_actionEmployeeUpdate_triggered()
{
    pUdateEmpDialog->exec();
    

}// end function 


//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_loadTableButton_clicked()
{
    QMessageBox msgBox;
    QSqlQueryModel* pQmodel = new QSqlQueryModel();

    switch (ui.tableComboBox->currentIndex())
    {
    
    case 0:
        pQmodel = pDataBase->employeeLoadTableQry();
        if (pQmodel == nullptr)
        {
            msgBox.warning(this, tr("WARNING!!!"), tr("Please Check Model."));
        }// end if 
        else
        {
            ui.tableView->setModel(pQmodel);
            //tBSlotandSignalConnect();

        }// end else 
        break;

    case 1:
        pQmodel = pDataBase->patientLoadTableQry();
        if (pQmodel == nullptr)
        {
            msgBox.warning(this, tr("WARNING!!!"), tr("Please Check Model."));
        }// end if 
        else
        {
            ui.tableView->setModel(pQmodel);
            //tBSlotandSignalConnect();

        }// end else
        break;

    case 2:
        pQmodel = pDataBase->doctorLoadTableQry();
        if (pQmodel == nullptr)
        {
            msgBox.warning(this, tr("WARNING!!!"), tr("Please Check Model."));
        }// end if 
        else
        {
            ui.tableView->setModel(pQmodel);
            //tBSlotandSignalConnect();

        }// end else
        break;

    }

}



//*********************************************************************************
//
//*********************************************************************************
Employee* MainWindow::getEmpInfo()
{
    Employee* pEmpU = new Employee();


    if (!ui.searchByUserEdit->text().toStdString().empty())
    {
        pEmpU->setEmpID(stoi(ui.searchByUserEdit->text().toStdString()));
    }// end if 
    else
    {
        pEmpU = nullptr;
    }// end else 

    return pEmpU;
}// end function 


//*********************************************************************************
//
//*********************************************************************************
Patient* MainWindow::getPatientInfo()
{
    Patient* pPatient = new Patient(this);


    if (!ui.searchByUserEdit->text().toStdString().empty())
    {
        pPatient->setPatientID(stoi(ui.searchByUserEdit->text().toStdString()));
    }// end if 
    else
    {
        pPatient = nullptr;
    }// end else 

    return pPatient;
}// end function 



//*********************************************************************************
//
//*********************************************************************************
Doctor* MainWindow::getDocInfo()
{
    Doctor* pDoc = new Doctor(this);


    if (!ui.searchByUserEdit->text().toStdString().empty())
    {
        pDoc->setDocId(stoi(ui.searchByUserEdit->text().toStdString()));
    }// end if 
    else
    {
        pDoc = nullptr;
    }// end else 

    return pDoc;
}// end function 




//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_findButton_clicked()
{
    QMessageBox msgBox;
    
    switch (ui.tableComboBox->currentIndex())
    {
   
    case 0:
      
        if (pDataBase->findEmployee(getEmpInfo()) == QRY_SUCCESS)
        {
            ui.tableView->reset();
            ui.tableView->setModel(MysqlDataBase::pStaticQModel);
        }
        else
        {
            if (pDataBase->findEmployee(getEmpInfo()) == QRY_FAIL)
            {
                msgBox.critical(this, tr("CRITICAL!!!"),
                    tr("INVALID QUERY."));
            }// end if 
            else
            {
                if (pDataBase->findEmployee(getEmpInfo()) == EMPTY_FIELD)
                {
                    msgBox.warning(this, tr("WARINIG!!!"),
                    tr("PLEASE FILL IN THE EMPTY FIELDS."));
                }// end if 
                else
                {
                    if (pDataBase->findEmployee(getEmpInfo()) == INVALID_ID)
                    {
                        msgBox.warning(this, tr("WARINIG!!!"),
                            tr("INVALID ID."));
                    }
                }// end else
            }// end else
        }// end else 
         
        break;

    case 1:
      

        if (pDataBase->findPatient(getPatientInfo()) == QRY_SUCCESS)
        {
            ui.tableView->reset();
            ui.tableView->setModel(MysqlDataBase::pStaticQModel);
        }// end if 
          else
          {
              if (pDataBase->findPatient(getPatientInfo()) == QRY_FAIL)
              {
                  msgBox.critical(this, tr("CRITICAL!!!"),
                  tr("INVALID QUERY."));
              }// end if 
              else
              {
                  if (pDataBase->findPatient(getPatientInfo()) == EMPTY_FIELD)
                  {
                      msgBox.warning(this, tr("WARINIG!!!"),
                          tr("PLEASE FILL IN THE EMPTY FIELDS."));
                  }// end if 
                  else
                  {
                      if (pDataBase->findPatient(getPatientInfo()) == INVALID_ID)
                      {
                          msgBox.warning(this, tr("WARINIG!!!"),
                              tr("INVALID ID."));
                      }
                  }// end else 
              }// end else 

          }// end else 

               
        break;

    case 2:

        if (pDataBase->findDoctor(getDocInfo()) == QRY_SUCCESS)
        {
            ui.tableView->reset();
            ui.tableView->setModel(MysqlDataBase::pStaticQModel);
        }
        else
        {
            if (pDataBase->findDoctor(getDocInfo()) == QRY_FAIL)
            {
                msgBox.critical(this, tr("CRITICAL!!!"),
                    tr("INVALID QUERY."));
            }// end if 
            else
            {
                if (pDataBase->findDoctor(getDocInfo())  == EMPTY_FIELD)
                {
                    msgBox.warning(this, tr("WARINIG!!!"),
                        tr("PLEASE FILL IN THE EMPTY FIELDS."));
                }// end if 
                else
                {
                    if (pDataBase->findDoctor(getDocInfo()) == INVALID_ID)
                    {
                        msgBox.warning(this, tr("WARINIG!!!"),
                            tr("INVALID ID."));
                    }
                }// end else
            }// end else
        }// end else 
       
        break;

    }// end switch 


}// end function 

//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_actionAddEmployee_triggered()
{
    pEmoloyeeDialog->exec();
    QMessageBox msgBox;
    
    int result = pDataBase->empAddQuery(pEmoloyeeDialog->getEmployeeInfo());

    if (EMPTY_FIELD == result)
    {
        msgBox.warning(this, tr("WARINIG!!!"),
            tr("PLEASE FILL IN THE EMPTY FIELDS."));
    }// end fucntion
    else
    {
        if (QRY_FAIL == result)
        {
            msgBox.critical(this, tr("CRITICAL!!!"),
                tr("INVALID QUERY."));
        }// end if
        else
        {
            if (QRY_SUCCESS == result)
            {
                msgBox.information(this, tr("SUCCESS!!"), tr(" Employee Stored."));
             
            }
         
       }// end else
    }// end else

}// end function 


//*********************************************************************************
//
//*********************************************************************************
void MainWindow::on_actionAddPatient_triggered()
{
    pPatient->exec();
    QMessageBox msgBox;

    switch (pDataBase->patientAddQuery(pPatient->getPatient()))
    {
    case 0:
        msgBox.critical(this, tr("Error"), tr("Query Failed!!!"));
        break;

    case 1:
        msgBox.information(this, tr("SUCCESS"), tr("Patient registered"));
        break;
    
    case 2:
        msgBox.warning(this, tr("Warning"), tr("Empty Fields"));
        break;


    case 3:
        msgBox.warning(this, tr("Error"), tr("Please Register The Doctor As An Employee First"));
        break;
    }// end switch 
    

}// end function 


//*********************************************************************************
//
//*********************************************************************************
void MainWindow::setLoginWidget(QString user)
{
     
    ui.displayUserLable->setText(user); 
    ui.actionAddEmployee->setEnabled(true);
    ui.actionAddPatient->setEnabled(true);
    ui.actionEmployeeRemove->setEnabled(true);
    ui.actionPatientRemove->setEnabled(true);
    ui.actionEmployeeUpdate->setEnabled(true);
    ui.actionPatientUpdate->setEnabled(true);
    ui.actionAddDoctor->setEnabled(true);
    ui.actionRemoveDoctor->setEnabled(true);
  
}


//*********************************************************************************
//
//*********************************************************************************
void MainWindow::setStySheet()
{
    window()->layout()->setSizeConstraint(QLayout::SetFixedSize);
    
  
}
