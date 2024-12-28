/*
Author: JOURNOUD Lucas
Date: 2024-12-28
Website: Yandex Contest
Problems: Стажировка осень-зима 2024 | бэкенд | B. Медианы подотрезков
*/

#include <iostream>
#include <vector>
#include <algorithm>

/*
Example 1:
5 2
5 4 3 2 1
Expected output: 2

Example 2:
6 3
3 6 5 4 2 1
Expected output: 1

Example 3:
7 4
5 7 2 4 3 1 6
Expected output: 4
*/

void FindNumberOfSubdivision(std::vector<int> grid, int C, int positionC, int& numberOfSubdivision);

int main()
{
    int R = 0, C = 0;
    std::cin >> R >> C;
	std::vector<int> grid(R);
	int positionC = 0;
	int numberOfSubdivision = 0;
	for (int i = 0; i < R; ++i)
	{
		std::cin >> grid[i];
		if (grid[i] == C)
		{
			positionC = i;
			numberOfSubdivision++;
		}
	}

	FindNumberOfSubdivision(grid, C, positionC, numberOfSubdivision);
	std::cout << numberOfSubdivision;

    return 0;
}

void FindNumberOfSubdivision(std::vector<int> grid, int C, int positionC, int &numberOfSubdivision)
{
	bool stop = false;
	for (int windowSize = 3; !stop; windowSize += 2)
	{
		stop = true;
		for (int startOfWindow = positionC - windowSize + 1; (startOfWindow + windowSize) <= grid.size(); startOfWindow++)
		{
			if (startOfWindow >= 0)
			{
				stop = false;
				std::vector<int> subWindow(grid.begin() + startOfWindow, grid.begin() + startOfWindow + windowSize);
				std::sort(subWindow.begin(), subWindow.end());
				if (subWindow[subWindow.size() / 2] == C)
				{
					numberOfSubdivision++;
				}
			}
		}
	}
}