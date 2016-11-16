//#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
	int n,i,j,k;
	char arr[40001] ; string st;
//	map<string, int>table;
	//scanf("%d",&n);
	cin>>n;
	//cout<<"hi"<<endl;
	while (n--)
	{
		//cout << n<<endl;
		//scanf("%[^\n]s",arr);
		getline(cin, arr);
		
	    //gets(arr);
		//cin>>arr;
		st=(string)arr;
		i=0;
		cout<<arr<<endl;
	   // printf(" here %s\n",arr);
		while(arr[i])
		{
		    
			j=i;
			while(arr[j]!=' '&& arr[j])
			{
				j++;
		
			}
		   string st1=st.substr(i,j);
		    //printf("%s",st);
	        cout<<st1<<endl;
			while(arr[j]==' ')
			{
			
	        	j++;
	        }
	    i=j;
		
		}
		
	}
	return 0;
}
