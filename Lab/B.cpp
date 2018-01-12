#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,i,j,data,x,cnt;
    queue<int>q;

    scanf("%d %d",&n,&k);
    cnt=n;
    for(i=1;i<=n;i++)
    {
        q.push(i);
    }
    for(i=0;i<k;i++)
    {
        scanf("%d",&x);
        x=x%cnt;

        data=q.front();
        q.pop();

        if(x!=0)
        {
           q.push(data);
        }

        //cout<<"tt"<<data<<" "<<x<<"rr";
        for(j=0;j<x-1;j++)
        {
            data=q.front();
            q.pop();
            q.push(data);
        }
        if(x!=0)
        {
            data=q.front();
            q.pop();
        }
        cnt--;

        printf("%d ",data);
    }
    printf("\n");
    return 0;
}
