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

char *s="ALLIZZWELL";
char Grid[MAX][MAX];
int  row,column,visited[MAX][MAX];

int cell[MAX][MAX];


int check_dfs(int i, int j, int n)
{
	int x,z,a,b;

	if(n==9)
	{
		return 1;
	}
		

	
//	printf("%c in i=%d   j=%d\n",Grid[i][j],i,j);
	
		visited[i][j]=1;	
	
		for(a=-1;a<=1;a++)
		{
			for(b=-1;b<=1;b++)
			{
				 x=i+a;
				 z=j+b;
				if(x>=0&&x<row&&z>=0&&z<column&&visited[x][z]!=1)
				{
				
				if(Grid[x][z] == s[n+1]&& check_dfs(x,z,n+1))
					{
						return 1;
					}
			}
			}
		}
	
		

	visited[i][j]=0;
	return 0;
}

bool dfs(int a, int b, int n) {
    if(n == 9) return true;
    visited[a][b] = true;
    //cout << a << " " << b << " " << n << endl;

    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int aa = a+i;
            int bb = b+j;
            if(aa>=0 && bb>=0 && aa<row && bb<column && !visited[aa][bb]) {
                if(Grid[aa][bb] == s[n+1] && dfs(aa, bb, n+1)) return true; 
            }
        }
    }
    visited[a][b] = false;
    return false;
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
            	ret=0;
			   if(Grid[i][j]=='A')
                {
                	n=0;    
   					  ret=check_dfs(i,j,0);
						 if(ret)
  					  {
  						//ret=1;
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
    
memset(visited,0,sizeof(visited[0][0])*MAX*MAX);
//memset(cell,0,sizeof(cell[0][0])*MAX*MAX);
//printf("\n");
}

	return 0;
}
