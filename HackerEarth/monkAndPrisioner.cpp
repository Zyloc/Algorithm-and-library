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
	lli n,x;
	cin>>n;
	vi(v);
	loop(i,0,n-1){
		cin>>x;
		v.pb(x);
	}
	lli ansA[n],ansB[n];
	stack<pair<lli,lli> > st,st2;
	loop(i,0,n-1){
		if(st.empty()){
			st.push(mp(v[i],i+1));
			ansA[i]=-1;
		}
		else if(v[i] >= st.top().first){
			while(!st.empty() and st.top().first <= v[i] ){
				st.pop();
			}
			if (st.empty()){
				ansA[i]=-1;
				st.push(mp(v[i],i+1));
			}
			else{
				ansA[i]=st.top().second;
				st.push(mp(v[i],i+1));
			}
		}
		else{
			ansA[i]=st.top().second;
			st.push(mp(v[i],i+1));
		}
	}
	pool(i,n-1,0){
		if(st2.empty()){
			st2.push(mp(v[i],i+1));
			ansB[i]=-1;
		}
		else if(v[i] >= st2.top().first){
			while(!st2.empty() and st2.top().first <= v[i] ){
				st2.pop();
			}
			if (st2.empty()){
				ansB[i]=-1;
				st2.push(mp(v[i],i+1));
			}
			else{
				ansB[i]=st2.top().second;
				st2.push(mp(v[i],i+1));
			}
		}
		else{
			ansB[i]=st2.top().second;
			st2.push(mp(v[i],i+1));
		}
	}
	loop(i,0,n-1){
		cout<<ansA[i]+ansB[i]<<" ";
	}
	return 0;
}	