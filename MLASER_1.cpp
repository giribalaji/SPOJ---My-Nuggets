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

typedef pair <int, pair<int,int> > pt;

char Grid[MAX][MAX];
int  row,column,Visitation[6][MAX][MAX];

int add[6][MAX][MAX];

queue <pt >s;

static int retc;
static int chkc;

int check_bfs(int m,int n)
{
	int c=0;
	pt tmp;
	int flag=0;
	int cnt=0,i,j,k,rv,cv;
	while(!s.empty() )
	{
	
		tmp=s.front();
		
		s.pop();
		
	
		k=tmp.first;
		i=tmp.second.first;
		j=tmp.second.second;
	cout<<i<<j<<endl;	
		
		
if(Grid[i][j] == 'C'&&i!=m&&j!=n)
              {
            int z;
			 for(z=0;z<5;z++)
			 	cout<<add[z][i][j]<<endl;
			 return add[k][i][j];
          }

		if(k==0)
		{
			rv=0,cv=0;
		}
		else if(k==1||k==2)
		{
			rv=0,cv=1;
		}
		else if(k==3||k==4)
		{
			rv=1,cv=0;
		}
			if(i-1>=0&&Grid[i-1][j] != '*'&&Visitation[k][i-1][j]!=1)
			{
				Visitation[k][i-1][j]=1;
				s.push(make_pair(1,make_pair(i-1,j)));
				add[k][i-1][j]=add[k][i][j]+rv;
			}
			if(i+1<row&&Grid[i+1][j] != '*'&&Visitation[k][i+1][j]!=1)
			{
				Visitation[k][i+1][j]=1;
				s.push(make_pair(2,make_pair(i+1,j)));
				add[k][i+1][j]=add[k][i][j]+rv;
			}
			
			if(j-1>=0&&Grid[i][j-1] != '*'&&Visitation[k][i][j-1]!=1)
			{
				Visitation[k][i][j-1]=1;
				s.push(make_pair(3,make_pair(i,j-1)));
				add[k][i][j-1]=add[k][i][j]+cv;
			}
			if(j+1<column&&Grid[i][j+1] != '*'&&Visitation[k][i][j+1]!=1)
			{
				Visitation[k][i][j+1]=1;
				s.push(make_pair(4,make_pair(i,j+1)));
				add[k][i][j+1]=add[k][i][j]+cv;
			}
	
		
	}
	return 0;
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

		
	        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
               
              printf("%c \t",Grid[i][j]);
                              
            }
            }
	
              if(m!=-1)
              {
              Visitation[1][m][n]=1;
              Visitation[2][m][n]=1;
              Visitation[3][m][n]=1;
              Visitation[4][m][n]=1;
			  s.push(make_pair(0,make_pair(m,n)));
                  retc=check_bfs(m,n);
    		 printf("retc = %d\n",retc);
	
          }
        


   while(!s.empty()) 
	{
	s.pop();
}


retc=0;
memset(Visitation,0,sizeof(Visitation[0][0][0])*6*MAX*MAX);
memset(add,0,sizeof(add[0][0][0])*6*MAX*MAX);
}
	return 0;
}
