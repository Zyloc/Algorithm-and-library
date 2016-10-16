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
#define MOD 1000000009
#define PI  3.14159265358979323846
#define MAX 300005
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
lli fibo[MAX]={0};
lli constructSegmentTreeUtil(vector<lli> &v,lli* segmentTree,lli start, lli end, lli pos){
	if (start==end){
		segmentTree[pos] = v[start]%MOD;
		//cout<<segmentTree[pos]<<endl;
		return segmentTree[pos]%MOD;
	}
	lli mid((start+end)/2);
	segmentTree[pos] = (constructSegmentTreeUtil(v,segmentTree,start,mid,2*pos+1)%MOD+constructSegmentTreeUtil(v,segmentTree,mid+1,end,2*pos+2)%MOD)%MOD;
	return segmentTree[pos]%MOD;
}
lli* constructSegmentTree(vector<lli> &v){
	lli maxSize(2*pow(2,ceil(log2(v.size())))-1);
	lli* segmentTree = new lli[maxSize];
	constructSegmentTreeUtil(v,segmentTree,0,v.size()-1,0);
	return segmentTree; 
}
lli sumOfRangeUtil(lli* segmentTree,lli segmentStart,lli segmentEnd,lli qstart,lli qend,lli pos){
	if (qstart<= segmentStart and qend >= segmentEnd) {
		return segmentTree[pos]%MOD;
	}
	if (qstart > segmentEnd || qend < segmentStart){
		return 0;
	}	
	lli mid((segmentStart+segmentEnd)/2);
	return (sumOfRangeUtil(segmentTree,segmentStart,mid,qstart,qend,2*pos+1)%MOD+sumOfRangeUtil(segmentTree,mid+1,segmentEnd,qstart,qend,2*pos+2))%MOD;
}

lli sumOfRange(lli* segmentTree,lli n,lli qstart,lli qend){
	return sumOfRangeUtil(segmentTree,0,n-1,qstart,qend,0);
}
lli updateSegmentTreeUtil(lli* segmentTree,lli segmentStart,lli segmentEnd,lli qstart,lli qend,lli value,lli pos){
	lli mid((segmentStart+segmentEnd)/2);
	if (qend<segmentStart or qstart>segmentEnd){
		return 0;
	}
	if (segmentStart == segmentEnd){
		segmentTree[pos] = (segmentTree[pos]+fibo[segmentStart-qstart+1])%MOD;
		return (segmentTree[pos])%MOD; 
	}
	updateSegmentTreeUtil(segmentTree,segmentStart,mid,qstart,qend,value,2*pos+1);	
	updateSegmentTreeUtil(segmentTree,mid+1,segmentEnd,qstart,qend,value,2*pos+2);
	segmentTree[pos] = (segmentTree[2*pos+1]%MOD+segmentTree[2*pos+2]%MOD)%MOD;
	return 0;
}
// update the values from qstart to qend by 'value'
lli updateSegmentTree(lli* segmentTree,lli n,lli qstart, lli qend,lli value){
	updateSegmentTreeUtil(segmentTree,0,n-1,qstart,qend,value,0);
	return 0;
}
void calFibo(){
	fibo[1]=1;
	fibo[2]=1;
	loop(i,3,MAX-1){
		fibo[i] = (fibo[i-1]%MOD+fibo[i-2]%MOD)%MOD;
	}
}
int main(){
	calFibo();
	lli n,m,x,y,z;
	cin>>n>>m;
	vi(v);
	loop(i,0,n-1){
		cin>>x;
		v.pb(x);
	}
	lli* segmentTree(constructSegmentTree(v));
    loop(i,0,m-1){
    	cin>>x;
    	if (x==2){
    		cin>>x>>y;
    		x--,y--;
    		cout<<sumOfRange(segmentTree,n,x,y)%MOD<<endl;
    	}
    	else{
    		cin>>x>>y;
    		x--,y--;
    		updateSegmentTree(segmentTree,n,x,y,z);
    	}
    }
    return 0;
}	