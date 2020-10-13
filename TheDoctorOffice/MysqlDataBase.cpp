#include "MysqlDataBase.h"

QSqlQueryModel* pQueryModel;
QSqlDatabase secondDB;
FindEmployeeDialog* pEmpDialog;

//*******************************************************************************
//
//*******************************************************************************
MysqlDataBase::MysqlDataBase(QObject *parent)
	: QObject(parent)
{
	initalize();


	connection = mysql_init(0);

	if (!mysql_real_connect(connection,
		hostname,
		username,
		password,
		databaseName,
		port, NULL, 0))
	{
		result = CON_FAIL;
		
	}// end if
	else
	{
		result = CON_SUCCESS;
		secondDBconnection();
	}// end else 

	


}


//*******************************************************************************
//
//*******************************************************************************
void MysqlDataBase::secondDBconnection()
{
	
	bool conStatus = false;

	secondDB.setHostName(hostname);
	secondDB.setDatabaseName(databaseName);
	secondDB.setUserName(username);
	secondDB.setPassword(password);

	conStatus = secondDB.open();
	if (!conStatus)
	{
		qDebug() << "Second Connection Failed";

	}// end if
	else
	{
		qDebug() << "Second Connection Valid";
	}// end else 

}



//*******************************************************************************
//
//*******************************************************************************
int MysqlDataBase::logUserQuery(User* pObj)
{
	int queryReturn;


	stringstream sSql;
	stringstream sUserid;

	MYSQL_RES* pResultSet;
	MYSQL_ROW row;

	int userID;
	string firstName;
	string lastName;
	string username = pObj->getUsername();
	string pass = pObj->getPassword();
	bool loginFlag = false;

	if (!username.empty() && !pass.empty())
	{
		sSql << "SELECT * from users ";
		// Exception here.
		queryReturn = mysql_query(connection, sSql.str().c_str());
		if (!queryReturn)
		{
			pResultSet = mysql_store_result(connection);
			while ((row = mysql_fetch_row(pResultSet)) != NULL && !pObj->getLoginFlag())
			{
				if (username == row[1] && pass == row[4])
				{
					sUserid << row[0];
					sUserid >> userID;
					firstName = row[2];
					lastName = row[3];
					loginFlag = true;
					setUserData(pObj, userID, username, firstName,
						lastName, pass, loginFlag);
					
				}// end if 

			}// end while 

			return QRY_SUCCESS;
		}// end if 
		else
		{
			return QRY_FAIL;
		}// end else
	}// end if
	else
	{
		return EMPTY_FIELD;
	}// end else 


}// end function 


//*******************************************************************************
//
//*******************************************************************************
int MysqlDataBase::empAddQuery(Employee* employee)
{



	int queryReturn;
	//stringstream sSEmpID, sSEmpDouble, sSEmpAge, sSQL;
	
	/*
	string empID;
	string empAge;
	string empSalary;
	*/
	
	stringstream sSEmpID;
	stringstream sSEmpDouble;
	stringstream sSEmpAge;
	stringstream sSQL;
	stringstream empFirstName;
	stringstream empLastName;
	stringstream empAddress;
	stringstream empPhoneNumber;
	stringstream empSpecialty;
	stringstream empGender;


	sSEmpID << employee->getEmpID();
    empFirstName << employee->getFname();
	empLastName << employee->getLname();
	sSEmpAge << employee->getAge();
	 empAddress << employee->getStreetAdd();
	 empPhoneNumber << employee->getPhoneNum();
	 empSpecialty << employee->getSpecialty();
	 empGender << employee->getGender();
	sSEmpDouble << employee->getSalary();
	



	if (!sSEmpID.str().empty() && !empFirstName.str().empty() && !empLastName.str().empty()
		&& !sSEmpAge.str().empty() && !empAddress.str().empty() && !empPhoneNumber.str().empty()
		&& !empSpecialty.str().empty() && !sSEmpDouble.str().empty() && !empGender.str().empty())
	{
		sSQL << "INSERT INTO employee ( idEmployee, firstname, lastname,"
			" age, address, salary, gender, phonenumber, position)"
			<< " VALUES " << "(" << sSEmpID.str() << ", '" << empFirstName.str() << "', '" << empLastName.str() << "', " <<
			sSEmpAge.str() << ", '" << empAddress.str() << "', " << sSEmpDouble.str() << ", '" << empGender.str() << "', '" <<
			empPhoneNumber.str() << "', '" << empSpecialty.str() << "')";

		
			queryReturn = mysql_query(connection, sSQL.str().c_str());

			if (!queryReturn)
			{
				return QRY_SUCCESS;
			}// end if 
			else
			{
				return QRY_FAIL;
			}// end else 
		}// end if  
		else
		{
			return EMPTY_FIELD;
		}
	
	 
}// end function 



