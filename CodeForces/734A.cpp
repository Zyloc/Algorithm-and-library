/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (lli i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int main(){
	lli anton(0),danik(0),n;
	cin>>n;
	string s;
	cin>>s;
	loop(i,0,s.length()-1){
		if(s[i]=='A'){
			anton++;
		}
		else{
			danik++;
		}
	}
	if(anton > danik){
		cout<<"Anton"<<endl;
	}
	else if( danik > anton){
		cout<<"Danik"<<endl;
	}
	else{
		cout<<"Friendship"<<endl;
	}
	return 0;
}			