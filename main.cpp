#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include "TestRunner.h"

bool IsPath(std::vector<std::vector<int>> matrix)
{
    const int size = matrix.size();
    const std::vector<std::vector<int>> dir = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    std::queue<std::pair<int, int>> q;

    if (matrix[0][0] == 1)
    {
        q.push(std::make_pair(0, 0));
    }

    while (q.size() > 0)
    {
        std::pair<int, int> p = q.front();
        q.pop();

        matrix[p.first][p.second] = 0;

        if (p == std::make_pair(size - 1, size - 1))
        {
            return true;
        }
        
        for (size_t i = 0; i < dir.size(); i++)
        {
            int a = p.first + dir[i][0];
            int b = p.second + dir[i][1];

            if (a >= 0 && b >= 0 && a < size && b < size && matrix[a][b] != 0)
            {
                q.push(std::make_pair(a, b));
            }
        }
    }
    return false;
}

int GetSize()
{
    int size;
    std::cin >> size;

    while (size < 2 || size > 50 || std::cin.fail())
    {
        if (std::cin.fail())
        {
            std::cout << "Incorect size" << std::endl;
            std::cin.clear();
            while (std::cin.peek() != '\n')
            {
                std::cin.get();
            }
        }
        else
        {
            std::cout << "Size must be between 2 and 50" << std::endl;
        }
        std::cout << "Enter size again: " << std::endl;
        std::cin >> size;
    }

    return size;
}

void FillMatrix(std::vector<std::vector<int>>& matrix)
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            std::cout << "Matrix[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void PrintMatrix(const std::vector<std::vector<int>>& matrix)
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void TestFunctionIsPath()
{
    {
        const std::vector<std::vector<int>> vec = {
                    { 1, 1, 1, 0, 1},
                    { 0, 1, 1, 0, 0},
                    { 1, 1, 1, 0, 1},
                    { 0, 1, 1, 1, 1},
                    { 1, 1, 0, 1, 1} };
        AssertEqual(true, IsPath(vec), "1 case");
    }
    {
        const std::vector<std::vector<int>> vec = {
                    { 1, 1, 1, 0, 1},
                    { 0, 1, 1, 0, 0},
                    { 1, 1, 1, 0, 1},
                    { 0, 1, 0, 1, 1},
                    { 1, 1, 0, 1, 1} };
        AssertEqual(false, IsPath(vec), "2 case");
    }
    {
        const std::vector<std::vector<int>> vec = {
                    { 0, 1, 1, 0, 1},
                    { 0, 1, 1, 0, 0},
                    { 1, 1, 1, 0, 1},
                    { 0, 1, 0, 1, 1},
                    { 1, 1, 0, 1, 1} };
        AssertEqual(false, IsPath(vec), "3 case");
    }
    {
        const std::vector<std::vector<int>> vec = {
                    { 1, 0, 0},
                    { 1, 0, 0},
                    { 1, 1, 1} };
        AssertEqual(true, IsPath(vec), "4 case");
    }
    {
        const std::vector<std::vector<int>> vec = {
                    { 1, 0, 0},
                    { 0, 1, 0},
                    { 0, 0, 1} };
        AssertEqual(false, IsPath(vec), "5 case");
    }
    {
        const std::vector<std::vector<int>> vec = {
                    { 1, 1, 0, 0},
                    { 0, 1, 1, 0},
                    { 0, 1, 1, 1}, 
                    { 0, 0, 0, 1} };
        AssertEqual(true, IsPath(vec), "6 case");
    }
    {
        const std::vector<std::vector<int>> vec = {
                   { 1, 0, 1, 1, 1},
                   { 1, 0, 1, 0, 0},
                   { 1, 0, 1, 0, 0},
                   { 1, 0, 1, 0, 0},
                   { 1, 1, 1, 1, 1} };
        AssertEqual(true, IsPath(vec), "7 case");
    }
    {
        const std::vector<std::vector<int>> vec = {
                   { 1, 1, 1, 1, 1},
                   { 0, 0, 0, 0, 1},
                   { 0, 0, 0, 1, 1},
                   { 0, 0, 0, 1, 0},
                   { 0, 0, 1, 1, 0} };
        AssertEqual(false, IsPath(vec), "8 case");
    }
    {
        const std::vector<std::vector<int>> vec = {
                   { 1, 1, 1, 1, 0},
                   { 1, 0, 0, 1, 0},
                   { 1, 1, 1, 0, 0},
                   { 1, 0, 0, 0, 0},
                   { 1, 1, 1, 1, 1} };
        AssertEqual(true, IsPath(vec), "9 case");
    }
    {
        const std::vector<std::vector<int>> vec = {
                   { 1, 1, 0, 0, 0},
                   { 0, 1, 1, 1, 0},
                   { 1, 1, 0, 0, 0},
                   { 0, 1, 1, 1, 1},
                   { 1, 1, 0, 1, 1} };
        AssertEqual(true, IsPath(vec), "10 case");
    }
}

int main()
{
    TestRunner runner;
    runner.RunTest(TestFunctionIsPath, "TestFunctionIsPath");

    std::cout << "Enter size of matrix (minimum size = 2, maximum size = 50): ";
    
    int size = GetSize();
    std::vector<std::vector<int>> matrix(size, std::vector<int>(size, 0));

    std::cout << "Enter values for matrix" << std::endl;
    std::cout << std::endl;
    FillMatrix(matrix);

    std::cout << std::endl;
    PrintMatrix(matrix);

    std::cout << std::endl;

    if (IsPath(matrix))
    {
        std::cout << "Result: Yes" << std::endl;
    }
    else
    {
        std::cout << "Result: No" << std::endl;
    }
    return 0;
}
