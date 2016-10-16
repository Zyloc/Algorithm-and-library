#include<bits/stdc++.h>
     
    #define mod 1000000007
    #define nax 1000005
    #define inf 100000000000000000LL
    #define pb push_back
    #define mp make_pair
    #define in insert
    #define ff first
    #define ss second
    #define pll pair<long long int,long long int>
    #define pii pair<int,int>
    #define vll vector<long long int>
    #define vii vector<int>
    #define sii set<int>
    #define sll set<long long int>
    #define mii map<int,int>
    #define mll map<long long int,long long int>
    #define mis map<int,string>
    #define gi(n) scanf("%d",&n)
    #define gll(n) scanf("%lld",&n)
    #define gst(n) scanf("%s",n)
    #define gc(n) cin >> n
    #define oi(n) printf("%d",n)
    #define oll(n) printf("%lld",n)
    #define ost(n) printf("%s",n)
    #define oc(n) cout << n
    #define os cout<<" "
    #define on cout<<"\n"
    #define o2(a,b) cout<<a<<" "<<b
    #define all(n) n.begin(),n.end()
    #define present(s,x) (s.find(x) != s.end())
    #define cpresent(s,x) (find(all(s),x) != s.end())
    #define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
    #define lpi(i,a,b) for(int i=a;i<=b;i++)
    #define lpr(i,a,b) for(int i=a;i>=b;i--)
    #define lpv(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)
     
    using namespace std;
     
    typedef unsigned long long int ull;
    typedef long long int lli;
    typedef vector<vector<lli> > mat;
     
    void swap(int *a,int *b) { int t=*a;  *b=*a, *a=t; }
    double power(lli x,lli n) { double B=log(x); double C=n*B; return exp(C); }
    bool isOdd(lli n){ if(n&1) return 1; return 0; }
    lli noSetBit(lli n){ lli cnt=0; while(n){ n&=(n-1); cnt++;} return cnt; }
    lli tree[1000000];
    void build(lli ar[],lli node,lli start,lli end)
    {
        if(start==end)
        {
            //cout<<start<<endl;
            if(ar[start]&1){
                tree[node]=0;        //odd is 0
            }
            else{
                //cout<<start;
                tree[node]=1;       //even is 1
            }
            return;
        }
        else
        {
            lli mid=(start+end)/2;
            build(ar,2*node,start,mid);
            build(ar,2*node+1,mid+1,end);
        
        }
        //cout<<node<<" "<<tree[2*node]<<" "<<tree[2*node+1]<<endl;
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    void update(lli ar[],lli start,lli end,lli idx,lli node,lli value)
    {
        if(start == end)
        {
                ar[idx]=value;
                if(ar[idx]&1)
                    tree[node]=0;               //odd is 0
                else
                    tree[node]=1;               //even is 1
                return ;
        }
        else if(idx<start ||  idx > end)         //completly outside
        {
            return;
        }
        else
        {
                lli mid = (start + end) / 2;
     
                update(ar,start, mid, idx, 2*node, value);
     
                update(ar,mid+1, end, idx, 2*node+1, value);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    int query(lli l,lli r,lli start,lli end,lli node)
    {
        if(end<l||start>r)                  //complete disjoint set returns 0
            return 0;
        
        else if(start>=l&&end<=r)           //complete intersection returns node value
                return tree[node];

        else
        {
     
            lli mid=(start+end)/2;
            lli a=query(l,r,start,mid,2*node);
            lli b=query(l,r,mid+l,end,2*node+1);
            return (a+b);
            
        }
     
    }
    int main()
    {
        //ios_base::sync_with_stdio(false); cin.tie(0);
        lli n;
        cin>>n;
        lli ar[n+1];
        lpi(i,1,n)
            cin>>ar[i];
        build(ar,1,1,n);
        for(int i=0;i<=16;i++)
            cout<<tree[i]<<" ";
        lli q;
        cin>>q;
        lpi(i,0,q-1)
        {
            lli check,l,r,idx;
            lli value;
            cin>>check;
            if(check==0)
            {
                cin>>idx>>value;
                update(ar,1,n,idx,1,value);
            }
            else if(check==1)
            {
                cin>>l>>r;
                cout<<query(l,r,1,n,1)<<"\n";
            }
            else
            {
                cin>>l>>r;
                cout<<(r-l+1-query(l,r,1,n,1))<<"\n";
            }
        }
        return 0;
    }