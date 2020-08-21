
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

    vector<ll> F(guests) ;
    for(auto &x : F){
        cin >> x ;
    }

    unordered_map<ll,ll> trem ;
    vector <ll> prefix(guests + 1) ;

    for(int i = guests -1 ; i >= 0 ; i--){
      int g = F[i] ;
      int temp = 0 ;
      if(trem[g] == 1){
        temp += 2 ;
      }
      else if(trem[g] > 1){
        temp += 1;
      }
      trem[g] ++ ;
      prefix[i] += prefix[i+1] + temp ;
    }

    auto getValue = [&](ll cnt){
        ll same = 0 ;
        unordered_map<ll,ll> rem ;
        ll xcnt = 0 ;
        ll table = 1 ;
        ll tprefix = 1e12 + 90 ;

        for(int i = 0 ; i < guests ; i++){
            ll g = F[i] ;
            ll temp = 0 ;
            if(rem[g] == 1){
                same += 2;
                temp += 2;
            }
            else if(rem[g] > 1) {
                same ++ ;
                temp ++ ;
            }

            if(same - xcnt > cnt){
                table ++ ;
                rem.clear() ;
                same -= temp ;
                xcnt = same ;
                tprefix = min( tprefix ,same+prefix[i] + table * TableCost ) ;
            }

            rem[g] ++ ;

        }
        ll ans = ((table * TableCost) + same) ;
        return min(ans,tprefix);
    } ;

    // bruteforcing 
    ll ans = 1e12 + 90 ;
    for(int cnt = 1 ; cnt <= guests ; cnt ++ ){
        ans = min(ans, getValue(cnt)) ;
    }

    cout << ans << endl ;

    /*

    3
    5 1
    5 1 3 3 3

    1 = 5 1 3 | 3 | 3 = 3 * 1 = 3
    2 = 5 1 3 3 | 3 = 1 * 2 + 2 = 3
    3 = 5 1 3 3 3 = 1 + 3 = 4

    5 14
    1 4 2 4 4

    1 = 1 4 2 | 4 | 4 = 14* 3 = 42
    2 = 1 4 2 4 | 4 = 14 * 8 + 2 = 30
    3 = 1 4 2 4 4 = 14 + 3 = 17
    
    5 2
    3 5 4 5 1
    1 = 3 5 4 | 5 1 = 2 * 2 = 4
    2 = 3 5 4 5 1 = 2 + 2 = 4

    */
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
