#include <iostream>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertNode(Node*& tail, int element, int d) {
    if (tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        Node* curr = tail;
        while (curr->data != element) {
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* tail) {
    Node* temp = tail;
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    do {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node*& tail, int value) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    else {
        Node* prev = tail;
        Node* curr = prev->next;
        while (curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr == prev) {
            tail = NULL;
        }
        else if (tail == curr) {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

bool isCircularList(Node* head) {
    if (head == NULL) {
        return true;
    }
    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    if (temp == head) {
        return true;
    }
    return false;
}

bool detectLoop(Node* head) {
    if (head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while (temp != NULL) {
        if (visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* tail = NULL;

    int choice;
    while (true) {
        cout << "MENU:" << endl;
        cout << "1. Insert node" << endl;
        cout << "2. Print list" << endl;
        cout << "3. Delete node" << endl;
        cout << "4. Check if list is circular" << endl;
        cout << "5. Check if list has a loop" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int element, data;
                cout << "Enter the element after which to insert: ";
                cin >> element;
                cout << "Enter the data to insert: ";
                cin >> data;
                insertNode(tail, element, data);
                break;
            }
            case 2: {
                print(tail);
                break;
            }
            case 3: {
                int value;
                cout << "Enter the value of the node to delete: ";
                cin >> value;
                deleteNode(tail, value);
                break;
            }
            case 4: {
                if (isCircularList(tail)) {
                    cout << "List is circular" << endl;
                }
                else {
                    cout << "List is not circular" << endl;
                }
                break;
            }
            case 5: {
                if (detectLoop(tail)) {
                    cout << "Loop is present" << endl;
                }
                else {
                    cout << "No loop" << endl;
                }
                break;
            }
            case 6: {
                cout << "Exiting..." << endl;
                delete tail;
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
