#include<iostream>
#include <stack>
using namespace std;

bool areOpp(char c1, char c2)
{
    if (c1 == '(' && c2 == ')')
        return true;
    else if (c1 == '{' && c2 == '}')
        return true;
    else if (c1 == '[' && c2 == ']')
        return true;
    return false;
}

bool check(char* c, int size){
    stack<char> s;
    for (int i = 0; i < size; i++)
    {
        if (c[i] == '{' || c[i] == '(' || c[i] == '[')
        {
            s.push(c[i]);
        }
        else
        {
            if (!s.empty() && areOpp(c[i],s.top()))
            {
                s.pop();
            }
            else
                return false;
        } 
        
    }
    return s.empty()?true:false;
    
}

int main(){
    char c[7] = "{({)}}";

    if(check(c, strlen(c)))
        cout<<"balanced!";
    else
        cout<<"not balanced";
    
    return 0;
}