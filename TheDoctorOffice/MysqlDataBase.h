#pragma once

#include <QObject>
#include <sstream>
#include <mysql.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include"User.h"
#include <stdbool.h>
#include <QtSql/qsqlquerymodel.h>
#include <qdebug.h>
#include <QtSql/qsqlquery.h>
#include "Employee.h"
#include "Doctor.h"
#include "Patient.h"
#include <string>
#include "FindEmployeeDialog.h"
#include "RemovePatientDialog.h"
 

using namespace std;

#define QRY_SUCCESS 1
#define QRY_FAIL    0
#define EMPTY_FIELD 2
#define INVALID_ID  3



#define CON_SUCCESS 1
#define CON_FAIL    0

class MysqlDataBase : public QObject
{
	Q_OBJECT

public:
	static QSqlQueryModel* pStaticQModel;
	
	MysqlDataBase(QObject *parent);
	~MysqlDataBase();

	void setResult(int data);
	void initalize();

	int getResult();
	MYSQL* getConnection();
	int regUserQuery(User* pObj);
	int logUserQuery(User* pObj);
	User* setUserData(User* pObj, int userId, string userName,
		string firstName, string lastName, string pass, bool loginFlag);
	QSqlQueryModel* doctorLoadTableQry();
	QSqlQueryModel* patientLoadTableQry();
	QSqlQueryModel* employeeLoadTableQry();
	QSqlQueryModel* userLoadTableQry();
	QSqlQueryModel* findEmpTableQry(Employee* emp);
	void secondDBconnection();
	void addNewTableData(int data);
	int empAddQuery(Employee* employee);
	int docAddQuery(Doctor* doc);
	int patientAddQuery(Patient* patient);
	int findEmployee(Employee* pEmp);
	int findPatient(Patient* pPatient);
	int findDoctor(Doctor* pDoc);
	QSqlQueryModel* findPatientTableQry(Patient* patient);
	QSqlQueryModel* findDoctorTableQry(Doctor* pDoc);
	int deleteEmployee(Employee* pEmp);
	int deletePatient(Patient* pPatient);
	int deleteDoctor(Doctor* pDoc);
	int updateEmpLname(Employee* pEmp);
	int updateEmpPhoneNum(Employee* pEmp);
	int updateEmpAdd(Employee* pEmp);
	int updateEmpAge(Employee* pEmp);
	int updatePatient(Patient* pPatient);

private:
	int result;
	const char* hostname;
	const char* username;
	const char* password;
	const char* databaseName;
	int port;
	MYSQL* connection;
};
