#include<iostream>
#include<stack>
using namespace std;

void reverse(char* c, int size){
    stack<char> S;

    for (int i = 0; i < size; i++)
    {
        S.push(c[i]);
    }

    for (int i = 0; i < size; i++)
    {
        c[i] = S.top();
        S.pop();
    }
    
}

int main(){
   
    char c[6] = "hello";

    reverse(c,strlen(c));

    cout<<c;
    return 0;
}