
/**
 *    author        : Saurav Paul 
 *    created       : August 08, 2020 7:52 PM
 *    Problem Name  : Smallest KMP
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/AUG20B/problems/SKMP
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    string S , P ;
    cin >> S >> P ;

    unordered_map<char,int> rem ;
    for(auto c : P){
        rem[c] ++ ;
    }

    vector<char> ans ;
    for(auto c : S){
        if(rem[c] > 0) rem[c]-- ;
        else ans.emplace_back(c) ;
    }
    bool Pok = false ;
    for(int i = 1 ; i < P.size() ; i++){
        if(P[i] < P[0]){
            Pok = true ;
            break ;
        }
        else if(P[i] > P[0]) break ;
    }

    sort(ans.begin(), ans.end()) ;
    bool ok = true ;
    for(int i = 0, n = ans.size() ; i < n ; i++){
        if ((ok && P[0] < ans[i]) or (ok && Pok && P[0] == ans[i]) ){
            cout << P ;
            ok = false ;
        }
        cout << ans[i] ;
    }
    cout << (ok?P:"") << endl ;
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
