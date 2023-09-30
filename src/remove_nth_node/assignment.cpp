#include "assignment.h"

#include <cstdlib>

static auto
remove_nth_from_front(ListNode *head, ListNode *previous, int position)
    -> ListNode *
{
	if (position == 1) {
		previous->next = head->next;

		free(head);

		return previous->next;
	}

	return remove_nth_from_front(head->next, head, position - 1);
}

auto
remove_nth_from_back(ListNode *head, int position) -> ListNode *
{

	int len = 1;
	auto tmp = head;

	while (tmp->next) {
		len++;
		tmp = tmp->next;
	}

	return remove_nth_from_front(head, nullptr, len - position + 1);
}
