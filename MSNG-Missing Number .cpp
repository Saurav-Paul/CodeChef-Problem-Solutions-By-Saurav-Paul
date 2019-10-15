				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;
const ll mxnum = 1e12 ;
ll val(char c)
{
    if (c >= '0' && c <= '9')
        return (ll)c - '0';
    else
        return (ll)c - 'A' + 10;
}

ll toDeci( ll base ,string str)
{
    ll len = str.size();
    ll power = 1;     ll num = 0;

    double lim = 12.000000;
    bool problem = false;

    for (ll i = len - 1; i >= 0; i--)
    {
        ll value = val(str[i]) ;

        if (value >= base)
        {
           return -1;
        }

        if(value){
            if(problem) return -1 ;

            double x = log10(power) + log10(value) ;
            if(x > lim) return -1;

            num += (power * value) ;

            if(num > mxnum) return -1 ;
            x = log10(num) ;
            if(x > lim) return -1;
        }
        if(i){
            double x = log10(power) + log10(base) ;
            if(x > lim) problem = true;
            if(problem==false)
                power *= base ;
        }


    }

    return num;
}



void solve() {

    int N ;
    cin >> N ;
    map <ll , ll > cnt;
    for(int i =  0 ; i < N ; i++){
        ll base ,xans;
        string s;
        cin >> base >> s ;
        if(base == -1){

            set <ll> myset;
            for(int i = 2 ; i <= 36 ; i++){
                xans = toDeci(i,s) ;
                if(xans != -1)
                    myset.insert(xans);
            }
            for(auto x : myset) cnt[x] ++ ;

        }
        else{
            xans = toDeci(base,s) ;
            if(xans != -1)
                cnt[xans] ++;
        }
    }

    for(auto x : cnt){
        if(x.second == N){
            cout << x.first << endl;
            return ;
        }
    }
    cout << -1 << endl ;
}
int main()
{
    ios_base::sync_with_stdio(false) ;

	int t; cin >> t;
	while(t--)
		solve() ;

    return 0;
}

