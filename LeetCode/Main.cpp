#include<vector>
#include<unordered_map>

using namespace std;

int main(void)
{

	return 0;
}

//Easy--two sum
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> result;
	unordered_map<int, int> map;
	for (int i = 0; i < result.size(); i++)
	{
		int diff = target - i;
		if (map.find(diff) != map.end())
		{
			result.push_back(map[diff] + 1);
			result.push_back(i + 1);
			return result;
		}
		map[nums[i]] = i;
	}
}


//Easy--hammingDistance
int hammingDistance(int x, int y)
{
	int diff = 0;
	int num = x ^ y;
	while (num)
	{
		diff++;
		num &= num - 1;
	}
}

//Easy--reverse 32bit signed integer
int reverse(int x)
{
	long long newnum = 0;
	while (x != 0)
	{
		int a = x % 10;
		newnum = newnum * 10 + a;
		x = x / 10;
	}

	if (newnum > INT_MAX || newnum < INT_MIN)
		return 0;
	else
		return newnum;
}

//Medium--set Matrix zeroes
void setZeroes(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();	

	int sourcePoint = matrix[0][0];
	bool isRow0Con0 = false;
	bool isCol0Con0 = false;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][0] == 0)
				isCol0Con0 = true;
			if (matrix[0][j] == 0)
				isRow0Con0 = true;
		}
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
			{
				matrix[i][j] = 0;
			}
		}
	}

	if (isRow0Con0 == true || sourcePoint == 0)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix[0][j] = 0;
		}
	}

	if (isCol0Con0 == true || sourcePoint == 0)
	{
		for (int i = 0; i < m; ++i)
		{
			matrix[i][0] = 0;
		}
	}
	
}
