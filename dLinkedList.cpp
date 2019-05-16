#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

};

Node* head;

void add(int value){
    Node* temp  = new Node();
    temp->data = value;

    if (head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        
        return;
    }
    
    temp->next = head;
    temp->prev = NULL;
    head = temp;

}

int sizeNode(){
    Node *travPtr = head;
    int count = 0;

    while (travPtr != NULL)
    {

        count+=1;
        travPtr = travPtr->next;
    }
    return count;
}

void print(){
    Node* travPtr = head;

    while(travPtr != NULL){

        cout<<travPtr->data<<"\n";
        travPtr = travPtr->next;
    }
}

int getNode(int index){

    Node *p = head;
    int i = 0;

    if (index == 0)
    {
        return p->data;
    }
    
    while (i<index)
    {
        i += 1;
        p = p->next;
        
    }
    return p->data;
}

void revPrint(){
    Node *headref = head;
    int i = sizeNode() - 1;
    while (i >= 0)
    {
        cout << getNode(i) << "\n";
        i-=1;
    }
}

void push(int value){
    Node* temp = new Node();
    temp->data =value;

    if (head == NULL){
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return;
    }

    Node *travPtr = head;
    while (travPtr->next != NULL)
    {
        travPtr = travPtr->next;
    }
    temp->prev = travPtr;
    temp->next = NULL;
    travPtr->next = temp;
    
}

void insert(int value, int index)
{

    Node *travPtr = head;
    Node *temp = new Node();
    temp->data = value;

    if (index == 0)
    {
        temp->prev = NULL;
        temp->next = travPtr;
        travPtr->prev = temp;
        head = temp;
        return;
    }

    for (int i = 1; i <= index; i++)
    {
        
        travPtr = travPtr->next;
    }

    temp->prev = travPtr->prev;
    temp->next = travPtr;
    travPtr->prev->next = temp;
    travPtr->prev = temp;
}

int main(){
    
    head = NULL;

    push(1);  
    push(2);
    push(3);
    push(4);
    push(5);
    
    insert(6,4);
    print();

    cout<<"rev:"<<"\n";
    revPrint();
  
    return 0;
}