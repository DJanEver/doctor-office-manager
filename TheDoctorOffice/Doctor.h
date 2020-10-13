#pragma once

#include "Employee.h"



class Doctor : public Employee
{
    Q_OBJECT

public:
    Doctor(QObject* parent);
    ~Doctor();

    void setDocSpecialty(string specialty);
    void setDocId(int docId);

    

    int getDocId();
    string getDocSpecialty();
   
    void initalize();

private:
    string docSpecialty;
    int docID;

};
