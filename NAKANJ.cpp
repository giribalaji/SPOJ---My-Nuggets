#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector> 
#include<iterator>
#include<map>    
#include<list>   
#define MAX 106   
#include  <queue>
using namespace std;


char Grid[MAX][MAX];
int  row=9,column=9,Visitation[MAX][MAX];
int d1,d2;
int add[MAX][MAX];

queue <pair<int,int> >s;
bool Check(int, int ,char * );
static int retc;
static int chkc;

int check_bfs()
{
	int c=0;
	pair<int , int> tmp;
	int flag=0;
	int cnt=0,i,j;
	while(!s.empty() )
	{
	
		tmp=s.front();
		
		s.pop();
		
	
		i=tmp.first;
		j=tmp.second;
	cout<<i<<"\t"<<j<<endl;	
		
		
if(i == d1&&j==d2)
              {
             return add[i][j];
          }

			if(i-2>=1&&j-1>=1&&Visitation[i-2][j-1]!=1)
			{
				Visitation[i-2][j-1]=1;
				s.push(make_pair(i-2,j-1));
				add[i-2][j-1]=add[i][j]+1;
			}
		if(i-2>=1&&j+1<column&&Visitation[i-2][j+1]!=1)
			{
				Visitation[i-2][j+1]=1;
				s.push(make_pair(i-2,j+1));
				add[i-2][j+1]=add[i][j]+1;
			}
		if(i+2<row&&j-1>=1&&Visitation[i+2][j-1]!=1)
			{
				Visitation[i+2][j-1]=1;
				s.push(make_pair(i+2,j-1));
				add[i+2][j-1]=add[i][j]+1;
			}
		if(i+2<row&&j+1<column&&Visitation[i+2][j+1]!=1)
			{
				Visitation[i+2][j+1]=1;
				s.push(make_pair(i+2,j+1));
				add[i+2][j+1]=add[i][j]+1;
			}
	
			
			if(j-2>=1&&i-1>=1&&Visitation[i-1][j-2]!=1)
			{
				Visitation[i-1][j-2]=1;
				s.push(make_pair(i-1,j-2));
				add[i-1][j-2]=add[i][j]+1;
			}

			if(j-2>=1&&i+1<row&&Visitation[i+1][j-2]!=1)
			{
				Visitation[i+1][j-2]=1;
				s.push(make_pair(i+1,j-2));
				add[i+1][j-2]=add[i][j]+1;
			}
			if(j+2<column&&i-1>=1&&Visitation[i-1][j+2]!=1)
			{
				Visitation[i-1][j+2]=1;
				s.push(make_pair(i-1,j+2));
				add[i-1][j+2]=add[i][j]+1;
			}

			if(j+2<column&&i+1<row&&Visitation[i+1][j+2]!=1)
			{
				Visitation[i+1][j+2]=1;
				s.push(make_pair(i+1,j+2));
				add[i+1][j+2]=add[i][j]+1;
			}


	
		
	}
	return 0;
}


int main()
{
	char arr[20];
	char *p=arr;
	char tmp[20];
	char *t=tmp;
    int m,n,te;
    scanf("%d",&te);
	while(te--)
	{
		 scanf("%s %s",p,t);
   //  printf("%s %s\n",p,t);
     m=p[0]-'a'+1;n=p[1]-'0';
     d1=t[0]-'a'+1;d2=t[1]-'0';
 //	cout<<m<<"\t"<<n<<endl;
 //	cout<<d1<<"\t"<<d2<<endl;
     Visitation[m][n]=1;
	 s.push(make_pair(m,n));
    retc=check_bfs();

        	printf("%d\n",retc);


   while(!s.empty()) 
	{
	s.pop();
}


retc=0;
memset(Visitation,0,sizeof(Visitation[0][0])*MAX*MAX);
memset(add,0,sizeof(add[0][0])*MAX*MAX);

}
  return 0;   
 }
