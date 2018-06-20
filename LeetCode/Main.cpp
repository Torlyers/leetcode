#include<vector>
#include<list>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<iostream>
#include<ctype.h>

using namespace std;



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

	return 0;
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

	return 0;
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

int RightToLeft(int n);

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
int lastRemaining(int n) 
{
	return LeftToRight(n);	
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

	return 0;
}

//9--Easy--Palindrome Number
bool isPalindrome(int x)
{
	if (x < 0)
		return false;

	int o = x;
	int n = 0;
	while (x != 0)
	{
		n *= 10;
		n += x % 10;
		x /= 10;
	}

	if (n != o)
		return false;

	return true;
}

//13--Easy--Roman To Intager
int romanToInt(string s)
{
	unordered_map<char, int> value;
	value['M'] = 1000;
	value['D'] = 500;
	value['C'] = 100;
	value['L'] = 50;
	value['X'] = 10;
	value['V'] = 5;
	value['I'] = 1;

	int sum = value[s.back()];

	for (int i = s.length() - 2; i >= 0; --i)
	{
		if (value[s[i]] < value[s[i + 1]])
			sum -= value[s[i]];
		else
			sum += value[s[i]];
	}

	return sum;
}

//14--Easy--Longest Common Prefix
string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0)
		return "";

	if (strs.size() == 1)
		return strs[0];

	string s = strs[0];
	int loop = 0;
	for (int i = 1; i < strs.size(); ++i)
	{
		if (s.length() > strs[i].length())
		{
			int l = strs[i].length();
			s = s.substr(0, l);
			loop = l;
		}
		else
			loop = s.length();

		for (int j = 0; j < loop; ++j)
		{
			if (s[j] != strs[i][j])
			{
				s = s.substr(0, j);
				break;
			}
		}			
	}
	return s;
}

//20--Easy--Valid Parentheses
bool isValid(string s) 
{

	if (s.length() == 1)
		return false;

	unordered_map<char, int> map;
	map['('] = 1;
	map[')'] = 6;
	map['['] = 2;
	map[']'] = 5;
	map['{'] = 3;
	map['}'] = 4;

	vector<char> stack;
	for (int i = 0; i < s.length(); ++i)
	{
		if (map[s[i]] > 3)
		{
			if (stack.size() == 0 || map[s[i]] + map[stack.back()] != 7)
				return false;
			else
				stack.pop_back();			
		}
		else
		{
			stack.push_back(s[i]);
		}
	}

	if (stack.size() != 0)
		return false;

	return true;

}

//21--Easy--Merge Two Sorted Lists
struct ListNode {
	 int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{

	ListNode* root = new ListNode(0);
	ListNode* ptr = root;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			ptr->next = l1;
			l1 = l1->next;
		}
		else 
		{
			ptr->next = l2;
			l2 = l2->next;
		}

		ptr = ptr->next;
	}

	ptr->next = l1 ? l1 : l2;

	return root->next;
		
}

//26--Easy--Remove Duplicates from Sorted Array
int removeDuplicates(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;

	int temp = nums[0];
	int length = 1;
	
	for (auto iter = nums.begin() + 1; iter < nums.end(); ++iter)
	{
		if (temp != *iter)
		{
			temp = *iter;
			nums[length] = temp;
			length++;
		}		
	}
	return length;
}

//27--Easy--Remove Element
int removeElement(vector<int>& nums, int val)
{
	int length = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == val)
			length++;
		else
			nums[i - length] = nums[i];
	}
	return nums.size() - length;
}

//28--Easy--Implement strStr()
int strStr(string haystack, string needle)
{
	if (needle.length() == 0 || haystack == needle)
		return 0;

	if (haystack.length() < needle.length())
		return -1;

	int index = -1;

	for (int i = 0; i <= haystack.length() - needle.length(); ++i)
	{
		if (needle == haystack.substr(i, needle.length()))
		{
			index = i;
			break;
		}	
	}

	return index;
}

//35--Easy--Search Insert Position
//classical binary search. Remember it!!
int searchInsert(vector<int>& nums, int target)
{
	int i = 0;
	int j = nums.size() - 1;
	int temp = 0;

	while (i <= j)
	{
		temp = (j - i) / 2 + i;
		if (target == nums[temp])
		{
			return temp;
		}
		else if (target < nums[temp])
		{
			j = temp - 1;
		}
		else
		{
			i = temp + 1;
		}
	}

	return i;
	
}

//38--Easy--Count and Say
string countAndSay(int n)
{
	return "";
}

