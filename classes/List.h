#ifndef LIST
#define LIST
#include "Client.h"
#include "Employee.h"
#include <iostream>
#include <stdio.h>
#include <typeinfo>
using namespace std;

template <typename T>
class List {
    private:
        struct Node{
            T* data;
            /* Data attribute of the Node structure storing an object of the 
            specified type T */

            Node* next;
            /* Pointer to the next Node of the list. Can be nullptr. */

            long id;
            /* Id of the node. Used to distinguish objects on the list. 
            Cannot be less than 1 and should be given based on the class
            attribute static long id or an explicitly given id number in
            the insertNode method. */
        };
        
        Node* head;
        /* Pointer to the head node signifying the end of the list. */
        
        long amount;
        /* Amount of nodes own the list. */

        long max_amount;
        /* Maximum amount of nodes which can be in the list. Cannot be set to
        0 or less. */

        long id;
        /* id number of the list, when an empty list is created it should  
        be set to 0. Each time a new node is inserted with insertNode it should be
        incremented by 1 and its value should be given to the id attribute of the
        newly created node. */

        void removeAllElements();
        /* Private method which deleted all nodes of the list along with the objects
        pointed to by the data pointer. */

    public:
        List();
        /* Default constructor of List. Sets head to nullptr, amount to 0, max_amount to 0 
        and index to 0, */

        ~List();
        /* Default destructor of List. It must ensure that no memory leaks occur.
        Hence it must delete every dynamically allocated object on the list */

        void changeMaxAmount(long max);
        /* Changes the max amount attribute of the list to the one given. */

        bool insertNode(T* x,  long id = -1);
        /* Method which inserts a new Node into the list storing the given data x.
        First a condition is checked if the amount is smaller than max_amount. 
        If not the method prints a warning that the limit of list elements has 
        been reached, else the method proceeds to insert a new node to the list.
        Before creating the new node it should increment the amount and the id 
        attribute to then give id to the newly created node. It sets the head's 
        next pointer to the newly created node, sets the next pointer of that 
        new node to nullptr and sets head to the newly created node. */

        long giveListID();
        /* Method which returns the static id attibute. */

        T* findNode(long id);
        /* Method which returns the object stored on the list with the given id. If 
        there is no object with such an id, a warning is printed and the method
        returns nullptr. */

        T& iterateToNthNodeObject(long n);
        /* Method which passes through n nodes starting from the head node and 
        returns the nth one. Useful for for loops and overall iteration. 
        Warning: long n does not signify the id of the node which will be returned. */

        long iterateToNthNodeID(long n);
        /* Method which passes through n nodes starting from the head node and 
        returns the id of nth one. Useful for for loops and overall iteration. Can
        be used alongside iterateToNthNodeObject to determine the returned objects id.*/

        bool removeNode(long id);
        /* Method which removes the node with the given id from the list. If 
        there is no object with such an id, a warning is printed and the method returns
        false. If there is an object with the given id and the node we wish to remove 
        is the last node on the list it is simply deleted. If the node we wish to 
        remove is the head node then the next attribute of the node pointing to head 
        is set to nullptr and that node is proclaimed as head, else it sets the next pointer
        of the node which next attribute points to the node storing that object
        to the node pointed by the next attribute of the node we wish to remove. 
        If the node can be removed the amount is decreased by 1. */

        void softDelete();
        /* A copy of removeAllElements, this method, however, doesn't delete the objects pointed to by 
        the pointers stored in the data attribute of each node. */

        void printList() const;
        /* Method which iterates over each node in the list, printing its node id along with
        the object stored in the node. 
        Warning: For this method to work the specified type of the object T must have an
        overloaded << operator. */

        bool isEmpty() const;
        /* Method which checks if the list is empty i.e. amount == 0. */

        long getAmount();
        /* Method returning the amount of nodes on the list. */

        long getMaxAmount();
        /* Method returning the max amount of nodes on the list. */

};

