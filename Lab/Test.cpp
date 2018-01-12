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
FILE *fp=fopen("Job with test case.txt", "r");
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
ll i,j,k,l,m,n,qt=2,in;
void sjf()
{
    i=0;
    ll p,q;
    while(i<n)
    {
        fscanf(fp,"%lld%lld",&p,&q);
        a[i].st=p;
        a[i].bt=q;
        fbt[i+1]=a[i].bt;
        a[i].pid=i+1;
        fst[i+1]=a[i].st;
        i++;
    }
    vector<ll>ans;
    ll sum=0;
    ll tcp=0;
    ll gar=9999999999;
    bool ff=0;
    i=0;
    in=0;
    while(tcp<n)
    {
        ll txx=i;
        if(a[in].bt>0)
        {
            for(j=i;j<i+qt;j++)
            {
                if(a[in].bt==0)
                    break;
                a[in].bt--;
                ans.push_back(a[in].pid);
                if(a[in].bt==0)
                    tcp++;
            }
            i=ans.size();
        }

        if(txx==i)
        {
            ans.push_back(-9);
            i++;
        }
        in++;
        if(in==n)
            in=0;
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
    cout<<"\n\n\nGantt Chart :\n\n\n";
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
    cout<<"\n\n\nAverage waiting time : "<<(double)(sum)/(double)(n)<<" ms\n\n"<<endl;
    return;
}
int main()
{
    //FILE *fp=fopen("Preemptive with test case.txt", "r");
    while(1)
    {
        fscanf(fp,"%lld",&n);
        if(n==0)
            return 0;
        else
            sjf();
    }
}


