// 1391_检查网格中是否存在有效路径.cpp
#include "stdafx.h"
ustd

class Solution
{
	enum class Direction : uint8_t
	{
		None,
		South,
		North,
		West,
		East
	};

	[[nodiscard]] static string_view toString(const Direction direction)
	{
		switch (direction)
		{
		case Direction::None:
			return "None"sv;
		case Direction::South:
			return "South"sv;
		case Direction::North:
			return "North"sv;
		case Direction::West:
			return "West"sv;
		case Direction::East:
			return "East"sv;
		}
		return "None"sv;
	}

	[[nodiscard]] static Direction opposite(const Direction direction) 
	{
		switch (direction)
		{
		case Direction::None:
			return Direction::None;
		case Direction::South:
			return Direction::North;
		case Direction::North:
			return Direction::South;
		case Direction::West:
			return Direction::East;
		case Direction::East:
			return Direction::West;
		}
		return Direction::None;
	}

	[[nodiscard]] static pair<int, int> delta(const Direction direction)
	{
		switch (direction)
		{
		case Direction::None:
			return make_pair(0, 0);
		case Direction::South:
			return make_pair(1, 0);
		case Direction::North:
			return make_pair(-1, 0);
		case Direction::West:
			return make_pair(0, -1);
		case Direction::East:
			return make_pair(0, 1);
		}
		return make_pair(0, 0);
	}

	struct Street
	{
		Direction direction1;
		Direction direction2;

		[[nodiscard]] Direction go(const Direction from) const
		{
			if (from == direction1)
			{
				return direction2;
			}
			if (from == direction2)
			{
				return direction1;
			}
			return Direction::None;
		}

		[[nodiscard]] int getIdx(const Direction direction) const
		{
			if (direction == direction1)
			{
				return 0;
			}
			if (direction == direction2)
			{
				return 1;
			}
			return -1;
		}
	};

	static Street getStreet(const int i)
	{
		const Street streets[] = {
			{.direction1 = Direction::None, .direction2 = Direction::None},
			{.direction1 = Direction::West, .direction2 = Direction::East}, // Street1
			{.direction1 = Direction::North, .direction2 = Direction::South}, // Street2
			{.direction1 = Direction::West, .direction2 = Direction::South}, // Street3
			{.direction1 = Direction::East, .direction2 = Direction::South}, // Street4
			{.direction1 = Direction::West, .direction2 = Direction::North}, // Street5
			{.direction1 = Direction::East, .direction2 = Direction::North}, // Street6
		};
		return streets[i];
	}

public:
	bool hasValidPath(const vector<vector<int>>& grid)
	{
		const int m = static_cast<int>(grid.size());
		const int n = static_cast<int>(grid.front().size());
		vector visited(m, vector(n, vector(2, false)));
		struct State
		{
			int i = -1;
			int j = -1;
			Direction to;
		};
		stack<State> st;
		const auto [direction1, direction2] = getStreet(grid[0][0]);
		st.emplace(0, 0, direction2);
		st.emplace(0, 0, direction1);
		while (!st.empty())
		{
			const auto [i, j, to] = st.top();
			st.pop();
			if (i == m - 1 && j == n - 1) return true;
			const Street currStreet = getStreet(grid[i][j]);
			if (visited[i][j][currStreet.getIdx(to)]) continue;
			visited[i][j][currStreet.getIdx(to)] = true;
			const auto [deltaI, deltaJ] = delta(to);
			const int newI = i + deltaI;
			const int newJ = j + deltaJ;
			if (newI >= 0 && newI < m && newJ >= 0 && newJ < n)
			{
				const Direction newFrom = opposite(to);
				const Street newStreet = getStreet(grid[newI][newJ]);
				const Direction newTo = newStreet.go(newFrom);
				if (newTo != Direction::None)
				{
					st.emplace(newI, newJ, newTo);
				}
			}
		}
		return false;
	}
};
