#include<bits/stdc++.h>
using namespace std;

int func(int *arr, int n, int sum) {
	int **t = new int*[n + 1];
	for(int i = 0; i <= n; i++)
		t[i] = new int[sum + 1];
	for(int i = 0; i <= n; i++)
		t[i][0] = 1;
	for(int j = 1; j <= sum; j++)
		t[0][j] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= sum; j++) {
			if(arr[i - 1] <= j) 
				t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][sum];
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int sum;
	cin >> sum;
	cout << func(arr, n, sum);
	return 0;
}