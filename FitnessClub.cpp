#include "FitnessClub.h"
#include "List.h"
#include "Client.h"
#include "Employee.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#include <stdio.h>

FitnessClub::FitnessClub() {
    this->club_name = new char[strlen("not set") + 1];
    this->address = new char[strlen("not set") + 1];
    strcpy (this->club_name, "not set");
    strcpy (this->address, "not set");
    this->clients = new List<Client>();
    this->employees = new List<Employee>();
    this->budget = 0;
    this->rent = 0;
}

FitnessClub::FitnessClub(const char* club_name, const char* address, double budget, double rent) {
    this->club_name = new char[strlen(club_name) + 1];
    this->address = new char[strlen(address) + 1];
    strcpy (this->club_name, club_name);
    strcpy (this->address, address);
    this->clients = new List<Client>();
    this->employees = new List<Employee>();
    this->budget = budget;
    this->rent = rent;
}

FitnessClub::~FitnessClub(){
    delete []club_name;
    delete []address;
    delete employees;
    delete clients;
}

void FitnessClub::setName(const char* name) {
    if (this->club_name != nullptr) delete []this->club_name;
    this->club_name = new char[strlen(name) + 1];
    strcpy (this->club_name, name);
}

void FitnessClub::setAddress(const char* address) {
    if (this->address != nullptr) delete []this->address;
    this->address = new char[strlen(address) + 1];
    strcpy (this->address, address);
}

void FitnessClub::setBudget(double budget) {
    this->budget = budget;
}

void FitnessClub::setRent(double rent) {
    if (rent < 0) this->rent = -rent;
    else this->rent = rent;
}

void FitnessClub::addBudgetChange(double change) {
    this->budget+=change;
}

void FitnessClub::printClients() {
    cout << "\nThe total list of clients of '" << club_name;
    cout << "' fitness club in '" << address << "': " << endl;
    clients->printList();
    cout << endl; 
}

void FitnessClub::printClient(int id) {
    Client* bob = clients->findNode(id);
    cout << "Searching for a client with the ID: " << id << endl;
    if (bob == nullptr) {
        cout << "Client with such an ID was not found. " << endl;
    } else cout << *bob << endl;
    cout << endl;
}

void FitnessClub::printClientsWithNoEmployee() {
    int client_amount = clients->getAmount();
    cout << "The list of clients with no employees assigned to them registered at '" << club_name << "' Fitness Club located in '";
    cout << address << "':\n" << endl;
    for(int i = 1; i <= client_amount; i++) {
        if(clients->iterateToNthNodeObject(i).refStatus() == false){
            cout << "ID: " << clients->iterateToNthNodeID(i) << endl;
            cout << clients->iterateToNthNodeObject(i) << endl;
        }
    }
}

void FitnessClub::printEmployees() {
    cout << "\nThe total list of employees working in '" << club_name;
    cout << "' fitness club in '" << address << "': " << endl;
    employees->printList();
    cout << endl;
}

void FitnessClub::printEmployee(int id) {
    Employee* bob = employees->findNode(id);
    cout << "Searching for an employee with the ID: " << id << endl;
    if (bob == nullptr) {
        cout << "Employee with such an ID was not found. " << endl;
    } else cout << *bob << endl;
    cout << endl;
}

void FitnessClub::printEmployeesWithNoClients() {
    int amount = employees->getAmount();
    cout << "The list of employees with no clients assigned to them working at '" << club_name << "' Fitness Club located in '";
    cout << address << "':\n" << endl;
    for (int i = 1; i <= amount; i++) {
        if(employees->iterateToNthNodeObject(i).refClients().isEmpty()){
            cout << "ID: " << employees->iterateToNthNodeID(i) << endl;
            cout << employees->iterateToNthNodeObject(i) << endl;
        }
    }
}

bool FitnessClub::insertClient(const char* name, const char* surname, int citizenID, double fee) {
    for (int i = 1; i <= clients->getAmount(); i++) {
        if (clients->iterateToNthNodeObject(i).refCitizenID() == citizenID) {
            cout << "A client with such a citizen ID (" << citizenID << ") is already on the list. Please check if ";
            cout << "you have entered it correctly" << endl << endl;
            return false;
        }
    }

    Client* bob = new Client(name, surname, citizenID, fee);
    return clients->insertNode(bob);
}

bool FitnessClub::insertClient(const char* name, const char* surname, int citizenID, double fee, int employeeID) {
    for (int i = 1; i <= clients->getAmount(); i++) {
        if (clients->iterateToNthNodeObject(i).refCitizenID() == citizenID) {
            cout << "A client with such a citizen ID (" << citizenID << ") is already on the list. Please check if ";
            cout << "you have entered it correctly" << endl << endl;
            return false;
        }
    }
    Client* bob = new Client(name, surname, citizenID, fee);
    if (clients->insertNode(bob)) {
        if (assignClientToEmployee(clients->giveListID(), employeeID)) return true;
        else {
            cout << "The client has been added to the list with no employee assigned." << endl;
            return false;
        }
    }
    return false;
}

