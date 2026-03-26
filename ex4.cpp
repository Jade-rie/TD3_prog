#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>

int search(std::vector<int> vec, int value)
{
    int left{0};
    int right = vec.size() - 1.0f;
    int middle{};
    while (left != right + 1)
    {

        middle = (left + right) / 2.0f;
        if (vec[middle] < value)
        {
            left = middle + 1;
        }
        else if (vec[middle] > value)
        {
            right = middle - 1;
        }
        else if (vec[middle] == value)
        {
            return middle;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> array{1, 2, 2, 3, 4, 8, 12};
    // std::vector<int> array{1, 2, 3, 3, 6, 14, 12, 15};
    // std::vector<int> array{2, 2, 3, 4, 5, 8, 12, 15, 16};
    // std::vector<int> array{5, 6, 7, 8, 9, 10, 11, 12, 13};
    // std::vector<int> array{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << search(array, 8) << std::endl;
}