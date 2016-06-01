/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <bits/stdc++.h>
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
#define lli  long long int 
 
int main(){
	zyloc(){
		lli a,b,c,e=0,f,g;
		cin>>a>>b>>c;
		//cout<<c-a<<endl;
		//return 0;
		if ((a+b)>c and (a+c)>b and (b+c)>a and abs(a-b)<c and abs(a-c)<b and abs(b-c)<a ){
			if((a==b and a==c) or (b==c and b==a) or (c==a and c==b) ){
			cout<<"YES. It is a equilateral triangle."<<endl;
		}
		else if((a==b) or (a==c) or (b==c)){
			cout<<"YES. It is a isosceles triangle."<<endl;
		}
		else {
			cout<<"YES. It is a scalene triangle."<<endl;
		}
		}
		else {
			cout<<"NO"<<endl;
		}
	}	
    return 0;
}
Language: C++