#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }

    ~Node() {
        cout << "Memory freed for node with data " << data << endl;
        if (next != NULL) {
            delete next;
        }
    }
};

void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node*& tail, Node*& head, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node*& tail, Node*& head, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node*& tail, Node*& head, int position, int d) {
    if (position <= 0) {
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 1) {
        insertAtHead(tail, head, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1) {
        if (temp == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL) {
        cout << "Invalid position" << endl;
        return;
    }
    Node* newNode = new Node(d);
    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    if (newNode->next == NULL) {
        tail = newNode;
    }
}

void deleteNode(int position, Node*& head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (position <= 0) {
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position) {
        if (temp == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL) {
        cout << "Invalid position" << endl;
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    temp->prev = NULL;
    temp->next = NULL;
    delete temp;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int choice;
    while (true) {
        cout << "MENU:" << endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at tail" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete node" << endl;
        cout << "5. Print list" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter the data: ";
                cin >> data;
                insertAtHead(tail, head, data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter the data: ";
                cin >> data;
                insertAtTail(tail, head, data);
                break;
            }
            case 3: {
                int position, data;
                cout << "Enter the position: ";
                cin >> position;
                cout << "Enter the data: ";
                cin >> data;
                insertAtPosition(tail, head, position, data);
                break;
            }
            case 4: {
                int position;
                cout << "Enter the position of the node to delete: ";
                cin >> position;
                deleteNode(position, head);
                break;
            }
            case 5: {
                print(head);
                break;
            }
            case 6: {
                cout << "Exiting..." << endl;
                delete head;
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }

    return 0;
}
