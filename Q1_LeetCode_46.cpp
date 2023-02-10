#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void iPermute(vector<int> &nums, vector<vector<int>> &ans, vector<int> ds, int freq[])
    {
        // base case
        if (ds.size() == nums.size()) // if the size of the data structure is equal to the size of the input array, then we have found all permutation
        {
            ans.push_back(ds); // pushing the current permutation into the answer vector of vectors
            return;            // returning from the function
        }

        // recursive case
        for (int i = 0; i < nums.size(); i++) // iterating over the input array
        {
            if (!freq[i]) // if the element is not present in the data structure
            {
                ds.push_back(nums[i]);         // pushing the element into the data structure
                freq[i] = 1;                   // marking the element as present in the data structure
                iPermute(nums, ans, ds, freq); // calling the recursive function
                freq[i] = 0;                   // marking the element as not present in the data structure
                ds.pop_back();                 // popping the element from the data structure
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;              // answer vector of vectors to storing all the permutations
        vector<int> ds;                       // data structure to store current permutation in the recursion
        int freq[nums.size()];                // frequency array to check if the element is already present in the data structure
        for (int i = 0; i < nums.size(); i++) // initializing the frequency array to 0
            freq[i] = 0;                      // 0 means the element is not present in the data structure
        iPermute(nums, ans, ds, freq);        // calling the recursive function to print all the permutations of the input array nums
        return ans;                           // returning the answer vector of vectors containing all the permutations
    }
};