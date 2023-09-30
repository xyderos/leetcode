#include <cppunit/TestAssert.h>

#include "../../src/remove_nth_node/assignment.h"
#include "test_remove_nth_node.h"

#include <algorithm>
#include <sstream>

static auto
validate_nodes(ListNode *l1, ListNode *l2) -> bool
{

	std::string r1, r2;

	while (l1) {
		r1 += std::to_string(l1->val);
		l1 = l1->next;
	}

	while (l2) {
		r2 += std::to_string(l2->val);
		l2 = l2->next;
	}

	return r1 == r2;
}

static void
free_nodes(ListNode *l)
{
	ListNode *curr = l;

	while (curr != nullptr) {
		ListNode *node = curr;
		curr = curr->next;

		delete node;
	}
}

void
test_remove_nth_node::test_remove_nth_node_from_long_list()
{
	auto *l = new ListNode(1);
	l->next = new ListNode(2);
	l->next->next = new ListNode(3);
	l->next->next->next = new ListNode(4);
	l->next->next->next->next = new ListNode(5);

	remove_nth_from_back(l, 2);

	auto *expected = new ListNode(1);
	expected->next = new ListNode(2);
	expected->next->next = new ListNode(3);
	expected->next->next->next = new ListNode(5);

	CPPUNIT_ASSERT(validate_nodes(l, expected));

	free_nodes(l);
	free_nodes(expected);
}

void
test_remove_nth_node::test_remove_nth_node_from_single_list()
{
	auto *l = new ListNode(1);
	l->next = new ListNode(2);

	remove_nth_from_back(l, 1);

	auto *expected = new ListNode(1);

	CPPUNIT_ASSERT(validate_nodes(l, expected));

	free_nodes(l);
	free_nodes(expected);
}
