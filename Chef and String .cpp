
/**
 *    author:  Saurav Paul 
 *    created: June 11, 2020 11:24 AM
**/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size() ;
    int pairs = 0 ;
    for (int i = 1; i < n; i++){
        if(s[i] != s[i-1]){
            pairs ++;
            i ++ ;
        }
    }
    cout << pairs << endl; 
}

int main(){

    ios_base::sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    while(testcase--){
        solve();
    }

    return 0;
}
