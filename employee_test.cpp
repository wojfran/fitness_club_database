#include "Employee.h"
#include "List.h"
#include "Client.h"

int main(){

    cout << "Testing all constructors of Employee: " << endl;
    Employee* adam = new Employee();
    Employee* eve = new Employee("eve", "applebaum");
    Employee* barbara = new Employee("barbara", "rabarbara", 350);
    

    Client* one = new Client("one", "one", 1);
    Client* two = new Client("two", "two", 1);
    Client* three = new Client("three", "three", 1);
    Client* four = new Client("four", "four", 1);
    Client* five = new Client("five", "five", 1);
    
    cout << "Testing Client adam to Employee barbara and Employee eve: " << endl;
    eve->addClient(one, 1);
    barbara->addClient(two, 2);
    eve->addClient(three, 3);
    barbara->addClient(four, 4);
    eve->addClient(five, 5);
    

    cout << "Employee adam (default constructor): " << endl;
    cout << *adam << endl;
    cout << "Employee eve (defined constructor with default value of salary): " << endl;
    cout << *eve << endl;
    cout << "Employee barbara (defined constructor): " << endl;
    cout << *barbara << endl;
    

    cout << "Testing setter methods on copy of Employee adam: " << endl;

    cout << "Before: " << endl;
    cout << *adam << endl;
    adam->setName("NEWNAME");
    adam->setSurname("NEWSURNAME");
    adam->setSalary(231.21312);
    cout << "After: " << endl;
    cout << *adam << endl;

    cout << "Testing Employee adam (deletion of origin): " << endl;
    delete adam;
}