#include <iostream>
#include <vector>
#include <ctime>

bool ChangeStateOfCell(const bool& cell, const int& count)
{
	if (!cell && count == 3)
		return true;

	if (cell)
		switch (count)
		{
		case 2:
			return true;
		case 3:
			return true;
		default:
			return false;
			break;
		}
}

int FindNeighbours(const std::vector<std::vector<bool>>& matrix, const int& i, const int& j)
{
	int count = 0;

	if (matrix[i - 1][j - 1])
		++count;
	if (matrix[i - 1][j])
		++count;
	if (matrix[i - 1][j + 1])
		++count;
	if (matrix[i][j - 1])
		++count;
	if (matrix[i][j + 1])
		++count;
	if (matrix[i + 1][j - 1])
		++count;
	if (matrix[i + 1][j])
		++count;
	if (matrix[i + 1][j + 1])
		++count;

	return count;
}

void PrintMatrix(const std::vector<std::vector<bool>>& matrix)
{
	for (const auto& vector : matrix)
	{
		for (const auto& el : vector)
			std::cout << el << ' ';
		std::cout << std::endl;
	}
}

int main()
{
	srand(time(0));

	int size_x, size_y;
	bool cont = true;
	std::cout << "Enter the size of matrix:\nx = ";
	std::cin >> size_x;
	std::cout << "y = ";
	std::cin >> size_y;

	// Initialization of the initial matrix //
	std::vector<std::vector<bool>> initial_matrix(size_y, std::vector<bool>(size_x));
	// Filling the matrix with random numbers //
	for (auto& vector : initial_matrix)
		for (auto el : vector)
			el = rand() % 2;

	// Creating a copy of the matrix //
	std::vector<std::vector<bool>> modified_matrix(initial_matrix);

	std::cout << "\nInitial matrix:\n";
	PrintMatrix(initial_matrix);

	while (cont)
	{
		// Matrix modification //
		for (int i = 1; i < initial_matrix.size() - 1; ++i)
		{
			int count = 0;
			for (int j = 1; j < initial_matrix.size() - 1; ++j)
			{
				// Counting cell neighbors //
				count = FindNeighbours(initial_matrix, i, j);
				// A change in the state of the cell
				modified_matrix[i][j] = ChangeStateOfCell(initial_matrix[i][j], count);
			}
		}

		std::cout << "\nModified matrix:\n";
		PrintMatrix(modified_matrix);

		// Request for continued work //
		std::cout << "\nContinue? (Enter 0 or 1)\n>> ";
		std::cin >> cont;
		switch (cont)
		{
		case 1:
			initial_matrix = modified_matrix;
			break;
		case 0:
			break;
		default:
			std::cout << "Input error!\n";
			return 0;
		}
	}
	return 0;
}