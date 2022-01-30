// Tournament method
#include<bits/stdc++.h>
using namespace std;

pair<int, int> helper(int *arr, int l, int h) {
	pair<int, int> p, left, right;
	// If only one element present
	if(l == h) {
		p.first = arr[l];
		p.second = arr[l];
		return p;
	}

	// If only two elements are present
	if(h == l + 1) {
		p.first = min(arr[l], arr[h]);
		p.second = max(arr[l], arr[h]);
		return p;
	}

	int mid = (l + h)/2;
	left = helper(arr, l, mid);
	right = helper(arr, mid + 1, h);
	p.first = min(left.first, right.first);
	p.second = max(left.second, right.second);
	return p;
}

void func(int *arr, int n) {
	pair<int, int> p;
	p = helper(arr, 0, n - 1);
	cout << "Min:" << p.first << ", Max:" << p.second << endl;
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	func(arr, n);
	return 0;
}