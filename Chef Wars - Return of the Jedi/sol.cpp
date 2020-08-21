
/**
 *    author        : Saurav Paul 
 *    created       : August 08, 2020 12:43 PM
 *    Problem Name  : Chef Wars - Return of the Jedi
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/AUG20B/problems/CHEFWARS
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int H , P ;
    cin >> H >> P ;

    while(P){
        H -= P ;
        P >>= 1;
    }

    cout << (H <= 0 ? 1 : 0) << endl ;
}

int main(){
    ios_base::sync_with_stdio(false);

    int testcase ;
    cin >> testcase ;
    for(int i = 0 ; i < testcase ; i ++){
        solve();
    }

    return 0 ;
}
