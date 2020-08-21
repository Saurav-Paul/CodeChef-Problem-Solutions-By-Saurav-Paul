

/**
 *    author        : Saurav Paul 
 *    created       : August 08, 2020 8:49 PM
 *    Problem Name  : Chef and Wedding Arrangements
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/AUG20B/problems/CHEFWED
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(){
    ll guests , TableCost ;
    cin >> guests >> TableCost ;

    vector<ll> F(guests+1) ;
    for(int i = 1 ; i <= guests ; i++) cin >> F[i] ;

    const ll INF = 1e12 + 90 ;
    vector<ll> dp(guests + 1, INF) ;
    for(int i = guests ; i > 0 ; i--){
        ll cost = TableCost ;
        unordered_map<ll,ll> rem ;
        for(int j = i ; j <= guests ; j++){

            int g = F[j] ;
            if(rem[g] == 1) cost += 2;
            else if(rem[g] > 1) cost += 1;

            rem[g] ++ ;
            
            if(j == guests){
                dp[i] = min(dp[i] , cost) ;
                continue ;
            }
            else{
                dp[i] = min(dp[i] ,cost + dp[j+1]) ;
            }
        }
    }
    cout << dp[1] << endl ;
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
