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
    User user1("Dayne", "Ballerz");
    User user2("Wayne", "Ballerz");
    User user3("Clint", "ffghhiie");

    User* head = &user1;
    user1.next = &user2;
    user2.next = &user3;

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
    
    return 0;
}

// -----------------------------
// Core API — implement these
// -----------------------------

// Inserts a new (username, password) at the END of the list.
// If username already exists, do NOT insert a duplicate; return false.
// Otherwise insert and return true.
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
User* findUser(User* head, const string& username) {
    // TODO: implement
    User* current = head;
    while(current != nullptr) {
        if(current->username == username) {
            cout << "User found.";
            return current;
        }
        current = current->next;
    }
    
    return nullptr;
}

// Returns true if (username, password) matches an existing node; false otherwise.
bool authenticate(User* head, const string& username, const string& password) {
    // TODO: implement
     User* current = head;
    while(current != nullptr) {
        if(current->username == username) {
            if(current->password == password) {
                cout << "Username and password matches.";
                return true;
            }
            
        }
        current = current->next;
    }
   
    return false;
}

// Deletes the FIRST node (head) and updates head. No-op if list is empty.
// Return true if a node was deleted, false otherwise.
bool removeFront(User*& head) {
    // TODO: implement
    
    return false;
}

// Deletes the node with matching username (first match only).
// Return true if a node was found & deleted; false if not found.
bool removeByUsername(User*& head, const string& username) {
    // TODO: implement
    
    return false;
}

// Deletes ALL nodes and sets head=nullptr. 
void clearList(User*& head) {
    // TODO: implement
    
}

// Returns number of nodes.
size_t size(User* head) {
    // TODO: implement
    
    return 0;
}

// Prints usernames in order, separated by " -> " then " -> NULL".
// Example: alice -> bob -> charlie -> NULL
void printUsers(User* head) {
    // TODO: implement
    User* current = head;
    while(current != nullptr) {
        cout << current->username << " -> ";
        current = current->next;
    } cout << "Null" << endl;
    
}
