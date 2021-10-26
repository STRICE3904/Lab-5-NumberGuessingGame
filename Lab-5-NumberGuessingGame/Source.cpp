/*Samuel Trice
* C++ 2021
* Oct 27. 2021
* Lab 5
* Randomizing a number and guessing with different responses each time. Then asking if they want to play again and displaying the score
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
//Postcondition: Fuction should change the number variable to any random number between 0 and 100
void NumberGenerator(float& number); 
//Precondition: Takes the inputed answer to check to see if it matches the number
//Postcondition: Outputs a text saying higher, lower, or good job
void answer_gennerator(float number, float number_guess, int x, float& win, float& loss);
//Precondition: Takes the old answer or the empty answer and changes it
//Postcondition: Outputes the new inputed answer
void answer_check(float& number_guess);
//Precondition: After the game runs it sends you to ask if you want to play again
//Postcondition: Asks yes or no and sets yn to true or false. 
void play_again(bool& yn);
//Precondition: Gets called if either the numbers matched or the guesses are out
//Postcondition: Sets run to false and ends the loop
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
			answer_gennerator(number, number_guess, x, win, loss);//Calls the function for the text output. 
			if (number == number_guess)//If the numbers equal it calls the switch function
			{
				sw_statement(number, number_guess, x, run);//switch function
			}
			else if (x > 20)//If the guesses are out it calls the switch function
			{
				sw_statement(number, number_guess, x, run);//switch function
			}
			else if (number != number_guess || x<=x)//If the number is not correct and there are still guesses left it calls the input function again
			{
				answer_check(number_guess);//Input function
				x++;//Adds to the number of guesses. 
			}

		} while (run);//When run = false the loops ends. 
		play_again(yn);//Play again function call. 
	} while (yn);//When yn=false the loop ends. 
	cout << "Total wins = " << win << " and total losses = " << loss << endl; //Total number of wins and losses output. 
	return 0;
}


void intrduction()//Added this function to keep main looking cleaner
{
	cout << "Lets play a game!! Guess my number. 0 to 100.\n\n\n";
}

void NumberGenerator(float& number)//Function for the number guessed. Gets called every new game
{
	srand((unsigned)time(0));
	number = 1 + (rand() % 100);
	cout << "Alright. Ok I have my number. 20 guesses. Now GO GO GO.\n\n";
}

void answer_check(float& number_guess)//Fuction for the number guess. Gets called every time the player guesses
{
	cout << "your guess: ";
	cin >> number_guess;
}

void answer_gennerator(float number, float number_guess, int x, float& win, float& loss)//Function that allows the bot to reply different ways
{
	if (number == number_guess)//These are the awnsers for if the awnser is right
	{
		srand((unsigned)time(0));//Usses another random number to pick between 1 and 3. 
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
		win++;//Adds a point to win for the output at the end

	}
	else if (number >= number_guess)//These are the awnsers for when the number is low. 
	{
		//Exact same number system as the first one except no win is added
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
	else if (number <= number_guess)//These are the awnsers for when the number is high
		//Exact same number system as the last one
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
	else if (x >= 21)//If the guesses have ran out it says you loose 
	{
		cout << "You loose. You loose. You loose. hehehehehehe. That means I win. Till we play again freind.\n\n";
		loss++;//Adds a point to losses
	}
}

void play_again(bool& yn)//This is the switch for the play again. 
{
	int yn_input;
	//prompts a yes or no if they would like to play again
	cout << "Would you like to play again? Enter 1 for yes and 2 for no: ";
	cin >> yn_input;

	//yes it stays true and restarts the loop. no it becomes false and ends the loop. If neither is entered correctly it sets automaticaly to false
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

//switch statement for the number game. This gets called when the player wins or looses. If it gets called any other reason it stays true and keeps the loop going.
void sw_statement(float number, float number_guess, int x, bool& run)  
{
	if (number == number_guess)//If the number matches the guess it ends the loop
	{
		run = false;
	}
	else if (x > 20)//If the guess attemts run out it ends the loop
	{
		run = false;
	}
	else//If nothing has happened to end the game it just keeps going. 
		run = true;
}