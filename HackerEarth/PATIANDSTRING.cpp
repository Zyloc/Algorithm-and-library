#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int test_case;
    cin>>test_case;
    for (int i=0;i<test_case;i++){
        int length;
        cin>>length;
        char word[length];
        int hash[26]={0};
        cin>>word;
        //cout<<word<<endl;
        for (int j=0;j<length;j++){
            hash[word[j]-97]++;
        }
        int max=hash[0];
        for (int k=0;k<26;k++){
            if (max<hash[k]){
                max=hash[k];
            }
        }       
        if (max%2==0){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
  return 0;
}
 