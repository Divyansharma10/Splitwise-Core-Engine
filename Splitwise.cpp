#include "Splitwise.hpp"

void Splitwise::addUser(const std::string& name) {
    users.emplace_back(name);
    balanceSheet[name] = 0.0;
}

void Splitwise::addTransaction(const Transaction& txn) {
    transactions.push_back(txn);
    double splitAmount = txn.amount / txn.participants.size();

    for (const auto& participant : txn.participants) {
        if (participant != txn.payer) {
            balanceSheet[participant] -= splitAmount;
            balanceSheet[txn.payer] += splitAmount;
        }
    }
}

bool Splitwise::userExists(const std::string& name) const {
    return balanceSheet.find(name) != balanceSheet.end();
}

const std::unordered_map<std::string, double>& Splitwise::getBalances() const {
    return balanceSheet;
}
