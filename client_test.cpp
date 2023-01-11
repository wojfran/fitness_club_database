#include "Client.h"

int main(){

    cout << "Testing all constructors of client: " << endl;
    Client* adam = new Client();
    Client* eve = new Client("eve", "applebaum");
    Client* barbara = new Client("barbara", "rabarbara", 350);
    Client assignment;
    assignment = *adam;

    
    cout << *eve << endl;
    cout << *barbara << endl;
    cout << "Client adam:" << endl;
    cout << *adam << endl;
    cout << "Copy of Client adam: " << endl;
    cout << assignment << endl;

    cout << "Testing setter methods on copy of Client adam: " << endl;

    cout << "Before: " << endl;
    cout << assignment << endl;
    assignment.setName("NEWNAME");
    assignment.setSurname("NEWSURNAME");
    assignment.setFee(231.21312);
    assignment.setStatus(true);
    cout << "After: " << endl;
    cout << assignment << endl;
    

    cout << "Testing client assignment (change of value): " << endl;
    cout << "Client adam:" << endl;
    cout << *adam << endl;
    cout << "Copy of Client adam: " << endl;
    cout << assignment << endl;

    cout << "Testing client assignment (deletion of origin): " << endl;
    delete adam;
    cout << "Copy of Client adam after the deletion of Client adam: " << endl;
    cout << assignment;
}