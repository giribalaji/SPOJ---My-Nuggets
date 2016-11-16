#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector> 
#include<iterator>
#include<map>    
#include<list>   
#define MAX 102   
#include  <queue>
using namespace std;


char Grid[MAX][MAX];
int  row,column,Visitation[MAX][MAX],	count[MAX][MAX];

int cell[MAX][MAX];

queue <pair<int,int> >s;
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
	cout<<i<<j<<endl;	
		
		
if((i==0||i==row-1||j==0||j==column-1)&&Grid[i][j] == '.')
              {
             retc++;
             chkc++;
          }

			if(i-1>=0&&Grid[i-1][j] != '*'&&Visitation[i-1][j]!=1)
			{
				Visitation[i-1][j]=1;
				s.push(make_pair(i-1,j));
			}
			if(i+1<row&&Grid[i+1][j] != '*'&&Visitation[i+1][j]!=1)
			{
				Visitation[i+1][j]=1;
				s.push(make_pair(i+1,j));
			}
			
			if(j-1>=0&&Grid[i][j-1] != '*'&&Visitation[i][j-1]!=1)
			{
				Visitation[i][j-1]=1;
				s.push(make_pair(i,j-1));
			}
			if(j+1<column&&Grid[i][j+1] != '*'&&Visitation[i][j+1]!=1)
			{
				Visitation[i][j+1]=1;
				s.push(make_pair(i,j+1));
			}
	
		
	}
	
}

int main(void){
   
    int TestCases,i,j;
    int c1=0;
   
    scanf("%d",&TestCases);
    while(TestCases--){
       
        scanf("%d %d",&row,&column);
       scanf("%*c");
       
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
               
              scanf("%c",&Grid[i][j]);

            }
            scanf("%*c");           
                       
        }

		
		for(i=0;i<row;i++){
            for(j=0;j<column;j++){
              if(Grid[i][j] == 'C'&&Visitation[i][j]==0)
              {
              Visitation[i][j]=1;
			  s.push(make_pair(i,j));
                  retc=check_bfs();
    		 printf("retc = %d\n",retc);
    		 break;

          }
            }
            }
    
 
 


   while(!s.empty()) 
	{
	s.pop();
}

retc=0;
chkc=0;
c1=0;
memset(Visitation,0,sizeof(Visitation[0][0])*MAX*MAX);

}
	return 0;
}
