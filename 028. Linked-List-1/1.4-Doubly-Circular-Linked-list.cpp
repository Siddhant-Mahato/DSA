#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyCircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyCircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            head->next = tail;
            head->prev = tail;
            tail->next = head;
            tail->prev = head;
        }
        else {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at the head." << endl;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            insertAtHead(value);
            return;
        }
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
        cout << "Inserted " << value << " at the tail." << endl;
    }

    void insertAfterValue(int value, int newValue) {
        if (head == nullptr) {
            cout << "List is empty. Cannot insert after value." << endl;
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == value) {
                Node* newNode = new Node(newValue);
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
                cout << "Inserted " << newValue << " after " << value << "." << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << value << " not found in the list. Cannot insert." << endl;
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete node." << endl;
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == value) {
                if (temp == head) {
                    head = temp->next;
                }
                if (temp == tail) {
                    tail = temp->prev;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                cout << "Deleted node with value " << value << "." << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << value << " not found in the list. Cannot delete node." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Doubly Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyCircularLinkedList list;
    int choice, value, afterValue;

    while (true) {
        cout << "MENU:" << endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at tail" << endl;
        cout << "3. Insert after a value" << endl;
        cout << "4. Delete a node" << endl;
        cout << "5. Display list" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert at the head: ";
                cin >> value;
                list.insertAtHead(value);
                break;
            case 2:
                cout << "Enter the value to insert at the tail: ";
                cin >> value;
                list.insertAtTail(value);
                break;
            case 3:
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Enter the value after which to insert: ";
                cin >> afterValue;
                list.insertAfterValue(afterValue, value);
                break;
            case 4:
                cout << "Enter the value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 5:
                list.display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
