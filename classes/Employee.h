#ifndef EMPLOYEE
#define EMPLOYEE
#include "List.h"
#include "Client.h"

class Employee {
    private:
        char* name;
        /* First name of the employee. */
        
        char* surname;
        /* Surname of the employee. */

        long citizenID;
        /* Citizen ID of the employee. 
        No two employees should have the same citizen id. */

        double salary;
        /* Salary of the employee. Cannot be negative. */

        List<Client>* clients;
        /* List of all clients which currently trained by this employee. The 
        ids of the node on this list should coincide with those on the FitnessCLub 
        client list i.e. if a client named john has an id of 4 on the fitness
        club client list, then he should also have that id in the client list of 
        the employee that is training him. */
        
    public:
        Employee();
        /* Default constructor of Employee, should set name and surname to "not set" 
        and fee to 0. */

        Employee(const char* name, const char* surname, long citizenID, double salary=0);
        /* Defined constructor of Employee. Should create an Employee with attributes as the 
        given values as long as they fulfill the attribute conditions, else print warning. The 
        clients list should be also initialized but left empty. */

        ~Employee();
        /* Destructor of Employee. Needs to make sure no memory leaks occur, thus it
        needs to deallocate the memory given to name and surname attributes
        as they are dynamic char arrays, as well as the clients list. */

        char*& refName();
        /* Returns a reffrerence to the employee's name. */

        char*& refSurname();
        /* Returns a refference to the employee's surname. */

        long& refCitizenID();
        /* Returns a refference to the employee's citizen ID. */

        double& refSalary();
        /* Returns a refference to the employee's salary. */

        List<Client>& refClients();
        /* Returns a refference to the list of clients trained by 
        the employee */

        void setName(const char* x);
        /* Setter method for the employee's name. */

        void setSurname(const char* x);
        /* Setter method for the employee's surname. */

        bool setCitizenID(long citizenID);
        /* Setter for the employee's citizen id. */

        void setSalary(double x);
        /* Setter method for the employee's salary. It should be positive hence 
        when the given fee is negative it should be first converted into a positive
        number. */

        void setClientList(List<Client> x);
        /* Method setting the list of clients to that given in the method argument. It 
        should use the overloaded assignment operator of the List template class to delete
        the previous list stored in the clients attribute and assign to it x. */

        void addClient(Client* bob, long id);
        /* Method which inserts a client into the employee client list and gives it a given id
        the method doesn't check if the client is already on the list as its a helper method
        to the FitnessClub::assignClientToEmployee method. All the necesary checks are performed
        there or in the List<T>::insertNode method of the list class. */

        void removeClient(long idClient);
        /* Method which removes a client from the employee client list. It doesn't check if 
        a client with such an id exists on the list as it is a helper method. to the 
        FitnessClub::assignClientToEmployee method. All the necesary checks are performed
        there or in the List<T>::removeNode method of the list class.  */

        friend ostream& operator<<(ostream& out, const Employee& bob);
        /* A friend function overloading the << operator. It prints out
        the attributes of an employee object. */
};

#endif