#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int random, mynum,n= 0;
	srand(time(0)); 
	random = rand() % 100 + 1; 
	cout << "Guess My Number "<<endl;

	do
	{
		cout << "Enter a number between 1 and 100 : ";
		cin >> mynum;
		n++;

		if (mynum > random)
			cout << " its too high!\n"<<endl;
		else if (mynum < random)
			cout << "its too low!\n"<<endl;
		else
			cout << "Congratulations! you gussed correct ,  You got it in " << n << " attempts!";
	} while (mynum != random);

	return 0;
}