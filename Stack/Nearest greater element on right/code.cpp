#include<bits/stdc++.h>
using namespace std;

vector<int> func(int *arr, int n) {
	stack<int> s;
	vector<int> ans(n);
	int j = n - 1;
	for(int i = n - 1; i >= 0; i--) {
		int temp;
		if(s.empty())
			temp = -1;
		else if(s.top() > arr[i])
			temp = s.top();
		else if(s.top() <= arr[i]) {
			while(!s.empty() && s.top() <= arr[i])
				s.pop();
			if(s.empty())
				temp = -1;
			else
				temp = s.top();
		}
		s.push(arr[i]);
		ans[j] = temp;
		j--;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> ans = func(arr, n);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ", ";
	return 0;
}