
/**
 *    author        : Saurav Paul 
 *    created       : August 08, 2020 1:05 PM
 *    Problem Name  : Chef and Linear Chess
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/AUG20B/problems/LINCHESS
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int N , P ;
    cin >> N >> P ;
    int mn = 1e9 , ans = -1 ;

    for(int i = 0 ; i < N ; i++){
        int num ; 
        cin >> num ;
        if(P%num == 0 && P/num < mn) mn = P/num , ans = num ;
    }

    cout << ans << endl ;
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