//*******************************************************************************
//
//*******************************************************************************
User* MysqlDataBase::setUserData(User* pObj, int userId, string userName,
	string firstName, string lastName, string pass, bool loginFlag)
{
	pObj->setUserID(userId);
	pObj->setUsername(userName);
	pObj->setFname(firstName);
	pObj->setLname(lastName);
	pObj->setPassword(pass);
	pObj->setLoginFlag(loginFlag);
	return pObj;
}// end function 

//*******************************************************************************
//
//*******************************************************************************
QSqlQueryModel* MysqlDataBase::userLoadTableQry()
{
	//open database
	QSqlQuery* query = new QSqlQuery(secondDB);
	
	query->prepare("SELECT * FROM users");

	
		if (query->exec())
	{
			pQueryModel->setQuery(*query);
	}// end if

	else
	{
		qDebug() << "Not Loaded";
	}
	return pQueryModel;
}// end fucntion 

//*******************************************************************************
//
//*******************************************************************************
QSqlQueryModel* MysqlDataBase::doctorLoadTableQry()
{
	//open database
	QSqlQuery* query = new QSqlQuery(secondDB);

	query->prepare("SELECT * FROM doctor");


	if (query->exec())
	{
		pQueryModel->setQuery(*query);
	}// end if

	else
	{
		qDebug() << "Not Loaded";
	}
	return pQueryModel;
}// end fucntion

//*******************************************************************************
//
//*******************************************************************************
QSqlQueryModel* MysqlDataBase::patientLoadTableQry()
{
	//open database
	QSqlQuery* query = new QSqlQuery(secondDB);

	query->prepare("SELECT * FROM patient");


	if (query->exec())
	{
		pQueryModel->setQuery(*query);
	}// end if

	else
	{
		qDebug() << "Not Loaded";
	}
	return pQueryModel;
}// end fucntion


//*******************************************************************************
//
//*******************************************************************************
QSqlQueryModel* MysqlDataBase::employeeLoadTableQry()
{
	//open database
	QSqlQuery* query = new QSqlQuery(secondDB);

	query->prepare("SELECT * FROM employee");


		if (query->exec())
	{
			pQueryModel->setQuery(*query);
	}// end if

	else
	{
		qDebug() << "Not Loaded";
	}
	return pQueryModel;
}// end fucntion



//*******************************************************************************
//
//*******************************************************************************
QSqlQueryModel* MysqlDataBase::findEmpTableQry(Employee* emp)
{
	QSqlQuery* query = new QSqlQuery(secondDB);
	stringstream sSql;
	
	sSql << "SELECT * from doctorsoffice.employee WHERE"<<"(idEmployee = "<< emp->getEmpID()<<")";
	
	query->prepare(sSql.str().c_str());

	if (query->exec())
	{
		pQueryModel->setQuery(*query);
	}// end if 
		else
		{
			qDebug() << "Not Loaded";
		}// end else 

	return pQueryModel;
}// end function 

//*******************************************************************************
//
//******************************************************************************
QSqlQueryModel* MysqlDataBase::findDoctorTableQry(Doctor* pDoc)
{
	QSqlQuery* query = new QSqlQuery(secondDB);
	stringstream sSql;

	sSql << "SELECT * from doctorsoffice.doctor WHERE" << "(iddoctor = " << pDoc->getDocId() << ")";

	query->prepare(sSql.str().c_str());

	if (query->exec())
	{
		pQueryModel->setQuery(*query);
	}// end if 
	else
	{
		qDebug() << "Not Loaded";
	}// end else 

	return pQueryModel;
}// end function 



