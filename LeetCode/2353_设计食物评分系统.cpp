// 2353_设计食物评分系统.cpp
#include "custom.h"
ustd

template<class K, class V>
class Heap {
protected:
    map<K, int> _m;
	vector<K> _key;
    vector<V> _value;
	int _size;
	int percolateDown(int i) {
		V tempValue = _value[i];
		K tempKey = _key[i];
		int j = (i + 1) << 1; // 右孩子
		while (j <= _size) {
			if (j == _size || (_value[j] < _value[j - 1] || _value[j] == _value[j - 1] && _key[j - 1] < _key[j])) {
				--j;
			}
			if (tempValue < _value[j] || tempValue == _value[j] && _key[j] < tempKey) {
				_value[i] = _value[j];
				_key[i] = _key[j];
				_m[_key[i]] = i;
				i = j;
				j = (i + 1) << 1;
			}
			else {
				break;
			}
		}
		_value[i] = tempValue;
		_key[i] = tempKey;
		_m[_key[i]] = i;
		return i;
	}
	int percolateUp(int i) {
		V tempValue = _value[i];
		K tempKey = _key[i];
		int j = (i - 1) >> 1; // 父节点
		while (j >= 0 && (_value[j] < tempValue || _value[j] == tempValue && tempKey < _key[j])) {
			_value[i] = _value[j];
			_key[i] = _key[j];
			_m[_key[i]] = i;
			i = j;
			j = (i - 1) >> 1;
		}
		_value[i] = tempValue;
		_key[i] = tempKey;
		_m[_key[i]] = i;
		return i;
	}
	void heapify() {
		for (int i = (_size >> 1) - 1; i >= 0; i--) {
			percolateDown(i);
		}
	}
public:
	Heap() : _size(0) {}
	Heap(vector<K> foods, vector<V> ratings) : _size(static_cast<int>(foods.size())), _key(foods), _value(ratings) {
		for (int i = 0; i < _key.size(); i++) {
			_m[_key[i]] = i;
		}
		heapify();
	}
	int size() const { return _size; }
	K getMax() const { return _key[0]; }
	void change(const K& k, const V& v) {
		if (_m.count(k)) {
			_value[_m[k]] = v;
			percolateUp(_m[k]);
			percolateDown(_m[k]);
		}
	}
};

class FoodRatings {
	map<string, vector<size_t>> index;
	map<string, Heap<string, int>> m;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
		for (size_t i = 0; i < cuisines.size(); i++) {
			index[cuisines[i]].push_back(i);
		}
		for (const auto& [k, v] : index) {
			vector<string> tempFoods;
			vector<int> tempRatings;
			for (size_t i : v) {
				tempFoods.push_back(foods[i]);
				tempRatings.push_back(ratings[i]);
			}
			m[k] = Heap<string, int>(tempFoods, tempRatings);
		}
    }

    void changeRating(string food, int newRating) {
		for (auto& [_, h] : m) {
			h.change(food, newRating);
		}
    }

    string highestRated(string cuisine) {
		return m[cuisine].getMax();
    }
};

/*
int main() {
	vector<string> foods = { "kimchi","miso","sushi","moussaka","ramen","bulgogi" };
	vector<string> cuisines = { "korean","japanese","japanese","greek","japanese","korean" };
	vector<int> ratings = { 9,12,8,15,14,7 };
	FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
	cout << obj->highestRated("korean") << endl;
	cout << obj->highestRated("japanese") << endl;
	obj->changeRating("sushi", 16); 
	cout << obj->highestRated("japanese") << endl;
	obj->changeRating("ramen", 16);
	cout << obj->highestRated("japanese") << endl;
	return 0;
}
*/
