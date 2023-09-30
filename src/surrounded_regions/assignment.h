// https://leetcode.com/problems/surrounded-regions/

#include <cstddef>
#include <vector>
class surrounded_regions_graph {
    public:
	std::vector<std::vector<char>> adj;
	std::vector<std::vector<bool>> visited;
	std::size_t nof_columns, nof_rows;

	explicit surrounded_regions_graph(
	    const std::vector<std::vector<char>> &edges);

	auto get_adjacent_nodes(const std::pair<int, int> &coordinates)
	    -> std::vector<std::pair<int, int>>;

	auto should_not_be_flipped(const std::pair<int, int> &coordinates)
	    -> bool;

	void bfs();
};
