#include<iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

void push(Node **head, int value)
{
    
    Node *temp = new Node();
    temp->value = value;

    if (*head == NULL) {
        temp->next = NULL;
        *head = temp;
        return;
    }

    temp->next = *head;
    *head = temp;
   
}

int peek(Node* head){
    return head->value;
}

void pop(Node **head){

    if (*head == NULL) return;
    
    Node *temp1 = *head;
    *head = temp1->next;

    delete temp1;

}

    int main()
{
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    pop(&head);

    cout<<peek(head);

    return 0;
}