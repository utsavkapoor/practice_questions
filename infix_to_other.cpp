#include <iostream>
#include<vector>
#include<string>
using namespace std;

struct node{
    char val;
    node* next;
};

class Stack{
    node* head;
    public:
    Stack();
    void push(char chr);
    char pop();
    bool isempty();
    char top();
};

Stack::Stack(){
    head=NULL;
}

void Stack::push(char chr){
    node* temp = new node;
    temp->val = chr;
    if(head==NULL){
        temp->next=NULL;
    } else {
        temp->next=head;
    }
    head = temp;
}

char Stack::pop(){
    if(head==NULL){
        cout<<"Empty Stack"<<endl;
        return '\0';
    } else {
        int temp = head->val;
        head = head->next;
        return temp;
    }
}

bool Stack::isempty(){
    if(head==NULL){
        return true;
    }
    return false;
}

char Stack::top(){
    return head->val;
}

bool isoperand(char var){
    if(var=='/' || var=='^' || var=='*' || var=='+' || var=='-'){
        return true;
    }
    return false;
}

int priority(char var){
    if(var=='^'){
        return 5;
    } else if(var=='/'){
        return 4;
    } else if(var=='*'){
        return 3;
    } else if(var=='+'){
        return 2;
    } else if(var=='-'){
        return 1;
    } else {
        return 0;
    }
}

vector<char> infix_to_postfix(vector<char> expr){
    vector<char> answer;
    Stack operand;
    operand.push('#');
    int i=0;
    while(i<expr.size()){
        if((expr[i] >= 'a' && expr[i] <= 'z')||(expr[i] >= 'A' && expr[i] <= 'Z')){
            answer.push_back(expr[i]);
        } else if(expr[i] == '('){
            operand.push('(');
        } else if(expr[i] == ')'){
            while(operand.top() != '(' && operand.top() != '#'){
                char temp = operand.pop();
                answer.push_back(temp);
            }
            if(operand.top()=='('){
                operand.pop();
            }
        } else if(isoperand(expr[i])){
            int random = priority(expr[i]);
            int random1 = priority(operand.top());
                if(random > random1){
                    operand.push(expr[i]);
                } else {
                    while(random < random1 && operand.top() != '#'){
                        char temp2 = operand.pop();
                        answer.push_back(temp2);
                        random1 = priority(operand.top());
                    }
                    operand.push(expr[i]);
                }
        }
        i++;
    }
    while(operand.top() != '#'){
        char temp = operand.pop();
        answer.push_back(temp);
    }
    return answer;
}

vector<char> infix_to_prefix(vector<char> expr){
    vector<char> temp;
    for(int i=expr.size()-1;i>-1;i--){
        //cout<<"i AM HERE"<<endl;
        if(expr[i]=='('){
            temp.push_back(')');
        } else if(expr[i]==')'){
            temp.push_back('(');
        } else{
           temp.push_back(expr[i]); 
        }
    }
    vector<char> temp2 = infix_to_postfix(temp);
    reverse(temp2.begin(),temp2.end());
    return temp2;
}
        
int main() {
    vector<char> expression;
    expression.push_back('a');expression.push_back('+');expression.push_back('(');expression.push_back('b');expression.push_back('*');expression.push_back('c');expression.push_back('-');expression.push_back('(');expression.push_back('d');expression.push_back('/');expression.push_back('e');expression.push_back('-');expression.push_back('f');expression.push_back(')');expression.push_back('*');expression.push_back('g');expression.push_back(')');expression.push_back('*');expression.push_back('h');//expression.push_back('-');expression.push_back('i');
for(int i=0;i<expression.size();i++){
        cout<<expression[i];
    }
    cout<<endl;
    vector<char> postfix;
    postfix=infix_to_postfix(expression);
    for(int i=0;i<postfix.size();i++){
        cout<<postfix[i];
    }
    cout<<endl;
    //cout<<expression[0];
    vector<char> prefix = infix_to_prefix(expression);
    for(int i=0;i<prefix.size();i++){
        cout<<prefix[i];
    }
    cout<<endl;
    return 0;
}