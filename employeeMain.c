//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 

//gcc employeeMain.c employeeTable.c employeeTwo.c 

#include <string.h> 
#include <stdlib.h> 
#include "employee.h" 

int main(void){ 
    //defined in employeeSearchOne.c 
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); 

    //defined in employeeTable.c 
    extern Employee EmployeeTable[];     
    extern const int EmployeeTableEntries;      

    PtrToEmployee matchPtr;  //Declaration 
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 

    //Example not found 
    if (matchPtr != NULL) 
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee ID is NOT found in the record\n"); 

    //Example found 
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 

    if (matchPtr != NULL) 
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Tony Bobcat is NOT found in the record\n");

    //QUIZ STUFF//
    //Example found. P#
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "213-555-1212"); 

    //printf("%d\n", EmployeeTable);
    //printf("%d\n", matchPtr);

    if (matchPtr != NULL) 
        printf("Employee Phone #: 213-555-1212 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Phone #: 213-555-1212 is NOT found in the record\n");

    //Example not found. P#
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "626-555-1212");

    if (matchPtr != NULL) 
        printf("Employee Phone #: 626-555-1212 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Phone #: 626-555-1212 is NOT found in the record\n");


    //Example found. Sal
    double salaryT = 8.32;
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, salaryT); 

    //printf("%d\n", EmployeeTable);
    //printf("%d\n", matchPtr);

    if (matchPtr != NULL) 
        printf("Employee Salary: 8.32 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Salary: 8.32 is NOT found in the record\n");

    //Example not found. Sal
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, salaryT + 1.0);

    if (matchPtr != NULL) 
        printf("Employee Salary: 9.32 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Salary: 9.32 is NOT found in the record\n");

    return EXIT_SUCCESS; 
} 