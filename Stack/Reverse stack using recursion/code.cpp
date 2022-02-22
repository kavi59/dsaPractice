#include<bits/stdc++.h>
using namespace std;

void pushAtBottomOfStack(stack<int>& s, int temp) {
	if(s.empty()){
		s.push(temp);
		return;
	}
	int t = s.top();
	s.pop();
	pushAtBottomOfStack(s, temp);
	s.push(t);
}

void reverse(stack<int>& s) {
	if(s.empty())
		return;
	int temp = s.top();
	s.pop();
	reverse(s);
	pushAtBottomOfStack(s, temp);
}

void printStack(stack<int> s) {
	if(s.empty())
		return;
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}

int main() {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	cout << "Initial stack: ";
	printStack(s);
	reverse(s);
	cout << endl;
	cout << "Stack after reverse operation: ";
	printStack(s);
	return 0;
}