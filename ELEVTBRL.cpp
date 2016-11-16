#include<stdio.h>
#include<queue>
using namespace std;
int dis[1000002];
int vis[1000002]={0};
queue <int> q;
int main()
{
//	while(1)
//	{
	
	int f,s,g,u,d,s1,g1,c,flag,count=0,cur;
	
	scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
	
	dis[g]=-1;
	
	vis[s]=1;
	q.push(s);
	
	while(!q.empty())
	{
	s1=q.front();
	q.pop();
/*	if( ((s1+u)<=f) && vis[s1+u]!=1)
	{
		vis[s1+u]=1;
		dis[s1+u]=dis[s1]+1;
		q.push(s1+u);
	}
	
	else if( ((s1-d)>=1) && vis[s1-d]!=1)
	{
		vis[s1-d]=1;
		dis[s1-d]=dis[s1]+1;
		q.push(s1-d);
	}*/

        int nextUp = s1 + u;
        int nextDown = s1 - d;
        cur=s1;
		if(nextUp<=f && !vis[nextUp])
        {
            vis[nextUp] = 1;
            dis[nextUp] = dis[cur]  + 1;
            q.push(nextUp);
        }
        if(nextDown>=1 && !vis[nextDown])
        {
            vis[nextDown] = 1;
            dis[nextDown] = dis[cur]  + 1;
            q.push(nextDown);
        }	


}
	if(dis[g]!=1)
	{
		printf("%d\n",dis[g]);
	
	}
		
	else
		{
			printf("use the stairs\n");
		
		}
	
//}
return 0;	
}
