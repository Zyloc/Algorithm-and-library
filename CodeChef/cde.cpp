#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	vector <unsigned long long int> v;
	unsigned long long int number;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>number;
		v.push_back(number);
	}
	sort(v.begin(),v.end());
	for (int j=1;j<=n;j++){
		if (!binary_search(v.begin(),v.end(),j)){
			cout<<j<<" ";
		}

	}
}
