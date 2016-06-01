#include <bits/stdc++.h>
using namespace std;
 
int main()
{
   int t;
   cin>>t;
   for (int i=0;i<t;i++){
   		int pile;
   		cin>>pile;
   		int n,small=1000 ;
   		vector <int> v;
   		for (int j=0;j<pile;j++){
   			cin>>n;
   			if (j!=0){
   				v.push_back(v[j-1]+n);
   			}
   			else{
   				v.push_back(n);
   			}
   			if(small>n){
   				small=n;
   			}
   			
   		}
   		cout<<small-1<<" ";
   		cout<<v[(v.size()-1)]-pile<<endl;
   }
    return 0;
}