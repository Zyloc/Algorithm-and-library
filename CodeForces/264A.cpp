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
	set<pair<float,int> > mp;
	pair<float,float> pos;
	cin>>s;
	pos.first = 0;
	pos.second = 1;
	loop(i,0,s.length()-1){
		mp.insert(mp((pos.first+pos.second)/2,i+1));
		if (s[i]=='l'){
			pos.second = pos.second/2;
		}
		else{
			pos.first = pos.first/2;
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++){
		cout<<it->second<<endl;
	}
    return 0;
}	