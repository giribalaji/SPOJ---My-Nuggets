	#include<stdio.h>
	#include<iostream>
	#include<stack>
	#include <string>
	#include <queue> 
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h> 
	using namespace std;

	int element[1000000];
//	int team[1005];
	
	
	int main(void){
	   
	    int TestCases,i,j,n,k,e,z,c,r=0;
	    char s[10];
	    char *p=s;
	    
		scanf("%d",&n);
		while(n!=0)
		{
		r++;
		c=1;
	    queue <int> s[n+1];
	    queue <int>mq;
	   
	
	        for(i=1;i<=n;i++){
	            
	              scanf("%d",&k);
	        	for(j=0;j<k;j++)
	        	{
	        		scanf("%d",&e);
	        		element[e]=i;
	        		
	        	}
	                
	            }
	   printf("Scenario #%d\n",r);
	   while(1)
	   { 
	    scanf("%s",p);
	    if(strcmp(p,"ENQUEUE")==0)
	    {
	    	scanf("%d",&z);
	    	if(s[element[z]].empty())
	    	{
	    		int b=element[z];
	    		mq.push(b);
				//mq.push(element[z]);
	    	}
	    	s[element[z]].push(z);
	    }
		else if(strcmp(p,"DEQUEUE")==0)
		{
			c=mq.front();
			printf("%d\n",s[c].front());
			s[c].pop();
			if(s[c].empty())
			{
				mq.pop();
			}
		}
		else
		{
			printf("\n");
			break;
			
		}
}

memset(element,0,sizeof(element));

scanf("%d",&n);	
}
		return 0;
	}

