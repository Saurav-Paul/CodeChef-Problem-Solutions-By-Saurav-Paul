
/**
 *    author        : Saurav Paul 
 *    created       : September 05, 2020 9:50 PM
 *    Problem Name  : Ada Matrix
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/SEPT20A/problems/ADAMAT
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

class TC{

    int N ;
    vector<vector<int>> matrix, trans ;
    public :
    void solve(){

        cin >> N ;

        matrix.assign(N+1,vector<int>(N+1)) ;

        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                cin >> matrix[i][j] ;
            }
        }

        int ans = 0 ;

        for(int i = N; i > 0  ; i--){
            for(int j = i ; j > 0 ; j--){
                if(cal(i,j) != matrix[i][j] || cal(j,i) != matrix[j][i]){
                    transpose(i) ;
                    ans ++ ;
                    break ;
                }
            }
        }

        cout << ans << endl ;
        assert(check(N)) ;


    }

    void transpose(int n){

        trans = matrix ;
        for(int i = 1 ; i <= n; i++){
            for(int j = 1; j <= n; j++){
                trans[j][i] = matrix[i][j] ;
            }
        }
        matrix = trans ;
    }

    bool check(int L){

        for(int i = 1; i <= L ; i++){
            for(int j = 1; j <= L ; j++){
                if(cal(i,j) != matrix[i][j]){
                    return false ;
                }
            }
        }

        return true ;
    }
    int cal(int i, int j){
        return ((i-1) * N + j) ;
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
