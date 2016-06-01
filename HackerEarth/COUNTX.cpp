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
	lli n;
	cin>>n;
	string s;
	loop(i,n){
		cin>>s;
		int count=0;
		for (int j=1;j<s.length();){
			if (s[j]=='-'){
				if (s[j-1]=='-'){
					cout<<"0";
				}
				else{
					cout<<count;	
				}
				j=j+1;
				count=0;
			}
			else{
				j=j+1;
				count++;
			}
		}
		cout<<endl;
	}	
    return 0;
}
Language: C++