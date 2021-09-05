// refer question  Statement
// https://leetcode.com/problems/zigzag-conversion/

//solution
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.size();
        vector<vector<char>> ref;
        int i = 0, j = 0;
        int counter = 0;
        while (i < n)
        {
            if (counter % 2 == 0)
            {
                vector<char> temp(numRows);
                int k = 0;
                while (k < numRows && i < n)
                {
                    temp[k] = s[i];
                    k++;
                    i++;
                }
                ref.push_back(temp);
                counter += 1;
            }
            else
            {
                vector<char> temp(numRows, '@');
                int k = 1;
                while (k < numRows - 1 && i < n)
                {
                    temp[k] = s[i];
                    k++;
                    i++;
                }
                reverse(temp.begin(), temp.end());
                ref.push_back(temp);
                counter += 1;
            }
        }
        string ans = "", ans1 = "";
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < counter; j++)
            {

                if (ref[j][i] != '@')
                    ans += ref[j][i];
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == ',' || ans[i] == '.')
            {
                ans1 += ans[i];
                continue;
            }

            char at = toupper(ans[i]);
            int r = at - 'A';
            if (r >= 0 && r <= 25)
                ans1 += ans[i];
        }

        return ans1;
    }
};