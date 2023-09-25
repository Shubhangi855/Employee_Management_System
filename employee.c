
// employee.c

#include "employee.h"
#include <stdio.h>

void acceptEmployeeData(struct Employee *emp) {
    printf("Enter Employee Number: ");
    scanf("%d", &emp->Empno);

    printf("Enter Employee Name: ");
    scanf("%s", emp->EmpName);

    printf("Enter Hire Date (dd mm yy): ");
    scanf("%d %d %d", &emp->hiredate.dd, &emp->hiredate.mm, &emp->hiredate.yy);

    printf("Enter Basic Salary: ");
    scanf("%f", &emp->BasicSalary);
}

void calculateNetPay(struct Employee *emp) {
    emp->netSalary = emp->BasicSalary * (1 + 0.4 + 0.1 + 0.05);
}

void showEmployeeData(struct Employee emp) {
    printf("\nEmployee Number: %d\n", emp.Empno);
    printf("Employee Name: %s\n", emp.EmpName);
    printf("Hire Date: %02d-%02d-%02d\n", emp.hiredate.dd, emp.hiredate.mm, emp.hiredate.yy);
    printf("Basic Salary: %.2f\n", emp.BasicSalary);
    printf("Net Salary: %.2f\n", emp.netSalary);
}
void showById(struct Employee employees[], int numEmployees, int id) {
    int found = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].Empno == id) {
            showEmployeeData(employees[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void updateEmployeeData(struct Employee *emp) {
    int choice;
    printf("What do you want to update?\n");
    printf("1. Employee Number\n");
    printf("2. Employee Name\n");
    printf("3. Hire Date\n");
    printf("4. Basic Salary\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter new Employee Number: ");
            scanf("%d", &emp->Empno);
            break;
        case 2:
            printf("Enter new Employee Name: ");
            scanf("%s", emp->EmpName);
            break;
        case 3:
            printf("Enter new Hire Date (dd mm yy): ");
            scanf("%d %d %d", &emp->hiredate.dd, &emp->hiredate.mm, &emp->hiredate.yy);
            break;
        case 4:
            printf("Enter new Basic Salary: ");
            scanf("%f", &emp->BasicSalary);
            break;
        default:
            printf("Invalid choice. No updates made.\n");
            return;
    }

    // Recalculate net pay after updating data
    calculateNetPay(emp);
}
void deleteEmployee(struct Employee employees[], int *numEmployees, int id) {
    int found = 0;
    for (int i = 0; i < *numEmployees; i++) {
        if (employees[i].Empno == id) {
            // Shift remaining elements to the left to fill the gap
            for (int j = i; j < *numEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*numEmployees)--;
            found = 1;
            printf("Employee with ID %d has been deleted.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}