//53--Easy--Subarray
int maxSubArray(vector<int>& nums)
{
	if (nums.size() == 1)
		return nums[0];

	int max = nums[0];
	int sum = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		sum = nums[i];
		if (sum > max)
			max = sum;
		for (int j = i + 1; j < nums.size(); ++j)
		{
			sum += nums[j];
			if (sum > max)
				max = sum;
		}
	}

	return max;
}

//58--Easy--Length of Last Word
int lengthOfLastWord(string s) 
{
	int ans = 0;
	bool start = false;

	for (int i = s.length() - 1; i >= 0; --i)
	{
		if (s[i] == ' ')
		{
			if (!start)
				continue;
			else
				break;
		}
		else
		{
			if (!start)
				start = true;
			ans += 1;
		}	
	}

	return ans;
}

//66--Easy--Plus One
vector<int> plusOne(vector<int>& digits)
{	
	int e = digits.size() - 1;
	digits[e]++;
	for (int i = e; i > 0; --i)
	{
		if (digits[i] >= 10)
		{
			digits[i] -= 10;
			digits[i - 1]++;
		}
		else
			break;
	}

	if (digits[0] >= 10)
	{
		for (auto d : digits)
			d = 0;
		digits[0] = 1;
		digits.push_back(0);
	}
	
	return digits;	
}



//67--Easy--Add Binary
string addBinary(string a, string b)
{
	auto ia = a.length() >= b.length() ? a.end() : b.end();
	auto ib = a.length() >= b.length() ? b.end() : a.end();
	int l = min(a.length(), b.length());
	bool bl = false;
	string s = "";

	while (l > 0)
	{
		if (*ia == *ib)
		{
			if (bl)
				s.insert(s.begin(), '1');
			else
				s.insert(s.begin(), '0');

			if (*ia == 0)
				bl = false;
			else
				bl = true;
		}
		else
		{
			if (bl)
				s.insert(s.begin(), '0');
			else
				s.insert(s.begin(), '1');
		}
		ia--;
		ib--;
		l--;
	}

	if (bl)
	{

	}
		
	return s;
}

//69--Easy--Sqrt(x)
int mySqrt(int x)
{
	long r = x;
	while (r*r > x)
		r = (r + x / r) / 2;
	return r;
}

//10--Easy--Climbing Stairs
int climbStairs(int n)
{
	int a = 1, b = 1;

	while (n--)
	{
		int temp = a + b;
		a = b;
		b = temp;
	}

	return a;
}

//83--Easy--Remove Duplicates from Sorted List
ListNode* deleteDuplicates(ListNode* head)
{
	if (!head)
		return head;
	
	ListNode* ptr = head;
	while (ptr->next)
	{
		if (ptr->val == ptr->next->val)
			ptr->next = ptr->next->next;
		else
			ptr = ptr->next;
	}
	return head;
}

//88--Easy--Merge Sorted Array
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	auto i1 = nums1.end() - 1;
	
	while (*i1-- == 0)
		nums1.pop_back();
	
	i1 = nums1.begin();
	auto i2 = nums2.begin();

	vector<int> temp;
	while (i1 != nums1.end() || i2 != nums2.end())
	{
		if (*i1 <= *i2)
			temp.push_back(*i1++);
		else
			temp.push_back(*i2++);
	}

	if (i1 == nums1.end())
		while (i2 != nums2.end())
			temp.push_back(*i2++);
	else
		while (i1 != nums1.end())
			temp.push_back(*i1++);

	nums1.swap(temp);
}

// struct TreeNode 
// {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

