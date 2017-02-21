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
#define lli long long int 
#define debug() cout<<"######"<<endl 
lli constructSegmentTreeUtil(vector<lli> &v,lli* segmentTree,lli start, lli end, lli pos){
	if (start==end){
		segmentTree[pos] = start;
		return start;
	}
	lli mid((start+end)/2);
	constructSegmentTreeUtil(v,segmentTree,start,mid,2*pos+1);
	constructSegmentTreeUtil(v,segmentTree,mid+1,end,2*pos+2);
	if(v[segmentTree[2*pos+1]] < v[segmentTree[2*pos+2]]){
		segmentTree[pos] = segmentTree[2*pos+1];
	}
	else if(v[segmentTree[2*pos+1]] == v[segmentTree[2*pos+2]]){
		segmentTree[pos] = max(segmentTree[2*pos+1],segmentTree[2*pos+2]);	
	}
	else{
		segmentTree[pos] = segmentTree[2*pos+2];
	}
	return segmentTree[pos];
}
lli* constructSegmentTree(vector<lli> &v){
	lli maxSize(2*pow(2,ceil(log2(v.size())))-1);
	lli* segmentTree = new lli[maxSize];
	constructSegmentTreeUtil(v,segmentTree,0,v.size()-1,0);
	return segmentTree; 
}
lli rangeMinimumQueryUtil(lli* segmentTree,lli segmentStart,lli segmentEnd,lli qstart,lli qend,lli pos){
	if (qstart<= segmentStart and qend >= segmentEnd) {
		return segmentTree[pos];
	}
	if (qstart > segmentEnd || qend < segmentStart){
		return INT_MIN;
	}	
	lli mid((segmentStart+segmentEnd)/2);
	return max(rangeMinimumQueryUtil(segmentTree,segmentStart,mid,qstart,qend,2*pos+1),rangeMinimumQueryUtil(segmentTree,mid+1,segmentEnd,qstart,qend,2*pos+2));
}

lli rangeMinimumQuery(lli* segmentTree,lli n,lli qstart,lli qend){
	return rangeMinimumQueryUtil(segmentTree,0,n-1,qstart,qend,0);
}
lli updateSegmentTreeUtil(lli* segmentTree,lli segmentStart,lli segmentEnd,lli qstart,lli qend,lli value,lli pos){
	lli mid((segmentStart+segmentEnd)/2);
	if (mid == segmentStart){
		if (qstart<= segmentStart  and qend >= segmentEnd){
			segmentTree[2*pos+1] += value; 
			segmentTree[2*pos+2] += value;
		}
		else if (qstart > segmentStart){
			segmentTree[2*pos+2] += value;
		}
		else{
			segmentTree[2*pos+1] += value;
		}
	}
	else{
		// left tree
		if (qend <= mid ){
			updateSegmentTreeUtil(segmentTree,segmentStart,mid,qstart,qend,value,2*pos+1);
		}
		// right tree
		else if (qstart >= mid+1 ){
			updateSegmentTreeUtil(segmentTree,mid+1,segmentEnd,qstart,qend,value,2*pos+2);	
		}
		else{
			updateSegmentTreeUtil(segmentTree,segmentStart,mid,qstart,qend,value,2*pos+1);	
			updateSegmentTreeUtil(segmentTree,mid+1,segmentEnd,qstart,qend,value,2*pos+2);
		}
	}
	segmentTree[pos] = min(segmentTree[2*pos+1],segmentTree[2*pos+2]);
	return 0;
}
// update the values from qstart to qend by 'value'
lli updateSegmentTree(lli* segmentTree,lli n,lli qstart, lli qend,lli value){
	updateSegmentTreeUtil(segmentTree,0,n-1,qstart,qend,value,0);
	loop(i,0,6){
		cout<<segmentTree[i]<<" ";
	}
	cout<<endl;
	return 0;
}
int main(){
	lli n,x,y,z;
	cin>>n;
	vi(v);
	loop(i,0,n-1){
		cin>>x;
		v.pb(x);
	}
	lli* segmentTree(constructSegmentTree(v));
    lli q;
    cin>>q;
    for(int i=0;i<q;i++){
    	int l,r;
    	cin>>l>>r;
    	l--;
    	r--;
    	cout<<rangeMinimumQuery(segmentTree,n,l,r)<<endl;
    }
    return 0;
}	