#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node* startptr = NULL;
Node* endptr = NULL;

void enqueue(Node **head, int value)
{
    Node* temp = new Node();
    temp->value = value;

    if (*head == NULL)
    {
       temp->next = NULL;
       startptr = temp;
       endptr = temp;
       *head = temp;
       return;
    }
    else{
        endptr->next = temp;
        endptr = temp;
        endptr->next = NULL;
    }
   
}

int peek(Node *head)
{
    return startptr->value;
}

void dequeue(Node **head)
{
    Node* temp = startptr;

    startptr = startptr->next;
    *head = startptr;

    delete temp;

}

int main()
{
    Node *head = NULL;
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    dequeue(&head);

    cout << peek(head);

    return 0;
}