bool FitnessClub::insertEmployee(const char* name, const char* surname, int citizenID, double salary) {
    for (int i = 1; i <= employees->getAmount(); i++) {
        if (employees->iterateToNthNodeObject(i).refCitizenID() == citizenID) {
            cout << "An employee with such a citizen ID (" << citizenID << ") is already on the list. Please check if ";
            cout << "you have entered it correctly" << endl << endl;
            return false;
        }
    }

    Employee* bob = new Employee(name, surname, citizenID, salary);
    return employees->insertNode(bob);
}

bool FitnessClub::assignClientToEmployee(int clientID, int employeeID) {
    Employee* bob = employees->findNode(employeeID);
    Client* bobby = clients->findNode(clientID);

    if (bob && bobby) {
        if (bob->refClients().findNode(clientID)) {
            cout << "Assignment of a client to the employee failed. \n";
            cout << "A client with such an id is already trained by this employee. \n" << endl;
            return false;
        } else if (bobby->refStatus() == true) {
            cout << "Assignment of a client to the employee failed. \n";
            cout << "A client with such an id is already trained by another employee. \n" << endl;
            return false;
        }
        cout << "Assigning client with id: " << clientID;
        cout << " to employee with id: " << employeeID << "\n" << endl;
        bob->addClient(bobby, clientID);
        bobby->setStatus(true);
        return true;
    } else {
        cout << "Assignment of a client to the employee failed. \n";
        cout << "Either the client ID and/or the employee ID is wrong. \n"<< endl;
        return false;
    }
}

bool FitnessClub::automaticallyAssignClients(){
    int client_amount = clients->getAmount();
    int employee_amount = employees->getAmount();
    for(int i = 1; i <= client_amount; i++) {
        if(clients->iterateToNthNodeObject(i).refStatus() == false){
            int min = employees->iterateToNthNodeObject(1).refClients().getAmount();
            int min_n = 1;
            for (int j = 1; j <= employee_amount; j++) {
                if (employees->iterateToNthNodeObject(j).refClients().getAmount() <= min) {
                    min = employees->iterateToNthNodeObject(j).refClients().getAmount();
                    min_n = j;
                }
            }
            int emp_id = employees->iterateToNthNodeID(min_n);
            int client_id = clients->iterateToNthNodeID(i);
            assignClientToEmployee(client_id, emp_id);
        }
    }
    return true;
}

bool FitnessClub::unassignClientFromEmployee(int clientID, int employeeID) {
    Employee* bob = employees->findNode(employeeID);
    Client* bobby = clients->findNode(clientID);

    if (bob && bobby) {
        if (!bob->refClients().findNode(clientID)) {
            cout << "Unassignment of a client from the employee failed. \n";
            cout << "A client with such an id is not trained by this employee. \n" << endl;
            return false;
        }
        cout << "Unassinging client with id: " << clientID;
        cout << " from employee with id: " << employeeID << endl << endl;
        bob->removeClient(clientID);
        bobby->setStatus(false);
        return true;
    } else {
        cout << "Unassignment of a client with id: " << clientID << "to the employee with id: " << employeeID << " failed. \n";
        cout << "Either the client ID and/or the employee ID is wrong. \n"<< endl;
        return false;
    }
}

bool FitnessClub::removeClient(int id) {
    cout << "Trying to remove the client with the ID: " << id << endl;
    int employee_amount = employees->getAmount();
    
    if (clients->findNode(id)){

        for (int j = 1; j <= employee_amount; j++) {
            if (employees->iterateToNthNodeObject(j).refClients().findNode(id)) {
                unassignClientFromEmployee(id, employees->iterateToNthNodeID(j));
            }
        }


        if (clients->removeNode(id) == true) {
            cout << "The above client has been succesfully removed from the database.\n" << endl;
            cout << endl;
            return true;
        }

    } 
    cout << "No client has the given ID. " << endl;
    cout << endl;
    return false;
}

bool FitnessClub::removeEmployee(int id) {
    cout << "Trying to remove the employee with the ID: " << id << endl;
    Employee* bob = employees->findNode(id);

    if (bob) {
        for (int i = 0; i <= bob->refClients().getAmount(); i++) {
            
            int left_client_id = bob->refClients().iterateToNthNodeID(i);

            unassignClientFromEmployee(left_client_id, id);
        }
        employees->removeNode(id);
        cout << "The above employee has been succesfully removed from the database." << endl;
        cout << endl;
        return true;
    } else {
        cout << "No employee has the given ID. " << endl;
        cout << endl;
        return false;
    }
}

int FitnessClub::clientAmount() {
    return clients->getAmount();
}

int FitnessClub::clientMaxAmount() {
    return clients->getMaxAmount();
}

int FitnessClub::employeeAmount() {
    return employees->getAmount();
}

int FitnessClub::employeeMaxAmount() {
    return employees->getMaxAmount();
}

double FitnessClub::clientFees() { // private
    int amount = clients->getAmount();
    double fees = 0;
    for (int i = 1; i <= amount; i++) {
        fees += clients->iterateToNthNodeObject(i).refFee();
    }
    return fees;
}

