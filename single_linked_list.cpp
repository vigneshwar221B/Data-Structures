#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

//Global ref
Node *head;

// reverse list using recursion
void recRevNode(Node *travPtr){

    if (travPtr->next == NULL)
    {
       head = travPtr;
       return; 
    }

    recRevNode(travPtr->next);
    travPtr->next->next = travPtr;
    travPtr->next = NULL;
}

//reverse a linked list
void reverse(Node **head){

    if (*head == NULL)
        return;

    Node *currentNode = *head;
    Node *nextNode = currentNode;
    Node *prevNode = NULL;

    while(currentNode != NULL){
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
        
    }
    *head = prevNode;  
}

//sizeNode of the linkedlist
int sizeNode(Node **headref){

    Node *temphead = *headref;
    int i = 0;

    if (*headref == NULL)
    {
        return i;
    }
    while (temphead->next != NULL)
    {
        temphead = temphead->next;
        i += 1;
    }
    return i;
}

// to delete a node
void deleteNode(Node **head, int index){

    Node *temphead = *head;
    Node *temphead1 = *head;

    if (index == 0)
    {
        *head = temphead->next;
        return;
    }

    for (int i = 1; i <= index-1; i++)
    {
        temphead = temphead->next; 
    }

    temphead1 = temphead->next;
    if (index-1 == sizeNode(head))
    {
        delete temphead1;
        temphead->next = NULL;
        return;
    }
    
    temphead->next = temphead1->next;
    delete temphead1;

}

// get a value for a given index
int getNode(Node **head, int index){

    Node *temphead = *head;

    if (index == 0)
    {
        return temphead->value;
    }

    for (int i = 1;i<=index;i++)
    {
        temphead = temphead->next;
    }
    return temphead->value;
    
}

//insert at a paricular index
void insert(Node **head,int index, int value){
    Node *temphead = *head;

    Node *temp = new Node();
    temp->value = value;

    if(value == 0){
        temp->next = temphead;
        temphead = temp;
        return ;
    }

    for(int i = 1;i<=index-1;i++)
    {
        temphead = temphead->next;
    }

    Node* temp1 = temphead;
    temp->next = temp1->next;
    temp1->next = temp;

}

//beginning of the linked list
void add(Node **head, int value){
    Node *temphead = *head;

    Node *temp = new Node();
    temp->value = value;
    temp->next = *head;
    *head = temp;
}

//end of the linked list
void push(Node **head, int value){

    Node *temphead = *head;

    Node *temp = new Node();
    temp->value = value;
    temp->next = NULL;

    if (*head == NULL){
        *head = temp;
        return;
    }

    while (temphead->next != NULL){
        temphead = temphead->next;
    }
    temphead->next = temp;
}

// To print the linked list
void print(Node * head){
    Node *temp = head;

    while (temp != NULL){
        cout << temp->value << "\n";
        temp = temp->next;
    }
}

//reverse print
void revPrint(Node *head)
{
    Node *headref = head;
    int i = sizeNode(&head);
    while (i >= 0)
    {
        cout << getNode(&headref, i)<<"\n";
        i--;
    }
}

//print the list
void recPrint(Node* head){
    if (head == NULL)
    {
        return;
    }
    cout<<head->value<<"\n";
    recPrint(head->next);
}

// reverse print using recursion
void recRevPrint(Node *head)
{
    //  3  2  1  0

    if (head == NULL)
    {
        return;
    }
    
    recRevPrint(head->next);
    cout << head->value << "\n";
 
}

int main(){

    head = NULL;

    add(&head, 1);
    add(&head, 2);
    add(&head, 3);
    push(&head, 0);
    insert(&head,1,4);

    deleteNode(&head, 1);

    recPrint(head);

    cout << "------------------"<< "\n";

    recRevPrint(head);

    cout<<"------------------"<<"\n";
    cout<<"size: "<<sizeNode(&head)<<"\n";
    cout<<"Node val at 2: "<<getNode(&head, 2)<<"\n";
    cout << "------------------"<<"\n";

    recRevNode(head);
    print(head);

    return 0;
}