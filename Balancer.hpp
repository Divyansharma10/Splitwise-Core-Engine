#ifndef BALANCER_HPP
#define BALANCER_HPP
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
struct BalanceEntry {
    string user;
    double amount;

    bool operator<(const BalanceEntry& other) const;
};

void minimizeTransactions(const unordered_map<string, double>& balances);

#endif // BALANCER_HPP
