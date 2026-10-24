// 2409_统计共同度过的日子数.cpp
#include "stdafx.h"
ustd

class Solution {
	static int toTimestamp(const int month, const int day) {
		constexpr std::array<int, 12> dayOfMonth
		{
			31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
		};
		return accumulate(begin(dayOfMonth), begin(dayOfMonth) + month - 1, day);
	}

	static int toTimestamp(const string& str) {
		const string month = str.substr(0, 2);
		const string day = str.substr(3, 2);
		return toTimestamp(stoi(month), stoi(day));
	}

public:
	int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
		const int arriveAliceTimestamp = toTimestamp(arriveAlice);
		const int leaveAliceTimestamp = toTimestamp(leaveAlice);
		const int arriveBobTimestamp = toTimestamp(arriveBob);
		const int leaveBobTimestamp = toTimestamp(leaveBob);
		return max(
			0,
			min(leaveAliceTimestamp, leaveBobTimestamp) - max(arriveAliceTimestamp, arriveBobTimestamp) + 1);
	}
};
