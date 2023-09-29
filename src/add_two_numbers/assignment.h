// https://leetcode.com/problems/add-two-numbers/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <optional>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode()
	    : val(0)
	    , next(nullptr)
	{
	}
	explicit ListNode(int x)
	    : val(x)
	    , next(nullptr)
	{
	}
	ListNode(int x, ListNode *n)
	    : val(x)
	    , next(n)
	{
	}

	~ListNode() = default;
};

auto add_two_numbers(ListNode *l1, ListNode *l2) -> ListNode *;
