/*
Nathan Taylor
Nuclear Decay Calculator - using Taylor Polynomials
N(t) = Ne^(-.693t/h)
N(t) is the function of amount of an element remaining after t time
h is the half life of the element and N is the intial amount
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

void printCommands();

int main()
{
  
  return 0;
}



void printCommands()
{
  cout << "'add' - Add a node to the tree" << endl;
  cout << "'delete' - Remove a node from the tree" << endl;
  cout << "'print' - Print out the tree structure" << endl;
  cout << "'help' - Print out the list of commands" << endl;
  cout << "'quit' - Exit the program" << endl;
}
