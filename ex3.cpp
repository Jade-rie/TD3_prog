#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include "ScopedTimer.hpp"

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

std::vector<int> generate_random_vector(size_t const size, int const max = 100)
{
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

int main()
{
    std::vector<int> array = generate_random_vector(100);

    {
        ScopedTimer timer("bubble_sort");
        bubble_sort(array);
    }

    {
        ScopedTimer timer("quick_sort");
        quick_sort(array);
    }

    {
        ScopedTimer timer("sort");
        std::sort(array.begin(), array.end());
    }

    if (is_sorted(array))
    {
        std::cout << "Le tableau est trié" << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
}