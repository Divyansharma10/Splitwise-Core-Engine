#ifndef SPLITWISE_HPP
#define SPLITWISE_HPP
#include "Models.hpp"
#include <unordered_map>
#include <vector>
#include <string>

class Splitwise {
private:
    std::vector<User> users;
    std::vector<Transaction> transactions;
    std::unordered_map<std::string, double> balanceSheet;

public:
    void addUser(const std::string& name);
    void addTransaction(const Transaction& txn);
    const std::unordered_map<std::string, double>& getBalances() const;
    bool userExists(const std::string& name) const;
};

#endif // SPLITWISE_HPP