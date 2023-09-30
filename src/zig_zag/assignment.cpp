#include "assignment.h"

#include <algorithm>
#include <cmath>
#include <queue>

static auto
queueify(std::string s) -> std::queue<char>
{
	std::queue<char> q;

	std::for_each(s.begin(), s.end(), [&q](char c) { q.emplace(c); });

	return q;
}

static void
handle_pattern(std::vector<std::vector<char>> &grid, std::queue<char> &q,
    uint nof_rows, uint accumulator_of_iterations,
    uint nof_elements_in_diagonals)
{
	auto acc = 0;

	auto column = (nof_rows - 1) * accumulator_of_iterations;

	// handle column
	while (acc != nof_rows) {
		if (!q.empty()) {
			auto e = q.front();

			q.pop();

			grid[column][acc] = e;
		}
		acc++;
	}

	acc = 0;

	// handle diagonal
	int tx = column + 1, ty = nof_rows - 2;
	while (acc != nof_elements_in_diagonals - 1) {
		if (!q.empty()) {
			auto e = q.front();

			q.pop();

			grid[tx][ty] = e;
		}
		tx++;
		ty--;
		acc++;
	}
}

auto
zig_zag(const std::string &s, int nof_rows) -> std::string
{

	auto nof_elements_in_diagonals = (uint)std::sqrt(
					     2 * (nof_rows * nof_rows + 1)) -
	    2;
	uint iterations { static_cast<uint>(
	    s.length() / nof_elements_in_diagonals) };
	auto accumulator_of_iterations = (uint)0;
	auto columns_needed = (iterations) * (nof_elements_in_diagonals - 1);
	std::vector<std::vector<char>> grid(columns_needed,
	    std::vector<char>(nof_rows, ' '));
	auto q = queueify(s);
	std::string res("");

	while (accumulator_of_iterations != iterations) {
		handle_pattern(grid, q, nof_rows, accumulator_of_iterations,
		    nof_elements_in_diagonals);

		accumulator_of_iterations++;
	}

	for (size_t x = 0; x < nof_rows; x++) {
		for (size_t y = 0; y < columns_needed; y++) {
			auto c = grid[y][x];

			if (c != ' ') {
				res += c;
			}
		}
	}

	return res;
}