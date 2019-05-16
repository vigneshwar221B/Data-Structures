#include<iostream>
#include <string>
#include <stack>
using namespace std;

int solve(char operation, int operand1, int operand2){
    if (operation == '+')
        return operand1 + operand2;
    else if (operation == '-')
        return operand1 - operand2;
    else if (operation == '*')
        return operand1 * operand2;
    else if (operation == '/')
        return operand1 / operand2;

    return -1;
}

bool isNum(char ch ){
    return (ch >= '0' && ch <='9');
}

bool isOperand(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evaluate(string ch){
    stack<int> s;
    for (int i = 0; i < ch.length(); i++)
    {
        if (ch[i] == ' ' || ch[i] == ',') continue;

        if (isNum(ch[i]) && !isOperand(ch[i]))
        {
           
            int operand = ch[i] - '0';

            while (i<ch.length() && isNum(ch[i+1]))
            {
                i+=1;
                operand = (operand * 10) + (ch[i]-'0');   // '0' = 48 in ASCII
            }
            
            s.push(operand);
           
        }
        else if (isOperand(ch[i]))
        {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            
            int result = solve(ch[i], operand1, operand2);
            
            s.push(result);
        }
    }

    return s.top();
}

int main(){
    string c = "2 3 * 5 4 * + 9 -";
    cout<< evaluate(c);
    return 0;
}