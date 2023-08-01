#include <iostream>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Node(int data) {
    //     this->data = data;
    //     this->next = NULL;
    // }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head, int d) {
    // Node* temp = new Node(d);           //? See over here the new node is created.
    Node* temp = new Node();           //? See over here the new node is created.
    temp -> data = d;
    temp->next = head;  
    //?? To new node put of data has been already done by the constructer so just have put the new node next part and will be null  as the only LINKED LIST Present.

    head = temp;                    //? for very 1st node head will have it's value as is to point to 1st node 
}

// void insertAtTail(Node* &tail, int d) {
//     Node* temp = new Node(d);
//     tail->next = temp;
//     tail = temp;
// }

void print(Node* &head) {
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

// void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
//     if (position == 1) {
//         insertAtHead(head, d);
//         return;
//     }

//     Node* temp = head;
//     int cnt = 1;
//     while (cnt < position - 1) {
//         temp = temp->next;
//         cnt++;
//     }

//     if (temp->next == NULL) {
//         insertAtTail(tail, d);
//         return;
//     }

//     Node* nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void deleteNode(int position, Node* &head) {
//     if (position == 1) {
//         Node* temp = head;
//         head = head->next;
//         temp->next = NULL;
//         delete temp;
//     }
//     else {
//         Node* curr = head;
//         Node* prev = NULL;
//         int cnt = 1;
//         while (cnt < position) {
//             prev = curr;
//             curr = curr->next;
//             cnt++;
//         }
//         prev->next = curr->next;
//         curr->next = NULL;
//         delete curr;
//     }
// }

// bool isCircularList(Node* head) {
//     if (head == NULL) {
//         return true;
//     }
//     Node* temp = head->next;
//     while (temp != NULL && temp != head) {
//         temp = temp->next;
//     }
//     if (temp == head) {
//         return true;
//     }
//     return false;
// }

// bool detectLoop(Node* head) {
//     if (head == NULL) {
//         return false;
//     }
//     map<Node*, bool> visited;
//     Node* temp = head;
//     while (temp != NULL) {
//         if (visited[temp] == true) {
//             cout << "Cycle is present at element " << temp->data << endl;
//             return true;
//         }
//         visited[temp] = true;
//         temp = temp->next;
//     }
//     return false;
// }

// Node* floydDetectLoop(Node* head) {
//     if (head == NULL) {
//         return NULL;
//     }
//     Node* slow = head;
//     Node* fast = head;
//     while (slow != NULL && fast != NULL) {
//         fast = fast->next;
//         if (fast != NULL) {
//             fast = fast->next;
//         }
//         slow = slow->next;
//         if (slow == fast) {
//             cout << "Cycle is present at " << slow->data << endl;
//             return slow;
//         }
//     }
//     return NULL;
// }

// Node* getStartingNode(Node* head) {
//     if (head == NULL) {
//         return NULL;
//     }
//     Node* intersection = floydDetectLoop(head);
//     Node* slow = head;
//     while (slow != intersection) {
//         slow = slow->next;
//         intersection = intersection->next;
//     }
//     return slow;
// }

// void removeLoop(Node* head) {
//     if (head == NULL) {
//         return;
//     }
//     Node* startOfLoop = getStartingNode(head);
//     Node* temp = startOfLoop;
//     while (temp->next != startOfLoop) {
//         temp = temp->next;
//     }
//     temp->next = NULL;
// }

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
            // }
            // case 2: {
            //     int data;
            //     cout << "Enter the data: ";
            //     cin >> data;
            //     if (tail == NULL) {
            //         insertAtHead(head, data);
            //         tail = head;
            //     }
            //     else {
            //         insertAtTail(tail, data);
            //     }
            //     break;
            // }
            // case 3: {
            //     int position, data;
            //     cout << "Enter the position: ";
            //     cin >> position;
            //     cout << "Enter the data: ";
            //     cin >> data;
            //     insertAtPosition(tail, head, position, data);
            //     break;
            // }
            // case 4: {
            //     int position;
            //     cout << "Enter the position of the node to delete: ";
            //     cin >> position;
            //     deleteNode(position, head);
            //     break;
            // }
            case 5: {
                print(head);
                break;
            }
            // // case 6: {
            //     if (detectLoop(head)) {
            //         cout << "Loop is present" << endl;
            //     }
            //     else {
            //         cout << "No loop" << endl;
            //     }
            //     break;
            // }
            // case 7: {
            //     removeLoop(head);
            //     cout << "Loop removed" << endl;
            //     break;
            // }
            // case 8: {
            // //     cout << "Exiting..." << endl;
            // //     return 0;
            // }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
