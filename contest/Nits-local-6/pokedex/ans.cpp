#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(i=a;i<b;i++)
long long int b[10000001];
int main(){
    ll t,n,i,j,k,l,flag,S,L,sf,lf,maxi;
    cin>>t;
    while(t--){
        cin>>n;
        ll a[n];
        maxi=0;
        loop(i,0,n){
        cin>>a[i];
        if(a[i]>maxi){
            maxi=a[i];
        }
        }
        //Array b is for storing the frequency of various elements (HASHING)
        memset(b,0,sizeof b);//initializing the array to zero
        loop(i,0,n){
        b[a[i]-1]++;
        }
        set<ll>s; //set for storing the distinct frequencies
        loop(i,0,maxi){
            if(b[i]!=0){
                s.insert(b[i]);
            }
        }

        if(s.size()==2){// when there are only two distinct frequencies
            int c[2];
            k=0;//for index of array 'c'
            for (set<ll>::iterator i1 = s.begin(); i1!= s.end(); i1++){
                l=*i1;//value in the set
                c[k]=l;
                k++;
            }
            S=min(c[0],c[1]);//small element in the set
            L=max(c[0],c[1]);//large element in the set
            //cout<<S<<" "<<L<<endl;
            sf=0;//will store the frequency of the small element
            lf=0;//will store the frequency of the large element
            loop(i,0,maxi){
                if(b[i]==S){
                    sf++;
                }
                else if(b[i]==L){
                    lf++;
                }
            }
            if(sf==1){ //if the small element in set is not one like in case A={1,1,2,2,2,3,3,3} here S=2(freq of 1)
                if(S!=1)
                {cout<<"NO"<<endl;}
                else{
                    cout<<"YES"<<endl;
                }
            }
            else if((lf==1 || sf==1 )&& (L-S)==1 ){//if frequency of any element is one we will directly delete that element and get the result A=
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }

        else if(s.size()>2){// if there are more then 2 distinct numbers then we would require more then one deletions
            cout<<"NO"<<endl;
        }

        else{// if there is only single element present in the entire array
            cout<<"YES"<<endl;
        }
    }
    return 0;
}

