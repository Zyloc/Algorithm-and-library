/*

*/
#include<bits/stdc++.h>

using namespace std;
/*typedef*/
typedef unsigned int uint;
typedef long long lld;
typedef unsigned long long ulld;
typedef double lf;
typedef long double llf;
typedef pair<int,int> pii;
typedef pair<lld,lld> plld;

/*define*/
#define mod 1000000007
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define fl(i,a,b) for(int i=a;i<=b;i++)
#define rfl(i,a,b) for(int i=a;i>=b;i--)

int bs(int i,vector<int> b,int k){
    int low=i+1;
    int high=b.size()-1;
    int mid=(low+high)/2;
    while(low<high){
        if(b[mid]-b[i]<=k) low=mid+1;
        else if(b[mid]-b[i]>k) high=mid;
        mid=(low+high)/2;
    }
    return high;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    vector<int> b(n+1);
    fl(i,1,n){
        cin>>a[i];
        if(a[i]==0) b[i]=1;
        b[i]+=b[i-1];
    }
    int max=0;
    int low=-1,high=-1;
    fl(i,1,n){
        int x=bs(i-1,b,k);
        if(b[x]-b[i-1]>k) x--; 
        int num=x-i+1;
        if(num>max){
            max=num;
            low=i;
            high=x;
        }
        if(x==n) break;
    }
    cout<<max<<endl;
    fl(i,1,n){
        if(i>=low && i<=high) cout<<1<<" ";
        else cout<<a[i]<<" ";
    }
return 0;
} 