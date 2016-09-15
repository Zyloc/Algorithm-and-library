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
#define MAX 100005
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int main(){
	lli n,x,sum(0);
	cin>>n;
	lli hash[MAX]={0};
	vi(v);
	set<lli> st;
	loop(i,0,n-1){
		cin>>x;
		st.insert(x);
	}
	if (st.size()>3){
		cout<<"NO"<<endl;
	}
	else{
		if (st.size()==1){
			cout<<"YES"<<endl;
		}
		else if(st.size()==2){
			cout<<"YES"<<endl;
		}
		else {
			auto first = st.begin();
			auto second = ++st.begin();
			auto third = ++(++st.begin());
			if (*second-*first == *third-*second){
				cout<<"YES"<<endl;
			} 
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}	