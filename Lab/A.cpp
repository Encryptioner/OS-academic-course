#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,cnt=0,v;
    long long int x,mi=3000000000;
    vector<int>a;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(i=1;i<n;i++)
    {
        x=abs(a[i-1]-a[i]);
        if(x<mi)
        {
            mi=x;
            cnt=1;
        }
        else if(x==mi)
        {
            cnt++;
        }
    }
    cout<<mi;
    printf(" %d\n",cnt);
    return 0;
}

