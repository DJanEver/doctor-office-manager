#include "UpdateEmployeeDialog.h"


MysqlDataBase* pDataBaseUpdate;

//*******************************************************************************
//
//*******************************************************************************
UpdateEmployeeDialog::UpdateEmployeeDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
    pDataBaseUpdate = new MysqlDataBase(this);
}

//*******************************************************************************
//
//*******************************************************************************
void UpdateEmployeeDialog::on_editLNameAPushButton_clicked()
{
	UpdateLNClass* pUpdateLname = new UpdateLNClass();
	pUpdateLname->exec();
    QMessageBox msgBox;

    
    switch (pDataBaseUpdate->updateEmpLname(pUpdateLname->getEmpIdU()))
    {

    case QRY_SUCCESS:

        msgBox.information(this, tr("SUCCESS!!!"),
            tr("Employee Updated"));
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



//*******************************************************************************
//
//*******************************************************************************
void UpdateEmployeeDialog::on_editPhoneNumEPushButton_clicked()
{
    UpdateEmpPhoneNumDialog* pUpdateEmpPhoneNum = new UpdateEmpPhoneNumDialog();
    pUpdateEmpPhoneNum->exec();

    QMessageBox msgBox;


    switch (pDataBaseUpdate->updateEmpPhoneNum(pUpdateEmpPhoneNum->getEmpPH()))
    {

    case QRY_SUCCESS:

        msgBox.information(this, tr("SUCCESS!!!"),
            tr("Employee Updated"));
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


//*******************************************************************************
//
//*******************************************************************************
void UpdateEmployeeDialog::on_editAddressEPushButton_clicked()
{
    UpdateEmpAddress* pUpdateEmpAdd = new UpdateEmpAddress();
    pUpdateEmpAdd->exec();


        QMessageBox msgBox;


        switch (pDataBaseUpdate->updateEmpAdd(pUpdateEmpAdd->getEmpAdd()))
        {

        case QRY_SUCCESS:

            msgBox.information(this, tr("SUCCESS!!!"),
                tr("Employee Updated"));
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


//*******************************************************************************
//
//*******************************************************************************
void UpdateEmployeeDialog::on_editAgeEPushButton_clicked()
{
    UpdateEmpAge* pUpdateEmpAge = new UpdateEmpAge();
    pUpdateEmpAge->exec();
    
    QMessageBox msgBox;


    switch (pDataBaseUpdate->updateEmpAge(pUpdateEmpAge->getEmpAge()))
    {

    case QRY_SUCCESS:

        msgBox.information(this, tr("SUCCESS!!!"),
            tr("Employee Updated"));
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

//*******************************************************************************
//
//*******************************************************************************
UpdateEmployeeDialog::~UpdateEmployeeDialog()
{
}
