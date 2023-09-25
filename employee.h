
// employee.h

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "validation_util.h"
struct Date {
    int dd, mm, yy;
};

struct Employee {
    int Empno;
    char EmpName[50];
    struct Date hiredate;
    float BasicSalary;
    float netSalary;
};

void managerMenu();
void acceptEmployeeData(struct Employee *emp);
void calculateNetPay(struct Employee *emp);
void showEmployeeData(struct Employee emp);
void showById(struct Employee employees[], int numEmployees, int id);
void updateEmployeeData(struct Employee *emp);
void deleteEmployee(struct Employee employees[], int *numEmployees, int id);
#endif
