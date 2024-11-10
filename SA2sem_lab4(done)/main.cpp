#include <iostream>
#include <vector>

using namespace std;

int findPeak(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2; // находим середину
        if (nums[mid] < nums[mid + 1])       // если правее середины стоит элемент больше, то идем искать вправо
        {
            left = mid + 1;
        }
        else // если нет, идем искать влево
        {
            right = mid;
        }
    }

    return left; // Индекс пика
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int peakIndex = findPeak(nums);

    cout << "Индекс пика: " << peakIndex << endl;
    cout << "Значение пика: " << nums[peakIndex] << endl;

    return 0;
}