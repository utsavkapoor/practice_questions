/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class Stack{
    node *head;
    public:
        Stack();
        void push(int num);
        void pop(); 
};

Stack::Stack(){

    head = NULL;
}
void Stack::push(int num){
    if(head == NULL){
        node *temp = new node;
        temp->data = num;
        temp->next = NULL;
        head = temp;
    }
    else{
        node *temp = new node;
        temp->data = num;
        temp->next = head;
        head = temp;
    }
    }
void Stack::pop(){
    if (head == NULL){cout<<"No Stack is there"<<endl;}
    else if (head->next == NULL){
        cout<<head->data<<endl;
        head->data = 0;
        delete head;
    }
    else{
        node* temp = head;
        cout<<head->data<<endl;
        head = head->next;
        temp->next = NULL;
        temp->data = 0;
        delete temp;
    }
}

int main(){

    Stack astack;
    astack.push(10);astack.push(20);astack.push(30);astack.push(40);astack.push(50);
    astack.pop();astack.pop();astack.pop();astack.pop();astack.pop();astack.pop();
    return 0;

}

