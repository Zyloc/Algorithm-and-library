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
	char c;
	lli n,x,y,found(0);
	cin>>n;
	lli hash[5]={0};
	map<lli,lli> mp;
	queue<lli> q[4],q2;
	loop(i,0,n-1){
		cin>>c;
		if(c == 'E'){
			cin>>x>>y;
			q[x].push(y);
			if(mp[x]==0){
				q2.push(x);
			}
			mp[x]++;

		}
		else{
			cout<<q2.front()<<" "<<q[q2.front()].front()<<endl;
			mp[x]--;
			q[q2.front()].pop();	
			if(mp[x]==0){
				mp.erase(x);
				q2.pop();
			}
		}
	}
	return 0;
}	