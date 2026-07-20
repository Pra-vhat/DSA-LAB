// Convert from infix to postfix

#include <iostream>
#include <stack>
using namespace std;

int main(){
    string in;
    string out;
    getline(cin, in);

    // "a+b" should be converted to ab+
    stack<char> Stack;
    Stack.push('(');
    for(int i = 0; i < in.size(); i++){
        if(in[i] == ' ') continue;
        if(in[i] == '+' || in[i] == '-'){
            char top = Stack.top();
            if(top == '+' || top == '-' || top == '*' || top == '/' || top == '^'){
                while(Stack.top() != '('){
                    out.append(1, Stack.top());
                    Stack.pop();
                }
                Stack.push(in[i]);
            }else{
                Stack.push(in[i]);
            }
        }else if(in[i] == '*' || in[i] == '/'){
            char top = Stack.top();
            if(top == '+' || top == '-'){
                // if the top of stack has precedence lower than in[i] (i.e. if in[i] is '*' and top = '+')
                // just push * into the stack, so that when you pop the stack, '*' is evaluated first
                // pop only when the precedence of symbol on the stack top is higher or equal
                Stack.push(in[i]);
            }else if(top == '*' || top == '/' || top == '^'){
                while(Stack.top() != '(' && Stack.top() != '+' && Stack.top() != '-'){
                    out.append(1, Stack.top());
                    Stack.pop();
                }
                Stack.push(in[i]);
            }else{
                // if the character is '(', just push it to the stack
                Stack.push(in[i]);
            }
        }else if(in[i] == '^'){
            char top = Stack.top();
            // because '^' operator has right to left associativity, you pop it all in the end
            Stack.push(in[i]);
        }else if(in[i] == '('){
            Stack.push('(');
        }else if(in[i] == ')'){
            while(Stack.top() != '('){
                out.append(1, Stack.top());
                Stack.pop();
            }Stack.pop(); // pop the one '(' character
        }else{
            out.append(1, in[i]);
        }
    }
    while(Stack.top() != '('){
        out.append(1, Stack.top());
        Stack.pop();
    }


    cout << out << endl;


    return 0;
}