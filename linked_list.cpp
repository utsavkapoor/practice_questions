#include<iostream>
using namespace std;

struct node {
	int data;
	node * next;
};

class Linkedlist
{
		node *head;
	public:
		Linkedlist();
		void display();
		void addbegin(int num);
		void addlast(int num);
		void addmiddle(int num, int position);
		void del(int num);
		int search(int num);
};

Linkedlist::Linkedlist()
{
	head = NULL;
}

void Linkedlist::display()
{
	node *temp = new node;
	temp = head;
	while (temp->next != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
}

void Linkedlist::addbegin(int num){
	node * temp = new node;
	if(head == NULL){
		temp->data = num;
		temp->next = NULL;
		head = temp;
	}
	else{
		temp->data = num;
		temp->next = head;
		head = temp;
	}
}

void Linkedlist::addlast(int num){
	
	node * temp = new node;
	if(head ==  NULL){
		temp->data = num;
		temp->next = NULL;
		head = temp;
	}
	else
	{
		node * newnode = new node;
		temp = head;
		while (temp->next != NULL){
			temp = temp->next;
		}
		newnode->data = num;
		newnode->next = NULL;
		temp->next = newnode;
	}
}

void Linkedlist::addmiddle(int num, int position){
	node * temp = new node;
	node *prevnode = new node;
	if (head == NULL){
		temp->data = num;
		temp->next = NULL;
		head = temp;
	}
	else
	{
		if(position == 1){
			addbegin(num);
		}
		else{
			prevnode = head;
			int count=1;
			while(count != position-1){
				prevnode=prevnode->next;
				count++;
			}
			temp->data = num;
			if(prevnode->next == NULL){
				temp->next = NULL;
				prevnode->next = temp;
			}
			else{
				temp->next = prevnode->next;
				prevnode->next = temp;
			}
			
		}
	}
	
}

void Linkedlist::del(int num){
int answer = search(num);
if (answer == 0){
    cout<<"Number cannot be found in the Linked List"<<endl;
}
else{
    node *temp = new node();
    node *agla = head;
    node *prev = head;
    if (head->next == NULL){//only head is left
        head->data = 0;
        head->next = NULL;
        delete head;
    }
    else if (answer == 1){
            prev = prev->next;
            agla = agla->next;
            head->next = NULL;
            head->data = 0;
            head = prev;
    }
    else{  
        int count = 2;
        while(count != answer){
            agla = agla->next;
            prev = prev->next;
            count++;
        }
        if (agla->next->next == NULL){//deleting last element
            agla = agla->next;
            prev->next= NULL;
            agla->data = 0;
            delete agla;
        }
        else{
            agla = agla->next;
            prev->next = agla->next;
            agla->next=NULL;
            agla->data = 0;
            delete agla;
        }
    }
}
}

int Linkedlist::search(int num){
    int result=1;
    int flag = 0;
    node *temp=head;
    while(temp->next != NULL){
        if(temp->data == num){
            flag=1;
            break;
        }
        else{
            result++;
            temp=temp->next;
        }
    }
    if(temp->data == num){
        flag=1;
    }
    if (flag == 0){
        result = 0;
    }
    return result;
}

int main(){
	Linkedlist alist;
	alist.addbegin(5);
	alist.display();
	alist.addbegin(6);alist.display();
	alist.addbegin(8);alist.display();
	alist.addbegin(10);alist.display();
	alist.addlast(15);alist.display();
	alist.addlast(20);alist.display();
	alist.addmiddle(50,4);alist.display();
	alist.addmiddle(1,1);alist.display();
	alist.addmiddle(100,9);alist.display();
        alist.del(20);alist.display();
        alist.del(100);alist.display();
        alist.del(1);alist.display();
        alist.del(8);alist.del(6);alist.del(5);alist.del(50);alist.del(15);
        alist.display();
        alist.del(10);
        alist.display();
	return 0;
}

