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
#define debug() cout<<"######"<<endl 
int main(){
	zyloc(){
		string s1,s2,s3;
		lli n,ans(0),countOne(0),countTwo(0),countThree(0);
		cin>>s1>>s2>>s3>>n;
		loop(i,0,s1.length()-1){
			if (s1[i]=='1'){
				countOne++;
			}
		}
		loop(i,0,s2.length()-1){
			if (s2[i]=='1'){
				countTwo++;
			}
		}
		loop(i,0,s3.length()-1){
			if (s3[i]=='1'){
				countThree++;
			}
		}
		if(countOne+countTwo+countThree == s1.length()+s2.length()+s3.length()){
			cout<<"1"<<endl;
		}
		else if (countThree < s3.length()){
			lli dummy(0);
			pool(i,s3.length()-1,0){
				if (s3[i]=='0'){
					s3[i]='1';
					break;
				}
				else{
					s3[i]='0';
				}
			}
			loop(i,0,s3.length()-1){
				if (s3[i]=='1'){
					dummy++;
				}
			}
			cout<<countOne+countTwo*n+dummy<<endl;
		}
		else if (countTwo < s2.length()){
			lli dummy(0);
			pool(i,s2.length()-1,0){
				if (s2[i]=='0'){
					s2[i]='1';
					break;
				}
				else{
					s2[i]='0';
				}
			}
			loop(i,0,s2.length()-1){
				if (s2[i]=='1'){
					dummy++;
				}
			}
			cout<<countOne+countTwo*(n-1)+dummy<<endl;
		}
		else{
			lli dummy(0),flag(0);
			pool(i,s1.length()-1,0){
				if (s1[i]=='0'){
					s1[i]='1';
					break;
				}
				else{
					s1[i]='0';
				}
			}
			loop(i,0,s1.length()-1){
				if (s1[i]=='1'){
					dummy++;
				}
			}
			cout<<dummy<<endl;	
		}
	}
	return 0;
}	