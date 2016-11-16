#include <stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<cstdio>
#include<stdlib.h>

using namespace std;

int main (int argc, char const *argv[])
{
    char name[10001];
    int t=1,i1,i,k,j;
	
	//string arr="giri balaji   poda";
	string arr="giri balaji    poda   panni";
	//scanf("%d",&t);
for(i1=0;i1<t;i1++)
{

	//scanf("%[^\n]s",name);
    //scanf("%s",name);
    //cin.ignore();
   //int j=0;
    //getline(cin,arr);
    //cin >> name1;
   // printf("%s\n", name1);
    //string st;
    //st=(string)name1;
    cout<<arr<<endl;
    i=0;
    while(arr[i])
		{
		    
			j=i;k=0;
			while(arr[j] && arr[j]!=32 )
			{
				j++,k++;
		
			}
		   string st1=arr.substr(i,k);
		    //printf("%s",st);
	        cout<<i<<"\t"<<j<<"\t"<<st1<<endl;
			while(arr[j]==' ')
			{
			
	        	j++;
	        }
	    i=j;
		
		}
}
    return 0;
}
