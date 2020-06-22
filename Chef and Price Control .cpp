
/**
 *    author:  Saurav Paul 
 *    created: June 11, 2020 11:14 AM
**/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int loss = 0 ;
    for(int i = 0 ; i < n; i++){
        int x ;
        cin >> x;
        if( x > k)
            loss += x-k;
    }
    cout << loss << endl;

}

int main(){

    ios_base::sync_with_stdio(false);	
    int testcase;
    cin >> testcase;
    while(testcase--)
        solve();

    return 0;
}
