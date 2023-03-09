#ifndef FITNESSCLUB
#define FITNESSCLUB
#include "Client.h"
#include "Employee.h"
#include "List.h"

class FitnessClub {
    private:
        char* club_name;
        /* The name of the club (company name) f.e. "Zdrofit". */

        char* address;
        /* The address of the club. */

        List<Client>* clients;
        /* The list of clients of the fitness club. */

        List<Employee>* employees;
        /* The list of employees of the fitness club. */

        double budget;
        /* A double representing the budget of the club. It should be rounded
        down to two places after the decimal point when printing financial info. 
        Can be negative as to signify debt fe. */

        double rent;
        /* A double representing the rent paid by the club. It should be rounded
        down to two places after the decimal point when printing financial info.
        In the case where the club owns its own space it should be set to 0. Cannot be 
        negative. */

        double clientFees();
        /* Method calculating the sum of fees paid by the clients of the club stored in the List<Client> clients
        attribute. It should add the fee attribute of each Client object on the list to the result and return
        it when the end of the lsit is reached. If the client list is empty, return 0. */

        double employeeSalaries();
        /* Method calculating the sum of salaries paid to the employees of the club stored in the List<Employee> 
        employees attribute. It should add the salary attribute of each Employee object on the list to the result and 
        return it when the end of the lsit is reached. If the employee list is empty, return 0. */

        double calculateProfit();
        /* Method calculating the monthly profit of the club. Its result is equal to the sum of client fees (calculated 
        using the clientFees() method) minus the sum of employee salaries (calculated using the employeeSalaries() method)
        and minus the rent attribute. */

    public:
        FitnessClub();
        /* Default constructor of FitnessClub, it should initialize name and address as 
        "not set", create empty lists using their respective default constructors and
        initialize budget and rent as 0. */

        FitnessClub(const char* club_name, const char* address, double budget=0, double rent=0);
        /* Non-default constructor of FitnessClub. Should assign the given arguments
        to the appropriate class attributes. The default values of budget and rent are set 
        to 0, the budget can be given as a negative number since the Fitness club owners might 
        be in debt, the rent, however, must be greater or equal to 0, if it is given as a negative
        value it will be interpreted as a positive value. */

        ~FitnessClub();
        /* The destructor of FitnessClub objects. It needs to make sure that all of the memory
        used by the object attributes is freed i.e. club_name, address and each of the lists. */

        void setName(const char* name);
        /* A setter method setting the club_name attribute. It needs to make sure that there
        is no memory leakage as we are using a dynamic array of chars. If the new name is the 
        same as the old, do nothing */

        void setAddress(const char* address);
        /* A setter method setting the address attribute. It needs to make sure that there
        is no memory leakage as we are using a dynamic array of chars.  If the new address is
        the same as the old do nothing. */

        void setBudget(double budget);
        /* A setter method setting the budget attribute. */

        void setRent(double rent);
        /* A setter method setting the rent attribute. It should round down the given value
        to two decimal points. If the given value is negative transform it into a positive 
        number as it can be only greater or equal to 0 by convention. */

        void addBudgetChange(double change);
        /* A method incrementing the budget by the given value. The value can be negative
        (signifying an expense) or positive (signifying an unexpected profit f.e. a tax break) */

        void printClients();
        /* A method printing the list of clients. It should print all of the attributes of the
        Client class, as well as the id of the node storing each client object. */

        void printClient(long id);
        /* A method printing the data about a specific client. It should print all of the 
        attributes of the Client class, as well as the id of the node storing the client 
        object (despite it being given as an argument, as it will simply increase readability).*/

        void printClientsWithNoEmployee();
        /* A method that prints all of the clients in the fitness club client list along with their
        IDs who are not assigned to any employee. */
        
        void printEmployees();
        /* A method printing the list of employees. It should print all of the attributes of the
        Employee class, as well as the id of the node storing each employee object. */

        void printEmployee(long id);
        /* A method printing the data about a specific employee. It should print all of the 
        attributes of the Employee class, as well as the id of the node storing the employee 
        object (despite it being given as an argument, as it will simply increase readability).*/

        void printEmployeesWithNoClients();
        /* A method that prints all of the employees of the fitness club employee list along with their
        IDs who do not have any client assigned to them. */

        long clientAmount();
        /* Method returning the amount of clients registered in the fitness club's client list. */

        long clientMaxAmount();
        /* Method returning the amount of clients that can be registered in the fitness club's client list. */

        long employeeAmount();
        /* Method returning the amount of employees registered in the fitness club's employee list. */

        long employeeMaxAmount();
        /* Method returning the max amount of employees that can be registered in the fitness club's employee list. */

        bool insertClient(const char* name, const char* surname, long citizenID, double fee=0);
        /* This method inserts new client to the client list of the fitness club. 
        Based on the given attributes it should first create a new client object 
        and then insert it into the client list. */

        bool insertClient(const char* name, const char* surname, long citizenID, double fee, long idEmployee);
        /* This method inserts new client to the client list of the fitness club.
        and immediately assigns it to an employee with the given id if possible. 
        Based on the given attributes it should first create a new client object 
        , then insert it into the client list and use the assignClientToEmployee method
        to assign it to the given employee. If the assignment fails, a warning should
        be printed informaing the user that the client has been added to the client 
        list with no employee assigned. */

        bool insertEmployee(const char* name, const char* surname, long citizenID, double salary=0);
        /* This method inserts new employee to the employee list of the fitness club. 
        Based on the given attributes it should first create a new employee object 
        and then insert it into the employee list.*/

