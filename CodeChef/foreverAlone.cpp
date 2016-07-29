/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <functional>
#include <limits.h>
#include <list>  
using namespace std;
#define loop(i,start,end) for (int i=start;i<=end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
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
	string s;
	lli n,x,cnt(0);
	cin>>n;
	map<string,lli> mp1,mp2;
	loop(i,0,n-1){
		cin>>s;
		if (s[s.length()-2]=='k'){
			if (s[s.length()-1]=='i'){
				s[s.length()-1]=' ';
				s[s.length()-2]=' ';
				mp1[s]++;
			}
			if (s[s.length()-1]=='a'){
				s[s.length()-1]=' ';
				s[s.length()-2]=' ';
				mp2[s]++;
			}
		}
	}
	map<string,lli>::iterator it;
	for (it=mp1.begin();it!=mp1.end();it++){
		cnt += min(mp2[it->first],it->second);
	}
	cout<<cnt<<endl;
    return 0;
}	