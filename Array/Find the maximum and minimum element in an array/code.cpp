#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int ma, mi;
	if(n == 1) {
		ma= arr[0];
		mi = arr[0];
	} else {
		ma = max(arr[0], arr[1]);
		mi = min(arr[0], arr[1]);
		for(int i = 2; i < n; i++) {
			if(arr[i] < mi)
				mi = arr[i];
			else if(arr[i] > ma)
				ma = arr[i];
		}		
	}
	cout << "Max:" << ma << ", " << "Min:" << mi << endl;
	return 0;
}