#include<stdio.h>
#include<math.h>

int main()
{
	int i,j;
	
	while(1)
	{
	
	scanf("%d",&i);
	//printf("%f\n",log2(17));
    j=(int)log2(i);
    float f=log2(i);
    float g=(float)j;
    printf("%f   %d   %f\n",f,j,g);
    if (f==g)
    	printf("Yes\n");
    else
    	printf("No\n");
}
return 0;
}
