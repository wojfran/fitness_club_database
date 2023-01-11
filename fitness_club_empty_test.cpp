#include "FitnessClub.h"
#include "Client.h"
#include "Employee.h"
#include "List.h"

int main() {


    cout << "\nTesting behaviour of an empty FitnessClub object when every list is empty: \n" << endl;

    cout << "Creating a fitness club with an empty constructor and then setting"; 
    cout << "its attributes using setter methods: " << endl;
    FitnessClub* myclub = new FitnessClub();
    myclub->setName("Iron Church");
    myclub->setAddress("New York, Main St 1");
    myclub->setBudget(-3000);
    myclub->setRent(0);
    myclub->addBudgetChange(-1000);
    // The budget should be now 2000, rent 0
    // Name and address should be as given above

    cout << "\nTesting client list printing methods: " << endl;
    myclub->printClients();
    myclub->printClient(3);
    myclub->printClientsWithNoEmployee();

    cout << "\nTesting employee list printing methods: " << endl;
    myclub->printEmployees();
    myclub->printEmployee(2);
    myclub->printEmployeesWithNoClients();
    myclub->printEmployeeWorth();

    cout << "\nTesting assignment methods: " << endl;
    myclub->assignClientToEmployee(3,5);
    myclub->automaticallyAssignClients();
    myclub->unassignClientFromEmployee(2, 4);

    cout << "\nTesting remove methods: " << endl;
    myclub->removeClient(3);
    myclub->removeEmployee(2);

    cout << "\nTesting financial information print methods: " << endl;
    myclub->printFinancialInfo();
    myclub->printEmployeeWorth();
    
    cout << "\nTesting methods changing the attributes of client with id=1 on the client list (attributes should be: Changed, Changed and 330): " << endl;
    myclub->changeClientName(1, "Changed");
    myclub->changeClientSurname(1, "Changed");
    myclub->changeClientFee(1, -330);
    myclub->printClient(1);

    cout << "\nTesting methods changing the attributes of an employee with id=1 on the employee list (attributes should be: Changed, Changed and 330):: " << endl;
    myclub->changeEmployeeName(1, "Changed");
    myclub->changeEmployeeSurname(1, "Changed");
    myclub->changeEmployeeSalary(1, -330);
    myclub->printEmployee(1);

    cout << "\nTesting methods changing the max amount of clients and employees of clients and employees lists: " << endl;
    myclub->changeClientMaxAmount(-1);
    myclub->changeClientMaxAmount(0);
    myclub->changeClientMaxAmount(10);
    
    myclub->changeEmployeeMaxAmount(-1);
    myclub->changeEmployeeMaxAmount(0);
    myclub->changeEmployeeMaxAmount(4);


    delete myclub;
    // delete mylist;


    // to do

    // method that automatically assigns clients with no trainer to trainers with the least clients?
}