#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int (*compfn)(const void*, const void*);
struct s
{
    ll pid,st,bt;
} a[1000];
ll fbt[1000];
ll fst[1000];
int compare(struct s *elem1, struct s *elem2)
{
    if ( elem1->bt < elem2->bt)
        return -1;

    else if (elem1->bt > elem2->bt)
        return 1;
    else
    {
        if ( elem1->st < elem2->st)
            return -1;

        else if (elem1->st > elem2->st)
            return 1;
    }
}
ll i,j,k,l,m,n;
int main()
{
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i].st>>a[i].bt;
        fbt[i+1]=a[i].bt;
        a[i].pid=i+1;
        fst[i+1]=a[i].st;
    }
    vector<ll>ans;
    ll sum=0;
    ll jct=0;
    ll gar=9999999999;
    bool ff=0;
    i=0;
    while(jct<n)
    {
        qsort(a,n,sizeof(struct s),(compfn)compare );
        for(j=0; j<n; j++)
        {
            if(a[j].st<=i)
            {
                ff=1;
                ans.push_back(a[j].pid);
                a[j].bt--;
                if(a[j].bt==0)
                {
                    jct++;
                    a[j].bt=gar;
                }
                break;
            }
        }
        if(!ff)
        {
            ans.push_back(-999);
        }
        i++;
    }
    ll avwt[100];
    for(i=1; i<=n; i++)
    {
        ll b=-1,e=-1;
        bool flag=0;
        for(j=ans.size()-1; j>=0; j--)
        {
            if(flag==1&&ans[j]!=i)
                break;
            if(ans[j]==i&&e==-1)
            {
                e=j+1;
            }
            if(ans[j]==i&&e!=-1)
            {
                flag=1;
                b=j;
            }
        }
        ll x=b-(fbt[i]-(e-b))-fst[i];
        cout<<"Waiting time for "<<i<<"    : "<<x<<" ms"<<endl;
        cout<<"Turnaround time for "<<i<<" : "<<e-fst[i]<<" ms"<<endl;
        sum+=x;
    }
    ans.push_back(gar);
    for(i=0; i<ans.size(); i++)
    {
        //cout<<"i:"<<i<<endl;
        if(ans[i]==gar)
            break;
        cout<<i;
        cout<<"<--"<<ans[i]<<"-->";
        for(j=i+1;; j++)
        {
            if(ans[j]!=ans[i])
            {
                cout<<j<<" ";
                //cout<<111111111<<endl;
                i=j-1;
                break;
            }
            else
            {
                continue;
            }
        }
    }
    cout<<"\nAverage waiting time : "<<(double)(sum)/(double)(n)<<" ms"<<endl;
    return 0;
}
