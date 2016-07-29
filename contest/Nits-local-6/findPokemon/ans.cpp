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
	lli N,note1_sum(0),note2_sum(0),note3_sum(0),x;
	cin>>N;
	
	loop(i,0,N-1){
		cin>>x;
		note1_sum += x;
	}

	loop(i,0,N-2){
		cin>>x;
		note2_sum += x;
	}

	loop(i,0,N-3){
		cin>>x;
		note3_sum += x;
	}
	cout<<(note1_sum-note2_sum)<<" "<<(note2_sum-note3_sum)<<endl;
    return 0;
}	