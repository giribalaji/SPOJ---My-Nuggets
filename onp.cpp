#include<iostream>
#include<string>
#include<stack>
using namespace std;

string fun(string inp)
{
	string out;
	stack<char> st;
	int i;
	for(i=0;i<inp.length();i++)
	{
		if(inp[i]>='a'&&inp[i]<='z')
		{
		
			out=out+inp[i];
			//cout<<out<<endl;
}
	//	elseif(inp[i]=='(')
	//		st.push(inp[i]);
		else if(inp[i]==')')
			{
				while(!st.empty()&&st.top()!='(')
				{
					out+=st.top();
					//cout<<out<<endl;					
					st.pop();
					}			
					if(st.top()=='(')st.pop();
			}
		else
			st.push(inp[i]);
	
	}
	
	while(!st.empty())
	{
		out+=st.top();
		st.pop();
	}

	return out;
}


int main()
{
	string inp;
	string out;
	int n;
	cin>>n;
	while(n--)
	{
		cin >> inp;
		out=fun(inp);
		cout<<out<<endl;
	}
	
	
	return 0;
}
