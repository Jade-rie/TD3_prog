#include <vector>
#include <algorithm>
#include <iostream>

bool is_sorted(std::vector<int> const &vec) { return std::is_sorted(vec.begin(), vec.end()); }

void bubble_sort(std::vector<int> &vec)
{
    while (!is_sorted(vec))
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] > vec[i + 1])
            {
                std::swap(vec[i], vec[i + 1]);
            }
        }
    }
}

int main()
{
    std::vector<int> array{100, 24, 3, 47, 35, 69, 97, 27, 100, 56};
    bubble_sort(array);
    if (is_sorted(array))
    {
        std::cout << "Le tableau est trié" << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
}