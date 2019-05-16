#include<iostream>
#include <string>
#include <stack>

using namespace std;

bool IsOperand(char C)
{
    if (C >= '0' && C <= '9')
        return true;
    if (C >= 'a' && C <= 'z')
        return true;
    if (C >= 'A' && C <= 'Z')
        return true;
    return false;
}

bool IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
        return true;

    return false;
}

int GetOperatorWeight(char operator1)
{
    int weight;
    switch (operator1)
    {
    case '+':
    case '-':
        weight = 1;
        break;
    case '*':
    case '/':
        weight = 2;
        break;
    default:
        weight = 0;
    }
    return weight;
}

int HasHigherPrecedence(char op1, char op2)
{
    //cout << op1 << "\t" << op2 << "\n";
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);
    //cout<<op1Weight<<"\t"<<op2Weight<<"\n";
    return op1Weight < op2Weight ? true : false;
}

string resolve(string infStr){

    string res = "";
    stack<char> s;

    for (int i = 0; i < infStr.length(); i++)
    {
        if (infStr[i] == ' ' || infStr[i] == ',') continue;

        else if (IsOperand(infStr[i])){
            res+=infStr[i];
        }

        else if (s.empty() && IsOperator(infStr[i])){
            s.push(infStr[i]);
        }

        else if (!s.empty() && IsOperator(infStr[i]))
        {
            if (HasHigherPrecedence(s.top(), infStr[i]))
            {
                s.push(infStr[i]);
            }
            else{
                while(!s.empty() && s.top() != '('){
                    res+=s.top();
                    s.pop();
                }
                s.push(infStr[i]);
            }
            
        }

        else if (infStr[i] == '(')
        {
            s.push(infStr[i]);
        }

        else if (infStr[i] == ')')
        {
            
            while (s.top() != '(')
            {
                
                res += s.top();
                s.pop();

            }

            s.pop();
        }
    }

    if(!s.empty()){
        while (!s.empty())
        {
            res+=s.top();
            s.pop();
        }
        
    }
    return res;
}

int main(){
    //string infixstr = "a + b * c - d * e";
    string infixstr = "( ( a + b ) * c - d ) * e";

    cout<<resolve(infixstr);
    return 0;
}