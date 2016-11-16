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

using namespace std;

char *Target="ALLIZZWELL";
char Grid[MAX][MAX];
int  row,column,Visitation[MAX][MAX];

stack <pair<int,int> s;
bool Check(int, int ,char * );

int check_dfs()
{
	int c=0;
	pair<int , int> tmp;
	int flag=0;
	int cnt=0,i,j;
	while(!s.empty())
	{
		tmp=s.top();
		
		s.pop();
		
		if(c==10)
		{
			flag=1;
			break;
		}
		
		i=tmp.first;
		j=tmp.second];
		
		if(i<0||i>=row||j<0||j>=column)	 
	{
//	memset(v,0,sizeof(v[0][0])*6*6);
		continue;
	}
		
		if(Grid[tmp.first][tmp.second]==Target[c])
		{
			c++;
			Visitation[tmp.first][tmp.second]=1;
		}
		
		s.push(i-1,j);
		s.push(i-1,j+1);
		s.push(i-1,j-1);
		s.push(i,j-1);
		s.push(i,j+1);
		s.push(i+1,j);
		s.push(i+1,j+1);
		s.push(i+1,j-1);
		
		//Reseting Visiting array
		
		if(!(Grid[i-1][j]==Target[c]||Grid[i-1][j+1]==Target[c]||Grid[i-1][j-1]==Target[c]||Grid[i][j-1]==Target[c]||Grid[i][j+1]==Target[c]||Grid[i+1][j]==Target[c]||Grid[i+1][j-1]==Target[c]||Grid[i+1][j+1]==Target[c]))
		{
			
			memset(Visitation,0,sizeof(Visitation[0][0])*row*column);
			c=0;
		}
	}
	return flag;
}

int main(void){
   
    int TestCases,i,j,StartX,StartY,flag;
    
   
    scanf("%d",&TestCases);
    while(TestCases--){
       
        scanf("%d%d",&row,&column);
        flag=0;
      //  scanf("%*c");
       
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
               
              scanf("%c",&Grid[i][j]);
                              
                
            }
               
            //scanf("%*c");           
                       
        }
        
        
    }
    
    s.push(make_pair(0,0));
    
    check_dfs();
	return 0;
}
