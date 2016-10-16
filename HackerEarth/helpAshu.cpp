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
lli constructSegmentTreeUtil(vector<lli> &v,lli* segmentTree,lli start, lli end, lli pos){
	if (start==end){
		if (v[start]&1){
			segmentTree[pos] = 0;
		}
		else{
			segmentTree[pos] = 1;
		}
		return segmentTree[pos];
	}
	lli mid((start+end)/2);
	segmentTree[pos] = (constructSegmentTreeUtil(v,segmentTree,start,mid,2*pos+1)+constructSegmentTreeUtil(v,segmentTree,mid+1,end,2*pos+2));
	return segmentTree[pos];
}
lli* constructSegmentTree(vector<lli> &v){
	lli maxSize(2*pow(2,ceil(log2(v.size())))-1);
	lli* segmentTree = new lli[maxSize];
	constructSegmentTreeUtil(v,segmentTree,0,v.size()-1,0);
	return segmentTree; 
}
lli noOfEvenUtil(lli* segmentTree,lli segmentStart,lli segmentEnd,lli qstart,lli qend,lli pos){
	if (qstart<= segmentStart and qend >= segmentEnd) {
		return segmentTree[pos];
	}
	if (qstart > segmentEnd || qend < segmentStart){
		return 0;
	}	
	lli mid((segmentStart+segmentEnd)/2);
	return (noOfEvenUtil(segmentTree,segmentStart,mid,qstart,qend,2*pos+1)+noOfEvenUtil(segmentTree,mid+1,segmentEnd,qstart,qend,2*pos+2));
}

lli noOfEven(lli* segmentTree,lli n,lli qstart,lli qend){
	return noOfEvenUtil(segmentTree,0,n-1,qstart,qend,0);
}
lli updateSegmentTreeUtil(lli* segmentTree,lli segmentStart,lli segmentEnd,lli pos,lli value,lli node){
	//cout<<segmentStart<<" "<<segmentEnd<<endl;
	if (segmentStart == segmentEnd){
		if (value&1){
			segmentTree[node] = 0;
		}
		else{
			segmentTree[node] = 1;
		}
		return segmentTree[node];
	}
	lli mid((segmentStart+segmentEnd)/2);
	if (pos <= mid){
		updateSegmentTreeUtil(segmentTree,segmentStart,mid,pos,value,2*node+1);
	}
	else{
		updateSegmentTreeUtil(segmentTree,mid+1,segmentEnd,pos,value,2*node+2);	
	}
	segmentTree[node] = segmentTree[2*node+1]+segmentTree[2*node+2];
	return 0;
}
// update the values from qstart to qend by 'value'
lli updateSegmentTree(lli* segmentTree,lli n,lli pos,lli value){
	updateSegmentTreeUtil(segmentTree,0,n-1,pos,value,0);
	return 0;
}
int main(){
	lli n,x,y,z,q;
	cin>>n;
	vi(v);
	loop(i,0,n-1){
		cin>>x;
		v.pb(x);
	}
	lli* segmentTree(constructSegmentTree(v));
    /*loop(i,0,15){
    	cout<<segmentTree[i]<<" ";
    }*/
    /*loop(i,0,n-1){
    	cin>>x>>y>>z;
    	cout<<updateSegmentTree(segmentTree,n,x,y,z)<<endl;
    }*/
    cin>>q;
    loop(i,0,q-1){
    	cin>>x>>y>>z;
    	if (x==0){
    		y--;
    		updateSegmentTree(segmentTree,n,y,z);
    	}	
    	else if (x==1){
    		y--,z--;
    		cout<<noOfEven(segmentTree,n,y,z);
    	}
    	else{
    		y--,z--;
    		cout<<(z-y+1-noOfEven(segmentTree,n,y,z));
    	}
    }
    return 0;
}	