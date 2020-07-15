
/**
 *    author        : Saurav Paul 
 *    created       : July 09, 2020 8:52 PM
 *    Problem Name  : Chef and Card Game
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/JULY20B/problems/CRDGAME
**/

#include<bits/stdc++.h>
using namespace std;

int sumDig(int x){
    int ans = 0;
    while(x){
        ans += x%10 ;
        x /= 10;
    }
    return ans ;
}

void solve(){
    int n ;
    cin >> n ;
    int a = 0 , b = 0 ;
    for(int i = 0; i < n; i ++){
        int x , y ;
        cin >> x >> y ;
        x = sumDig(x);
        y = sumDig(y) ;

        if(x > y){
            ++ a;
        }
        else if(x < y){
            ++ b;
        }
        else {
            ++ a;
            ++ b;
        }
    }
    if ( a == b ){
        cout << 2 << " " << a << endl ;
    }
    else if ( a > b ) {
        cout << 0 << " " << a << endl ;
    }
    else {
        cout << 1 << " " << b << endl ;
    }
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
