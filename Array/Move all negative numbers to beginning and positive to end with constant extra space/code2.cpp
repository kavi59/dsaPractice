#include<bits/stdc++.h>
using namespace std;

void func(int *arr, int n1) {
	int n = 0, p = n1 - 1;
	while(n <= p) {
		if(arr[n] < 0 && arr[p] > 0) {
			n += 1;
			p -= 1;
		} else if(arr[n] < 0 && arr[p] < 0) {
			n += 1;
		} else if(arr[n] > 0 && arr[p] < 0) {
			swap(arr[n], arr[p]);
			n += 1;
			p -= 1;
		} else if(arr[n] > 0 && arr[p] > 0) {
			p -= 1;
		}
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