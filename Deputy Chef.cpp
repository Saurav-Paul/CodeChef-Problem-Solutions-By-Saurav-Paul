#include<iostream>
using namespace std;
int main()
{

    int t,n,a[105],shield;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cost=-1;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n; i++)
        {
            int temp;
            cin>>shield;
            if(i==0)
                temp=a[i+1]+a[n-1];

            else if(i==n-1)
                temp=a[n-2]+a[0];

            else
                temp=a[i-1]+a[i+1];

            if(shield-temp>0 && shield>cost)
                cost=shield;

        }
        cout<<cost<<endl;
    }

    return 0;
}
