#include "FitnessClub.h"
#include "Client.h"
#include "Employee.h"
#include "List.h"

// R15
int main() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing behaviour of a two FitnessClub objects working alongside each other: \n" << endl;

    cout << "Creating two fitness clubs with an empty constructor and then setting"; 
    cout << "its attributes using setter methods. " << endl;
    
    FitnessClub* myclub = new FitnessClub();
    FitnessClub* yourclub = new FitnessClub();
    myclub->setName("My Club");
    myclub->setAddress("New York, Main St 1");
    // R2
    myclub->setBudget(-3000);
    // R1
    myclub->setRent(-1000);
    myclub->addBudgetChange(-1000);

    yourclub->setName("Your Club");
    yourclub->setAddress("New York, Main St 2");
    // R2
    yourclub->setBudget(-3000);
    // R1
    yourclub->setRent(-1000);
    yourclub->addBudgetChange(-1000);

    // R4
    myclub->insertEmployee("Arnold", "Schwarzenegger", 111111123, 700);
    yourclub->insertEmployee("Arnold", "Schwarzenegger", 111111123, 700);
    myclub->insertEmployee("C", "Bum", 111111124, 600);

    // R5
    myclub->insertClient("John", "Johnson", 111111132, 400);
    yourclub->insertClient("Adam", "Driver", 111111113, 400);
    yourclub->insertClient("John", "Johnson", 111111132, 400);
    myclub->insertClient("Milly", "Girl", 111111112,300);
    // R3
    myclub->insertClient("Really", "Rich", 111111132, 500);
    yourclub->insertClient("Really", "Rich", 111111132, 500);

    yourclub->insertEmployee("Mariusz", "Pudzianowski", 111111125, 600);
    // R4
    myclub->insertEmployee("Fake", "ID", 111111123, 50000);
    yourclub->insertEmployee("Fake", "ID", 111111123, 50000);

    myclub->insertClient("Hilly", "Billy", 111111115, 300);
    myclub->insertClient("Someon", "Important", 111111114, 0);
    myclub->insertClient("Grilly", "Grillz", 111111117,400);
    yourclub->insertClient("Chris", "Peacock", 111111119, 450);
    yourclub->insertClient("Nuts", "Sugondese", 111111121, 300);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing client list printing methods: \n" << endl;
    myclub->printClients();
    yourclub->printClients();
    cout << "myclub: \n";
    myclub->printClient(3);
    cout << "yourclub:\n";
    yourclub->printClient(3);
    // R6
    myclub->printClient(20);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing employee list printing methods: \n" << endl;
    myclub->printEmployees();
    yourclub->printEmployees();
    cout << "myclub: \n";
    myclub->printEmployee(2);
    cout << "yourclub:\n";
    yourclub->printEmployee(2);
    // R7
    myclub->printEmployee(20);
    cout << "myclub: \n";
    myclub->printEmployeeWorth();
    cout << "yourclub:\n";
    yourclub->printEmployeeWorth();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing assignment methods: \n" << endl;
    cout << "Trying to assign client with id 3 to employee with id 5:" << endl; 
    cout << "myclub: \n";
    myclub->assignClientToEmployee(3,1);
    cout << "yourclub:\n";
    yourclub->assignClientToEmployee(4, 2);

    cout << "Trying to use the automaticallyAssignClients method, which should assign all of the remaining clients evenly among the employees: \n" << endl;
    cout << "myclub: \n";
    myclub->automaticallyAssignClients();
    cout << "yourclub:\n";
    yourclub->automaticallyAssignClients();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing printEmployeeWorth method after cient assignment: \n" << endl;
    cout << "myclub: \n";
    myclub->printEmployeeWorth();
    cout << "yourclub:\n";
    yourclub->automaticallyAssignClients();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing unassignment methods: \n" << endl;

    myclub->printEmployees();

    myclub->unassignClientFromEmployee(2, 2);

    myclub->unassignClientFromEmployee(4, 1);

    yourclub->printEmployees();

    yourclub->unassignClientFromEmployee(4, 2);

    yourclub->unassignClientFromEmployee(3, 1);


    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Showing that unassignment from employees has not deleted the clients from the fintesslcub clients list (should show clients with ids from 10 to 1): \n" << endl;
    cout << "myclub:\n";
    myclub->printClients();
    cout << "yourclub:\n";
    yourclub->printClients();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing printClientsWithNoEmployee method: \n" << endl;
    cout << "myclub:\n";
    myclub->printClientsWithNoEmployee();
    cout << "yourclub:\n";
    yourclub->printClientsWithNoEmployee();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing printEmployeesWithNoClients method (should show no employees): \n" << endl;
    cout << "myclub:\n";
    myclub->printEmployeesWithNoClients();
    cout << "yourclub:\n";
    yourclub->printEmployeesWithNoClients();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing remove methods: \n" << endl;

    cout << "myclub:\n";
    myclub->printEmployee(2);

    myclub->removeClient(5);

    myclub->printEmployee(2);

    myclub->printEmployee(1);

    myclub->removeEmployee(1);

    cout << "yourclub:\n";
    yourclub->printEmployee(2);

    yourclub->removeClient(1);

    yourclub->printEmployee(2);

    yourclub->printEmployee(1);

    yourclub->removeEmployee(1);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Showing that the removal of employees with id 1 didn't also delete the clients trained by these employees (ids 1 and 3 for myclub and id 1 for yourclub): " << endl;
    cout << "Notice how their status has also changed to not trained.\n" << endl;
    cout << "myclub:\n";
    myclub->printClient(1);
    myclub->printClient(3);
    cout << "yourclub:\n";
    yourclub->printClient(1);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing financial information print methods: \n" << endl;
    myclub->printFinancialInfo();
    myclub->printEmployeeWorth();
    
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing methods changing the attributes of client with id=1 on the client list (attributes should be: Changed, Changed, 999999998 and 330): \n" << endl;
    myclub->changeClientName(1, "Changed");
    myclub->changeClientSurname(1, "Changed");
    myclub->changeClientCitizenID(1, 999999998);

    yourclub->changeClientName(1, "Changed");
    yourclub->changeClientSurname(1, "Changed");
    yourclub->changeClientCitizenID(1, 999999998);
    // 13
    myclub->changeClientFee(1, -330);
    yourclub->changeClientFee(1, -330);
    cout << "myclub:\n";
    myclub->printClient(1);
    cout << "yourclub:\n";
    yourclub->printClient(1);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing methods changing the attributes of an employee with id=1 on the employee list (attributes should be: Changed, Changed, 999999999 and 330): \n" << endl;
    myclub->changeEmployeeName(2, "Changed");
    myclub->changeEmployeeSurname(2, "Changed");
    // R13
    myclub->changeEmployeeSalary(2, -330);
    myclub->changeEmployeeCitizenID(2, 999999999);

    yourclub->changeEmployeeName(2, "Changed");
    yourclub->changeEmployeeSurname(2, "Changed");
    // R13
    yourclub->changeEmployeeSalary(2, -330);
    yourclub->changeEmployeeCitizenID(2, 999999999);

    cout << "myclub:\n";
    myclub->printEmployee(2);
    cout << "yourclub:\n";
    yourclub->printEmployee(2);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing methods changing the max amount of clients and employees of clients and employees lists: \n" << endl;
    cout << "Trying to set max client amount to -1 (prints nothing if successful):" << endl;
    myclub->changeClientMaxAmount(-1);
    cout << "Trying to set max client amount to 2 (prints nothing if successful):" << endl;
    myclub->changeClientMaxAmount(2);
    cout << "Trying to set max client amount to 4 (prints nothing if successful):" << endl;
    myclub->changeClientMaxAmount(4);
    
    cout << "\nTrying to set max employee amount to -1 (prints nothing if successful):" << endl;
    myclub->changeEmployeeMaxAmount(-1);
    cout << "Trying to set max employee amount to 0 (prints nothing if successful):" << endl;
    myclub->changeEmployeeMaxAmount(0);
    cout << "Trying to set max employee amount to 1 (prints nothing if successful):" << endl;
    myclub->changeEmployeeMaxAmount(1);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing what happens when we try to add an employee and a client once the maximum limit on the lists have been reached: " << endl;

    cout << "\nCurrent employee amount is: " << myclub->employeeAmount() << " and the max amount of employees is: " << myclub->employeeMaxAmount() << endl;
    cout << "Trying to insert a 2nd employee. " << endl << endl; 
    // R14
    myclub->insertEmployee("Maximus", "Employus", 111111129, 5000);
    
    cout << "\nCurrent client amount is: " << myclub->clientAmount() << " and the max amount of clients is: " << myclub->clientMaxAmount() << endl;
    cout << "Trying to insert a 5th client. " << endl << endl;
    // R14
    myclub->insertClient("Maximus", "Clientus", 111111131, 2500);
    cout << endl;

    delete myclub;
}