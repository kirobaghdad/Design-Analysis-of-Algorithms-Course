#include <iostream>
using namespace std;

void MY_InsertionSort(int *nums, int count)
{
    for (int i = 1; i < count; i++)
    {
        int j = i;
        while (j > 0 && nums[j] < nums[j - 1])
        {
            swap(nums[j], nums[j - 1]);
            j--;
        }
    }
}

void InsertionSort(int *nums, int count)
{
    for (int i = 1; i < count; i++)
    {
        int key = nums[i];
        int j = i - 1;

        while (j > -1 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
}

int main()
{

    int nums[] = {5,
                  4,
                  3,
                  7,
                  1};

    InsertionSort(nums, 5);

    for (int i = 0; i < 5; i++)
        cout
            << nums[i] << endl;

    return 0;
}