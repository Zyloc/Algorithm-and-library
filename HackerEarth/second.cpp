/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <bits/stdc++.h>  
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
#define Lim  1000000
using namespace std;
long long mohit[1000010]  ;
long long  ret[1000010];
lli constructSegmentTreeUtil(vector<lli> &v,lli* segmentTree,lli start, lli end, lli pos){
	if (start==end){
		segmentTree[pos] = v[start];
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
	if (segmentStart == segmentEnd){
		segmentTree[node] = value;
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
void cal_mohit()
   {
      for(int i = 1 ;i <= Lim ; i++ ) mohit[i]=i;
      for(int i=2 ; i<= Lim ; i++ )
        if ( mohit[i] == i)
          for(int j = 2*i ; j <= Lim ; j += i) mohit[j] -=  mohit[j]/ i ;
      for(int i=2 ; i<= Lim ; i++) if ( mohit[i]==i) mohit[i] = i-1;
  for(int i=1;i <= Lim ; i++) for (int j = i ; j <= Lim ; j += i  ) ret[j]+= i*mohit[i];
}

int main(){
	cal_mohit();
	lli n,x,y;
	scanf("%lld",&n);
	vi(v);
	for(int i=0 ; i<n ; i++){
		scanf("%lld",&x);
		long long sum = ( 1 + ret[x] )/ 2;
		v.pb(sum);
	}
	/*loop(i,0,v.size()-1){
		cout<<v[i]<<" ";
	}*/
	lli* segmentTree(constructSegmentTree(v));
	/*loop(i,0,6){
		cout<<segmentTree[i]<<" ";
	}*/
	lli q;
	scanf("%lld",&q);
	char c;
	loop(i,0,q-1){
		//scanf("%c",&c);
		cin>>c;
		if (c=='C'){
			//cout<<"here";
			scanf("%lld %lld",&x,&y);
			x--,y--;
			//cout<<x<<" "<<y<<endl;
			cout<<noOfEven(segmentTree,n,x,y)<<endl;
		}
		else{
			scanf("%lld %lld",&x,&y);
			x--;
			y = (1 + ret[y])/2;
			updateSegmentTree(segmentTree,n,x,y);	
		}
	}
}