#include<stdio.h>
#include<iostream>
#include<stack>
#include <string>
#include <queue>  
using namespace std;
stack<int>s;



int main(void){
   
    int TestCases,i,j,n,k,c=0;
    queue <pair<int,int> >s;
   	priority_queue<int> pq;
   
    scanf("%d",&TestCases);
    while(TestCases--){
       c=0;
        scanf("%d %d",&n,&k);

        for(i=0;i<n;i++){
            
              scanf("%d",&j);
                              
                
                	s.push(make_pair(i,j));
                	pq.push(j);
                
            }
              
while(!s.empty())
{
	pair<int,int> tmp;
	tmp=s.front();
	
	if(tmp.second==pq.top())
	{
	s.pop();
	pq.pop();
	c++;	
		if(tmp.first==k)
		{
			break;
		}
	}
	else
	{
	s.pop();
	s.push(tmp);
	}
}

printf("%d\n",c);

   while(!s.empty()) 
	{
	s.pop();
}
 while(!pq.empty()) 
	{
	s.pop();
}

}
	return 0;
}

