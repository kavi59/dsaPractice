#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* next;
};

class myStack {
	Node *head;
	int s_size;

public:

	myStack() {
		head = NULL;
		s_size = 0;
	}

	void push(int x) {
		Node *temp = new Node();
		temp -> val = x;
		temp -> next = head;
		head = temp;
		s_size += 1;
	}

	void pop() {
		if(head == NULL) {
			cout << "Stack is empty!!!" << endl;
			return;
		}
		Node *temp = head;
		head = head -> next;
		temp -> next = NULL;
		delete temp;
		s_size -= 1;
	}

	int top() {
		if(head == NULL) {
			cout << "Stack is empty!!!" << endl;
			return -1;
		}
		return head -> val;
	}

	int size() {
		return s_size;
	}

	int empty() {
		if(s_size == 0)
			return 1;
		else
			return 0;
	}
};

int main() {
	myStack s;
	cout << s.empty() << endl;
	s.push(9);
	s.push(7);
	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
	cout << s.empty() << endl;
}