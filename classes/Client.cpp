#include "Client.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#include <stdio.h>

Client::Client() {
    this->name = new char[strlen("not set") + 1];
    strcpy (this->name, "not set");
    this->surname = new char[strlen("not set") + 1];
    strcpy (this->surname, "not set");
    this->setFee(0);
    citizenID = -1;
    status = false;
}

Client::Client(const char* name, const char* surname, long citizenID, double fee) {
    this->name = new char[strlen(name) + 1];
    strcpy (this->name, name);
    this->surname = new char[strlen(surname) + 1];
    strcpy (this->surname, surname);
    this->setFee(fee);
    this->setCitizenID(citizenID);
    status = false;
}

Client::~Client() {
    cout << "This is deleted:" << endl;
    cout << *this << endl; 
    delete []name;
    delete []surname;
}

Client& Client::operator=(const Client& x) {
    this->setName(x.name);
    this->setSurname(x.surname);
    this->setFee(x.fee);
    this->setCitizenID(x.citizenID);
    return *this;
}


ostream& operator<<(ostream& out, const Client& bob) {
    out << "--------------------------" << endl;
    out << "Name: " << bob.name;
    out << "\nSurname: " << bob.surname;
    out << "\nCitizen ID: " << bob.citizenID;
    out << "\nFee: " << bob.fee;
    out << "\nTrained: " << (bob.status==1 ? "Yes" : "No");
    out << "\n--------------------------" << endl;
    out << endl;
    return out;
}

char*& Client::refName() {
    return name;
}

char*& Client::refSurname() {
    return surname;
}

double& Client::refFee() {
    return fee;
}

bool& Client::refStatus() {
    return status;
}

long& Client::refCitizenID() {
    return citizenID;
}

void Client::setName(const char* name) {
    if (this->name != nullptr) delete []this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Client::setSurname(const char* surname) {
    if (this->surname != nullptr) delete []this->surname;
    this->surname = new char[strlen(surname) + 1];
    strcpy(this->surname, surname);
}

void Client::setFee(double fee) {
    if (fee < 0) refFee() = -fee;
    else refFee() = fee;
}

void Client::setCitizenID(long citizenID) {
    long number_of_digits = 0;
    long n = citizenID;
    if (citizenID <= 0) {
        cout << "No citizen ID is 0 or negative, please enter a correct citizen ID. " << endl;
    } else {
        do {
            number_of_digits++;
            n /= 10;
        } while (n);

        if (number_of_digits == 9) refCitizenID() = citizenID;
        else cout << "Given citizen ID has a wrong amount of digits, please try again. " << endl;
    }
    
}

void Client::setStatus(bool status) {
    refStatus() = status;
}