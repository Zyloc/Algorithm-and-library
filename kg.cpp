
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (int i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
#define kg() lli t;cin>>t;while(t--)
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

struct tb
{
    int a;
    int b;
    int c;
    int d;
};

bool cmp( tb  x , tb   y){
  if (x.a!=y.a){
    return x.a<y.a;
  }
  return x.d<y.d;
}
int main()
{
  int n;
  cin>>n;
  vector < struct tb > v ; // can define constant size here;

  int ar[3];
  loop(i,0,n-1)
  {
  cin>>ar[0]>>ar[1]>>ar[2];
  tb temp ;
  temp.a=ar[0];
  temp.b=ar[1];
  temp.c= ar[2];
  temp.d= i+1;
  v.pb(temp);
  }
  sort(v.begin(),v.end(),cmp);
  loop(i,0,n-1){
    cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].c<<" "<<v[i].d<<endl;
  }
  return 0;
}