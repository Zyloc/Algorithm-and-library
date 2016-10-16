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
	zyloc(){
		lli a,b,c,d;
		cin>>a>>b>>c>>d;
		if (d<=a){
			cout<<"0"<<endl;
		}
		else if (a<=c and d<=b){
			cout<<(c-a)*(d-c+1)+((d-c)*(d-c+1))/2<<endl;
		}
		else if (a<=c and d>=b){
			cout<<(c-a)*(d-c+1)+((d-c)*(d-c+1))/2-((d-b-1)*(d-b))/2<<endl;	
		}
		else if(c>=b){
			if (c==b){
				cout<<(b-a)*(d-c+1)+(d-c)<<endl;
			}
			else{
				cout<<(b-a+1)*(d-c+1)<<endl;
			}
		}
		else if (c<=a and d>=b){
			cout<<((d-a+1)*(d-a))/2-((d-b-1)*(d-b))/2<<endl;	
		}
		else if (c<=a and d<=b){
			cout<<((d-a)*(d-a+1))/2<<endl;
		}
	}
	return 0;
}	