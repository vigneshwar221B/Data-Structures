#include<iostream>
#define MAX_SIZE 100 
using namespace std;

int top_index = -1;

void push(int* arr, int value){
    top_index += 1;
    arr[top_index] = value;
}

int pop(int *arr){
    int a = arr[top_index];
    top_index -= 1;
    return a;
}

int peek(int *arr){
    return arr[top_index];
}

int main(){
    int* arr = new int[MAX_SIZE];
    

    push(arr, 5);
    push(arr, 6);
    push(arr, 5);
    push(arr, 6);

    pop(arr);

    cout<<peek(arr);
    
    return 0;
}