//*******************************************************************************
//
//******************************************************************************
QSqlQueryModel* MysqlDataBase::findPatientTableQry(Patient* patient)
{
	QSqlQuery* query = new QSqlQuery(secondDB);
	stringstream sSql;

	sSql << "SELECT * from doctorsoffice.patient WHERE" << "(idpatient = " << patient->getPatientID()<< ")";

	query->prepare(sSql.str().c_str());

	if (query->exec())
	{
		pQueryModel->setQuery(*query);
	}// end if 
	else
	{
		qDebug() << "Not Loaded";
	}// end else 

	return pQueryModel;
}// end function 

//*******************************************************************************
//
//*******************************************************************************
int MysqlDataBase::regUserQuery(User* pObj)
{


	int queryReturn;
	stringstream sSql;
	stringstream sUserID;
	stringstream sUserName;
	stringstream sFirstName;
	stringstream sLastName;
	stringstream sPass;

	sUserID << pObj->getUserID();
	sUserName << pObj->getUsername();
	sFirstName << pObj->getFname();
	sLastName << pObj->getLname();
	sPass << pObj->getPassword();


	if (!sUserID.str().empty() && !sUserName.str().empty() && !sFirstName.str().empty()
		&& !sLastName.str().empty() && !sPass.str().empty())
	{
		sSql << "INSERT INTO users ( userID, usernameID, firstname, lastname, password)"
			<< "VALUES " << "(" << sUserID.str().c_str() << ", '" << sUserName.str().c_str()
			<< "', '" << sFirstName.str().c_str() << "', '" << sLastName.str().c_str() << "' , '"
			<< sPass.str().c_str() << "')";

		if (connection)
		{

			queryReturn = mysql_query(connection, sSql.str().c_str());

			if (!queryReturn)
			{
				return QRY_SUCCESS;
			}// end if 
			else
			{
				return QRY_FAIL;
			}// end else 
		}
	}// end if 
	else
	{
		return EMPTY_FIELD;
	}
}



//*******************************************************************************
//
//*******************************************************************************
int MysqlDataBase::updatePatient(Patient* pPatient)
{
	MYSQL_RES* pResult;
	MYSQL_ROW row;

	int queryReturn;

	stringstream sDoc;
	stringstream sPaitent;

	string docId;

	bool flag = false;

	sDoc << "SELECT * from doctor ";

	queryReturn = mysql_query(connection, sDoc.str().c_str());
	pResult = mysql_store_result(connection);

	if (pPatient != nullptr)
	{
		while ((row = mysql_fetch_row(pResult)) != NULL && !flag)
		{
			docId = row[0];
			if (stoi(docId) == pPatient->getDocID())
			{
				//UPDATE doctorsoffice.patient SET iddoctor =  1234  
				//WHERE(idpatient = 9000);
				sPaitent << "UPDATE patient SET iddoctor = " << pPatient->getDocID() << " WHERE ( idpatient ="
						 << pPatient->getPatientID() << ")";

				queryReturn = mysql_query(connection, sPaitent.str().c_str());
				if (!queryReturn)
				{
					return QRY_SUCCESS;
				}// end if
				else
				{
					return QRY_FAIL;
				}//end else	

				flag = true;
			}// end if 
		}// end while

	}// end if
	else
	{
		return EMPTY_FIELD;
	}// end else
	if (!flag)
	{
		return INVALID_ID;
	}// end if 

}// end function 


//*******************************************************************************
//
//*******************************************************************************
int MysqlDataBase::patientAddQuery(Patient* patient)
{
	MYSQL_RES* pResult;
	MYSQL_ROW row;
	
	int queryReturn;
	
	stringstream sDoc;
	stringstream sPaitent;

	string docId;

	bool flag = false;

	sDoc << "SELECT * from doctor ";
	
	queryReturn = mysql_query(connection, sDoc.str().c_str());
	pResult = mysql_store_result(connection);

	if (!to_string(patient->getPatientID()).empty() && !patient->getFname().empty()
		&& !patient->getLname().empty() && !patient->getGender().empty() && !patient->getDOB().empty()
		&& !patient->getPhoneNum().empty() && !to_string(patient->getDocID()).empty())
	{
		while ((row = mysql_fetch_row(pResult)) != NULL && !flag)
		{
			docId = row[0];
			if (stoi(docId) == patient->getDocID())
			{
				sPaitent << "INSERT INTO doctorsoffice.patient (idpatient, firstname, lastname, "
					"gender, DOB, phonenumber, iddoctor)"
					"VALUES" "(" << patient->getPatientID() << " ,'" << patient->getFname()
					<< "', '" << patient->getLname() << "', '" << patient->getGender() << "', '"
					<< patient->getDOB() << "', '" << patient->getPhoneNum() << "', " << patient->getDocID()
					<< ")";
				queryReturn = mysql_query(connection, sPaitent.str().c_str());
				if (!queryReturn)
				{
					return QRY_SUCCESS;
				}// end if
				else
				{
					return QRY_FAIL;
				}//end else	

				flag = true;
			}// end if 
		}// end while
			
	}// end if
	else
	{
		return EMPTY_FIELD;
	}// end else
		if (!flag)
		{
			return INVALID_ID;
		}// end if 
	

}// end function 


