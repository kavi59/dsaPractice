// Compare in pairs
#include<bits/stdc++.h>
using namespace std;

void func(int *arr, int n) {
	int ma, mi, i;
	if(n == 1) {
		ma = arr[0];
		mi = arr[0];
	} else {
		if(n % 2 == 0) {
			ma = max(arr[0], arr[1]);
			mi = min(arr[0], arr[1]);
			i = 2;
		} else {
			ma = arr[0];
			mi = arr[0];
			i = 1;
		}
		while(i < n) {
			if(arr[i] < arr[i + 1]) {
				if(ma < arr[i + 1])
					ma = arr[i + 1];
				if(mi > arr[i])
					mi = arr[i];
			} else {
				if(ma < arr[i])
					ma = arr[i];
				if(mi > arr[i + 1])
					mi = arr[i + 1];
			}
			i += 2;
		}
	}
	cout << "Max:" << ma << ", " << "Min:" << mi << endl;
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