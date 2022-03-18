// 2043_简易银行系统.cpp
#include "custom.h"
ustd

#define INDEX(account) static_cast<size_t>(account - 1)

class Bank {
    vector<long long> _balance;
    bool check(int account) {
        if (INDEX(account) < 0 || INDEX(account) >= _balance.size()) {
            return false;
        }
        return true;
    }
public:
    Bank(vector<long long>& balance) : _balance(balance) {
        
    }

    bool transfer(int account1, int account2, long long money) {
        if (!check(account1) || !check(account2)) {
            return false;
        }
        if (_balance[INDEX(account1)] >= money) {
            _balance[INDEX(account1)] -= money;
            _balance[INDEX(account2)] += money;
            return true;
        }
        else {
            return false;
        }
    }

    bool deposit(int account, long long money) {
        if (!check(account)) {
            return false;
        }
        _balance[INDEX(account)] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!check(account)) {
            return false;
        }
        if (_balance[INDEX(account)] >= money) {
            _balance[INDEX(account)] -= money;
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
