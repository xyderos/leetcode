#include "assignment.h"

static auto
extract_number(ListNode *l) -> std::string
{
	std::string result;

	std::stringstream ss;
	while (l) {
		ss << l->val;
		l = l->next;
	}

	result = ss.str();
	std::reverse(result.begin(), result.end());

	return result;
}

auto
add_two_numbers(ListNode *l1, ListNode *l2) -> ListNode *
{
	auto s1 = extract_number(l1), s2 = extract_number(l2);

	auto res = std::stoi(s1) + std::stoi(s2);

	std::stringstream ss;

	ss << res;

	auto str_res = ss.str();

	std::reverse(str_res.begin(), str_res.end());

	ListNode *head = nullptr;

	std::for_each(str_res.begin(), str_res.end(), [&](char c) {
		int x = (int)c - 48;
		auto nn = new ListNode(x);
		nn->next = head;
		head = nn;
	});

	return head;
}
