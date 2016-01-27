#include <iostream>
#include <stdlib.h>
#include <time.h>
// Program that creates a maze you move around in
// you only see where you have been and block around you
void setMazeNull(int* maze, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			maze[i*width+j] = 0;
		}
	}
}
int main()
{
	srand(time(NULL));
	// Creates blank 21x21 board
	int const BOARD_WIDTH = 79; // ODD VALUES ONLY
	int const BOARD_HEIGHT = 79; // ODD VALUES ONLY
	int board[BOARD_HEIGHT][BOARD_WIDTH];
	int i, j, s, d, c, x, y;
	int sx, sy;
	int revealed[BOARD_HEIGHT][BOARD_WIDTH];
	int direction = 0;
	bool keeprun = true;
	bool quit = false;

	
	while (!quit)
	{
		keeprun = true;
		/*for (i = 0; i < BOARD_HEIGHT; i++)
		{
			for (j = 0; j < BOARD_WIDTH; j++)
			{
				board[i][j] = 0;
			}
		}*/
		setMazeNull(&(board[0][0]), BOARD_WIDTH, BOARD_WIDTH);
		for (i = 0; i < BOARD_HEIGHT; i++)
		{
			for (j = 0; j < BOARD_WIDTH; j++)
			{
				revealed[i][j] = 0;
			}
		}
		int randdirection;
		for (s = 2; s < BOARD_HEIGHT; s += 2)
		{
			for (d = 2; d < BOARD_WIDTH; d += 2)
			{
				randdirection = rand() % 4 + 1;
				board[s][d] = 2;
				if (randdirection == 1)
				{
					board[s-1][d] = 2;
				}
				if (randdirection == 2)
				{
					board[s][d+1] = 2;
				}
				if (randdirection == 3)
				{
					board[s+1][d] = 2;
				}
				if (randdirection == 4)
				{
					board[s][d-1] = 2;
				}
			}
		}
		for (int c = 0; c < BOARD_HEIGHT; c++)
		{
			board[c][0] = 2;
			board[c][BOARD_WIDTH-1] = 2;
		}
		for (int c = 0; c < BOARD_WIDTH; c++)
		{
			board[0][c] = 2;
			board[BOARD_HEIGHT - 1][c] = 2;
		}

		x = rand() % (BOARD_WIDTH-2) + 1;
		y = rand() % (BOARD_HEIGHT-2) + 1;
		sx = rand() % (BOARD_WIDTH-4) + 2;
		sy = rand() % (BOARD_HEIGHT-4) + 2;

		board[sy][sx] = 0; board[sy + 1][sx] = 0; board[sy + 1][sx + 1] = 0;
		board[sy][sx + 1] = 0; board[sy][sx - 1] = 0; board[sy - 1][sx] = 0;
		board[sy - 1][sx - 1] = 0; board[sy + 1][sx - 1] = 0; board[sy - 1][sx + 1] = 0;

		
		while (keeprun)
		{
			revealed[y][x] = 1; revealed[y + 1][x] = 1; revealed[y + 1][x + 1] = 1;
			revealed[y][x + 1] = 1; revealed[y][x - 1] = 1; revealed[y - 1][x] = 1;
			revealed[y - 1][x - 1] = 1; revealed[y + 1][x - 1] = 1; revealed[y - 1][x + 1] = 1;
			std::cout << "Cave: " << std::endl;
			for (int a = 0; a < BOARD_HEIGHT; a++)
			{
				for (int b = 0; b < BOARD_WIDTH; b++)
				{
					
					if (a == y && b == x)
					{
						std::cout << "8";
					}
					else if (a == sy && b == sx)
					{
						std::cout << "D";
					}
					else if (revealed[a][b] == 1 && board[a][b] == 2)
					{
						std::cout << "W";
					}
					else if (revealed[a][b] == 1)
					{
						std::cout << " ";
					}
					else
					{
						std::cout << "X";
					}
				}
				std::cout << std::endl;
			}
			std::cout << "Directions: 1 is up, 2 is down, 3 is right, 4 is left, 5 is quit: ";
			std::cin >> direction;
			if (direction == 1 && board[y - 1][x] == 0)
			{
				y--;
			}
			else if (direction == 2 && board[y + 1][x] == 0)
			{
				y++;
			}
			else if (direction == 3 && board[y][x + 1] == 0)
			{
				x++;
			}
			else if (direction == 4 && board[y][x - 1] == 0)
			{
				x--;
			}
			else if (direction == 5)
			{
				quit = true;
				keeprun = false;
			}
			if (sx == x && sy == y)
			{
				keeprun = false;
			}
		}
	}
	
}
