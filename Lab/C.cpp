#include<bits/stdc++.h>
using namespace std;

int cnt[10];

int main()
{
    string s;
    int len,i,j,x,y=0,sum=0,ttl_cnt;
    vector<int>val[10];

    cin>>s;
    len=s.length();

    for(i=0;i<len;i++)
    {
        x=s[i]-48;
        val[x].push_back(i);
        cnt[x]++;
        sum+=x;
    }
    if((sum%3)==0)
    {
        for(i=0;i<len-1;i++)
        {
            if(s[i]!='0')
            {
                cout<<s[i];
            }
        }
        cout<<s[i];
    }
    else if((sum%3)==2)
    {
        ttl_cnt=cnt[2]+cnt[4]+cnt[6]+cnt[8];
        if(ttl_cnt==0)
        {
            printf("-1");
        }
        else
        {
            if(cnt[2]!=0){x=val[2][0];s[x]='!';}
            else if(cnt[4]!=0){x=val[4][0];s[x]='!';}
            else if(cnt[6]!=0){x=val[6][0];s[x]='!';}
            else{x=val[8][0];s[x]='!';}
            x=0;
            for(i=0;i<len-1;i++)
            {
                if(s[i]!='0' && s[i]!='!')
                {
                    cout<<s[i];
                    x++;
                }
            }
            if(s[i]=='!')
            {
                if(x==0){printf("-1");}
            }
            else
            {
                cout<<s[i];
            }
        }
    }
    else
    {
        ttl_cnt=cnt[1]+cnt[3]+cnt[5]+cnt[7];
        if(ttl_cnt<2)
        {
            printf("-1");
        }
        else
        {
            if(cnt[1]!=0)
            {
                if(cnt[1]==1){x=val[1][0];s[x]='!';y++;}
                else if(y==0){x=val[1][0];s[x]='!';x=val[1][1];s[x]='!';y=2;}
            }
            if(cnt[3]!=0 && y<2)
            {
                if(cnt[3]==1){x=val[3][0];s[x]='!';y++;}
                else if(y==0){x=val[3][0];s[x]='!';x=val[3][1];s[x]='!';y=2;}
            }
            if(cnt[5]!=0 && y<2)
            {
                if(cnt[5]==1){x=val[5][0];s[x]='!';y++;}
                else if(y==0){x=val[5][0];s[x]='!';x=val[5][1];s[x]='!';y=2;}
            }
            if(cnt[7]!=0 && y<2)
            {
                if(cnt[7]==1){x=val[7][0];s[x]='!';y++;}
                else if(y==0){x=val[7][0];s[x]='!';x=val[7][1];s[x]='!';y=2;}
            }
            if(cnt[9]!=0 && y<2)
            {
                if(cnt[9]==1){x=val[9][0];s[x]='!';y++;}
                else if(y==0){x=val[9][0];s[x]='!';x=val[9][1];s[x]='!';y=2;}
            }
            x=0;
            for(i=0;i<len-1;i++)
            {
                if(s[i]!='0' && s[i]!='!')
                {
                    cout<<s[i];
                    x++;
                }
            }
            if(s[i]=='!')
            {
                if(x==0){printf("-1");}
            }
            else
            {
                cout<<s[i];
            }
        }

    }
    printf("\n");
    return main();
}
