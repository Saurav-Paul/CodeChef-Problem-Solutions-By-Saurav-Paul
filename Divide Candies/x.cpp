
/**
 *    author        : Saurav Paul 
 *    created       : September 12, 2020 3:57 PM
 *    Problem Name  : Divide Candies
 *    Problem Limit : 2000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/SEPT20A/problems/EQDIV
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class TC{

    public :
    void solve(){
        ll N , K ;
        cin >> N  >> K;

        ll a = 0 ;

        for(ll i = 1; i <= N/2 ; i++){
            ll x ;
            cin >> x;
            ll temp = x;
            for(int i = 1 ; i < K ; i++) temp *= x;
            a += temp ;
        }
        ll b = 0 ;

        for(ll i = N/2 + 1; i <= N ; i++){
            ll x ;
            cin >> x;
            ll temp = x;
            for(int i = 1 ; i < K ; i++) temp *= x;
            b += temp ;
        }

        cout << a << " " << b  << " " <<  abs(a-b) << endl ;
    }
};

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){
        TC tc;
        tc.solve() ;
    }

    return 0 ;
}
