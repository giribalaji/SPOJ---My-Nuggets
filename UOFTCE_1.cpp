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
int  row,column,Visitation[MAX][MAX];

int add[MAX][MAX];

queue <pair<int,int> >s;
priority_queue<int>pq;
bool Check(int, int ,char * );
static int retc;
static int chkc;

void check_bfs()
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
	//cout<<i<<j<<endl;	
	//	cout<<"Add value "<<add[i][j]<<endl;
		
if(Grid[i][j] == 'S')
              {
             pq.push(add[i][j]);
        //     cout<<pq.top()<<endl;
           //  return;
          }

			if(i-1>=0&&Grid[i-1][j] != '#'&&Visitation[i-1][j]!=1)
			{
				Visitation[i-1][j]=1;
				s.push(make_pair(i-1,j));
				
				add[i-1][j]=add[i][j]+1;
			}
			if(i+1<row&&Grid[i+1][j] != '#'&&Visitation[i+1][j]!=1)
			{
				Visitation[i+1][j]=1;
				s.push(make_pair(i+1,j));
				add[i+1][j]=add[i][j]+1;
			}
			
			if(j-1>=0&&Grid[i][j-1] != '#'&&Visitation[i][j-1]!=1)
			{
				Visitation[i][j-1]=1;
				s.push(make_pair(i,j-1));
				add[i][j-1]=add[i][j]+1;
			}
			if(j+1<column&&Grid[i][j+1] != '#'&&Visitation[i][j+1]!=1)
			{
				Visitation[i][j+1]=1;
				s.push(make_pair(i,j+1));
				add[i][j+1]=add[i][j]+1;
			}
	
		
	}
//	return 0;
}

int main(void){
   
    int TestCases,i,j;
    int c1=0;
   
    scanf("%d",&TestCases);
    while(TestCases--){
       
       int m=-1,n=-1;
        scanf("%d %d",&row,&column);
       scanf("%*c");
       
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
               
              scanf("%c",&Grid[i][j]);

			if(Grid[i][j]=='C')
			{
				m=i,n=j;
			}
            }
            scanf("%*c");           
                       
        }

if(m!=-1)
              {
              Visitation[m][n]=1;
			  s.push(make_pair(m,n));
                  check_bfs();
    		 //printf("retc = %d\n",retc);
	
          }
		
        


int sum=pq.top()+60;
pq.pop();

  while(!pq.empty()) 
	{
	sum+=(pq.top()*2)+60;
pq.pop();
	
}
printf("%d\n",sum);


   while(!s.empty()) 
	{
	s.pop();
}


sum=0;
memset(Visitation,0,sizeof(Visitation[0][0])*MAX*MAX);
memset(add,0,sizeof(add[0][0])*MAX*MAX);
}
	return 0;
}
