// Lab 1: Singly Linked List for Username/Password storage

// Goal: Implement a simple credential store using a singly linked list

// Instructions:
// 1) Search for "TODO" and implement each function.
// 2) Build & run:   g++ -std=c++17 -O2 -Wall linked_lists.cpp -o lab && ./lab
// 3) Do not change function signatures

// NOTE: In the real world, NEVER store plaintext passwords.


// ADD HEADER FILES HERE
#include <iostream>
using namespace std;

// -----------------------------
// Data Model
// -----------------------------
struct User {
    string username;
    string password; 
    User* next;
    
    User(string u, string p) {
        username = u;
        password = p;
        next = nullptr;
    }
};

//Fucntion implementations
bool insertUser(User*& head, const string& username, const string& password);
User* findUser(User* head, const string& username);
bool authenticate(User* head, const string& username, const string& password);
bool removeFront(User*& head);
bool removeByUsername(User*& head, const string& username);
void clearList(User*& head);
size_t size(User* head);
void printUsers(User* head);


int main() {
  
    // Write code here to test your implementation
    //create a linked list to start with
    User* head = new User("Dayne", "Ballerz");
    head->next = new User("Wayne", "Ballerz");
    head->next->next = new User("Clint", "ffghhiie");


    printUsers(head);

    string username, password;
    username = "Dayne";
    password = "Stroyer";
    insertUser(head, username, password);

    printUsers(head);

    username = "Nanz";
    findUser(head, username);

    username = "Clint";
    password = "ffghhiie";
    authenticate(head, username, password);

    removeFront(head);

    printUsers(head);


    username = "Brian";
    removeByUsername(head, username);

    printUsers(head);

    clearList(head);

    printUsers(head);

    cout << "Linked list size: " << size(head) << endl;

    
    return 0;
}

// -----------------------------
// Core API — implement these
// -----------------------------

// Inserts a new (username, password) at the END of the list.
// If username already exists, do NOT insert a duplicate; return false.
// Otherwise insert and return true.
//code has a single while loop so the run time is O(n) or linear time
bool insertUser(User*& head, const string& username, const string& password) {
    // TODO: implement
    User* current = head;
   while(current->next != nullptr) {
    if(current->username == username) {
        return false;
    }
        current = current->next;
   }
   if(current->username == username) {
        return false;
    }
    current->next = new User(username, password);

    return true;
}

// Returns pointer to the node with matching username; otherwise nullptr.
//code has a single while loop so the run time is O(n) or linear time
User* findUser(User* head, const string& username) {
    // TODO: implement
    User* current = head;
    while(current != nullptr) {
        if(current->username == username) {
            cout << "User found.\n";
            return current;
        }
        current = current->next;
    }
    
    return nullptr;
}

// Returns true if (username, password) matches an existing node; false otherwise.
//code has a single while loop so the run time is O(n) or linear time
bool authenticate(User* head, const string& username, const string& password) {
    // TODO: implement
     User* current = head;
    while(current != nullptr) {
        if(current->username == username) {
            if(current->password == password) {
                cout << "Username and password matches.\n";
                return true;
            }
            
        }
        current = current->next;
    }
   
    return false;
}

// Deletes the FIRST node (head) and updates head. No-op if list is empty.
// Return true if a node was deleted, false otherwise.
// code only uses simple condition statements so the run time is O(1) or constant time
bool removeFront(User*& head) {
    // TODO: implement
    if(head == nullptr) {
        cout << "List is empty...";
        return false;
    } else {
    //use the swap method to delete the old head
    User* temp = head;
    head = head->next;
    delete temp;
    }
    
    return true;
}

// Deletes the node with matching username (first match only).
// Return true if a node was found & deleted; false if not found.
//code has a single while loop so the run time is O(n) or linear time
bool removeByUsername(User*& head, const string& username) {
    // TODO: implement
    User* current = head;
    while(current != nullptr) {
        if(current->username == username) {
            delete current;
            cout << "Node deleted" << endl;
            return true;
        }
        current = current->next;
    }
    cout << "Name not found...\n";
    return false;
}

// Deletes ALL nodes and sets head=nullptr. 
//code has a single while loop so the run time is O(n) or linear time
void clearList(User*& head) {
    // TODO: implement
    User* current = head;
    while(current != nullptr) {
        current = current->next;
        delete current;
    }

    head = nullptr;
    
}

// Returns number of nodes.
//code has a single while loop so the run time is O(n) or linear time
size_t size(User* head) {
    // TODO: implement
    size_t count = 0;
    User* current = head;
    while(current != nullptr) {
        count++;
        current = current->next;
        }
    
    return count;
}

// Prints usernames in order, separated by " -> " then " -> NULL".
// Example: alice -> bob -> charlie -> NULL
//code has a single while loop so the run time is O(n) or linear time
void printUsers(User* head) {
    // TODO: implement
    if(head == nullptr) {
        cout << "List empty...\n";
        return;
    }

    User* current = head;
    while(current != nullptr) {
        cout << current->username << " -> ";
        current = current->next;
    } cout << "Null" << endl;
    
}
