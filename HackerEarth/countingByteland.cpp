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
struct myDataType{
	lli x,y,z,no;
};
int main(){
	lli n,k,x,y,z,x1,y1,z1,dummy,total(0);
	vector<myDataType> v;
 	cin>>n>>k;
 	loop(i,0,k-1){
 		cin>>dummy;
 		if (dummy==1){
 			cin>>x>>y>>z>>dummy;
 			myDataType data;
 			data.x = x;
 			data.y = y;
 			data.z = z;
 			data.no = dummy;
 			v.pb(data);
 			total+= dummy;
 		}
 		else{
 			lli ans(0);
 			cin>>x>>y>>z>>x1>>y1>>z1;
 			loop(j,0,v.size()-1){
 			if (v[j].x>=x and v[j].x<=x1){
 				if (v[j].y>=y and v[j].y<=y1){
 					if (v[j].z>=z and v[j].z<=z1){
 							ans += v[j].no;
 							//cout<<v[x<<y<<z<<endl;
 					}
 				}	
 			}
 			cout<<total-ans<<endl;
 			}
 		}	
 	}
 	return 0;
}	