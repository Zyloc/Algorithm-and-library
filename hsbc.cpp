
#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// copy paste this method

bool compare(int first,int second){
	string temp1(to_string(first)+to_string(second));
	string temp2(to_string(second)+to_string(first));
	if(temp1 > temp2){
		return true;
	}
	return false;
}

int* LargestValue(int* arr,int n){
	sort(arr,arr+n,compare);
	return arr;
}

// ignore this part

int main(){
	int arr[5] = {34,6,75,45,9};
	int *temp = LargestValue(arr,5);
	for(int i(0);i<5;i++){
		cout<<temp[i]<<" ";
	}
	return 0;
}
