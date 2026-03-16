//COMSC 210 | Lab 21 | Alexander Sierra
#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 15, W = 10;

class Goat {
private:
    int age;
    string name;
    string color;
    string names[SIZE]={"Daisy", "Clover", "Pepper",
    "Luna", "Rocky", "Maple", "Willow", "Rusty",
    "Jasper", "Olive", "Scout", "Ginger", "Thor",
    "Bella", "Milo"};
    string colors[SIZE]={"White", "Black", "Brown",
    "Gray", "Cream", "Tan", "Golden", "Chocolate",
    "Silver", "Spotted", "Speckled", "Black and White",
    "Brown and White", "Red", "Sandy"};
public:
    //constructors
    Goat() {
        age = rand() % (20-1) + 1;
        name = names[rand() % (SIZE-1)];
        color = colors[rand() % (SIZE-1)];
    }

    Goat(int a, string n, string c) {
        age = a;
        name = n;
        color = c;
    }
    //getters
    int getAge() {return age;}
    string getName() {return name;}
    string getColor() {return color;}
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;

        Node(Goat g, Node* p = nullptr, Node* n = nullptr) {
            data = g;
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(Goat g) {
        Node* newNode = new Node(g);

        if (!tail) { // if there's no tail, the list is empty
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat g) {
        Node* newNode = new Node(g);

        if (!head) { // if there's no head, the list is empty
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(Goat g, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(g);

        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < position && temp; ++i) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next) {
            temp->next->prev = newNode;
        }
        else {
            tail = newNode; // Inserting at the end
        }

        temp->next = newNode;
    }

    void delete_node(Goat g) {
        if (!head) return; // Empty list

        Node* temp = head;

        while (temp && ((temp->data.getName() != g.getName()) && 
        (temp->data.getAge() != g.getAge()) && 
        (temp->data.getColor() != g.getColor()))) {
            temp = temp->next;
        }

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void print() {
        Node* current = head;

        if (!current) {
            cout << "List is empty" << endl;
            return;
        }
        
        while (current) {
            cout << setw(W) << current->data.getName() << " (";
            cout << current->data.getColor() << ", ";
            cout << current->data.getAge() << ")" << endl;
            current = current->next;
        }

        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;

        if (!current) {
            cout << "List is empty" << endl;
            return;
        }
        
        while (current) {
            cout << setw(W) << current->data.getName() << " (";
            cout << current->data.getColor() << ", ";
            cout << current->data.getAge() << ")" << endl;
            current = current->prev;
        }

        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    srand(time(0));
    DoublyLinkedList list;
    int s = rand() % (20-5) + 5;
    for (int i = 0; i < s; i++) {
        Goat *g = new Goat;
        list.push_back(*g);
    }
    cout << "Forward:" << endl;
    list.print();
    cout << "Backward:" << endl;
    list.print_reverse();
    return 0;
}