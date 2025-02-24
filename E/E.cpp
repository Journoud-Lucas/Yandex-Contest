/*
Author: JOURNOUD Lucas
Date: 2025-02-24
Website: Yandex Contest
Problems: Стажировка осень-зима 2024 | бэкенд | E. Неэффективный поиск
*/

#include <iostream>
#include <vector>
#include <numeric>

/*


3
ba
ab
abc
3
cd
ba
ab



*/


int NumberOfActions(std::vector<std::string>& dictionary, std::string& request, int N);

int main()
{
	int N;
	std::cin >> N;
	std::vector<std::string> dictionary(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> dictionary[i];
	}

	int Q;
	std::cin >> Q;
	std::vector<std::string> request(Q);
	for (int i = 0; i < Q; i++)
	{
		std::cin >> request[i];
	}

	for (int i = 0; i < Q; i++)
	{
		std::cout << NumberOfActions(dictionary, request[i], dictionary.size()) << std::endl;
	}
}

int NumberOfActions(std::vector<std::string> & dictionary, std::string &request, int N)
{
	std::vector<std::string> prefixe;
	prefixe.resize(N);

	int i = 0;
	for (; i < N; ++i) // Dictionaries
	{
		for (int j = 0; j < dictionary[i].size(); j++) // Letter
		{
			if (dictionary[i][j] == request[j])
			{
				prefixe[i] += dictionary[i][j];
			}
			else
			{
				break;
			}
		}
		if (prefixe[i] == request)
		{
			i++;
			break;
		}
	}

	int totalLength = std::accumulate(prefixe.begin(), prefixe.end(), 0,
		[](size_t sum, const std::string& str) {
			return sum + str.size();
		});

	return i + totalLength;
}