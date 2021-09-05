// refer question
// https://leetcode.com/problems/count-number-of-teams/

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int leftLess = 0;
            int rightGreater = 0;

            int leftGreater = 0;
            int rightLess = 0;

            for (int j = 0; j < i; j++)
            {
                if (rating[i] > rating[j])
                    leftLess++;
                else
                    leftGreater++;
            }

            for (int j = i + 1; j < n; j++)
            {
                if (rating[i] < rating[j])
                    rightGreater++;
                else
                    rightLess++;
            }

            ans += (leftLess * rightGreater) + (leftGreater * rightLess);
        }
        return ans;
    }
};