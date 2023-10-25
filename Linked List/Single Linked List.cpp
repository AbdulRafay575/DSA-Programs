#include <iostream>
using namespace std;

const int MAX_SIZE = 5; 

class Stack{
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack() {
        top = -1; 
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == MAX_SIZE - 1;
    }
    void push(int data) {
        if (isFull()) {
            cout << "Stack is full. Cannot push." << endl;
            return;
        }
        arr[++top] = data;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        --top;
    }
     int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return 0;
        }
        //cout<<arr[top]<<"  ";
        return arr[top];
    }
    int display() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot Display." << endl;
            return -1; 
        }
        int display=top;
        while(display!=-1){
        	cout<<arr[display]<<"  ";
        	display--;
		}
    }
};


class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
	Stack stack;
    LinkedList() {
        head = NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
	void SSL(){
		Node* temp=head;
		while(temp!=NULL){
			stack.push(temp->data);
			temp=temp->next;
		}
		
		stack.display();
	}
	void palindrome(){
		Node* temp=head;
		int a=0;
		while(temp!=NULL){
		if(temp->data==stack.peek()){
			temp=temp->next;
			stack.pop();
		}	
		else{
			cout<<"\n\nThe Given Linked List Is Not Palindrome"<<endl;
			a=5;
			return;
		}
		}
		if(a==0){
			cout<<"\n\nThe Given Linked List Is Palindrome";
		}
			
	}
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(1);
	
    cout << "\nOriginal list: ";
    list.display();
    cout << "\nStack Element list: ";
    list.SSL();
 	list.palindrome();
    return 0;
}

