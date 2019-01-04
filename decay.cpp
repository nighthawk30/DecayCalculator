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
#include <iomanip>

using namespace std;

void printCommands();
void centerMaclaurin(int iterations, double time, double half, double initial);
void derivativeMaclaurin(int iterations, double time, double half, double initial);
void integralMaclaurin(int iterations, double time, double half, double initial);
double factorial(double number);

int main()
{
  char* input = new char[80];
  bool end = false;
  cout << "This program will use Taylor Polynomials to calculate the amount of an element that remains after it experiences nuclear decay" << endl;
  printCommands();
  cout << setprecision(43) << endl;
  while (!end)
    {
      double initial;
      cout << "Initial Quantity: ";
      cin.getline(input, 80);
      initial = (double)(atof(input));

      double half;
      cout << "Half Life: ";
      cin.getline(input, 80);
      half = (double)(atof(input));
  
      while(true)
	{
	  cout << endl << "Command: ";
	  cin.getline(input, 80);
	  if (strcmp(input, "new") == 0)
	    {
	      break;
	    }
	  else if (strcmp(input, "quit") == 0)
	    {
	      end = true;
	      break;
	    }
	  else if (strcmp(input, "help") == 0)
	    {
	      printCommands();
	    }
	  else if (strcmp(input, "center") == 0)
	    {
	      cout << "Time: ";
	      cin.getline(input, 80);
	      double time = (double)(atof(input));

	      cout << "Iterations: ";
	      cin.getline(input, 80);
	      centerMaclaurin(atoi(input), time, half, initial);
	    }
	  else if (strcmp(input, "derivative") == 0)
	    {
	      cout << "Time: ";
	      cin.getline(input, 80);
	      double time = (double)(atof(input));

	      cout << "Iterations: ";
	      cin.getline(input, 80);
	      derivativeMaclaurin(atoi(input), time, half, initial);
	    }
	  else if (strcmp(input, "integral") == 0)
	    {
	      cout << "Time: ";
	      cin.getline(input, 80);
	      double time = (double)(atof(input));

	      cout << "Iterations: ";
	      cin.getline(input, 80);
	      integralMaclaurin(atoi(input), time, half, initial);
	    }
	}
    }
  return 0;
}

// e^x = 1 + x/1! + x^2/2! + x^3/3!...
void centerMaclaurin(int iterations, double time, double half, double initial)
{
  double rate = .693*time/half;
  double remaining = 0;
  for (int i = 0; i < iterations; i++)
    {
      remaining += pow(rate, i)/factorial(double(i));
      //cout << pow(rate, i) << " " << factorial(double(i)) << " " << pow(rate, i)/factorial(double(i)) << endl;
    }
  initial /= remaining;
  cout << initial << endl;
  return;
}

//get the slope 0+ 2x^1/2! + 3x^2/3! + (x^3)/3!+5x^4/(5x4!)
void derivativeMaclaurin(int iterations, double time, double half, double initial)
{
  double rate = .693*time/half;
  //cout << rate << endl;
  double remaining = 0;
  for (int i = 1; i < iterations; i++)
    {
      remaining += i*pow(rate, i-1)/factorial(double(i));
      //cout << pow(rate, i) << " " << factorial(double(i)) << " " << pow(rate, i)/factorial(double(i)) << endl;
    }
  initial /= remaining;
  cout << initial << endl;
  return;  
}

//get the slope x^1/1*0! + x^2/(2*1!) + x^3/(3*2!)...from x^n/n! to x^(n+1)/((n+1)n!)
void integralMaclaurin(int iterations, double time, double half, double initial)
{
  double rate = .693*time/half;
  //cout << rate << endl;
  double remaining = 0;
  for (int i = 0; i < iterations; i++)
    {
      remaining += pow(rate, i+1)/((i+1)*factorial(double(i)));
      //cout << pow(rate, i) << " " << factorial(double(i)) << " " << pow(rate, i)/factorial(double(i)) << endl;
    }
  initial /= remaining;
  cout << initial << endl;
  return;  
}


double factorial(double number)
{
  double fact = 1;
  while (number > 0)
    {
      fact *= number--;
    }
  return fact;
}

void printCommands()
{
  cout << "'center' - Calculate the amount left at a time" << endl;
  cout << "'integral' - Calculate the integral at a time" << endl;
  cout << "'derivative' - Calculate the decay rate at a time" << endl;
  cout << "'new' - Start a new decay equation" << endl;
  cout << "'help' - Print out the list of commands" << endl;
  cout << "'quit' - Exit from the program" << endl;
}
