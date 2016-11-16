#include<iostream>
#include<map>
using namespace std;
int main(){
map<string,char> namemap;
namemap["yogi"]='c';
namemap.insert(pair<string,char>("yogendra",'a'));
namemap.insert(pair<string,char>("yogendra",'b'));
cout<<namemap["yogendra"]<<endl;
return 0;
}
