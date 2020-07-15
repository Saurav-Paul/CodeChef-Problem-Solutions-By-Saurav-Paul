
/**
 *    author        : Saurav Paul 
 *    created       : July 09, 2020 8:42 PM
 *    Problem Name  : Chef and Strings
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/JULY20B/problems/CHEFSTR1
**/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n ,prev = 0;
    cin >> n;
    long long int cnt = 0;

    for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        if( i ){
            cnt += max(0,abs(prev-x)-1) ;

        }
        prev = x ;
    }
    cout << cnt << endl ;
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
