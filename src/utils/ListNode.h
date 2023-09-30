#pragma once

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