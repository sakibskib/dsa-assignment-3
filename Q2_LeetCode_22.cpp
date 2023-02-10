#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void iPremute(int n, vector<string> &ans, int l, int r, string s)
    {

        // base case
        if (l >= r && r == n) // if the size of the data structure is equal to the size of the input array, then we have found all permutation of the string
        {
            ans.push_back(s); // pushing the current permutation into the answer vector of vectors
            return;
        }

        // recursive cases
        if (r < n)
        {
            s.push_back('(');              // pushing the element into the data structure and marking the element as present in the data structure
            iPremute(n, ans, l, r + 1, s); // calling the recursive function
            s.pop_back();                  // popping the element from the data structure
        }

        if (l < r)
        {
            s.push_back(')');              // pushing the element into the data structure and marking the element as present in the data structure
            iPremute(n, ans, l + 1, r, s); // calling the recursive function
        }
        return;
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans; // answer vector of vectors to store all the permutations
        string s = "";      // staring with ( if the is for than 0
        if (n > 0)
            s += '(';
        int l = 0, r = 1;          // l is the number of left brackets and r is the number of right brackets , r = 1 because we have already added one left bracket on s
        iPremute(n, ans, l, r, s); // calling the recursive function to print all the permutations of the input array nums
        return ans;
    }
};