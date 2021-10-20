/*Samuel Trice
* C++ 2021
* 
* Lab 5
* Randomizing a number and guessing with different responses each time
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>


using namespace std; //Makes the writting of the code smoother

//Precondition: Fuction should say the flavored introduction
//Postcondition: Outputs the prompt that starts the prosses
void intrduction();
//Precondition: Fuction should take the empty value of the number variable
//Post condition: Fuction should change the number variable to any random number between 0 and 100
void NumberGenerator(); 
//Precondition: Takes the inputed awnser to check to see if it matches the number
//Postcondition: Outputs a text saying higher, lower, or good job
void awnser_gennerator();
//Precondition: Takes the old awnser or the empty awnser and changes it
//Postcondition: Outputes the new inputed awnser
void awnser_check();
//Variables that need to be used globaly by multiple functions and the main
float number;
float number_guess = 1;
int x = 1;

int main()
{
	intrduction();//Starts the prosses
	NumberGenerator();//Finds a number
	awnser_check();//Promts the usser for an awnser
	while (x < 20)//While the awnser attempts are below 21 it will run. 
	{
		awnser_gennerator();
		if (number == number_guess)
		{
			return 1;
		}
		awnser_check();
		x++;
	}
	return 0;
}

void intrduction()
{
	int awnser;
	cout << "Lets play a game!!\n\n\n";
	cout << "Number between 1 and 100!!! 20 guesses GO GO GO!!!!!\n\n\n";
	cout << "your awnser: ";
	cin >> awnser;
	if (awnser >= 100 || awnser <= 100 && awnser >= 1 || awnser <= 1)
	{
		cout << "WAIT. I havent chosen a number yet. Be patient.\n\n";
	}
}
void NumberGenerator()
{
	srand((unsigned)time(0));
	number = 1 + (rand() % 100);
	cout << "Alright. Ok I have my number. 20 guesses. You can now GO GO GO.\n\n";
}

void awnser_check()
{
	cout << "your guess: ";
	cin >> number_guess;
}

void awnser_gennerator()
{
	if (number == number_guess)
	{
		srand((unsigned)time(0));
		int result = 1 + (rand() % 3);
		switch (result)
		{
		case 1:
			cout << "Good job! Good job! Good job!\n\n";
			break;
		case 2:
			cout << "WOW you did it!!!\n\n";
			break;
		case 3:
			cout << "YAY you are sooo good\n\n";
			break;
		}

	}
	else if (number >= number_guess)
	{
		srand((unsigned)time(0));
		int result = 1 + (rand() % 3);
		switch (result)
		{
		case 1:
			cout << "Wow you readlly let me down. You need to bring it back up\n\n";
			break;
		case 2:
			cout << "No no no you need to guess higher if you want to win\n\n";
			break;
		case 3:
			cout << "Wrong! Wrong! Wrong! Too low\n\n";
			break;
		}

	}
	else if (number <= number_guess)
	{
		srand((unsigned)time(0));
		int result = 1 + (rand() % 3);
		switch (result)
		{
		case 1:
			cout << "Muda! Muda! Muda! Muda! Muda! Taka sugi masu!(Too high)\n\n";
			break;
		case 2:
			cout << "You need to sober up a bit mister cause your too high\n\n";
			break;
		case 3:
			cout << "Too high, Get back down here\n\n";
			break;
		}
	}
	else if (x <= 21)
	{
		cout << "You loose. You loose. You loose. hehehehehehe. That means I win. Till we play again freind.\n\n";
	}
}