//*******************************************************************************
//
//*******************************************************************************
void MysqlDataBase::addNewTableData(int data)
{


}// end function 

//*******************************************************************************
//
//*******************************************************************************
MYSQL* MysqlDataBase::getConnection()
{
	return this->connection;
}



//*********************************************************************************
//
//*********************************************************************************
int MysqlDataBase::docAddQuery(Doctor* doc)
{
	bool flag = false;
	
	string rowID;

	MYSQL_RES* pResultSet;
	MYSQL_ROW row;
	
	stringstream sSql;
	stringstream sStream;
	stringstream sPositon;
	
	int com;
	int queryReturn, docID;

	
	sSql << "SELECT * from employee ";
	queryReturn = mysql_query(connection, sSql.str().c_str());
	if (!queryReturn)
	{
		pResultSet = mysql_store_result(connection);
		if (!to_string(doc->getDocId()).empty() && !doc->getDocSpecialty().empty())
		{
			while ((row = mysql_fetch_row(pResultSet)) != NULL)
			{
	
				rowID = row[0];
				docID = stoi(rowID);
				sPositon << row[8];

				com = strncmp(sPositon.str().c_str(), "Doctor", strlen("Doctor"));
				sPositon.str("");

				if (docID == doc->getDocId() && !com && !flag)
				{

					sStream << "INSERT INTO doctor ( iddoctor, specialty)"
						<< "VALUES " << "(" << doc->getDocId() << ", '" << doc->getDocSpecialty() << "')";
					queryReturn = mysql_query(connection, sStream.str().c_str());
					if (!queryReturn)
					{
						return QRY_SUCCESS;
					}// end if 
					else
					{
						return QRY_FAIL;
					}// end else 
					flag = true;
				}// end if 

			}//end while
		}// end if 
		else
		{
			return EMPTY_FIELD;
		}// end if 
			 if(!flag)
			{
				 return INVALID_ID;
			}// end if 
	}

}// end function 



//*********************************************************************************
//
//*********************************************************************************
int MysqlDataBase::findEmployee(Employee* pEmp)
{
	
	
	int queryReturn;
	MYSQL_RES* pResultSet;
	MYSQL_ROW row;
	
	stringstream sSql;
	stringstream sSEmp;

	bool flag = false;
	


	if (pEmp != nullptr)
	{

		sSql << "SELECT* from employee";
		queryReturn = mysql_query(connection, sSql.str().c_str());
		if (!queryReturn)
		{
			pResultSet = mysql_store_result(connection);

			while ((row = mysql_fetch_row(pResultSet)) != nullptr)
			{
				if (row[0] == to_string(pEmp->getEmpID()))
				{	
					 pStaticQModel = findEmpTableQry(pEmp);
					 flag = true;
				}// end if 
			}// end while 
		
			if (flag)
			{
				return QRY_SUCCESS;
			}// end if
				else
				{
				return INVALID_ID;
				}// end else 
		}//endif
			else
			{
			return QRY_FAIL;
			}// end else
	}// endif
		else
		{
			return EMPTY_FIELD;
		}// end else

}// end function 

