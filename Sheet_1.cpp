#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <set>
using namespace std;

int maxLength;
int ways;
int minCost;
vector<int> minPath;
int countColors;
int n;
vector<bool> xC;
int check;

// Complete Problem_1
void Problem_1(int n, string str = "")
{
    if (str.length() == n)
    {
        cout << (str) << endl;
        return;
    }

    Problem_1(n, str + '0');
    Problem_1(n, str + '1');
}

// Complete Problem_2
void Problem_2(const int &n, const int &k, string str = "")
{
    if (str.length() == n)
    {
        cout << str << endl;
        return;
    }

    for (int i = 0; i < k; i++)
        Problem_2(n, k, str + to_string(i));
}

// Complete Problem_3
void Problem_3(vector<int> nums, int index = 0, int last = 0, int count = 0)
{

    if (index < nums.size())
    {
        if (last < nums[index])
        {
            last = nums[index];
            count++;
        }
        Problem_3(nums, index + 1, last, count);
        Problem_3(nums, index + 1, 0, 0);
    }
    else if (index == nums.size())
        if (count > maxLength)
            maxLength = count;
}

// Complete Problem_4
void Problem_4(int n, int count = 0)
{
    if (count == n)
    {
        ways++;
    }
    else if (count > n)
    {
        return;
    }
    else
    {
        Problem_4(n, count + 1);
        Problem_4(n, count + 2);
        Problem_4(n, count + 3);
    }
}

// Complete Problem_5
bool validColoring(vector<vector<bool>> nums, vector<int> color)
{
    for (int i = 0; i < color.size(); i++)
    {
        for (int j = 0; j < color.size(); j++)
        {
            if (nums[i][j] && color[i] == color[j])
                return false;
        }
    }
    return true;
}
void Problem_5(vector<vector<bool>> nums, vector<int> color = vector<int>(n, 0), int i = 0)
{

    if (i == n)
    {
        if (validColoring(nums, color))
        {
            int c = std::set<int>(color.begin(), color.end()).size();

            if (c < countColors)
                countColors = c;
            return;
        }
        else
            return;
    }

    for (int j = 0; j < nums[0].size(); j++)
    {
        color[i] = j;
        (Problem_5(nums, color, i + 1));
        color[i] = 0;
    }
}
// Complete Problem_6_7
bool isValid(int i, int j, int n)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}

void Problem_6(vector<vector<int>> nums, int i = 0, int j = 0, vector<int> path = vector<int>(), vector<vector<bool>> isVisited = vector<vector<bool>>(3, vector<bool>(3, 0)), int curCost = 0)
{
    if (!isValid(i, j, 3) || isVisited[i][j])
        return;

    curCost += nums[i][j];
    path.push_back(nums[i][j]);

    if (curCost > minCost) // Problem 7
        return;

    if (i == 2 && j == 2)
    {
        if (curCost < minCost)
        {
            minPath = path;
            minCost = curCost;
        }
        return;
    }

    isVisited[i][j] = true;
    // General case
    Problem_6(nums, i + 1, j, path, isVisited, curCost);
    Problem_6(nums, i - 1, j, path, isVisited, curCost);
    Problem_6(nums, i, j + 1, path, isVisited, curCost);
    Problem_6(nums, i, j - 1, path, isVisited, curCost);
}
// Complete Problem_8
bool isTrue(vector<vector<char>> c, vector<bool> x)
{
    bool y;
    for (auto &r : c)
    {
        y = false;
        for (int i = 0; i < r.size(); i++)
        {
            if ((r[i] > 97 && x[i] == 1) || (r[i] <= 90 && x[i] == 0))
            {
                y = true;
            }
        }
        if (!y)
            return false;
    }
    return true;
}

void Problem_8(vector<vector<char>> c, vector<bool> x = vector<bool>(3, 0), int index = 0)
{
    // Base Case
    if (isTrue(c, x))
    {
        check = true;
        xC = x;
        return;
    }

    if (index >= n)
        return;

    // General Case
    if (check == 0)
    {
        Problem_8(c, x, index + 1);
        x[index] = true;
        Problem_8(c, x, index + 1);
    }
}
int main()
{

    // Testing Problem_8
    check = false;
    cin >> n;

    vector<vector<char>> c(n, vector<char>(3, '\0'));

    for (auto &r : c)
    {
        for (auto &e : r)
        {
            cin >> e;
        }
    }

    Problem_8(c);
    cout << check;
    cout << endl
         << endl;

    for (int i = 0; i < xC.size(); i++)
    {

        cout << xC[i] << endl;
    }

    return 0;
}
