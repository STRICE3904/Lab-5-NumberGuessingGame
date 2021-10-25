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
void NumberGenerator(float& number); 
//Precondition: Takes the inputed answer to check to see if it matches the number
//Postcondition: Outputs a text saying higher, lower, or good job
void answer_gennerator(float number, float number_guess, int x, float& win, float& loss);
//Precondition: Takes the old answer or the empty answer and changes it
//Postcondition: Outputes the new inputed answer
void answer_check(float& number_guess);

void play_again(bool& yn);

void sw_statement(float number, float number_guess, int x, bool& run);


int main()
{
	bool yn = true;
	float number = 1;
	float number_guess = 1;
	int x = 1;
	float win = 0;
	float loss = 0;
	do
	{
		intrduction();//Starts the prosses
		NumberGenerator(number);//Finds a number
		answer_check(number_guess);//Promts the usser for an answer
		bool run = true;
		do//While the answer attempts are below 21 it will run. 
		{
			answer_gennerator(number, number_guess, x, win, loss);
			if (number == number_guess)
			{
				sw_statement(number, number_guess, x, run);
			}
			else if (x > 20)
			{
				sw_statement(number, number_guess, x, run);
			}
			else if (number != number_guess || x<=x)
			{
				answer_check(number_guess);
				x++;
			}

		} while (run);
		play_again(yn);
	} while (yn);
	cout << "Total wins = " << win << " and total losses = " << loss << endl;
	return 0;
}


void intrduction()
{
	cout << "Lets play a game!! Guess my number. 0 to 100.\n\n\n";
}

void NumberGenerator(float& number)
{
	srand((unsigned)time(0));
	number = 1 + (rand() % 100);
	cout << "Alright. Ok I have my number. 20 guesses. Now GO GO GO.\n\n";
}

void answer_check(float& number_guess)
{
	cout << "your guess: ";
	cin >> number_guess;
}

void answer_gennerator(float number, float number_guess, int x, float& win, float& loss)
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
		win++;

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
	else if (x >= 21)
	{
		cout << "You loose. You loose. You loose. hehehehehehe. That means I win. Till we play again freind.\n\n";
		loss++;
	}
}

void play_again(bool& yn)
{
	int yn_input;
	cout << "Would you like to play again? Enter 1 for yes and 2 for no: ";
	cin >> yn_input;

	switch (yn_input)
	{
	case 1:	yn = true;
		break;

	case 2:	yn = false;
		break;

	default: cout << "Input error! Exiting program.\n\n";
		yn = false;
		break;
	}
}

void sw_statement(float number, float number_guess, int x, bool& run)
{
	if (number == number_guess)
	{
		run = false;
	}
	else if (x > 20)
	{
		run = false;
	}
	else
		run = true;
}