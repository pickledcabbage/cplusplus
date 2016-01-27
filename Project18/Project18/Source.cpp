#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	int lasttake = 1;
	srand(time(NULL));
	int sticks = rand() % 20 + 10;
	bool playersTurn;
	bool complete = false;
	int temp;
	cout << "Do you want to go first (1) or second (2)?: ";
	cin >> temp;
	playersTurn = temp == 1;
	while (!complete)
	{
		int take = 0;
		cout << "There are " << sticks << " sticks left." << endl;
		if (playersTurn)
		{
			while (take < 1 || take > lasttake)
			{
				cout << "How many sticks do you want to take? (1-" << lasttake << "): ";
				cin >> take;
			}
		}
		if (!playersTurn)
		{
			if (lasttake >= sticks - 1)
				take = sticks - 1;
			else if (lasttake * 3 + 2 <= sticks)
				take = lasttake;
			else
				take = 1;
			cout << "Opponent takes " << take << " stick(s)." << endl;
		}
		
		playersTurn = !playersTurn;
		sticks -= take;
		lasttake = take * 2;
		if (sticks <= 0)
			complete = true;
	}
	if (!playersTurn)
		cout << "You LOSE!" << endl;
	else
		cout << "You WIN!" << endl;
	return 0;
}