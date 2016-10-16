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
	vi(red);
	vi(blue);
	lli n,x,ans(0);
	string s;
	cin>>n;
	loop(i,0,n-1){
		cin>>s;
		if (s[s.length()-1]=='R'){
			lli number(0),iterator(0);
			while(iterator<s.length()-1){
				number = (number*10) + s[iterator]-'0';
				iterator++; 
			}
			cout<<number<<endl;
		}
		else{
			lli number(0),iterator(0);
			while(iterator<s.length()-1){
				number = (number*10) + s[iterator]-'0';
				iterator++; 
			}
			cout<<number<<endl;
		} 
	}
	return 0;
}	