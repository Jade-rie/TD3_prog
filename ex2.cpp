#include <vector>
#include <algorithm>
#include <iostream>

bool is_sorted(std::vector<int> const &vec) { return std::is_sorted(vec.begin(), vec.end()); }

size_t quick_sort_partition(std::vector<int> &vec, size_t left, size_t right)
{
    int pivot = vec[right];
    size_t indice = -1;
    for (size_t i = left; i <= right; i++)
    {
        if (vec[i] < pivot)
        {
            if (indice != -1)
            {
                std::swap(vec[i], vec[indice]);
                indice++;
            }
        }
        else
        {
            if (indice == -1)
            {
                indice = i;
            }
        }
    }
    std::swap(vec[right], vec[indice]);

    return indice;
}

void quick_sort(std::vector<int> &vec, size_t const left, size_t const right)
{
    if (left < right)
    {
        size_t pivot = quick_sort_partition(vec, left, right);
        if (pivot > 0)
        {
            quick_sort(vec, left, pivot - 1);
            quick_sort(vec, pivot + 1, right);
        }
    }
}

void quick_sort(std::vector<int> &vec)
{
    quick_sort(vec, 0, vec.size() - 1);
}

int main()
{
    std::vector<int> array{100, 24, 3, 47, 35, 69, 97, 27, 100, 56};
    quick_sort(array);
    if (is_sorted(array))
    {
        std::cout << "Le tableau est trié" << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
}