double FitnessClub::employeeSalaries() { // private
    int amount = employees->getAmount();
    double salaries = 0;
    for (int i = 1; i <= amount; i++) {
        salaries += employees->iterateToNthNodeObject(i).refSalary();
    }
    return salaries;
}

double FitnessClub::calculateProfit() { // private
    return (clientFees() - employeeSalaries() - rent);
}

void FitnessClub::printFinancialInfo() {
    cout << "Financial status for the '" << club_name << "' fitness club.";
    cout << "Located in '" << address << "': " << endl;
    cout << "Current Budget: " << budget << endl;
    cout << "Rent to be paid monthly: " << rent << endl;
    cout << "Sum of salaries paid to employees monthly: " << employeeSalaries() << endl;
    cout << "Sum of fees paid to the club by its clients: " << clientFees() << endl;
    cout << "Net monthly profit (loss if negative): " << calculateProfit() << endl;
    cout << endl;
}

void FitnessClub::printEmployeeWorth() {
    int amount = employees->getAmount();
    cout << "The list showing the worth that each employee brings to the club by training their clients:\n" << endl;
    for (int i = 1; i <= amount; i++) {
        Employee* bob = &employees->iterateToNthNodeObject(i);
        int client_amount = bob->refClients().getAmount();
        double worth = 0;
        for (int j = 1; j <= client_amount; j++) {
            worth += bob->refClients().iterateToNthNodeObject(j).refFee();
        }

        cout << "ID: " << employees->iterateToNthNodeID(i) << endl;
        cout << "Name: " << bob->refName() << endl;
        cout << "Surname: " << bob->refSurname() << endl;
        cout << "Amount of clients trained: " << bob->refClients().getAmount() << endl;
        cout << "Worth: " << worth << endl << endl;
    }
}

bool FitnessClub::changeClientName(int id, const char* name) {
    Client* bob = clients->findNode(id);
    if (bob) {
        bob->setName(name);
        return true;
    } else return false;
}

bool FitnessClub::changeClientSurname(int id, const char* surname) {
    Client* bob = clients->findNode(id);
    if (bob) {
        bob->setSurname(surname);
        return true;
    } else return false;
}

bool FitnessClub::changeClientCitizenID(int id, int citizenID) {
    int amount = clients->getAmount();

    if (!clients->findNode(id)) {
        cout << "Client with such an id: " << id << " was not found on the fitness club list. " << endl;
        return false;
    }

    for (int i = 1; i <= amount; i++) {
        if (employees->iterateToNthNodeObject(i).refCitizenID() == citizenID) {
            cout << "The attempt to change the citizen id of the client with fitness club id: " << id << "failed." << endl;
            cout << "There already exists an client with such a citizen id on the fitness club list. " << endl;
            return false;
        }
    }

    clients->findNode(id)->setCitizenID(citizenID);
    return true;
}

bool FitnessClub::changeClientFee(int id, double fee) {
    Client* bob = clients->findNode(id);
    if (bob) {
        bob->setFee(fee);
        return true;
    } else return false;
}

bool FitnessClub::changeClientMaxAmount(int max_amount) {
    if (clients->getAmount() > max_amount) {
        cout << "The amount of clients on the list is greater than the given maximum amount or ";
        cout << "the given maximum amount is negative. " << endl;
        cout << "Please remove some clients or give an appropriate maximum amount" << endl;
        cout << endl;
        return false;
    } else {
        clients->changeMaxAmount(max_amount);
        return true;
    }
}

bool FitnessClub::changeEmployeeName(int id, const char* name) {
    Employee* bob = employees->findNode(id);
    if (bob) {
        bob->setName(name);
        return true;
    } else return false;
}

bool FitnessClub::changeEmployeeSurname(int id, const char* surname) {
    Employee* bob = employees->findNode(id);
    if (bob) {
        bob->setSurname(surname);
        return true;
    } else return false;
}

bool FitnessClub::changeEmployeeCitizenID(int id, int citizenID) {
    int amount = employees->getAmount();

    if (!employees->findNode(id)) {
        cout << "Employee with such an id: " << id << " was not found on the fitness club list. " << endl;
        return false;
    }

    for (int i = 0; i <= amount; i++) {
        if (employees->iterateToNthNodeObject(i).refCitizenID() == citizenID) {
            cout << "The attempt to change the citizen id of the employee with fitness club id: " << id << "failed." << endl;
            cout << "There already exists an employee with such a citizen id on the fitness club list. " << endl;
            return false;
        }
    }

    employees->findNode(id)->setCitizenID(citizenID);
    return true;
}

bool FitnessClub::changeEmployeeSalary(int id, double salary) {
    Employee* bob = employees->findNode(id);
    if (bob) {
        bob->setSalary(salary);
        return true;
    } else return false;
}

bool FitnessClub::changeEmployeeMaxAmount(int max_amount) {
    if (employees->getAmount() > max_amount) {
        cout << "The amount of employees on the list is greater than the given maximum amount or ";
        cout << "the given maximum amount is negative. " << endl;
        cout << "Please remove some employees or give an appropriate maximum amount" << endl;
        cout << endl;
        return false;
    } else {
        employees->changeMaxAmount(max_amount);
        return true;
    }
}