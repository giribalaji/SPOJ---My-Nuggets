#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector> 
#include<iterator>
#include<map>    
#include<list>   
#define MAX 1006   
#include  <queue>
using namespace std;


char Grid[MAX][MAX];
int  row,column,DP[MAX][MAX];

//int cell[MAX][MAX];

 int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
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
        //    scanf("%*c");           
                       
        }

for(i=1;i<=row;i++){
            for(j=1;j<=column;j++){
				
				if(Grid[i-1][j-1] == 'F')
				{
					DP[i][j]=min(DP[i][j-1],DP[i-1][j],DP[i-1][j-1])+1;
				}
				else
				{
					DP[i][j]=0;
				}
}
}

int max=0;		
	for(i=1;i<=row;i++){
            for(j=1;j<=column;j++){
         	if(DP[i][j]>max)  
         	{
         		max=DP[i][j];
         	}
            	
            }
        }
    
 printf("%d\n",max*3);

memset(DP,0,sizeof(DP[0][0])*MAX*MAX);

}
	return 0;
}
