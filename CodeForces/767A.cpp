/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX  = 1e6+1;
bool freq[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	lli input[n+1];
	vector<lli> v;
	for(int i=0;i<n;i++){
		cin>>input[i];
	}
	lli last(n);
	for(int i=n;i>=1;i--){
		freq[input[n-i]]  = true;
		if(input[n-i] == last){
			bool flag(false);
			for(int j=last;j>=i;j--){
				if(freq[j]){
					cout<<j<<" ";
				}
				else{
					flag = true;
					last= j;
					break;
				}
			}
			if(!flag){
				last = i-1;
			}
			cout<<endl;
		}
		else{
			cout<<endl;
		}
	}	
	for(int j=last;j>=1;j--){
				cout<<j<<" ";
	}
	return 0;
}