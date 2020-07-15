
/**
 *    author        : Saurav Paul 
 *    created       : July 15, 2020 11:46 PM
 *    Problem Name  : Ada King
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/JULY20B/problems/ADAKING
**/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n ; 
    cin >> n;

    vector < vector <char> > v(8, vector<char>(8,'X')) ;
    int cnt = 0 ;
    for(int i = 0 ; i < n and cnt < n ; i++) {
        for(int j = 0 ; j < 8 and cnt < n ; j ++ ){
            v[i][j] = '.' ;
            ++ cnt ;
        }
    }

    v[0][0] = 'O' ;

    for(int i = 0 ; i < 8 ; i ++){
        for(int j = 0 ; j < 8 ; j ++){
            cout << v[i][j] ;
        }
        cout << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);

    int testcase ;
    cin >> testcase ;
    for(int i = 0 ; i < testcase ; i ++){
        if(i){
            cout << endl ;
        }
        solve();
    }

    return 0 ;
}
