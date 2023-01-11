#include "Employee.h"
#include "Client.h"
#include "List.h"

int main() {


    Client* adam = new Client("adam", "smith", 25.25);
    Client* barbara = new Client("barbara", "rabarbara", 350);
    Client* sue = new Client("sue", "gondese", 40);
    Employee* mark = new Employee("mark", "iplier", 3000);
    Employee* andrew = new Employee("andrew", "producer", 3500);

    cout << "Testing list creation and insertion with Client as the specified type of the list:" << endl;
    List<Client>* clients = new List<Client>();

    cout << "\nInserting three clients." << endl;
    clients->insertNode(*adam);
    clients->insertNode(*barbara);
    clients->insertNode(*sue);

    cout << "\nmylist after insertion: \n" << endl;
    clients->printList();
    
    cout << "Testing list creation and insertion with Employee as the specified type of the list: " << endl;
    List<Employee>* employees = new List<Employee>();

    cout << "\nInserting two employees." << endl;
    employees->insertNode(*mark);
    employees->insertNode(*andrew);

    cout << "\nyourlist after insertion: \n" << endl;
    employees->printList();

    cout << "\nTesting findNode method (should find and print node with id=3 and not find the node with id=4 since it doesn't exist): " << endl;
    Client* id3 = clients->findNode(3);
    Client* id4 = clients->findNode(4);

    if (id3) {
        cout << "The client on clients with ID = 3 is: \n" << *clients->findNode(3) << endl;
    } else cout << "Client id3 is null." << endl;
    
    if (id4) {
        cout << "The client on clients with ID = 4 is: \n" << *clients->findNode(4) << endl;
    } else cout << "Client id4 is null." << endl;

    cout << "\nTesting iteration methods of the list class: \n" << endl;
    cout << "(if the iterate function argument is greater than the amount of nodes on the list it returns the last node) " << endl;
    cout << "(if the iterate function argument is less than 1 it returns the first node (the current head)) \n" << endl;
   
    cout << "N = 1" << endl;
    cout << "ID: " << clients->iterateToNthNodeID(1) << endl;
    cout << clients->iterateToNthNodeObject(1) << endl;

    cout << "N = 0" << endl;
    cout << "ID: " << clients->iterateToNthNodeID(0) << endl;
    cout << clients->iterateToNthNodeObject(0) << endl;
    
    cout << "N = -1" << endl;
    cout << "ID: " << clients->iterateToNthNodeID(-1) << endl;
    cout << clients->iterateToNthNodeObject(-1) << endl;
    
    cout << "N = 2" << endl;
    cout << "ID: " << clients->iterateToNthNodeID(2) << endl;
    cout << clients->iterateToNthNodeObject(2) << endl;
    
    cout << "N = 3" << endl;
    cout << "ID: " << clients->iterateToNthNodeID(3) << endl;
    cout << clients->iterateToNthNodeObject(3) << endl;
    
    cout << "N = 4" << endl;
    cout << "ID: " << clients->iterateToNthNodeID(4) << endl;
    cout << clients->iterateToNthNodeObject(4) << endl;
    

    cout << "\nPrinting clients before deleting any nodes. " << endl;
    clients->printList();

    cout << "Deleting nodes 1, 0 and 3 (should only show information about deleting node 1 and 3 as node 0 does not exist): \n" << endl;
    clients->removeNode(1);
    clients->removeNode(0);
    clients->removeNode(3);

    cout << "Printing clients after deleting nodes with ids: 1, 0 and 3 (should only print node with id 2): " << endl; 
    clients->printList();

    cout << "Testing the addition of clients into the Employees on the employee list (insertion of Clients into the clients list which is an attribute of Employee): \n" << endl;
    employees->findNode(1)->addClient(adam, 1);
    employees->findNode(1)->addClient(clients->findNode(2), 2);
    employees->findNode(2)->addClient(sue, 1);

    employees->printList();

    cout << "Testing if the clients have been added to the employee list as hard copies (deleting clients and separate Client objects and then printing employees): \n" << endl;
    delete clients;
    delete sue;
    delete barbara;
    delete adam;

    employees->printList();
}