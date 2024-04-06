#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
   public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
       unordered_map<int, int> numMap;
       int n = nums.size();
       
       for(int i = 0; i < n; i++)
       {
        int complement = target - nums[i];
        if(numMap.count(complement))
        {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
       }
       return {};

    }
};

int main() 
{
    vector<int> nums = {4, 7, 11, 15};
    int target = 15;

    Solution solution;
    vector<int> indices = solution.twoSum(nums, target);

    if (indices.size() == 2) {
        cout << "Indices of the two numbers that add up to " << target << " are: ";
        cout << indices[0] << " and " << indices[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
