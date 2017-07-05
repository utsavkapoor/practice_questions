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

class Queue{
    node *head;
public:
    Queue();
    void enqueue(int num);
    void dequeue();
    void display();

};

Queue::Queue(){head = NULL;}

void Queue::enqueue(int num){
    if (head == NULL){
        node *temp = new node;
        temp->data = num;
        temp->next = NULL;
        head = temp;
    }
    else{
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        node* newnode = new node;
        newnode->data = num;
        newnode->next = NULL;
        temp->next = newnode;
    }
}

void Queue::dequeue(){
    if(head->next == NULL){
        cout<<head->data<<endl;
        head->data =0;
        head->next = NULL;
        delete head;
    }
    else{
            node *temp = head;
            head = head->next;
            cout<<temp->data<<endl;
            temp->data = 0;
            temp->next = NULL;
            delete temp;
        }
    
    }

void Queue::display(){
    cout<<head->data<<endl;
}

int main(){
    Queue aqueue;
    aqueue.enqueue(10);aqueue.enqueue(20);aqueue.enqueue(30);aqueue.enqueue(40);aqueue.enqueue(50);
    aqueue.dequeue();aqueue.dequeue();aqueue.dequeue();
    aqueue.display();
    aqueue.dequeue();aqueue.dequeue();
    return 0;
}