//100--Easy--Same Tree
bool isSameTree(TreeNode* p, TreeNode* q) 
{
	bool ans = true;

	if ((!p && q) || (p && !q))
		ans = false;
	else if (p && q)
	{
		if (p->val != q->val)
			return false;
		else
			ans = isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
	return ans;
}

//101--Easy--Symmetric Tree
bool isSymmetric(TreeNode* root) 
{
	if (!root)
		return true;

	TreeNode* l = root->left;
	TreeNode* r = root->right;

	if ((l && !r) || (!l && r))
		return false;
	else if(l && r)
	{
		if (l->val != r->val)
			return false;
		
		if ((!l->left && r->right) || (l->left && !r->right) || (!l->right && r->left) || (l->right && !r->left))
			return false;

		if (l->left && l->right && r->left && r->right)
		{
			if (l->left->val != r->right->val || l->right->val != r->left->val)
				return false;
			else
				return isSymmetric(l) && isSymmetric(r);
		}

		if (l->left && r->right)
		{
			if (l->left->val != r->right->val)
				return false;
			else
				return isSymmetric(l) && isSymmetric(r);
		}
		else if (l->right && r->left)
		{
			if (l->right->val != r->left->val)
				return false;
			else 
				return isSymmetric(l) && isSymmetric(r);
		}		
	}

	return true;
}

//104--Easy--Maximum Depth of Binary Tree
int maxDepth(TreeNode* root)
{
	return root==nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
}



//107--Easy--Binary Tree Level Order Traversal II
void addnum(TreeNode* root, vector<vector<int>> & v, int i)
{
	if (root == nullptr)
		return;

	if (v.size() == i)
		v.push_back(vector<int>());

	v[i].push_back(root->val);

	if (root->left)
		addnum(root->left, v, i + 1);

	if (root->right)
		addnum(root->right, v, i + 1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> v;
	v.push_back(vector<int>());
	if (root == nullptr)
		return v;
	v[0].push_back(root->val);
	addnum(root, v, 1);
	return v;
}

//108--Easy--Convert Sorted Array to Binary Search Tree
TreeNode* sortedArrayToBST(vector<int>& nums)
{
	return new TreeNode(0);
	
	
}

//110--Easy--Balanced Binary Tree
int CalculateDepth(TreeNode* root)
{
	return root == nullptr ? 0 : max(CalculateDepth(root->left), CalculateDepth(root->right)) + 1;
}

bool isBalanced(TreeNode* root)
{
	if (root == nullptr)
		return true;

	if(root->left != nullptr && root->right != nullptr)
		return abs(CalculateDepth(root->left) - CalculateDepth(root->right)) <= 1;
	else
	{
		if (CalculateDepth(root) > 2)
			return false;
		else
			return true;
	}
}

//111--Easy--Minimum Depth of Binary Tree
int minDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr)
		return minDepth(root->right) + 1;
	if (root->right == nullptr)
		return minDepth(root->left) + 1;
	return min(minDepth(root->left), minDepth(root->right)) + 1;
}

//112--Easy--Path Sum
bool hasPathSum(TreeNode* root, int sum)
{
	if (root == nullptr)
		return false;
	if (root->val == sum && root->left == nullptr && root->right == nullptr)
		return true;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

//118--Easy--Pascal's Triangle
vector<vector<int>> generate(int numRows) 
{
	vector<vector<int>> v(numRows);

	for (int i = 0; i < numRows; ++i)
	{
		v[i].resize(i + 1);
		v[i][0] = v[i][i] = 1;

		for (int j = 1; j < i; ++j)
			v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
	}

	return v;
}

//119--Easy--Pascal's Triangle II
vector<int> getRow(int rowIndex) 
{
	vector<int> v(rowIndex);
	v[0] = 1;

	for (int i = 0; i <= rowIndex; ++i)
		for (int j = i; j > 0; --j)
			v[j] = v[j] + v[j - 1];

	return v;
}

//121--Easy--Best Time to Buy and Sell Stock
int maxProfit(vector<int>& prices)
{
	if (prices.size() < 2)
		return 0;

	int ans = 0;
	int num = INT_MAX;
	for (int i = 0; i < prices.size() - 1; ++i)
	{
		if (prices[i] >= num)
			continue;
		else
			num = prices[i];

		for (int j = i + 1; j < prices.size(); ++j)
		{
			if(prices[j] <= prices[i])
				continue;

			if(prices[j] - prices[i] > ans)
				ans = prices[j] - prices[i];
		}
	}

	return ans;
}

//122--Easy--Best Time to Buy and Sell Stock II
int maxProfit1(vector<int>& prices)
{
	int ans = 0; 
	for (int i = 1; i < prices.size(); ++i)
		ans += max(prices[i] - prices[i - 1], 0);
	return ans;
}

//125--Easy--Valid Palindrome
bool isPalindrome(string s)
{
	int i = 0;
	int j = s.size() - 1;

	while (i < j)
	{
		while (!isalnum(s[i]) && i < j)
			++i;
		while (!isalnum(s[j]) && i < j)
			--j;

		if (s[i] < 'a')
			s[i] += 32;

		if (s[j] < 'a')
			s[j] += 32;

		if (s[i] != s[j])
			return false;
		else
		{
			++i;
			--j;
		}
	}

	return true;
}

//136--Easy--Single Number
//从头到尾异或一遍
int singleNumber(vector<int>& nums) 
{
	int ans = 0;
	for (int i = 0; i < nums.size(); ++i)
		ans = ans ^ nums[i];
	return ans;
}

//144--Easy--Linked List Cycle
bool hasCycle(ListNode *head)
{
	ListNode* p1 = head;
	ListNode* p2 = head;

	while (p1 != nullptr && p2 != nullptr && p2->next != nullptr)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2)
			return true;
	}

	return false;
}

int main(void)
{
	
	bool b = isPalindrome("A man, a plan, a canal: Panama");

	cout << b << endl;

	getchar();

	return 0;
}

