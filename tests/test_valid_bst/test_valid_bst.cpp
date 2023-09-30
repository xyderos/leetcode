#include <cppunit/TestAssert.h>

#include "../../src/valid_bst/assignment.h"
#include "test_valid_bst.h"

static void
free_nodes(TreeNode *head)
{
	if (head->left)
		free_nodes(head->left);

	if (head->right)
		free_nodes(head->right);

	delete head;
}

void
test_valid_bst::test_valid_bst_with_valid_bst_should_be_okay()
{
	auto *t = new TreeNode(2, new TreeNode(1), new TreeNode(3));

	auto result = valid(t);

	CPPUNIT_ASSERT(result == true);

	free_nodes(t);
}

void
test_valid_bst::test_valid_bst_with_invalid_bst_should_not_be_okay()
{
	auto *t = new TreeNode(5, new TreeNode(1),
	    new TreeNode(4, new TreeNode(3), new TreeNode(6)));

	auto result = valid(t);

	CPPUNIT_ASSERT(result == false);

	free_nodes(t);
}
