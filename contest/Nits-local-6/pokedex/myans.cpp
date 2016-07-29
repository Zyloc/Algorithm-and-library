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
	zyloc(){
		lli n,x,cnt=0;
		cin>>n;
		set<lli> st;
		map<lli,lli> mp,mp2;
		loop(i,0,n-1){
			cin>>x;
			mp[x]++;
		}
		map<lli,lli>::iterator it;
		lli mini(INT_MAX),maxi(INT_MIN);
		for (it=mp.begin();it!=mp.end();it++){
			st.insert(it->second);
			mp2[it->second]++;
			mini = min(mini,it->second);
			maxi = max(maxi,it->second);
		}
		it = mp2.begin();
		lli cntMini,cntMaxi;
		cntMini = mp2[mini];
		cntMaxi = mp2[maxi];
		set<lli>::iterator it2=st.begin();
		if (st.size()==1){
			cout<<"YES"<<endl;
		}
		else if ((st.size()==2 and mini==1) or (st.size()==2 and (maxi-mini==1 and (cntMini==1 or cntMaxi==1)))){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	}
    return 0;
}
