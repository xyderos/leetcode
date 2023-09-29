#include <cppunit/TestAssert.h>

#include "../../src/add_two_numbers/assignment.h"
#include "test_add_two_numbers.h"

#include <algorithm>
#include <sstream>

static auto
validate_nodes(ListNode *l1, ListNode *l2) -> bool
{
	std::stringstream s1;
	std::stringstream s2;
	std::string r1, r2;

	auto t = l1;

	while (l1->next) {
		s1 << t->val;
		l1 = l1->next;
	}

	r1 = s1.str();

	t = l2;

	while (l2->next) {
		s2 << t->val;
		l2 = l2->next;
	}
	r2 = s2.str();

	return s1.str() == s2.str();
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
test_add_two_numbers::test_add_two_numbers_first_case()
{
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	auto *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	auto expected = new ListNode(8);
	expected->next = new ListNode(0);
	expected->next->next = new ListNode(7);

	auto result = add_two_numbers(l1, l2);

	CPPUNIT_ASSERT(validate_nodes(result, expected));

	free_nodes(l1);
	free_nodes(l2);
	free_nodes(expected);
	free_nodes(result);
}

void
test_add_two_numbers::test_add_two_numbers_second_case()
{
	auto *l1 = new ListNode(0);

	auto *l2 = new ListNode(0);

	auto expected = new ListNode(0);

	auto result = add_two_numbers(l1, l2);

	CPPUNIT_ASSERT(validate_nodes(result, expected));

	free_nodes(l1);
	free_nodes(l2);
	free_nodes(expected);
	free_nodes(result);
}

void
test_add_two_numbers::test_add_two_numbers_third_case()
{
	auto *l1 = new ListNode(9);
	l1->next = new ListNode(9);
	l1->next->next = new ListNode(9);
	l1->next->next->next = new ListNode(9);
	l1->next->next->next->next = new ListNode(9);
	l1->next->next->next->next->next = new ListNode(9);
	l1->next->next->next->next->next->next = new ListNode(9);

	auto *l2 = new ListNode(9);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(9);
	l2->next->next->next = new ListNode(9);

	auto *expected = new ListNode(1);
	expected->next = new ListNode(0);
	expected->next->next = new ListNode(0);
	expected->next->next->next = new ListNode(0);
	expected->next->next->next->next = new ListNode(9);
	expected->next->next->next->next->next = new ListNode(9);
	expected->next->next->next->next->next->next = new ListNode(9);
	expected->next->next->next->next->next->next->next = new ListNode(8);

	auto result = add_two_numbers(l1, l2);

	CPPUNIT_ASSERT(validate_nodes(result, expected));

	free_nodes(l1);
	free_nodes(l2);
	free_nodes(expected);
	free_nodes(result);
}
