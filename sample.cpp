#include <iostream>
#include <unordered_map>
#include <vector>

int maxLengthOfSubarray(std::vector<int> &nums)
{
    int maxLength = 0;
    std::unordered_map<int, int> lastIndex;
    int n = nums.size();
    int length = 0;

    for (int i = 0; i < n; i++)
    {
        if (lastIndex.find(nums[i]) != lastIndex.end())
        {
            length = i - lastIndex[nums[i]] + 1;
        }
        else
        {
            lastIndex[nums[i]] = i;
        }

        maxLength = std::max(maxLength, length);
    }

    return maxLength;
}

int main()
{
    // int n;
    // std::cout << "Enter the size of the array: ";
    // std::cin >> n;

    std::vector<int> nums = {2, 2, 3, 1, 2, 2, 3, 1, 1};
    // std::cout << "Enter the elements of the array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     std::cin >> nums[i];
    // }

    int result = maxLengthOfSubarray(nums);
    std::cout << "Maximum length of a subarray with the same start and end element: " << result << std::endl;

    return 0;
}
