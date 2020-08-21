
/**
 *    author        : Saurav Paul 
 *    created       : August 08, 2020 1:10 PM
 *    Problem Name  : Another Card Game Problem
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/AUG20B/problems/CRDGAME3
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int Pc , Pr;
    cin >> Pc >> Pr  ;

    auto getMinValue = [](int x){
        return int((x+8)/9);
    } ;

    int  c = getMinValue(Pc) , r = getMinValue(Pr) ;
    int who = 1 , digit = r ;

    if(c < r) who = 0 , digit = c ; 

    cout << who <<" " << digit << endl ;

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
