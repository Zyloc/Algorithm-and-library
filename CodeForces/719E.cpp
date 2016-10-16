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
#define ll long long int
#define debug() cout<<"######"<<endl 
ll fibo(ll n){
 ll e=n-2;
// pair< pair< int, int >,pair < int ,int > > p;;
   ll a=0,b=1,c=1,d=1; 
   ll a1,b1,c1,d1,a2=0,b2=1,c2=1,d2=1;  
  while(e>0){
       if(e%2==1){
           a1= (a*a2+b*c2)%MOD;
           c1= (c*a2+d*c2)%MOD;
           b1= (a*b2+ b*d2)%MOD;
           d1= (b2*c+ d*d2)%MOD;
           a=a1;
           b=b1;
           c=c1;
           d= d1;
     	}
           a1= (a2*a2+b2*c2)%MOD;
           c1= (c2*a2+d2*c2)%MOD;
           b1= (a2*b2+ b2*d2)%MOD;
           d1= (b2*c2+ d2*d2)%MOD;
           a2=a1;
           b2=b1;
           c2=c1;
           d2= d1;
           e= e/2;
	}
    return d%MOD;
}
lli constructSegmentTreeUtil(vector<lli> &v,lli* segmentTree,lli start, lli end, lli pos){
	if (start==end){
		//cout<<v[start]<<" "<<fibo(v[start]+2)<<endl;
		segmentTree[pos] = (fibo(v[start])-1)%MOD;
		return segmentTree[pos]%MOD;
	}
	lli mid((start+end)/2);
	segmentTree[pos] = (constructSegmentTreeUtil(v,segmentTree,start,mid,2*pos+1)%MOD+constructSegmentTreeUtil(v,segmentTree,mid+1,end,2*pos+2)%MOD)%MOD;
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
		return segmentTree[pos]%MOD;
	}
	if (qstart > segmentEnd || qend < segmentStart){
		return 0;
	}	
	lli mid((segmentStart+segmentEnd)/2);
	return (noOfEvenUtil(segmentTree,segmentStart,mid,qstart,qend,2*pos+1)%MOD+noOfEvenUtil(segmentTree,mid+1,segmentEnd,qstart,qend,2*pos+2)%MOD)%MOD;
}

lli noOfEven(lli* segmentTree,lli n,lli qstart,lli qend){
	return noOfEvenUtil(segmentTree,0,n-1,qstart,qend,0)%MOD;
}
void updateSegmentTreeUtil(vector<lli> &v ,lli* segmentTree,lli segmentStart,lli segmentEnd,lli qstart,lli qend,lli value,lli pos){
	if (segmentStart > segmentEnd or segmentStart > qend or segmentEnd < qstart){
		return;
	}
	if (segmentStart == segmentEnd ){
		v[segmentStart]+= value;
		segmentTree[pos] = (fibo(v[segmentStart]+2)-1)%MOD;
	}
	lli mid((segmentStart+segmentEnd)/2);
	updateSegmentTreeUtil(v,segmentTree,segmentStart,mid,qstart,qend,value,2*pos+1);
	updateSegmentTreeUtil(v,segmentTree,mid+1,segmentEnd,qstart,qend,value,2*pos+2);
	segmentTree[pos] = (segmentTree[2*pos+1]+segmentTree[2*pos+2])%MOD;
	return;
}
// update the values from qstart to qend by 'value'
lli updateSegmentTree(vector<lli> &v ,lli* segmentTree,lli n,lli qstart, lli qend,lli value){
	updateSegmentTreeUtil(v,segmentTree,0,n-1,qstart,qend,value,0);
	
	return 0;
}

int main(){
	lli n,m,x,l,r;
	cin>>n>>m;
	vi(v);
	loop(i,0,n-1){
		cin>>x;
		v.pb(x);
	}
	lli* segmentTree(constructSegmentTree(v));
	loop(i,0,15){
		cout<<segmentTree[i]<<" ";
	}
	loop(i,0,m-1){
		cin>>x;
		if (x == 1){
			cin>>l>>r>>x;	
			updateSegmentTree(v,segmentTree,n,--l,--r,x);
		}
		else{
			cin>>l>>r;
			cout<<noOfEven(segmentTree,n,--l,--r)%MOD<<endl;
		}
	}
	return 0;
}	