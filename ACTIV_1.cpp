#include<iostream>
#include <stack> 
#include <string>        // std::stack
#include<map>
#include<math.h>
//#include<multimap>
#include<stdio.h>
using namespace std;


int count(int h)
{
	int n=h;
	int cnt=0;
	while(n>0)
	{
		n=n/10;
		cnt++;
	}
return cnt;
}


int main()
{

	while(1)
	{
		multimap<int,char> mp;
	multimap<int,char>::iterator it;
	int t,cnt=0,i,num=0,n1=0,n2=0;
	char buf[9];
	int s,e,prev_f,prev_s;
		int max=0,ov=0;
		scanf("%d",&t);
		if(t==-1)
			break;
		for(i=0;i<t;i++)
		{
			scanf("%d %d",&s,&e);
			mp.insert(make_pair(s,'s'));
			mp.insert(make_pair(e,'e'));
			
		}
		
		for(it=mp.begin();it!=mp.end();++it)
		{
			//cout<<(*it).first<<":"<<(*it).second<<endl;
			if((*it).second=='s')
				++ov;
			else
			{
				if(ov>max)
					max=ov;
				--ov;
				if(prev_f==(*it).first&&prev_s!=(*it).second)
				{
					max--;
				}
			}
		  prev_f=(*it).first;
		  prev_s=(*it).second;
		}

    int no=t-ov;
	if(t==1)
    {
    	num=t;
    }
	 else if(max==1)
	 {
	 	num=t;
	 }
	else
	{
		n1=t-max;
		if(n1>1)
			n1=pow(2,n1);
		n2=pow(2,max);
		num=n1+n2;
	}
	// printf("Overlapes:n1 = %d,n2 = %d, ov = %d\n",n1,n2,max);
	//int num=123;
	int c=count(num);
	//printf("%d\n",c);
	sprintf(buf,"%s","00000000");
	int r=sprintf(buf+(8-c),"%d",num);
    printf("%s\n",buf);
    //puts(buf);
	
}
	
	return 0;
	
	
	}
