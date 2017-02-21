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
		if (start>0 and start<v.size()-1){
			//cout<<start<<endl;
			if (v[start-1]<v[start] and v[start]>v[start+1]){
				//cout<<start<<" ";
				segmentTree[pos] = 1;
			}
			else{
				segmentTree[pos] = 0;
			}
		}
		else if (start==0){
			if (v[1]<v[0]){
				//debug();
				segmentTree[pos] = 1;
			}
			else{
				segmentTree[pos] = 0;
			}
		}
		else if(start == v.size()-1){
			if (v[start]>v[start-1]){
				//debug();
				segmentTree[pos] = 1;
			} 
			else{
				segmentTree[pos] = 0;
			}
		}
		else{
			segmentTree[pos] = 0;
		}
		return segmentTree[pos];
	}
	lli mid((start+end)/2);
	segmentTree[pos] = constructSegmentTreeUtil(v,segmentTree,start,mid,2*pos+1)+constructSegmentTreeUtil(v,segmentTree,mid+1,end,2*pos+2);
	return segmentTree[pos];
}
lli* constructSegmentTree(vector<lli> &v){
	lli maxSize(2*pow(2,ceil(log2(v.size())))-1);
	lli* segmentTree = new lli[maxSize];
	constructSegmentTreeUtil(v,segmentTree,0,v.size()-1,0);
	return segmentTree; 
}
lli noOfpeakUtil(lli* segmentTree,lli segmentStart,lli segmentEnd,lli qstart,lli qend,lli pos){
	if (qstart<= segmentStart and qend >= segmentEnd) {
		return segmentTree[pos];
	}
	if (qstart > segmentEnd || qend < segmentStart){
		return 0;
	}	
	lli mid((segmentStart+segmentEnd)/2);
	return noOfpeakUtil(segmentTree,segmentStart,mid,qstart,qend,2*pos+1)+noOfpeakUtil(segmentTree,mid+1,segmentEnd,qstart,qend,2*pos+2);
}

lli noOfpeak(lli* segmentTree,lli n,lli qstart,lli qend){
	return noOfpeakUtil(segmentTree,0,n-1,qstart,qend,0);
}
int main(){
	lli n,x,y,q;
	cin>>n>>q;
	vi(v);
	loop(i,0,n-1){
		cin>>x;
		v.pb(x);
	}
	lli* segmentTree(constructSegmentTree(v));
   /* loop(i,0,15){
    	cout<<segmentTree[i]<<" ";
    }*/
    loop(i,0,q-1){
    	cin>>x>>y;
    	x--,y--;
    	cout<<noOfpeak(segmentTree,n,x,y)<<endl;
    }
    return 0;
}	