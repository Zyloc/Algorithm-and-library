/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <iomanip>
using namespace std;
#define loop(i,start,end) for (int i=start;i<end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 

int main(){
	lli n,m;
	cin>>n>>m;	
	lli arr[100002]={0},a[100002]={0},b[100002];
	loop(i,0,n){
		cin>>b[i];
	}
	pool(i,n-1,0){
		if (arr[b[i]]==0){
			a[i]=a[i+1]+1;
			arr[b[i]]++;
		}
		else{
			a[i]=a[i+1];
		}
		
	}
	int x;
	loop(i,0,m){
		cin>>x;
		cout<<a[x-1]<<endl;
	}
    return 0;
}