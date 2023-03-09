#include "FitnessClub.h"
#include "Client.h"
#include "Employee.h"
#include "List.h"

int main() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing behaviour of a filled FitnessClub object: \n" << endl;

    cout << "Creating a fitness club with an empty constructor and then setting"; 
    cout << "its attributes using setter methods. " << endl;
    
    FitnessClub* myclub = new FitnessClub();
    myclub->setName("Iron Church");
    myclub->setAddress("New York, Main St 1");
    // R2
    myclub->setBudget(-3000);
    // R1
    myclub->setRent(-1000);
    myclub->addBudgetChange(-1000);

    // R4
    myclub->insertEmployee("Arnold", "Schwarzenegger", 111111123, 700);

    // R5
    myclub->insertClient("John", "Johnson", 111111132, 400);
    myclub->insertClient("Silly", "Dog", 111111113, 300);
    // R3
    myclub->insertClient("Really", "Rich", 111111114, 500);

    myclub->insertEmployee("Mariusz", "Pudzianowski", 111111125, 600);
    // R4
    myclub->insertEmployee("Fake", "ID", 111111123, 50000);

    myclub->insertClient("Hilly", "Billy", 111111115, 300);
    // R3
    myclub->insertClient("Fake", "ID", 111111114, 0);
    myclub->insertClient("Grilly", "Grillz", 111111117,400);
    myclub->insertClient("Chris", "Peacock", 111111119, 450);
    myclub->insertClient("Nez", "Mayo", 111111122, 500);
    myclub->insertEmployee("Noel", "Deyzel", 111111128, 600);
    //R5
    myclub->insertEmployee("John", "Johnson", 111111132, 500);
    

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing client list printing methods: \n" << endl;
    myclub->printClients();
    myclub->printClient(3);
    // R6
    myclub->printClient(20);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing employee list printing methods: \n" << endl;
    myclub->printEmployees();
    myclub->printEmployee(2);
    // R7
    myclub->printEmployee(20);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing assignment methods: \n" << endl;

    cout << "Trying to assign client with id 3 to employee with id 1:" << endl; 
    myclub->assignClientToEmployee(3,1);

    cout << "Trying to assign client with id 20 to employee with id 1 (client with id 20 doesn't exist):" << endl;
    // R8
    myclub->assignClientToEmployee(20,1);
    
    cout << "Trying to assign client with id 1 to employee with id 4 (They are the same person i.e. have same citizen ID):" << endl; 
    //R16
    myclub->assignClientToEmployee(1,4);

    cout << "Trying to assign client with id 1 to employee with id 20 (employee with id 20 doesn't exist):" << endl; 
    // R8
    myclub->assignClientToEmployee(1,20);
    
    cout << "Trying to use the automaticallyAssignClients method, which should assign all of the remaining clients evenly among the employees: \n" << endl;
    myclub->automaticallyAssignClients();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing printEmployeeWorth method after cient assignment: \n" << endl;
    myclub->printEmployeeWorth();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing unassignment methods: \n" << endl;

    myclub->printEmployees();

    myclub->unassignClientFromEmployee(4 , 1);

    myclub->unassignClientFromEmployee(2, 2);
    
    myclub->unassignClientFromEmployee(5, 4);

    // R9
    myclub->unassignClientFromEmployee(20, 4);
    myclub->unassignClientFromEmployee(2, 20);  
    myclub->unassignClientFromEmployee(20, 20);  

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Showing that unassignment from employees has not deleted the clients from the fintesslcub clients list (should show clients with ids from 7 to 1): \n" << endl;
    myclub->printClients();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing printClientsWithNoEmployee method (should show clients with ids: 5, 4 and 2): \n" << endl;
    myclub->printClientsWithNoEmployee();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing printEmployeesWithNoClients method (should show employee with id 4) \n" << endl;
    myclub->printEmployeesWithNoClients();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing standard remove methods: \n" << endl;

    // R10
    myclub->removeClient(20);
    myclub->removeEmployee(20);

    myclub->printEmployee(1);
    myclub->removeClient(3);
    myclub->printEmployee(1);

    myclub->printEmployee(2);
    myclub->removeEmployee(2);
    
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Showing that the removal of employee with id 2 didn't also delete the client trained by this employee (client with id 7): " << endl;
    cout << "Notice how their status has also changed to not trained.\n" << endl;
    myclub->printClient(7);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing financial information print methods: \n" << endl;
    myclub->printFinancialInfo();
    myclub->printEmployeeWorth();
    
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing methods changing the attributes of client with id=1 on the client list (attributes should be: Changed, Changed, 999999998 and 330): \n" << endl;
    myclub->changeClientName(1, "Changed");
    myclub->changeClientSurname(1, "Changed");
    myclub->changeClientCitizenID(1, 999999998);
    // 13
    myclub->changeClientFee(1, -330);
    myclub->printClient(1);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing methods changing the attributes of an employee with id=1 on the employee list (attributes should be: Changed, Changed, 999999999 and 330): \n" << endl;
    myclub->changeEmployeeName(4, "Changed");
    myclub->changeEmployeeSurname(4, "Changed");
    // R13
    myclub->changeEmployeeSalary(4, -330);
    myclub->changeEmployeeCitizenID(4, 999999999);
    myclub->printEmployee(4);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing fail scenarios of methods changing the attributes of an employee and a client: \n" << endl;
    // R11
    myclub->changeEmployeeName(20, "Changed");
    myclub->changeClientSurname(20, "Changed");
    myclub->changeEmployeeSalary(20, -330);
    // R12
    myclub->changeClientCitizenID(2, 111111115);
    myclub->changeEmployeeCitizenID(4, 111111123);



    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing methods changing the max amount of clients and employees of clients and employees lists: \n" << endl;
    cout << "Trying to set max client amount to -1 (prints nothing if successful):" << endl;
    myclub->changeClientMaxAmount(-1);
    cout << "Trying to set max client amount to 5 (prints nothing if successful):" << endl;
    myclub->changeClientMaxAmount(5);
    cout << "Trying to set max client amount to 6 (prints nothing if successful):" << endl;
    myclub->changeClientMaxAmount(6);
    
    cout << "\nTrying to set max employee amount to -1 (prints nothing if successful):" << endl;
    myclub->changeEmployeeMaxAmount(-1);
    cout << "Trying to set max employee amount to 2 (prints nothing if successful):" << endl;
    myclub->changeEmployeeMaxAmount(2);
    cout << "Trying to set max employee amount to 3 (prints nothing if successful):" << endl;
    myclub->changeEmployeeMaxAmount(3);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing what happens when we try to add an employee and a client once the maximum limit on the lists have been reached: " << endl;

    cout << "\nCurrent employee amount is: " << myclub->employeeAmount() << " and the max amount of employees is: " << myclub->employeeMaxAmount() << endl;
    cout << "Trying to insert a 4th employee. " << endl << endl; 
    // R14
    myclub->insertEmployee("Maximus", "Employus", 111111129, 5000);
    
    cout << "\nCurrent client amount is: " << myclub->clientAmount() << " and the max amount of clients is: " << myclub->clientMaxAmount() << endl;
    cout << "Trying to insert a 7th client. " << endl << endl;
    // R14
    myclub->insertClient("Maximus", "Clientus", 111111131, 2500);
    cout << endl;

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Testing remove methods on the borders of the list: " << endl;
    myclub->removeClient(7);
    myclub->removeClient(1);
    myclub->removeEmployee(4);
    myclub->removeEmployee(1);

     cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Deleting FitnessClub myclub: " << endl << endl;
    delete myclub;

    
}
