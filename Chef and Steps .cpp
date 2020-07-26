
/**
 *    author        : Saurav Paul 
 *    created       : July 25, 2020 8:00 PM
 *    Problem Name  : Chef and Steps
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/LTIME86B/problems/CHEFSTEP
**/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n , step;
    cin >> n >> step ; 

    string ans ="" ;

    for(int i = 0 ; i < n; i++){
        int x ; 
        cin >> x;
        if(x%step==0){
            ans +='1' ;
        }
        else{
            ans += '0' ;
        }
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
