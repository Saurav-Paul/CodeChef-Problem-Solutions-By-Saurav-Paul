
/**
 *    author        : Saurav Paul 
 *    created       : July 25, 2020 9:25 PM
 *    Problem Name  : Maximum Candies
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/LTIME86B/problems/CHECHOC
**/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long N , M , x , y , f , s;
    cin >> N  >> M >> x >> y ;

    if(N==1 && M==1){
        cout << x << endl ;
        return ; 
    }

    long long lim = min(2*x,y) ;
    x = min(x,y) ;

    if(lim < x){
        f = lim ;
        s = 0 ;
    }
    else{
        f = x ;
        s = lim - x ;
        if(f < s){
            swap(f,s) ;
        }
    }

    long long half = M/2 ;
    long long ans = 0 ;

    ans = half * f + half * s ;
    ans *= N ;

    if(M&1) {
        ans += (N/2) * f + (N/2) * s + (N%2)*f ;
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
