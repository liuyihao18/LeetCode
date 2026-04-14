// 2069_模拟行走机器人_II.cpp
#include "stdafx.h"
ustd

class Robot
{
	enum class Dir : uint8_t
	{
		East = 0,
		West = 1,
		North = 2,
		South = 3
	};

	static void rotate(Dir& dir)
	{
		constexpr array next = {Dir::North, Dir::South, Dir::West, Dir::East};
		dir = next[static_cast<size_t>(dir)];
	}

	static string toString(const Dir dir)
	{
		constexpr array strings = {"East", "West", "North", "South"};
		return strings[static_cast<size_t>(dir)];
	}

	int width = 0;
	int height = 0;
	int length = 0;
	int currPos = 0;
	vector<int> positions;
	vector<Dir> directions;

	bool probe(int& currX, int& currY, const Dir& dir) const
	{
		switch (dir)
		{
		case Dir::East:
			if (++currX >= width)
			{
				--currX;
				return false;
			}
			break;
		case Dir::West:
			if (--currX < 0)
			{
				++currX;
				return false;
			}
			break;
		case Dir::North:
			if (++currY >= height)
			{
				--currY;
				return false;
			}
			break;
		case Dir::South:
			if (--currY < 0)
			{
				++currY;
				return false;
			}
			break;
		}
		return true;
	}

	bool next(int& currX, int& currY, Dir& dir) const
	{
		while (!probe(currX, currY, dir))
		{
			rotate(dir);
		}
		return true;
	}

public:
	Robot(const int width, const int height) : width(width), height(height)
	{
		length = (width + height) * 2 - 4;
		positions.reserve(length + 1);
		directions.reserve(length + 1);
		int currX = 0;
		int currY = 0;
		auto dir = Dir::East;
		positions[0] = currX << 16 | currY;
		directions[0] = dir;
		for (int i = 1; i <= length; i++)
		{
			next(currX, currY, dir);
			positions[i] = currX << 16 | currY;
			directions[i] = dir;
		}
	}

	void step(const int num)
	{
		// 除了最开始的 0, 后面把值域移动到 [1, length]，从而保证初始点的两解
		currPos = (currPos + num - 1) % length + 1;
	}

	[[nodiscard]]
	vector<int> getPos() const
	{
		return {positions[currPos] >> 16, positions[currPos] & 0xffff};
	}

	[[nodiscard]]
	string getDir() const
	{
		return toString(directions[currPos]);
	}
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
