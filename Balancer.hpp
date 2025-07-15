#ifndef BALANCER_HPP
#define BALANCER_HPP
#include <vector>
#include <string>
#include <unordered_map>

struct BalanceEntry {
    std::string user;
    double amount;

    bool operator<(const BalanceEntry& other) const;
};

void minimizeTransactions(const std::unordered_map<std::string, double>& balances);

#endif // BALANCER_HPP
