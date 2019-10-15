				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

const int nax = 1e6 + 90 ;

void divisor(vector<int> &cnt , int target){
	int sq = sqrt(target) ;
	for(int i = 1 ; i <= sq ; i++){
		if(target%i==0){
			int vag = target/i;
			if(vag==i)
				cnt[i] ++;
			else
				cnt[i]++ , cnt[vag] ++;
		}
	}
	
}

void solve() {
	int N ;
	scanf("%d",&N) ;
	
	vector<int> v(N) ;
	for(int i = 0 ; i < N ; i++) scanf("%d",&v[i]) ;

	vector<int> cnt(nax+5);
	int mx = 0;
	for(int i = 0 ; i < N; i++){
		int target = v[i] ;
		mx = max(cnt[target],mx) ;
		divisor(cnt,target) ;
	}

	printf("%d\n",mx) ;
}

int main()
{

	int t ;
	scanf("%d",&t);
	while(t--) 
		solve() ;
	
    return 0;
}
