#include <iostream>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout << "Memory is freed for node with data " << data << endl;
        if (next != NULL) {
            delete next;
        }
    }
};

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);            //? See over here the new node is created
    temp->next = head;
    //?? To new node put of data has been already done by the constructer so just have put the new node next part and will be null  as the only LINKED LIST Present.

    head = temp;            //? for very 1st node head will have it's value as is to point to 1st node
}

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;   //? As because head has to be with 1st LL so need another pointer as here TEMP which can move to other nodes. 
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node* &head, int position, int d) {
    if (position <= 0) {
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 1) {
        insertAtHead(head, d);
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
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(int position, Node* &head) {
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
        temp->next = NULL;
        delete temp;
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1) {
        if (temp == NULL || temp->next == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position" << endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    nodeToDelete->next = NULL;
    delete nodeToDelete;
}

bool isCircularList(Node* head) {
    if (head == NULL) {
        return true;
    }
    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

bool detectLoop(Node* head) {
    if (head == NULL) {
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            cout << "Cycle is present at element " << slow->data << endl;
            return true;
        }
    }
    return false;
}

void removeLoop(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (slow != fast) {
        return; // No loop found
    }
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
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
        cout << "6. Check for loop" << endl;
        cout << "7. Remove loop" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter the data: ";
                cin >> data;
                insertAtHead(head, data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter the data: ";
                cin >> data;
                insertAtTail(tail, data);
                if (head == NULL) {
                    head = tail;
                }
                break;
            }
            case 3: {
                int position, data;
                cout << "Enter the position: ";
                cin >> position;
                cout << "Enter the data: ";
                cin >> data;
                insertAtPosition(head, position, data);
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
                if (detectLoop(head)) {
                    cout << "Loop is present" << endl;
                } else {
                    cout << "No loop" << endl;
                }
                break;
            }
            case 7: {
                removeLoop(head);
                cout << "Loop removed" << endl;
                break;
            }
            case 8: {
                // cout << "Exiting..." << endl;
                // delete head;
                // return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
