#include <iostream>       // std::cout
#include <stack> 
#include <string>        // std::stack

int main ()
{
  std::stack<char> mystack;

  for (int i=0; i<5; ++i) mystack.push('a'+i);
   std::string inp;
  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     inp += mystack.top();
    // std::cout << ' ' << i;
     mystack.pop();
  }
  std::cout <<inp<<'\n';

  return 0;
}

