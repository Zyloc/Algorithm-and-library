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
#define MAX 100
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int genrateSign(){
	if (rand()%2==0){
		return 2;
	}
	else{
		return -3;
	}
}
int main(){
	lli n,x1,y1,x2,y2,t,r,d,l;
	cin>>n;
	cout<<n<<endl;
	loop(i,0,n-1){
		x1 = -1*genrateSign()*rand()%MAX;
		x2 = -1*genrateSign()*rand()%MAX;
		y1 = -1*genrateSign()*rand()%MAX;
		y2 = -1*genrateSign()*rand()%MAX;	
		t = rand()%MAX;
		r = rand()%MAX;
		d = rand()%MAX;
		l = rand()%MAX;
		cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
		cout<<t<<" "<<r<<" "<<d<<" "<<l<<endl;
	}
    return 0;
}	