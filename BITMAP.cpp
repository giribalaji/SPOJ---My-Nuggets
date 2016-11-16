#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector> 
#include<iterator>
#include<map>    
#include<list>   
#define MAX 192   
#include  <queue>
using namespace std;


char Grid[MAX][MAX];
int  row,column,Visitation[MAX][MAX];

int add[MAX][MAX];

queue <pair<int,int> >s;
bool Check(int, int ,char * );
static int retc;
static int chkc;

void check_bfs()
{
	int dist;
	pair<int , int> tmp;
	int cnt=0,i,j;
	while(!s.empty() )
	{
	
		tmp=s.front();
		
		s.pop();
		
	
		i=tmp.first;
		j=tmp.second;
	//cout<<i<<j<<add[i][j]<<endl;	
		dist=add[i][j]+1;
		


			if(i-1>=0&&Visitation[i-1][j]!=1&&dist<add[i-1][j])
			{
				Visitation[i-1][j]=1;
				s.push(make_pair(i-1,j));
				add[i-1][j]=dist;
			}
			if(i+1<row&&Visitation[i+1][j]!=1&&dist<add[i+1][j])
			{
				Visitation[i+1][j]=1;
				s.push(make_pair(i+1,j));
				add[i+1][j]=dist;
			}
			
			if(j-1>=0&&Visitation[i][j-1]!=1&&dist<add[i][j-1])
			{
				Visitation[i][j-1]=1;
				s.push(make_pair(i,j-1));
				add[i][j-1]=dist;
			}
			if(j+1<column&&Visitation[i][j+1]!=1&&dist<add[i][j+1])
			{
				Visitation[i][j+1]=1;
				s.push(make_pair(i,j+1));
				add[i][j+1]=dist;
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
   memset(add,9999,sizeof(add[0][0])*MAX*MAX);    
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
               
              scanf("%c",&Grid[i][j]);

            }
            scanf("%*c");           
                       
        }

		
		for(i=0;i<row;i++){
            for(j=0;j<column;j++){
              if(Grid[i][j] == '1')
              {
              Visitation[i][j]=1;
			  s.push(make_pair(i,j));
			  add[i][j]=0;
                  check_bfs();
memset(Visitation,0,sizeof(Visitation[0][0])*MAX*MAX);
          }
            }
            }
    
    		for(i=0;i<row;i++){
            for(j=0;j<column;j++){
            	cout<<add[i][j]<<" ";
            }
        	cout<<endl;
		}
        
 


   while(!s.empty()) 
	{
	s.pop();
}




}
	return 0;
}
