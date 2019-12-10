#include <iostream>
#include <queue>
#include <stack>
using namespace std;
long  n,m;
static long sum=0;
long s[10005][10005]={0};//有联系
long s1[10005];// 判断是否有点与它相通
long s2[10005];//判断它是否被用过
long s3[10005];//每个的最小联通度
void dfs(int start)
{
    stack<int>ss;
    ss.push(start);
    s2[start]=1;
    long v=ss.top();//记录你的头
    long t=s3[ss.top()];//
    int flag=0;
    int count=0;
    while(!ss.empty())
    {
        flag=0;
        for(int i=1;i<=n;i++)
        {
            if( s[v][i]==s3[v] && s2[i]!=1 && s[v][i]<=t)
            {
                count++;
                ss.push(i);
                s2[i]=1;
                sum+=s[v][i];
                //                cout<<sum<<" "<<i<<endl;
                flag=1;
                //                t=s3[ss.top()];
                v=ss.top();
                break;
            }
        }
        if(flag==0)
        {
            ss.pop();
            if(ss.empty())
            {
                break;
            }
            v=ss.top();
            //            t=s3[ss.top()];
        }
        
    }
    if(count==0)
    {
        flag=0;
        for(int i=1;i<=n;i++)
        {
            if( s[start][i]!=0 && s[start][i]<=s3[start] && s2[i]==1)
            {
                sum+=s3[start];
                flag=1;
                break;
            }
            
        }
        
        if(flag==0)
        {
            cout<<"-1"<<endl;
        }
        
        
        
        
        //        sum+=s3[start];
        //        cout<<sum<<" "<<start<<endl;
        
    }
    
    
}
int main()
{
    cin>>n>>m;
    long qi,si,len;
    for(long i=0;i<m;i++)
    {
        
        cin>>qi>>si>>len;
        s[qi][si]=len;
        s[si][qi]=len;
        
        //
        s1[qi]++;
        if(s1[qi]==1)
        {
            s3[qi]=len;
            
        }
        else
        {
            if(len<=s3[qi])
            {
                s3[qi]=len;
            }
            
        }
        
        //
        s1[si]++;
        if(s1[si]==1)
        {
            s3[si]=len;
        }
        else
        {
            if(len<=s3[si])
            {
                s3[si]=len;
            }
        }
    }
    //    cout<<sum<<" "<<"1"<<endl;
    //
    for(long i=1;i<=n;i++)
    {
        if(s1[i]<n-1)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        if(s2[i]==1)
        {
            continue;
        }
        else
        {
            dfs(i);
        }
    }
    
    
    
    
    
    
    
    
    
    cout<<sum<<endl;
    
    return 0;
}
