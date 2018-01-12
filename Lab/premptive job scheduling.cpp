#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("new.txt","r",stdin);
    int i,j,m=1,t,n,ms,mt,s1;
    float sum,sum1,sum2,avg,num=0,a[20][20],s[100][100],r[10],sub;
s[0][0]=0;
s[0][1]=0;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<3;j++)
        cin>>a[i][j];
    for(i=0;i<n;i++)
    {
        for(t=i;t>=1;t--)
        {
            if(a[t][2]<a[t-1][2])
            {
                float temp=a[t-1][2];
                a[t-1][2]=a[t][2];
                a[t][2]=temp;
                float temp1=a[t-1][0];
                a[t-1][0]=a[t][0];
                a[t][0]=temp1;
                float temp2=a[t-1][1];
                a[t-1][1]=a[t][1];
                a[t][1]=temp2;
            }
        }

        num++;
        a[0][2]-=1;
        s[m][0]=a[0][0];
        s[m][1]=num;
        m++;

    }
    int u=m;
    for(i=1;i<u-1;i++)
    {
        if(s[u][0]==s[u+1][0])
        {
            s[u][1]+=1;
            m--;
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i][2]>0)

            s[m][0]=a[i][0];
            num+=a[i][2];
            s[m][1]=num;
            m++;

    }
    for(i=1;i<m;i++)
        cout<<"p"<<s[i][0]<<"   ";
    cout<<endl;
    for(i=0;i<m;i++){
        cout<<s[i][1]<<"   ";

        }
        cout<<endl;
        for(i=1;i<=n;i++)
        {
            sum1=0;
            ms=0;
            for(j=m-1;j>0;j--)
            {
                if(s[j][0]==i)
                {
                    if(ms==0){
                    sum1=s[j-1][1];
                    ms++;

                }
                else
                {
                    sub=s[j][1]-s[j-1][1];
                    sum1-=sub;

                }}
            }
            for(s1=0;s1<n;s1++)
            {
                if(a[s1][0]==i)
                    sum1-=a[s1][1];
            }
            r[i-1]=sum1;
            cout<<"waiting time of p"<<i<<" ="<<sum1<<endl;
        }
        for(i=0;i<n;i++)
            sum2+=r[i];
        avg=sum2/n;
        cout<<"average waiting time="<<avg<<endl;

}