        bool assignClientToEmployee(long clientID, long employeeID);
        /* This method assigns a client with the given client id to an employee with 
        the given emplyoee id. It returns false if a client with such an id already is
        assigned to the employee with the given id or is already trained by another 
        employee. It also returns false if either the client or the employee with the 
        given id does not exist in this FitnessClub. In all of those cases the method also 
        prints a warning, explaining what was wrong. If both the employee and client with
        given ids exist and the client is not trained by anyone already, then the method
        assigns the client to the employee's client list using the Employee:addClient method
        and changes the clients status attribute to true. */

        bool automaticallyAssignClients();
        /* This method automatically assigns all of the fitness club's clients to employees
        with the least amount of clients assigned to them. It does so by iterating through 
        the client list of the fitness club and checks if their status attribute is false, 
        which signifies that they are not trained by any employee currently. If the method 
        finds a client which is not trained by any employee, it then determines which of 
        the employees on the fitness club's employee list has the least amount of clients
        and assigns the client to that employee.*/;

        bool unassignClientFromEmployee(long clientID, long employeeID);
        /* This metod unassigns a cient from an employee training them. It returns false if 
        a client with the given id is not trained by the employee with the given id or if either
        one of the given ids is wrong. In both cases it prints a warning informing the user of 
        what might be wrong. If it finds a cient with such an id in the employee's client list, it
        uses the Emplyoee::removeClient method to remove him from that list and sets the client's 
        status attribute to false, signifying that they are no longer being trained by any employee. */

        bool removeClient(long id);
        /* Method which removes a client from the client list. It should use the remove node method from
        the List class. If no client with such an id exists print a warning infromation and return false, else
        it should remove the client and return true. */

        bool removeEmployee(long id);
        /* Method which removes an employee from the employee list. It should use the remove node method from
        the List class. If no employee with such an id exists print a warning infromation and return false, else
        it should remove the employee and return true. */

        void printFinancialInfo();
        /* Method prinitng the information about the current financial situation of the fitness club.
        It should print the name of the fitness club, the budget of the club, the rent, the sum of employee 
        salaries (calculated using the employeeSalaries() function), the sum of client fees (calculated 
        using the clientFees() function) and its monthly profit (calculated using the calculateProfit() 
        function) */

        void printEmployeeWorth();
        /* This function prints the "worth" of each employee working in the fitness club i.e. the sum of the fees paid
        to the fitness club by the clients trained by them.  It ddoes so by iterating first through the fitness club's
        employee list and then through each of the employees client list (nested for loop). While iterating over the 
        employee's list of clients it sums their fees and prints te final sum along employee's id, name and surname. */        

        // Configuration methods, should be used primarily for correction of mistakes rather than casual operation of the 
        // system:

        bool changeClientName(long id, const char* name);
        /* Method which which should change the name of the client with the given id to the given name. Returns true 
        if succesfful, returns false if client with such an id doesnt exist. */

        bool changeClientSurname(long id, const char* surname);
        /* Method which which should change the surname of the client with the given id to the given surname. Returns 
        true if succesfful, returns false if client with such an id doesnt exist.  */

        bool changeClientCitizenID(long id, long citizenID);
        /* Method which should change the citizen id of the client with the given fitness club id. 
        Note that id is the id of the client on the fitness club list and the citizen id is their national id number.
        It should return false if :
            - another client on the list already has such a citizen id
            - the citizen id format is wrong i.e. not 9 digits
        It returns true otherwise signifying that the change was successful. */

        bool changeClientFee(long id, double fee);
        /* Method which should change the membership fee paid by the client with the given id to the given fee. Returns 
        true if succesfful, returns false if client with such an id doesnt exist. */

        bool changeClientMaxAmount(long max_amount);
        /* Method which should change the maximum amount of clients on the client list. If the amount of clients 
        currently inserted into the fitness club's client list is greater than the given max amount or the max amount is
        negative, it prints a warning explaining what is wrong and reutrns false, else it changes the maximum amount to 
        the one given and returns true. */

        bool changeEmployeeName(long id, const char* name);
        /* Method which which should change the name of the employee with the given id to the given name, Returns true 
        if succesfful, returns false if employee with such an id doesnt exist.  */

        bool changeEmployeeSurname(long id, const char* surname);
        /* Method which which should change the surname of the employee with the given id to the given surname. Returns 
        true if succesfful, returns false if employee with such an id doesnt exist. */

        bool changeEmployeeCitizenID(long id, long citizenID);
        /* Method which should change the citizen id of the employee with the given fitness club id. 
        Note that id is the id of the employee on the fitness club list and the citizen id is their national id number.
        It should return false if :
            - another employee on the list already has such a citizen id
            - the citizen id format is wrong i.e. not 9 digits
        It returns true otherwise signifying that the change was successful. */

        bool changeEmployeeSalary(long id, double salary);
        /* Method which should change the salary paid to the employee with the given id to the given salary value. Returns 
        true if succesfful, returns false if employee with such an id doesnt exist. */

        bool changeEmployeeMaxAmount(long max_amount);
        /* Method which should change the maximum amount of employees on the employee list. If the amount of employees 
        currently inserted into the fitness club's employee list is greater than the given max amount or the max amount is
        negative, it prints a warning explaining what is wrong and reutrns false, else it changes the maximum amount to 
        the one given and returns true. */

};

#endif