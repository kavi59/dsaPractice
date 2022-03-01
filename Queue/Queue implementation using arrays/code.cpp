#include<bits/stdc++.h>
using namespace std;

class Queue {
	int *arr;
	int front;
	int rear;
	int capacity;
	int size;

public:
	Queue(int n) {
		arr = new int[n];
		front = 0;
		rear = 0;
		capacity = n;
		size = 0;
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}

	void push(int x) {
		if(isFull())
			return;
		arr[rear % capacity] = x;
		rear++;
		size++;
	}

	void pop() {
		if(isEmpty())
			return;
		front++;
		size--;
	}

	int top() {
		if(isEmpty())
			return -1;
		int ans = arr[front % capacity];
		return ans;
	}

	void print() {
		for(int i = front; i < rear; i++) {
			cout << arr[i % capacity] << " ";
		}
		cout << endl;
		return;
	}
};

int main() {
	Queue q(5);
	q.push(3);
	q.push(2);
	q.push(1);
	q.push(8);
	q.push(6);
	q.push(7);
	q.print();
	q.pop();
	cout << q.top() << endl;
	q.pop();
	cout << q.top() << endl;
	q.push(10);
	q.print();
	q.pop();
	q.print();
	return 0;
}