/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli long long int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1000000007;
class BearPlaysDiv2{
public:
	bool visited[10][10][10];
	bool magicBox(int input[]){
		if(input[3]>500){
			return false;
		}
		sort(input,input+3);
		if(visited[input[0]][input[1]][input[2]]){
			return false;
		}
		if(input[0]==input[1] and input[1]==input[2]){
			return true;
		}
		visited[input[0]][input[1]][input[2]] = true;
		int x(input[0]),y(input[1]);
		if(x < y){
			if(magicBox(input)){
				return true;
			}			
		}
		x = input[1];
		y = input[2];
		if(x < y){
			if(magicBox(input)){
				return true;
			}
		}
		return false;	
	}
	string equalPiles(int a,int b,int c){
		int input[3];
		input[0] = a;
		input[1] = b;
		input[2] = c;
		sort(input,input+3);
		if(magicBox(input)){
			return "possible";
		}
		return "impossible";
	}
};
int main(){
	BearPlaysDiv2 obj;
	cout<<obj.equalPiles(10,15,35);
	return 0;
}