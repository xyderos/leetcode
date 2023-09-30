#include <cppunit/TestAssert.h>

#include "../../src/surrounded_regions/assignment.h"
#include "test_surrounded_regions.h"

#include <algorithm>
#include <iterator>

void
test_surrounded_regions::first_test()
{
	std::vector<std::vector<char>> v = { { 'X', 'X', 'X', 'X' },
		{ 'X', 'O', 'O', 'X' }, { 'X', 'X', 'O', 'X' },
		{ 'X', 'O', 'X', 'X' } };

	auto g = surrounded_regions_graph(v);

	g.bfs();

	for (auto c1 = g.adj.begin(); c1 != g.adj.end(); c1++) {

		auto dst1 = std::distance(g.adj.begin(), c1);
		for (auto c2 = c1->begin(); c2 != c1->end(); c2++) {

			auto dst2 = std::distance(c1->begin(), c2);
			char val = g.adj.at(dst1).at(dst2);

			if (dst1 == 3 && dst2 == 1) {
				CPPUNIT_ASSERT_EQUAL(val, 'O');
				continue;
			}

			CPPUNIT_ASSERT_EQUAL(val, 'X');
		}
	}
}
