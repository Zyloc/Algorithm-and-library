#include <bits/stdc++.h>
using namespace std;
//Buffer reading
int INP,AM;
#define BUFSIZE (1<<10)
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) { \
    if(!*inp) { \
        fread(BUF,1,BUFSIZE,stdin); \
        inp=BUF; \
    } \
    INP=*inp++; \
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) { \
    AM=0;\
    GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
    if (INP=='-') {AM=1;GETCHAR(INP);} \
    j=INP-'0'; GETCHAR(INP); \
    while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
    if (AM) j=-j;\
}
//End of buffer reading
 
pair<long long,int> d[100000];
long long n,k,nn;
int nd,q,z,t;
map<long long,int> f;
void getdiv(long long now,int cnt,int id){
    if (id==nd+1){
        z++;
        f[now]=cnt;
        return ;
    }
    for (int i=0; i<=d[id].second; i++){
        getdiv(now,cnt*(i+1),id+1);
        now*=1LL*d[id].first;
    }
}
int main(){
    GN(n);GN(q);
    nn=n;
    for (int j,i=2; 1LL*i*i<=n; i++){
        if (n%i==0){
            j=0;
            while (n%i==0){
                j++;
                n/=i;
            }
            d[++nd]=make_pair(i,j);
        }
    }
    if (n>1) d[++nd]=make_pair(n,1);
    n=nn;
    getdiv(1,1,1);
    while (q--){
        GN(t);GN(k);
        if (t==1){
            k=__gcd(n,k);
            printf("%d\n",f[k]);
        } else
        if (t==2){
            if (n%k==0){
                k=n/k;
                printf("%d\n",f[k]);
            } else printf("0\n");
        } else{
            if (n%k==0){
                k=n/k;
                printf("%d\n",z-f[k]);
            } else printf("%d\n",z);
        }
    }
}