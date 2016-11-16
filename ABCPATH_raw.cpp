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
     
    char *Target="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char Grid[MAX][MAX];
    int  row,column,Visitation[MAX][MAX],cl,pl;
     
    int cell[MAX][MAX];
     
    stack <pair<int,int> >s;
    bool Check(int, int ,char * );
     
    int check_dfs(int i, int j, int n)
    {
    	int x,z,max_dep=0,dep;
    	if(n==26)
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
    				
    				if(Grid[x][z]==Target[n+1])
    					{
    						dep=1+check_dfs(x,z,n+1);
    						if(max_dep<dep)
    							max_dep=dep;
    						//return 1;
    					}
    			}
    			}
    		}
    	
    		
     
    	Visitation[i][j]=0;
    	return max_dep;
    }
     
    int main(void){
       
        int TestCases=0,i,j,StartX,StartY,flag;
        
       
        scanf("%d %d",&row,&column);
        
        while(row&&column){
           TestCases++;
        	int n=0,ret;
    	    
            flag=0;
            
            
             for(i=0;i<row;i++){
    		scanf("%s", Grid[i]);
    	}
            
        cl=0;
    	 for(i=0;i<row;i++){
                for(j=0;j<column;j++){
                 	  
                //  printf("%c\n",Grid[i][j]);
                   if(Grid[i][j]=='A')
                    {
                    	   
     				   pl=1+check_dfs(i,j,0);
      					  if(cl<pl)
      					  {
      						cl=pl;
               			 }
    				}
                                  
                }
            }
     
      printf("case %d: %d\n",TestCases,cl);  
    memset(Visitation,0,sizeof(Visitation[0][0])*MAX*MAX);
    scanf("%d %d",&row,&column);
    //memset(cell,0,sizeof(cell[0][0])*MAX*MAX);
    //printf("\n");
    }
     
    	return 0;
    } 


