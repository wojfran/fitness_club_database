#include "Employee.h"
#include "List.h"
#include "Client.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

Employee::Employee() {
    this->setName("not set");
    this->setSurname("not set");
    this->citizenID = -1;
    this->setSalary(0);
    List<Client>* clients = new List<Client>();
    this->clients = clients;
}

Employee::Employee(const char* name, const char* surname, int citizenID, double salary) {
    setName(name);
    setSurname(surname);
    setCitizenID(citizenID);
    setSalary(salary);
    this->clients = new List<Client>();
}

Employee::~Employee() { 
    cout << "This is deleted:" << endl;
    cout << *this << endl;
    delete []name;
    delete []surname;
    clients->softDelete();
}

ostream& operator<<(ostream& out, const Employee& bob) {
    out << "=============================================" << endl;
    out << "\tName: " << bob.name;
    out << "\n\tSurname: " << bob.surname;
    out << "\n\tCitizen ID: " << bob.citizenID;
    out << "\n\tSalary: " << bob.salary;
    out << "\n\tAmount of clients trained: " << bob.clients->getAmount(); 
    out << "\n\tClients trained: \n{\n\n";
    if (bob.clients->isEmpty()) {
        cout << "\tNo clients trained.\n\n";
    } else bob.clients->printList();
    out << "}" << endl;
    out << "=============================================" << endl;
    return out;
}

char*& Employee::refName() {
    return name;
}

char*& Employee::refSurname() {
    return surname;
}

int& Employee::refCitizenID() {
    return citizenID;
}

double& Employee::refSalary() {
    return salary;
}

List<Client>& Employee::refClients() {
    return *clients;
}

void Employee::setName(const char* name) {
    if (this->name != nullptr) delete []this->name;
    this->name = new char[strlen(name) + 1];
    strcpy (this->name, name);
}

void Employee::setSurname(const char* surname) {
    if (this->surname != nullptr) delete []this->surname;
    this->surname = new char[strlen(surname) + 1];
    strcpy (this->surname, surname);
}

bool Employee::setCitizenID(int citizenID) {
    if (citizenID <= 0) {
        cout << "No citizen ID is 0 or negative, please enter a correct citizen ID" << endl;
        return false;
    } else {
        refCitizenID() = citizenID;
        return true;
    }
}

void Employee::setSalary(double salary) {
    if (salary < 0) refSalary() = -salary;
    else refSalary() = salary;
}

void Employee::setClientList(List<Client> clients) {
    refClients() = clients;
}

void Employee::addClient(Client* bob, int id) {
    if (refClients().insertNode(bob, id)){
        refClients().findNode(id)->setStatus(true);
    }
}

void Employee::removeClient(int idClient) {
    refClients().findNode(idClient)->setStatus(false);
    refClients().removeNode(idClient);
}