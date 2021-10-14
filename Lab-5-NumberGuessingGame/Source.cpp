#include <iostream>
#include <string>

using namespace std;

void NumberGenerator();

float number;
float number_guess = 1;

int main()
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
	NumberGenerator();

	return 0;
}

void NumberGenerator()
{
	int number = rand() % 100 + 1;

	cout << "Alright. Ok I have my number. 20 guesses. You can now GO GO GO.\n\n";

	do
	{
		cout << "your guess: ";

		cin >> number_guess;

		int comO;
		if (number == number_guess)
		{
			srand(time(0));
			for (int i = 1; i <= 3; i++)
			{
				comO = rand() % 1;
			}
			{
				if (comO = 1)
				{
					cout << "Good job! Good job! Good job!\n\n";
				}
				else if (comO = 2)
				{
					cout << "WOW you did it!!!\n\n";
				}
				else if (comO = 3)
				{
					cout << "YAY you are sooo good\n\n";
				}
				break;
			}

		}
		else if (number >= number_guess)
		{
			for (int i = 1; i <= 3; i++)
			{
				comO = rand() % 1;
			}
			{
				if (comO = 1)
				{
					cout << "Wow you readlly let me down. You need to bring it back up\n\n";
				}
				else if (comO = 2)
				{
					cout << "No no no you need to guess higher if you want to win\n\n";
				}
				else if (comO = 3)
				{
					cout << "Wrong! Wrong! Wrong! Too low\n\n";
				}
				continue;
			}
		}
		else if (number <= number_guess)
		{
			for (int i = 1; i <= 3; i++)
			{
				comO = rand() % 1;
			}
			{
				if (comO = 1)
				{
					cout << "Wrong! Wrong! Wrong! Too high\n\n";
				}
				else if (comO = 2)
				{
					cout << "You need to sober up a bit mister cause your too high\n\n";
				}
				else if (comO = 3)
				{
					cout << "Too high, Get back down here\n\n";
				}
				continue;
			}
		}
		else if (number > number_guess)
		{
			cout << "You loose. You loose. You loose. hehehehehehe. That means I win. Till we play again freind.\n\n";
		}
	} while (number_guess <= 20);
}