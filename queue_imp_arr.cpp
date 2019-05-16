#include <iostream>
#define MAX_SIZE 100
using namespace std;

int start = -1;

void enqueue(int *arr, int value)
{
    
    arr[++start] = value;
}

int dequeue(int *arr)
{
   
    return arr[start--];
}

int peek(int *arr)
{
    return arr[start];
}

int main()
{
    int *arr = new int[MAX_SIZE];

    enqueue(arr, 5);
    enqueue(arr, 6);
    enqueue(arr, 5);
    enqueue(arr, 7);
    enqueue(arr, 6);

    dequeue(arr);

    cout << peek(arr);

    return 0;
}