template<typename T>
List<T>::List() {
    this->head = nullptr;
    this->amount = 0;
    this->id = 0;
    this->max_amount = 500;
}

template <typename T>
List<T>::~List(){
    removeAllElements();
}

template <typename T>
void List<T>::changeMaxAmount(long max) {
    this->max_amount = max;
}

template <typename T>
void List<T>::printList() const{
    Node* etr = head;
    while(etr) {
        cout << "ID: " << etr->id << endl;
        cout << *etr->data << endl;
        etr = etr->next;
    }
}

template <typename T>
bool List<T>::isEmpty() const {
    return amount==0;
}

template <typename T>
long List<T>::getAmount() {
    return amount;
}

template <typename T>
long List<T>::getMaxAmount() {
    return max_amount;
}

template <typename T>
bool List<T>::insertNode(T* x, long id) {
    if(amount < max_amount) {

        // this part exists to check if the method has been called without
        // specifying the id of the node or specyfing. In the second case 
        // which is called in the Employee::addClient method we assume that the 
        // specified id is different from the ids already on the employees
        // clients list as this condition is checked in the FitnessClub::assignClientToEmployee
        // method which is the only method using the Employee::addClient method
        if (id < 0) id = ++this->id;
        else this->id++;

        
        Node* etr = new Node;
        if (etr == nullptr) {
            cerr << "List::insertNode: Allocation memory failure!" << endl;
            return false;
        }

        

        etr->data = x;
        etr->next = head;
        etr->id = id;

        if (strcmp(typeid(*x).name(), "6Client") == 0) {
            cout << "A client with the following id has been added: " << id << endl << endl;
        } else if (strcmp(typeid(*x).name(), "8Employee") == 0 ) {
            cout << "An employee with the following id has been added: " << id << endl << endl;
        } else cout << "A node with the following id has been added: " << id << endl << endl;
        
        head = etr;
        amount++;
        return true;

    } else {
        cout << "New element cannot be inserted as the list is alread full.\n";
        cout << "If you wish to add it nonetheless, please increase the maximum amount of elements.";
        cout << endl;
        return false;
    }
}

template <typename T>
long List<T>::giveListID() {
    return id;
}

template <typename T>
T* List<T>::findNode(long id) {
    Node* current = head;
    while (current) {
        if (current->id == id) return current->data;
        current = current->next;
    }
    return nullptr;
}

template <typename T>
T& List<T>::iterateToNthNodeObject(long n) {
    if (n < 1 || this->isEmpty()) return *head->data;
    Node* current = head;
    while (n > 1) {
        if (current->next == nullptr) return *current->data;
        current = current->next;
        n--;
    }
    return *current->data;
}

template <typename T>
long List<T>::iterateToNthNodeID(long n) {
    if (n < 1 || this->isEmpty()) return head->id;
    Node* current = head;
    while (n > 1) {
        if (current->next == nullptr) return current->id;
        current = current->next;
        n--;
    }
    return current->id;
}

template <typename T>
bool List<T>::removeNode(long id) {
    Node* current = head;
    Node* previous = nullptr;

    while (current) {
        if (current->id == id) {
            if (previous == nullptr) {
                head = current->next;
                cout << "Node with ID '" << id << "' has been deleted. \n" << endl;
                delete current;
                amount--;
                return true;
            } else {
                previous->next = current->next;
                cout << "Node with ID '" << id << "' has been deleted. \n" << endl;
                delete current;
                amount--;
                return true;
            }
        }
        previous = current;
        current = current->next;
    }
    return false;
}

template <typename T>
void List<T>::softDelete() { // private
    Node* etr = head;
    while (etr) { // remove all elements from *this
        etr = etr->next;
        delete head;
        head = etr;
    }
    this->amount = 0;
}

template <typename T>
void List<T>::removeAllElements() { // private
    Node* etr = head;
    while (etr) { // remove all elements from *this
        etr = etr->next;
        delete head->data;
        delete head;
        head = etr;
    }
    this->amount = 0;
}

#endif