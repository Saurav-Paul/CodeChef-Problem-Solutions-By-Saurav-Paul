
/**
 *    author        : Saurav Paul 
 *    created       : August 30, 2020 9:13 AM
 *    Problem Name  : Game on a Strip
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/LTIME87A/problems/ARRGAME
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class TC{

    vector<int> pos , len ;
    int N ;

    public :
    void solve(){
        cin >> N ;

        pos.assign(N,0) ;
        for(auto &x : pos){
            cin >> x;
        }

        int cnt = 0 ;
        len.push_back(cnt) ;
        for(int i = 0 ; i < N ; i++){
            if(pos[i]){
                len.push_back(cnt) ;
                cnt = 0 ;
            }
            else{
                cnt ++;
            }

        }
        len.push_back(cnt) ;

        cout << (check()?"Yes":"No") << "\n" ;

    }
    bool check(){
        sort(len.rbegin(),len.rend()) ;
        if(len[0]%2==0) return false ;
        if(len[1]*2 >= len[0] + 1) return false ; 
        return true ;
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
