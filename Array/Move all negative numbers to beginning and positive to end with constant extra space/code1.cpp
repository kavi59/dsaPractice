#include<bits/stdc++.h>
using namespace std;

void func(int *arr, int n1) {
	int countn = 0;
	for(int i = 0; i < n1; i++) {
		if(arr[i] < 0)
			countn += 1;
	}
	int n = 0, p = countn;
	int *a = new int[n];
	for(int i = 0; i < n1; i++) {
		if(arr[i] < 0)
			a[n++] = arr[i];
		else
			a[p++] = arr[i];
	}
	for(int i = 0; i < n1; i++) {
		arr[i] = a[i];
	}
	for(int i = 0; i < n1; i++)
		cout << arr[i] << ",";
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