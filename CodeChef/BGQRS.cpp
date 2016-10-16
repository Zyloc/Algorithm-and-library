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
lli powerTwo[MAX]={0},powerFive[MAX]={0};
lli powerOfTwo(lli n){
	lli ans(0);
	while(n >0 and n%2==0){
		ans++;
		n/=2;
	}
	return ans;
}
lli powerOfFive(lli n){
	lli ans(0);
	while(n >0 and n%5==0){
		ans++;
		n/=5;
	}
	return ans;
}
void updateFirst(vector<pair<lli,lli> > &v,lli start,lli end,pair<lli,lli> p){
	loop(i,start,end){
		v[i].first += p.first; 
		v[i].second += p.second;
	}
}
void updateSecond(vector<pair<lli,lli> > &v,lli start,lli end,pair<lli,lli> p){
	loop(i,start,end){
		v[i].first = p.first+powerTwo[i-start+1]; 
		v[i].second = p.second+powerFive[i-start+1];
	}
}
lli trailingZeros(vector<pair<lli,lli> > &v,lli start,lli end){
	lli noOfTwo(0),noOfFive(0);
	loop(i,start,end){
		noOfTwo += v[i].first;
		noOfFive += v[i].second;
	}
	return min(noOfTwo,noOfFive);
}
int main(){
	loop(i,1,MAX){
		powerTwo[i] = powerOfTwo(i);
		powerFive[i] = powerOfFive(i);
	}
	zyloc(){
		lli n,m,x,y,z,ans(0);
		cin>>n>>m;
		vector<pair<lli,lli> > v;
		loop(i,0,n-1){
			cin>>x;
			v.pb(mp(powerOfTwo(x),powerOfFive(x)));
		}
		loop(i,0,m-1){
			cin>>x;
			if (x==1){
				pair<lli,lli> p;
				cin>>x>>y>>z;
				x--,y--;
				p.first = powerOfTwo(z);
				p.second = powerOfFive(z);
				updateFirst(v,x,y,p);
			}
			else if (x==2){
				pair<lli,lli> p;
				cin>>x>>y>>z;
				x--,y--;
				p.first = powerOfTwo(z);
				p.second = powerOfFive(z);
				updateSecond(v,x,y,p);
			}
			else{
				cin>>x>>y;
				x--,y--;
				ans += trailingZeros(v,x,y);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}	