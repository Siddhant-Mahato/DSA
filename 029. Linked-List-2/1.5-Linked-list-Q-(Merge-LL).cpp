
#include <iostream>
using namespace std;

/*

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

void solve(Node<int> *first, Node<int> *second)
{

    Node *curr1 = first;
    Node *next1 = curr1->next;

    Node *curr2 = second;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {

        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {

            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
        }
    }
}

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    if (first->data <= second->data)
    {
        solve(first, second);
    }
    else
    {
        solve(second, first);
    }
}

*/

/*
void sortLinkedList(Node *&head)
{
    vector<int> elements;
    Node *temp = head;
    while (temp != NULL)
    {
        elements.push_back(temp->data);
        temp = temp->next;
    }

    sort(elements.begin(), elements.end());

    temp = head;
    for (size_t i = 0; i < elements.size(); i++)
    {
        temp->data = elements[i];
        temp = temp->next;
    }
}

*/