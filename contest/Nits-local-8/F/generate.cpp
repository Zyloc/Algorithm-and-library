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
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
lli MAX;
pair<lli,lli> generate(){
	pair<lli,lli> pa;
	if (rand()%2){
		if (rand()%2){
			pa.first = -rand()%MAX;
			pa.second = -rand()%MAX;
		}
		else{
			pa.first = rand()%MAX;
			pa.second = -rand()%MAX;
		}
	}
	else{
		if (rand()%2){
			pa.first = -rand()%MAX;
			pa.second = rand()%MAX;
		}
		else{
			pa.first  = rand()%MAX;
			pa.second = -rand()%MAX;
		}
	}
	return pa;
}
int main(){
	lli q,k,a,b;
	cin>>q>>k>>MAX;
	cout<<q<<" "<<k<<endl;
	a = rand()%MAX;
	b = rand()%MAX;
	loop(i,1,k){
		cout<<"1 "<<a<<" "<<b<<endl;
		a -= rand()%45;
		b -= rand()%45;
	}
	loop(i,(k+1),q){
		if (i%2){
			cout<<"2"<<endl;
		}
		else{
			cout<<"1 "<<a<<" "<<b<<endl;
			a -= rand()%45;
			b -= rand()%45;
		}
	}
	return 0;
}	