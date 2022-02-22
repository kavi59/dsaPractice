#include<bits/stdc++.h>
using namespace std;

class myStack {
	int *s;
	int max_capacity;
	int s_size;

public:
	myStack(int g) {
		s = new int[g];
		max_capacity = g;
		s_size = 0;
	}

	void push(int x) {
		if(s_size < max_capacity) {
			s[s_size] = x;
			s_size += 1;
			cout << x << " pushed in stack!!!" << endl;
		} else {
			cout << "Cannot push!!! Stack full!!!" << endl;
			return;
		}
	}

	void pop() {
		if(s_size == 0) {
			cout << "Cannot pop!!! Stack is empty!!!" << endl;
			return;
		}
		s_size -= 1;
	}

	int top() {
		if(s_size == 0) {
			cout << "Cannot give the top element!!! Stack is empty!!!" << endl;
			return -1;
		}
		return s[s_size - 1];
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
	myStack s(7);
	cout << s.empty() << endl;
	s.push(9);
	s.push(7);
	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
	cout << s.empty() << endl;
}