#include <sys/types.h>

#include "assignment.h"

#include <algorithm>
#include <queue>

surrounded_regions_graph::surrounded_regions_graph(
    const std::vector<std::vector<char>> &edges)
    : nof_columns(edges.at(0).size())
    , nof_rows(edges.size())
{

	adj = std::vector<std::vector<char>>(nof_rows, std::vector<char>());
	visited = std::vector<std::vector<bool>>(nof_rows, std::vector<bool>());

	uint index = 0;
	std::for_each(edges.begin(), edges.end(), [&](auto _v) {
		std::for_each(_v.begin(), _v.end(), [&](char c) {
			adj.at(index).emplace_back(c);
			visited.at(index).emplace_back(false);
		});
		index++;
	});

	bfs();
}
auto
surrounded_regions_graph::get_adjacent_nodes(
    const std::pair<int, int> &coordinates) -> std::vector<std::pair<int, int>>
{
	auto result = std::vector<std::pair<int, int>>();
	auto row = coordinates.first, column = coordinates.second;

	if (column == 0 && row == 0) {
		result.emplace_back(row + 1, column);
		result.emplace_back(row, column + 1);
	} else if (column == nof_columns - 1 && row == nof_rows - 1) {
		result.emplace_back(row - 1, column);
		result.emplace_back(row, column - 1);
	} else if (row == 0) {
		if (column == nof_columns - 1) {
			result.emplace_back(row, column - 1);
			result.emplace_back(row + 1, column);
		} else {
			result.emplace_back(row, column - 1);
			result.emplace_back(row + 1, column);
			result.emplace_back(row, column + 1);
		}
	} else if (column == 0) {
		if (row == nof_rows - 1) {
			result.emplace_back(row - 1, column);
			result.emplace_back(row, column + 1);
		} else {
			result.emplace_back(row - 1, column);
			result.emplace_back(row, column + 1);
			result.emplace_back(row - 1, column);
		}
	} else if (row == nof_rows - 1) {
		if (column == 0) {
			result.emplace_back(row - 1, column);
			result.emplace_back(row, column + 1);
		} else {
			result.emplace_back(row - 1, column);
			result.emplace_back(row, column - 1);
			result.emplace_back(row, column + 1);
		}
	} else if (column == nof_columns - 1) {
		if (row == 0) {
			result.emplace_back(row - 1, column);
			result.emplace_back(row, column - 1);
		} else {
			result.emplace_back(row - 1, column);
			result.emplace_back(row, column - 1);
			result.emplace_back(row + 1, column);
		}
	} else {
		result.emplace_back(row - 1, column);
		result.emplace_back(row + 1, column);
		result.emplace_back(row, column + 1);
		result.emplace_back(row, column - 1);
	}
	return result;
}
void
surrounded_regions_graph::bfs()
{
	std::queue<std::pair<int, int>> q;

	q.push(std::pair<int, int>(0, 0));

	while (!q.empty()) {
		auto e = q.front();
		visited.at(e.first).at(e.second) = true;

		if (!should_not_be_flipped(e) &&
		    adj.at(e.first).at(e.second) == 'O')
			adj.at(e.first).at(e.second) = 'X';

		q.pop();

		auto adjacent_nodes = get_adjacent_nodes(e);

		for (auto &adjacent_node : adjacent_nodes) {
			if (!visited.at(adjacent_node.first)
				 .at(adjacent_node.second)) {
				if (should_not_be_flipped(e) &&
				    !should_not_be_flipped(adjacent_node)) {
					adj.at(adjacent_node.first)
					    .at(adjacent_node.second) = 'X';
				}
				q.push(adjacent_node);
			}
		}
	}
}

auto
surrounded_regions_graph::should_not_be_flipped(
    const std::pair<int, int> &coordinates) -> bool
{
	return (coordinates.first == 0 ||
		   coordinates.first == nof_columns - 1) ||
	    (coordinates.second == 0 || coordinates.second == nof_rows - 1);
}
