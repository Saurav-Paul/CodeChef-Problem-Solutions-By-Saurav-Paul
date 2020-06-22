
/**
 *    author:  Saurav Paul 
 *    created: June 22, 2020 7:10 PM
 *    Problem Name : Chef and Icecream
 *    Problem Url : https://www.codechef.com/JUNE20B/problems/CHFICRM
**/

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n ; 
    cin >> n;
    bool ok = true ;
    vector<int> v(3);
    for(int i = 0 ; i< n; i++){
        int x ;
        cin >> x;
        if(x == 5){
            v[0] ++ ;
        }
        else if (x == 10){
           if(v[0] <= 0 ){
              ok = false ;
           } 
           v[0] -- ;
           v[1] ++ ;
        }
        else if( x == 15 ){
            if(v[1] > 0 ){
                v[1] -- ;
            }
            else if ( v[0] > 1 ){
                v[0] -= 2;
            }
            else{
                ok = false ;
            }
        }
    }
    cout << (ok?"YES":"NO") << endl ;    
}
int main(){

    ios_base::sync_with_stdio(false);
    int testcase ;
    cin >> testcase;
    for(int i = 0 ; i < testcase ; i++){
        solve();
    }    

    return 0;
}
