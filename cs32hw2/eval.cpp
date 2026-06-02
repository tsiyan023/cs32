#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

int evaluate(string infix, string& postfix, bool& result)

{
    string realinf;
    for (int n = 0; n < infix.size(); n++)
    {
        if (infix[n] != ' ')
        {
            if (infix[n] != 'F'  &&  infix[n] != 'T'  &&  infix[n] != '!'  &&  infix[n] != '&'  &&  infix[n] != '|'  &&  infix[n] != '('  &&  infix[n] != ')')
                return 1;
            else
                realinf += infix[n];
        }
    }
    
    if (realinf.size() == 0)
        return 1;
    int opencount = 0;
    int closecount = 0;
    
    stack<char> operators;
    postfix = "";
    
    for (int n = 0; n < realinf.size(); n++)
    {
        switch (realinf[n])
        {
            case 'T':
            case 'F':
                if (n > 0)
                {
                    if (realinf[n-1] == 'T' || realinf[n-1] == 'F')
                        return 1;
                }
                postfix += realinf[n];
                break;
            
            case '(':
                if (n > 0)
                    if (realinf[n-1] == 'F' ||  realinf[n-1] == 'T')
                        return 1;
                opencount++;
                operators.push(realinf[n]);
                break;
            case ')':
                closecount++;
                if(closecount > opencount)
                    return 1;
                if (realinf[n-1] == '('  ||  realinf[n-1] == '&'  ||  realinf[n-1] == '|'  ||  realinf[n-1] == '!')
                    return 1;
    
                while (operators.top() != '(')
                {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.pop();
                break;
                
                
            case '!':
                if (n == realinf.size()-1)
                    return 1;
                if (n > 0)
                    if (realinf[n-1] == 'T'  ||  realinf[n-1] == 'F')
                
                while (!operators.empty()  &&  operators.top() != '(' &&  operators.top() != '&'  &&  operators.top() != '|')
                {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(realinf[n]);
                break;
                
            case '&':
                if (n == realinf.size()-1)
                    return 1;
                if (n == 0)
                    return 1;
                if (realinf[n-1] == '(' ||  realinf[n-1] == '!'  ||  realinf[n-1] == '|'  ||  realinf[n-1] == '&')
                    return 1;
                
                while (!operators.empty()  &&  operators.top() != '(' &&  operators.top() != '|')
                {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(realinf[n]);
                break;
                
            case '|':
                if (n == realinf.size()-1)
                    return 1;
                if (n == 0)
                    return 1;
                if (realinf[n-1] == '('  ||  realinf[n-1] == '!'  ||  realinf[n-1] == '&'  ||  realinf[n-1] == '|')
                    return 1;
                while (!operators.empty()  &&  operators.top() != '(')
                {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(realinf[n]);
                break;
        }

    }
    if (opencount != closecount)
        return 1;
    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }
    
    
    for (int n = 0; n < postfix.size(); n++)
    {
        if (postfix[n] == 'T'  ||  postfix[n] == 'F')
        {
            operators.push(postfix[n]);
        }
        else if (postfix[n] == '|'  ||  postfix[n] == '&')
        {
            bool operand2;
            if (operators.top() == 'T')
                operand2 = true;
            else if (operators.top() == 'F')
                operand2 = false;
            else
            {
                cerr << "something wrong with your postfix in TF" << endl;
                return 1;
            }
            operators.pop();
            
            bool operand1;
            if (operators.top() == 'T')
                operand1 = true;
            else if (operators.top() == 'F')
                operand1 = false;
            else
            {
                cerr << "something wrong with your postfix in TF" << endl;
                return 1;
            }
            operators.pop();
            bool tempresult;
            if (postfix[n] == '|')
                tempresult = (operand1|operand2);
            else
                tempresult = (operand1&operand2);
            
            if (tempresult)
                operators.push('T');
            else
                operators.push('F');
        }
        else if (postfix[n] == '!')
        {
            bool operand;
            if (operators.top() == 'T')
                operand = true;
            else if (operators.top() == 'F')
                operand = false;
            else
            {
                cerr << "something wrong with your postfix in TF" << endl;
                return 1;
            }
            operators.pop();
            
            if (operand)
                operators.push('F');
            else
                operators.push('T');
        }
        else
        {
            cerr << "there is something wrong with you postfix!" << endl;
            return 1;
        }
    }
    bool operandfinal;
    if (operators.top() == 'T')
        operandfinal = true;
    else if (operators.top() == 'F')
        operandfinal = false;
    else
    {
        cerr << "there is something wrong with you postfix!" << endl;
        return 1;
    }
    
    operators.pop();
    if (operators.empty())
    {
        if (operandfinal)
        {
            result = true;
            return 0;
        }
        else
        {
            result = false;
            return 0;
        }
        
    }
    else
        return 1;
}