//*********************************************************************************
//
//*********************************************************************************
int MysqlDataBase::deleteEmployee(Employee* pEmp)
{

	
	int queryReturn;
	MYSQL_RES* pResultSet;
	MYSQL_ROW row;

	stringstream sSql;
	stringstream sSDel;

	bool flag = false;

	//DELETE FROM doctorsoffice.users WHERE(userID = 667);

	if (pEmp != nullptr)
	{

		sSql << "SELECT* from employee";
		queryReturn = mysql_query(connection, sSql.str().c_str());
		if (!queryReturn)
		{
			pResultSet = mysql_store_result(connection);

			while ((row = mysql_fetch_row(pResultSet)) != nullptr)
			{
				if (row[0] == to_string(pEmp->getEmpID()))
				{
					flag = true;
					sSDel << "DELETE FROM employee WHERE" << "(idEmployee = "
						<< pEmp->getEmpID() << ")";
					
					queryReturn = mysql_query(connection, sSDel.str().c_str());
					if (!queryReturn)
					{
		
						return QRY_SUCCESS;
					}// end if 
						else
						{
							return QRY_FAIL;
						}// end else 
				}// end if 
			}// end while 

			if(!flag)
			{
				return INVALID_ID;
			}// end if
		}//endif
		else
		{
			return QRY_FAIL;
		}// end else
	}// endif
	else
	{
		return EMPTY_FIELD;
	}// end else
	

}// end function 

//*********************************************************************************
//
//*********************************************************************************
int MysqlDataBase::deletePatient(Patient* pPatient)
{

	
	int queryReturn;
	MYSQL_RES* pResultSet;
	MYSQL_ROW row;

	stringstream sSql;
	stringstream sSDel;

	bool flag = false;


	if (pPatient != nullptr)
	{

		sSql << "SELECT* from patient";
		queryReturn = mysql_query(connection, sSql.str().c_str());
		if (!queryReturn)
		{
			pResultSet = mysql_store_result(connection);

			while ((row = mysql_fetch_row(pResultSet)) != nullptr)
			{
				if (row[0] == to_string(pPatient->getPatientID()))
				{
					flag = true;
					sSDel << "DELETE FROM patient WHERE" << "(idpatient = "
						<< pPatient->getPatientID() << ")";

					queryReturn = mysql_query(connection, sSDel.str().c_str());
					if (!queryReturn)
					{

						return QRY_SUCCESS;
					}// end if 
					else
					{
						return QRY_FAIL;
					}// end else 
				}// end if 
			}// end while 

			if (!flag)
			{
				return INVALID_ID;
			}// end if
		}//endif
		else
		{
			return QRY_FAIL;
		}// end else
	}// endif
	else
	{
		return EMPTY_FIELD;
	}// end else

}// end function 

//*********************************************************************************
//
//*********************************************************************************
int MysqlDataBase::deleteDoctor(Doctor* pDoc)
{


	int queryReturn;
	MYSQL_RES* pResultSet;
	MYSQL_ROW row;

	stringstream sSql;
	stringstream sSDel;

	bool flag = false;


	if (pDoc != nullptr)
	{

		sSql << "SELECT* from doctor";
		queryReturn = mysql_query(connection, sSql.str().c_str());
		if (!queryReturn)
		{
			pResultSet = mysql_store_result(connection);

			while ((row = mysql_fetch_row(pResultSet)) != nullptr)
			{
				if (row[0] == to_string(pDoc->getDocId()))
				{
					flag = true;
					sSDel << "DELETE FROM patient WHERE" << "(iddoctor = "
						<< pDoc->getDocId() << ")";

					queryReturn = mysql_query(connection, sSDel.str().c_str());
					if (!queryReturn)
					{

						return QRY_SUCCESS;
					}// end if 
					else
					{
						return QRY_FAIL;
					}// end else 
				}// end if 
			}// end while 

			if (!flag)
			{
				return INVALID_ID;
			}// end if
		}//endif
		else
		{
			return QRY_FAIL;
		}// end else
	}// endif
	else
	{
		return EMPTY_FIELD;
	}// end else

}// end function 


//*********************************************************************************
//
//*********************************************************************************
int MysqlDataBase::findPatient(Patient* pPatient)
{


	int queryReturn;
	MYSQL_RES* pResultSet;
	MYSQL_ROW row;

	stringstream sSql;
	stringstream sSEmp;
	
	bool flag = false;


	if (pPatient != nullptr)
	{

		sSql << "SELECT* from patient";
		queryReturn = mysql_query(connection, sSql.str().c_str());
		if (!queryReturn)
		{
			pResultSet = mysql_store_result(connection);

			while ((row = mysql_fetch_row(pResultSet)) != nullptr)
			{
				if (row[0] == to_string(pPatient->getPatientID()))
				{
					pStaticQModel = findPatientTableQry(pPatient);
					flag = true;
				}// end if 
			}// end while 
			
			if (flag)
			{
				return QRY_SUCCESS;
			}// end if
			else
			{
				return INVALID_ID;
			}// end else 
		}//endif
		else
		{
			return QRY_FAIL;
		}// end else
	}// endif
	else
	{
		return EMPTY_FIELD;
	}// end else
}// end function


 //*********************************************************************************
