#include<bits/stdc++.h>
using namespace std;
#define S(x) scanf("%d",&x)
#define P(x) printf("%d",x)
#define fl(i , a, b) for(i = a; i<b; i++)
#define MOD 1000000007
#define MAX 1000000010
#define ll long long
#define mp make_pair
#define pb push_back
typedef pair<int,int> pp;
ll a[1234567];
int n ; 
ll m[1000002][12];
void fun()
{
    for(int i =1;i<=n;i++) m[i][0] = i ; 
    for(int j = 1; (1<<j)<=n;j++)
    {
        for(int i = 1; i+(1<<j)-1<=n;i++)   
        {
            if(a[m[i][j-1]] < a[m[i+(1<<(j-1))][j-1]])
                m[i][j] = m[i][j-1];
            else
               m[i][j] = m[i+(1<<(j-1))][j-1];  
        }
    }
}
int main()
{
    //std::ios_base::sync_with_stdio(false);
    cin>>n;
    int i ,l,r , pos; 
    fl(i ,1, n+1)
        cin>>a[i];  
    fun();
    int q;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        int k = log2(r-l+1);
        pos = a[m[l][k]] < a[m[r-(1<<k)+1][k]] ? m[l][k] : m[r-(1<<k)+1][k] ; 
        // cout<<pos<<" "<<a[pos]<<endl;
    }
    return 0;
}
