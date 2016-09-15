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
#define MAX 2000009
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
lli smallestPrimeDivisor[MAX];
lli constructSegmentTreeUtil(vector<lli> &v,lli* segmentTree,lli start, lli end, lli pos){
	if (start==end){
		//cout<<v[start]<<" ";
		segmentTree[pos] = smallestPrimeDivisor[v[start]];
		//cout<<segmentTree[pos]<<" "<<smallestPrimeDivisor[v[start]]<<endl;
		return segmentTree[pos];
	}
	lli mid((start+end)/2);
	constructSegmentTreeUtil(v,segmentTree,start,mid,2*pos+1);
	constructSegmentTreeUtil(v,segmentTree,mid+1,end,2*pos+2);
	segmentTree[pos] = max(segmentTree[2*pos+1],segmentTree[2*pos+2]);
}

lli* constructSegmentTree(vector<lli> &v){
	lli maxSize(2*pow(2,ceil(log2(v.size())))-1);
	lli* segmentTree = new lli[maxSize];
	constructSegmentTreeUtil(v,segmentTree,0,v.size()-1,0);
	return segmentTree; 
}
lli rangeMaximumQueryUtil(lli* segmentTree,lli segmentStart,lli segmentEnd,lli qstart,lli qend,lli pos){
	if (qstart<= segmentStart and qend >= segmentEnd) {
		return segmentTree[pos];
	}
	if (qstart > segmentEnd || qend < segmentStart){
		return INT_MIN;
	}	
	lli mid((segmentStart+segmentEnd)/2);
	return max(rangeMaximumQueryUtil(segmentTree,segmentStart,mid,qstart,qend,2*pos+1),rangeMaximumQueryUtil(segmentTree,mid+1,segmentEnd,qstart,qend,2*pos+2));
}

lli rangeMaximumQuery(lli* segmentTree,lli n,lli qstart,lli qend){
	return rangeMaximumQueryUtil(segmentTree,0,n-1,qstart,qend,0);
}
lli updateSegmentTreeUtil(vector<lli> &v,lli* segmentTree,lli segmentStart,lli segmentEnd,lli qstart,lli qend,lli pos){
	lli mid((segmentStart+segmentEnd)/2);
	if (segmentTree[pos]==1){
		return 1;
	}
	if (segmentStart == segmentEnd){
		if (segmentTree[pos]!=0){
			v[segmentStart] /= segmentTree[pos];
			segmentTree[pos] = smallestPrimeDivisor[v[segmentStart]];
		}
		return segmentTree[pos];
	}
	else{
		if(qend <= mid){
			updateSegmentTreeUtil(v,segmentTree,segmentStart,mid,qstart,qend,2*pos+1);	
		}
		else if(qstart >= mid+1){
			updateSegmentTreeUtil(v,segmentTree,mid+1,segmentEnd,qstart,qend,2*pos+2);
		}
		else{
			updateSegmentTreeUtil(v,segmentTree,segmentStart,mid,qstart,qend,2*pos+1);	
			updateSegmentTreeUtil(v,segmentTree,mid+1,segmentEnd,qstart,qend,2*pos+2);
		}
	}
	segmentTree[pos] = max(segmentTree[2*pos+1],segmentTree[2*pos+2]);
}
// update the values from qstart to qend by 'value'
lli updateSegmentTree(vector<lli> &v,lli* segmentTree,lli n,lli qstart, lli qend){
	updateSegmentTreeUtil(v,segmentTree,0,n-1,qstart,qend,0);
	/*loop(i,0,12){
		cout<<segmentTree[i]<<" ";
	}
	cout<<endl;*/
	return 0;
}


void SieveOfEratosthenes(int n)
{
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	smallestPrimeDivisor[0] = 1;
	smallestPrimeDivisor[1] = 1;
	for (int p=2; p*p<=n; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples of p
			smallestPrimeDivisor[p] = p;
			for (int i=p*2; i<=n; i += p){
				prime[i] = false;
				if (smallestPrimeDivisor[i]==0){
					smallestPrimeDivisor[i] = p;
				}
			}
		}
	}
	// Print all prime numbers
	loop(i,0,MAX-2){
		if (smallestPrimeDivisor[i]==0){
			smallestPrimeDivisor[i] = i;
		}
		//cout<<smallestPrimeDivisor[i]<<" ";
	}
	//cout<<endl;
		
}

int main(){
	SieveOfEratosthenes(MAX-1);
	zyloc(){
		lli n,m,x,y,z;
		scanf("%lld %lld",&n,&m);
		//cin>>n>>m;
		vi(v);
		loop(i,0,n-1){
			cin>>x;
			v.pb(x);
		}
		lli* segmentTree(constructSegmentTree(v));
		/*loop(i,0,12){
			cout<<segmentTree[i]<<" ";
		}
		cout<<endl;*/
		loop(i,0,m-1){
			scanf("%lld %lld %lld",&x,&y,&z);
			//cin>>x>>y>>z;
			y--;
			z--;
			if (x == 0){
				updateSegmentTree(v,segmentTree,n,y,z);
				/*loop(i,0,v.size()-1){
					cout<<v[i]<<" ";
				}*/
			}
			else{
				printf("%lld ",rangeMaximumQuery(segmentTree,n,y,z));
				//cout<<rangeMaximumQuery(segmentTree,n,y,z)<<" ";
			}
		}
		//cout<<"here"<<endl;
		//v.clear();
		delete[] segmentTree; 
		printf("\n");
	}
    return 0;
}	