//
//**********************************************************************************
int MysqlDataBase::updateEmpLname(Employee* pEmp)

{

	int queryReturn;
	MYSQL_RES* pResultSet;
	MYSQL_ROW row;

	stringstream sSql;
	stringstream sSUpdate;

	bool flag = false;


	if (pEmp != nullptr)
	{

		sSql << "SELECT* from employee";
		queryReturn = mysql_query(connection, sSql.str().c_str());
		if (!queryReturn)
		{
			pResultSet = mysql_store_result(connection);

			while ((row = mysql_fetch_row(pResultSet)) != nullptr)
			{
				if (row[0] == to_string(pEmp->getEmpID()))
				{
					flag = true;
					sSUpdate << "UPDATE employee SET lastname = " << " '" << pEmp->getLname() << "' " << "WHERE"
						<< "( idEmployee = " << pEmp->getEmpID() << ")";
						
					queryReturn = mysql_query(connection, sSUpdate.str().c_str());
					if (!queryReturn)
					{

						return QRY_SUCCESS;
					}// end if 
					else
					{
						return QRY_FAIL;
					}// end else 
				}// end if 
			}// end while 

			if (!flag)
			{
				return INVALID_ID;
			}// end if
		}//endif
		else
		{
			return QRY_FAIL;
		}// end else
	}// endif
	else
	{
		return EMPTY_FIELD;
	}// end else
	
}// end function 


 //*********************************************************************************
//
//**********************************************************************************
int MysqlDataBase::updateEmpAge(Employee* pEmp)

{

	int queryReturn;
	MYSQL_RES* pResultSet;
	MYSQL_ROW row;

	stringstream sSql;
	stringstream sSUpdate;

	bool flag = false;


	if (pEmp != nullptr)
	{

		sSql << "SELECT* from employee";
		queryReturn = mysql_query(connection, sSql.str().c_str());
		if (!queryReturn)
		{
			pResultSet = mysql_store_result(connection);

			while ((row = mysql_fetch_row(pResultSet)) != nullptr)
			{
				if (row[0] == to_string(pEmp->getEmpID()))
				{
					flag = true;
					//UPDATE `doctorsoffice`.`employee` SET `phonenumber` = '1234-687-7' WHERE (`idEmployee` = '1234');
					sSUpdate << "UPDATE employee SET age = " << " '" << pEmp->getAge() << "' " << "WHERE"
						<< "( idEmployee = " << pEmp->getEmpID() << ")";

					queryReturn = mysql_query(connection, sSUpdate.str().c_str());
					if (!queryReturn)
					{

						return QRY_SUCCESS;
					}// end if 
					else
					{
						return QRY_FAIL;
					}// end else 
				}// end if 
			}// end while 

			if (!flag)
			{
				return INVALID_ID;
			}// end if
		}//endif
		else
		{
			return QRY_FAIL;
		}// end else
	}// endif
	else
	{
		return EMPTY_FIELD;
	}// end else

}// end function 


 //*********************************************************************************
//
//**********************************************************************************
int MysqlDataBase::updateEmpAdd(Employee* pEmp)

{

	int queryReturn;
	MYSQL_RES* pResultSet;
	MYSQL_ROW row;

	stringstream sSql;
	stringstream sSUpdate;

	bool flag = false;


	if (pEmp != nullptr)
	{

		sSql << "SELECT* from employee";
		queryReturn = mysql_query(connection, sSql.str().c_str());
		if (!queryReturn)
		{
			pResultSet = mysql_store_result(connection);

			while ((row = mysql_fetch_row(pResultSet)) != nullptr)
			{
				if (row[0] == to_string(pEmp->getEmpID()))
				{
					flag = true;
					//UPDATE `doctorsoffice`.`employee` SET `phonenumber` = '1234-687-7' WHERE (`idEmployee` = '1234');
					sSUpdate << "UPDATE employee SET address = " << " '" << pEmp->getStreetAdd() << "' " << "WHERE"
						<< "( idEmployee = " << pEmp->getEmpID() << ")";

					queryReturn = mysql_query(connection, sSUpdate.str().c_str());
					if (!queryReturn)
					{

						return QRY_SUCCESS;
					}// end if 
					else
					{
						return QRY_FAIL;
					}// end else 
				}// end if 
			}// end while 

			if (!flag)
			{
				return INVALID_ID;
			}// end if
		}//endif
		else
		{
			return QRY_FAIL;
		}// end else
	}// endif
	else
	{
		return EMPTY_FIELD;
	}// end else

}// end function 

 //*********************************************************************************
