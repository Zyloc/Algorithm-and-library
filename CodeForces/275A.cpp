/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (int i=start;i<=end;i++)
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
char toggle(char c){
	if (c=='0'){
		return '1';
	}
	else{
		return '0';
	}
}
int main(){
	lli initial[6][6]={0};
	string s[3];
	lli x;
	loop(i,1,3){
		loop(j,1,3){
			cin>>x;
			initial[i][j] = x;
		}
	}
	loop(i,1,3){
		loop(j,1,3){
			int c = initial[i - 1][j] + initial[i + 1][j] + initial[i][j] + initial[i][j + 1] + initial[i][j - 1];
			if (c % 2 == 0)	cout << 1;
			else	cout << 0;	
		}
		cout<<endl;
	}
	
	return 0;
}	