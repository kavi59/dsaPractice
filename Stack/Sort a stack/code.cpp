#include<bits/stdc++.h>
using namespace std;

void rearrangeStack(stack<int> &s, int temp) {
	if(s.empty()) {
		s.push(temp);
		return;
	}
	if(s.top() > temp) {
		s.push(temp);
		return;
	}
	int t = s.top();
	s.pop();
	rearrangeStack(s, temp);
	s.push(t);
}

void sortStack(stack<int> &s) {
	if(s.empty())
		return;
	int temp = s.top();
	s.pop();
	sortStack(s);
	rearrangeStack(s, temp);
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
	s.push(7);
	s.push(3);
	s.push(0);
	s.push(9);
	cout << "Initial stack: ";
	printStack(s);
	sortStack(s);
	cout << endl;
	cout << "Stack after sorting: ";
	printStack(s);
	return 0;
}