// Given an integer array nums of unique elements, return all possible subsets (the power set).The solution set must not contain duplicate subsets. Return the solution in any order.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void iPermute(vector<vector<int>> &ans, vector<int> &subset, int i, vector<int> &nums)
    {
        // base case
        if (i == nums.size()) // if the size of the data structure is equal to the size of the input array, then we have found all permutation
        {
            ans.push_back(subset); // pushing the current permutation into the answer vector of vectors
            return;                // returning from the function
        }

        // recursive case
        subset.push_back(nums[i]);          // pushing the element into the data structure
        iPermute(ans, subset, i + 1, nums); // calling the recursive function again
        subset.pop_back();                  // popping the element from the data structure as we have already pushed it into the answer vector of vectors and we don't want to push it again
        iPermute(ans, subset, i + 1, nums); // calling the recursive function
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> subset;             // data structure to store the current subset in the recursion
        vector<vector<int>> ans;        // answer vector of vectors to store all the permutations
        iPermute(ans, subset, 0, nums); // calling the recursive function to print all the permutations of the input array nums
        return ans;                     // returning the answer vector of vectors containing all the permutations
    }
};