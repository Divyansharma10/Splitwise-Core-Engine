#include "Balancer.hpp"
#include <algorithm>
#include <iostream>

void minimizeTransactions(const std::unordered_map<std::string, double>& balances) {
    std::vector<BalanceEntry> creditors, debtors;

    for (const auto& entry : balances) {
        if (entry.second > 0.01)
            creditors.push_back({entry.first, entry.second});
        else if (entry.second < -0.01)
            debtors.push_back({entry.first, entry.second});
    }

    std::sort(creditors.begin(), creditors.end(), [](const auto& a, const auto& b) { return a.amount > b.amount; });
    std::sort(debtors.begin(), debtors.end(), [](const auto& a, const auto& b) { return a.amount < b.amount; });

    int i = 0, j = 0;
    while (i < creditors.size() && j < debtors.size()) {
        double settleAmount = std::min(creditors[i].amount, -debtors[j].amount);
        std::cout << debtors[j].user << " owes " << creditors[i].user << ": " << settleAmount << "\n";

        creditors[i].amount -= settleAmount;
        debtors[j].amount += settleAmount;

        if (creditors[i].amount < 0.01) ++i;
        if (debtors[j].amount > -0.01) ++j;
    }
}