//
//**********************************************************************************
int MysqlDataBase::updateEmpPhoneNum(Employee* pEmp)

{

	int queryReturn;
	MYSQL_RES* pResultSet;
	MYSQL_ROW row;

	stringstream sSql;
	stringstream sSUpdate;

	bool flag = false;


	if (pEmp != nullptr)
	{

		sSql << "SELECT* from employee";
		queryReturn = mysql_query(connection, sSql.str().c_str());
		if (!queryReturn)
		{
			pResultSet = mysql_store_result(connection);

			while ((row = mysql_fetch_row(pResultSet)) != nullptr)
			{
				if (row[0] == to_string(pEmp->getEmpID()))
				{
					flag = true;
					//UPDATE `doctorsoffice`.`employee` SET `phonenumber` = '1234-687-7' WHERE (`idEmployee` = '1234');
					sSUpdate << "UPDATE employee SET phonenumber = " << " '" << pEmp->getPhoneNum() << "' " << "WHERE"
						<< "( idEmployee = " << pEmp->getEmpID() << ")";

					queryReturn = mysql_query(connection, sSUpdate.str().c_str());
					if (!queryReturn)
					{

						return QRY_SUCCESS;
					}// end if 
					else
					{
						return QRY_FAIL;
					}// end else 
				}// end if 
			}// end while 

			if (!flag)
			{
				return INVALID_ID;
			}// end if
		}//endif
		else
		{
			return QRY_FAIL;
		}// end else
	}// endif
	else
	{
		return EMPTY_FIELD;
	}// end else

}// end function 

 //*********************************************************************************
//
//*********************************************************************************
int MysqlDataBase::findDoctor(Doctor* pDoctor)
{


	int queryReturn;
	MYSQL_RES* pResultSet;
	MYSQL_ROW row;

	stringstream sSql;
	stringstream sSEmp;

	bool flag = false;

	if (pDoctor != nullptr)
	{

		sSql << "SELECT* from doctor";
		queryReturn = mysql_query(connection, sSql.str().c_str());
		if (!queryReturn)
		{
			pResultSet = mysql_store_result(connection);

			while ((row = mysql_fetch_row(pResultSet)) != nullptr)
			{
				if (row[0] == to_string(pDoctor->getDocId()))
				{
					pStaticQModel = findDoctorTableQry(pDoctor);
					flag = true;
				}// end if
			}// end while

			if (flag)
			{
				return QRY_SUCCESS;
			}// end if
			else
			{
				return INVALID_ID;
			}// end else 

		}//endif
		else
		{
			return QRY_FAIL;
		}// end else
	}// endif
	else
	{
		return EMPTY_FIELD;
	}// end else
}// end function




//*********************************************************************************
//
//*********************************************************************************
void MysqlDataBase::initalize()
{
	this->result = 0;
	this->hostname = "localhost";
	this->username = "root";
	this->password = "jamaican";
	this->databaseName = "doctorsoffice";
	this->port = 3306;
    pQueryModel = new QSqlQueryModel();
	secondDB = QSqlDatabase::addDatabase("QMYSQL", "second");
	pEmpDialog = new FindEmployeeDialog();
	
}// end function 


//*******************************************************************************
//
//*******************************************************************************
void MysqlDataBase::setResult(int data)
{
	this->result = data;
}

//*******************************************************************************
//
//*******************************************************************************
int MysqlDataBase::getResult()
{
	
	return result;
}

//*******************************************************************************
//
//*******************************************************************************
MysqlDataBase::~MysqlDataBase()
{
	mysql_close(connection);
	secondDB.close();
}
