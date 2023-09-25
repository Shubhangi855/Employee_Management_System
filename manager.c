
#include "employee.h"
#include <stdio.h>
#include "validation_util.h"

void managerMenu(){
    struct Employee employees[100];
    int numEmployees = 0;
    int choice, id;

    do {
        printf("\nSelect from options given below\n");
        printf("1. Add Employee\n");
        printf("2. Show Employee Detail\n");
        printf("3. Search Employee by Id\n");
        printf("4. Update Employee detail\n");
        printf("5. Delete Employee detail\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numEmployees < 100) {
                    struct Employee newEmployee;
                    acceptEmployeeData(&newEmployee);

                    // Validate employee data before adding
                    if (validateID(newEmployee.Empno) &&
                        validateLength(newEmployee.EmpName, 50) &&
                        validateName(newEmployee.EmpName) &&
                        validateDate(newEmployee.hiredate.dd, newEmployee.hiredate.mm, newEmployee.hiredate.yy)) {
                        calculateNetPay(&newEmployee);
                        employees[numEmployees] = newEmployee;
                        numEmployees++;
                        printf("Employee added successfully!\n");
                    } else {
                        printf("\nInvalid input. Please check your data.\n");
                    }
                } else {
                    printf("\nMaximum number of employees reached!\n");
                }
                break;

            case 2:
                if (numEmployees > 0) {
                    printf("Employee Data:\n");
                    for (int i = 0; i < numEmployees; i++) {
                        showEmployeeData(employees[i]);
                    }
                } else {
                    printf("No employees to display!\n");
                }
                break;

            case 3:
                   printf("Enter Employee ID: ");
                   scanf("%d", &id);
                   showById(employees, numEmployees, id);
                   break;
            case 4:
               printf("Enter Employee ID to update: ");
                scanf("%d", &id);

                if (validateID(id)) {
                    int found = 0;
                    for (int i = 0; i < numEmployees; i++) {
                        if (employees[i].Empno == id) {
                            updateEmployeeData(&employees[i]);
                            printf("Employee data updated successfully!\n");
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Employee with ID %d not found.\n", id);
                    }
                } else {
                    printf("Invalid Employee ID. Please try again.\n");
                }
                break;
        case 5:
             printf("Enter Employee ID to delete: ");
                scanf("%d", &id);

                if (validateID(id)) {
                    deleteEmployee(employees, &numEmployees, id);
                } else {
                    printf("\nInvalid Employee ID. Please try again.\n");
                }
                break;
         case 6:
                   printf("Exiting...\n");
                   break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);
}
