#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	stack<char> st;
	int i = 0;
	while(i < s.size()) {
		if(s[i] == ')') {
			if(st.top() == '(') {
				cout << "Yes" << endl;
				return 0;
			} else {
				int flag = 0;
				while(!st.empty() && st.top() != '(') {
					if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
						flag = 1;
					}
					st.pop();
				}
				st.pop();
				if(flag == 1) {
					i++;
					continue;
				} else {
					cout << "Yes" << endl;
				    return 0;
				}
			}
		} else {
			st.push(s[i]);
		}
		i++;
	}
	cout << "No" << endl;
	return 0;
}