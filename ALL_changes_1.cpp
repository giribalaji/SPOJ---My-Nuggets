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
	int x,z;

	if(n==9)
	{
		return 1;
	}
		

	
//	printf("%c in i=%d   j=%d\n",Grid[i][j],i,j);
	
		Visitation[i][j]=1;	
	
		for(x=i-1;x<=i+1&&x<row;x++)
		{
			for(z=j-1;z<=j+1&&z<column;z++)
			{
				if(x>=0&&z>=0&&Visitation[x][z]!=1)
				{
				
				if((Grid[x][z]==Target[n+1])&& check_dfs(x,z,n+1))
					{
						return 1;
					}
			}
			}
		}
	
		

	Visitation[i][j]=0;
	return 0;
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
 				   ret=check_dfs(i,j,0);
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
