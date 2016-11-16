#include <utility>      // std::pair
#include <iostream>  
#include  <stack> // std::cout
using namespace std;

stack <pair<int, int > > s;
int main () {
  std::pair <int,int> foo;
  std::pair <int,int> bar;
pair<int, int> t;
  foo = std::make_pair (10,20);
  bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>
s.push(make_pair(30,40));

t=s.top();

int i=t.first;
int j=t.second;
  std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
	std::cout << "t: " << t.first << ", " << t.second << '\n';  
	std::cout << "t: " << i << ", " << j << '\n';

  return 0;
}
