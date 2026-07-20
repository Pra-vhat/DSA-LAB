#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char symbol){

    switch(symbol){

    case ('+'):
        return 0;
    case ('-'):
        return 0;
    case('*'):
        return 1;
    case('/'):
        return 1;
    case ('^'):
        return 2;
    default:
        return -1;
    }
}


string toPostfix(string in){
    string out;
    stack <char> Stack;
    for(int i = 0; i < in.size(); i++){
        if(in[i] == ' '){
            continue;
        }

        if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/'){
            if(Stack.empty()){
                Stack.push(in[i]);
            }else{
                if((precedence(Stack.top()) < precedence(in[i]))){
                    Stack.push(in[i]);
                }else{
                    while(!Stack.empty() && (precedence(Stack.top()) >= precedence(in[i]) && Stack.top() != '(')){
                        out.append(1, Stack.top());
                        Stack.pop();
                    }
                    Stack.push(in[i]);
                }
            }
        }else if(in[i] == '^'){
            if(Stack.empty()){
                Stack.push(in[i]);
            }else{
                while(!Stack.empty() && Stack.top() != '(' && precedence(Stack.top()) > precedence(in[i])){
                    out.append(1, Stack.top());
                    Stack.pop();
                }
                Stack.push(in[i]);
            }
        }
        else if(in[i] == '(' || in[i] == ')'){
            if(in[i] == '('){
                Stack.push('(');
            }else{
                while(Stack.top() != '('){
                    out.append(1, Stack.top());
                    Stack.pop();
                }Stack.pop(); // pop the final '('
            }
        }
        else{
            out.append(1, in[i]);
        }
    }
    while(!Stack.empty()){
        out.append(1, Stack.top());
        Stack.pop();
    }

    return out;
}

string toPrefix(string in){
    reverse(in.begin(), in.end());
    for(int i = 0; i < in.size(); i++){
        if(in[i] == ')'){
            in[i] = '(';
        }else if(in[i] == '('){
            in[i] = ')';
        }
    }
    string out = toPostfix(in);
    reverse(out.begin(), out.end());
    return out;
}

int main(){
    while(1){
        string in;
        cin >> in;
        cout << "Postfix: " << toPostfix(in) << endl;
        cout << "Prefix: " << toPrefix(in) << endl;
    }
}