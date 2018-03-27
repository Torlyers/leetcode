#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{

	return 0;
}

//1--Easy--two sum
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> result;
	unordered_map<int, int> map;
	for (int i = 0; i < result.size(); i++)
	{
		int diff = target - nums[i];
		if (map.count(diff))
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

//7--Easy--reverse 32bit signed integer
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

//73--Medium--set matrix zeros
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

//522--Medium--longest Uncommon subsequence
int findLUSlength(vector<string>& strs)
{
	for (int i = 0; i < strs.size(); ++i)
	{

	}
}

//236--Medium--lowest common ancestor of a binary tree
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if (root == NULL || root == p || root == q)
		return root;
	TreeNode* LeftNode = lowestCommonAncestor(root->left, p, q);
	TreeNode* RightNode = lowestCommonAncestor(root->right, p, q);

	if (LeftNode && RightNode)
		return root;
	else
		return LeftNode ? LeftNode : RightNode;
}

//390--medium--Elimination Game
int lastRemaining(int n) 
{
	return LeftToRight(n);	
}

int LeftToRight(int n)
{
	if (n <= 2)
		return n;
	return 2 * RightToLeft(n / 2);
}

int RightToLeft(int n)
{
	if (n <= 2)
		return 1;
	if (n % 2 == 1)
		return 2 * LeftToRight(n / 2);
	return 2 * LeftToRight(n / 2) - 1;
}

//539--Medium--Minimum Time Difference
int findMinDifference(vector<string>& timePoints)
{
	vector<int> timeminutes;
	
	for (int i = 0; i < timePoints.size(); ++i)
	{
		int hour = stoi(timePoints[i].substr(0, 2));
		int min = stoi(timePoints[i].substr(3, 2));
		int totalmin = hour * 60 + min - 720;
		timeminutes.push_back(totalmin);
	}

	int minTime = INT_MAX;
	sort(timeminutes.begin(), timeminutes.end());
	for (int i = 0; i < timeminutes.size(); i++)
	{
		int a = abs(timeminutes[i] - timeminutes[(i - 1 + timeminutes.size()) % timeminutes.size()]);
		int temp = min(a, 1440 - a);
		minTime = min(temp, minTime);
	}	
	return minTime;
}

//532--Easy--K diff pairs in an array
int findPairs(vector<int>& nums, int k) 
{
	int num = 0;
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); ++i)
	{
		

	}
}

