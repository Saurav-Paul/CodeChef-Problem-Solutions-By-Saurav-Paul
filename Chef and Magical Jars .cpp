#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
        int tcase;
        cin>>tcase;

        long long int N;
        while(tcase--)
        {
                cin>>N;
                long long total=0, temp;
                for(int i=0; i<N; i++)
                {
                        cin>>temp;
                        total+=temp;
                }
                cout<<total-(N-1)<<endl;

        }
        return 0;
}
