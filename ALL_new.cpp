#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector> 
#include<iterator>
#include<map>    
#include<list>   
#define MAX 105
#include  <stack>
using namespace std;

char *Target="ALLIZZWELL";
char Grid[MAX][MAX];
int  row,column,Visitation[MAX][MAX];

int cell[MAX][MAX];

stack <pair<int,int> >s;
bool Check(int, int ,char * );

int check_dfs(int i, int j, int n)
{


	if(n==10)
	{
		return 1;
	}
		
		if(i<0||i>=row||j<0||j>=column)	 
	{
//	memset(v,0,sizeof(v[0][0])*6*6);
		//printf("%d %d\n",i,j);
		return 0;
	}
	
//	printf("%c in i=%d   j=%d\n",Grid[i][j],i,j);
		
		if(Visitation[i][j]!=1 && Grid[i][j]==Target[n])	
		{
		
			Visitation[i][j]=1;
			n++;
		
		if(check_dfs(i-1,j,n)||check_dfs(i-1,j+1,n)||check_dfs(i-1,j-1,n)||check_dfs(i,j-1,n)||check_dfs(i,j+1,n)||check_dfs(i+1,j,n)||check_dfs(i+1,j+1,n)||check_dfs(i+1,j-1,n))
		{
			return 1;
		}
	
		else
		{
			Visitation[i][j]=0;
			return 0;
		}
		}
		else
		{
		
		Visitation[i][j]=0;
	return 0;

}
}

int main(void){
   
    int TestCases,i,j,StartX,StartY,flag;
    
   
    scanf("%d",&TestCases);
    while(TestCases--){
       
    	int n=0,ret;
	    scanf("%d %d",&row,&column);
        flag=0;
/*       scanf("%*c");
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
               
              scanf("%c",&Grid[i][j]);
                             
               
            }
              
            scanf("%*c");           
                       
        }*/
        
        
         for(i=0;i<row;i++){
		scanf("%s", Grid[i]);
	}
        
     for(i=0;i<row;i++){
            for(j=0;j<column;j++){
               
            //  printf("%c\n",Grid[i][j]);
               if(Grid[i][j]=='A')
                {
                	n=0;    
 				   ret=check_dfs(i,j,n);
  					  if(ret)
  					  {
  						break;
           			 }
				}
                              
            }
           
		   if(ret)
  					  {
  						break;
           			 }
		    }
    
    	  if(ret)
	    	printf("YES\n");
		else
		 printf("NO\n");
    
memset(Visitation,0,sizeof(Visitation[0][0])*MAX*MAX);
//memset(cell,0,sizeof(cell[0][0])*MAX*MAX);
//printf("\n");
}

	return 0;
}
