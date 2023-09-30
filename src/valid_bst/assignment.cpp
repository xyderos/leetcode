#include "assignment.h"

auto
valid(TreeNode *head) -> bool
{
	TreeNode *l = head->left, *r = head->right;

	if (l && l->left)
		valid(l);

	if (r && (l->val < head->val && r->val > head->val)) {
		return true;
	}

	if (r && r->left)
		valid(r);

	return false;
}
