#include<stdio.h>
int main()
{
int t;
int count;
	scanf("%d",&t);
    while(t--)
    {
	char p[10005];
	count=0;
	scanf("%s",p);
	//printf("%s",p);
    char *s , *e;
    s=p;
    e=p+(strlen(p)-1);
    printf("%c -- %c\n",*s,*e);
    while(s<e)
    {
    	if (*s > *e)
    	{
    		while (*s > *e)

    		{
    		--*s;
    		//printf(" %c %c %d ",*s,*e,count);
    		count++;
    		}
    	}
    	else if (*s < *e)
    	{
    		while (*s < *e)

    		    		{
    		    		--*e;
    		    		//printf(" %c-%c-%d ",*s,*e,count);
    		    	    count++;
    		    		}
    	}
    	s++,e--;
    }

    printf("%d\n",count);
}
    return 0;
}
