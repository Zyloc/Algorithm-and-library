#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <iomanip>
using namespace std;
#define lli long long int
#define loop(i,n) for (int i=0;i<n;i++)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n); 
#define MOD 1000000007
int main(){
	lli t;
	cin>>t;
	loop(i,t){
		lli n;
		cin>>n;
		string s;
		int a[10]={0};
		loop(j,n){
			cin>>s;
			a[int(s[0])-48]++;
		}
		int threshold;
		cin>>threshold;
		double expected[10]={0};
		for(int k=1;k<=9;k++){
			expected[k]=log10(1+float(1)/float(k))*n; 
			//cout<<expected[k]<<" ";			
		}
		
		int flag=0;
		for (int k=1;k<=9;k++){
			if ((a[k]>=expected[k]*threshold) || a[k]<=double(expected[k])/double(threshold)){
				cout<<k<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<"-1"<<endl;
		}
	}	
    return 0;
}
Language: C++