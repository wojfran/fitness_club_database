#ifndef CLIENT_H
#define CLIENT_H
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#include <stdio.h>

class Client {
    private:
        char* name;
        /* First name of the client. */

        char* surname;
        /* Surname of the client. */

        int citizenID;
        /* Citizen ID of the client. 
        No two clients should have the same citizen id. */

        double fee;
        /* Membership fee paid by the client to the fitness club. Cannot be 
        negative. */

        bool status;
        /* Boolean value denoting whether the client is currently being trained 
        by an employee of the fitness club. True if assigned to an employee, 
        false otherwise. */

    public:
        Client();
        /* Default constructor of Client, should set name and surname to "not set" 
        and fee to 0. */

        Client(const char* name, const char* surname, int citizenID, double fee=0);
        /* Defined constructor of Client. Should create a Client with attributes as the 
        given values. As long as they fulfill the attribute conditions, else print warning */

        ~Client(); 
        /* Destructor of Client. Needs to make sure no memory leaks occur, thus it
        needs to deallocate the memory given to name and surname attributes
        as they are dynamic char arrays. */

        Client& operator=(const Client& x);
        /* Client assignment operator, dallocates the memory stored for the 
        dynamic attributes of this client (name, surname) and assigns to it
        all of the attributes of client x. */

        char*& refName();
        /* Returns a reffrerence to the client's name. */

        char*& refSurname();
        /* Returns a refference to the client's surname. */

        int& refCitizenID();
        /* Returns a refference to the clients citizen ID. */

        double& refFee();
        /* Returns a refference to the client's membership fee. */

        bool& refStatus();
        /* Returns a refference to the client's employee assignment status. */
        
        void setName(const char* name);
        /* Setter method for the client's name. */

        void setSurname(const char* surname);
        /* Setter method for the client's surname. */

        void setCitizenID(int citizenID);
        /* Setter for the employee's citizen id. */

        void setFee(double fee);
        /* Setter method for the client's membership fee. It should be positive hence 
        when the given fee is negative it should be first converted into a positive
        number. */

        void setStatus(bool status);
        /* Setter method for the client's status. If he is currently trained
        by some employee of the fitness club, it should be set to true and set
        to false if otherwise. */
        
        friend ostream& operator<<(ostream& out, const Client& bob);
        /* A friend function overloading the << operator. It prints out
        the attributes of a client object. */
};

#endif