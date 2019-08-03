#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	scanf("%d",&n);
	vector<int > score(n);
	for(int i= 0 ; i < n ; i++){
		int temp; scanf("%d",&temp);
		
		score[i] = 20 * temp;
		
	}
	int mx = 0;
	for(int i = 0 ; i < n ; i++){
		int temp ; scanf("%d",&temp);
		score[i] -= (temp*10);
		mx = max(mx,score[i]);
	}
	printf("%d\n",mx);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
}
