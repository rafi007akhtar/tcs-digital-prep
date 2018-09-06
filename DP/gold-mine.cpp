/** Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect. 
 
 Examples:
 ---------

	Input : mat[][] = {
					{1, 3, 3},
					{2, 1, 4},
					{0, 6, 4}
				};
	Output : 12 
	{(1,0)->(2,1)->(2,2)}

	Input: mat[][] = { {1, 3, 1, 5},
					{2, 2, 4, 1},
					{5, 0, 2, 3},
					{0, 6, 1, 2}};
	Output : 16
	(2,0) -> (1,1) -> (1,2) -> (0,3) OR
	(2,0) -> (3,1) -> (2,2) -> (2,3)


	Input : mat[][] = {
					{10, 33, 13, 15},
					{22, 21, 04, 1},
					{5, 0, 2, 3},
					{0, 6, 14, 2}
				};
	Output : 83
*/

#include <bits/stdc++.h>
using namespace std;

int **mine;
int n, m;

pair <int,int> move(pair <int, int> p, char dir)
{
	/** Move (or update x, y) as per the direction given */

	int x, y;
	x = p.first;
	y = p.second;
	
	switch(dir)
	{
		case 'r': // right
			y++;
			break;

		case 'u': // right-up
			x--;
			y++;
			break;
		
		case 'd': // right-down
			x++;
			y++;
			break;

		default:
			return p;
	}

	p.first = x;
	p.second = y;
	return p;
}

int getStartingRow(int n, int y)
{
	/** Get the row (x-value) from where the exploration must begin (since y value is known to be the first column) */

	int elem = -1, x;
	for (int i = 0; i < n; i++)
	{
		if (mine[i][y] > elem) // choose the row with the greatest value to begin with
		{
			x = i;
			elem = mine[x][y];
		}
	}
	return x;
}


int main()
{
	cout << "Enter the order of the matrix (space-separated): ";
	cin >> n >> m;

	mine = new int *[n];
	for (int i = 0; i < m; i++)
		mine[i] = new int[m];

	cout << "\nEnter the elements of the matrix:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> mine[i][j];
	}

	int y = 0; // since exploration of the mine begins from the first column
	int x = getStartingRow(n,y); // get the initial value of x

	int gold = mine[x][y];
	cout << "We shall start from (" << x << ", " << y << ") with value " << gold << "\n";

	pair <int, int> p1; // position that would keep changing throughout the mine
	p1.first = x;
	p1.second = y;

	pair <int, int> p2, p3;
	p3 = p2 = p1;
	
	char right = 'r';
	char rightUp = 'u';
	char rightDown = 'd';

	while (1)
	{
		cout << "\nChoices:\n";
		p1 = move(p1, right); // move right
		p2 = move(p2, rightUp); // move right-up
		p3 = move(p3, rightDown); // move right-down

		if (p1.second >= m) // exceeded boundary on going right
			break; // can't really move anywhere else
		else 
		{
			x = p1.first;
			y = p1.second;
			cout << mine[x][y] << " in (" << x << ", " << y << ") on right\n";
		}

		if (p2.first < 0 || p2.second >= m) // exceeded boundary while going right-up
			rightUp = 'n'; // don't go right-up anymore
		else
		{
			cout << mine[p2.first][p2.second] << " in (" << p2.first << ", " << p2.second << ") on right-up\n";
			if (mine[p2.first][p2.second] > mine[x][y])
			{
				x = p2.first;
				y = p2.second;
				rightDown = 'd'; // free to move down if possible
			}
		}

		if (p3.first >= n || p3.second >= m) // exceeded boundary while going right-down
			rightDown = 'n'; // don't go right down anymore
		else
		{
			cout << mine[p3.first][p3.second] << " in (" << p1.first << ", " << p2.second << ") on right down\n";
			if (mine[p3.first][p3.second] > mine[x][y])
			{
				x = p3.first;
				y = p3.second;
				rightUp = 'u'; // free to move up if possible
			}
		}

		p3 = p2 = p1 = make_pair(x, y); // continue on from this point

		if (right == 'n' && rightUp == 'n' && rightDown == 'n')
			break; // no place to go
	
		cout << "Gold in this iteration: " << mine[x][y] << " at (" << x << ", " << y << ")" << "\n";

		gold += mine[x][y];
	}

	cout << "\nMaximum gold that can be achieved: " << gold << endl;

	return 0;
}
