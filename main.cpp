#include <iostream>
#include "Splitwise.hpp"
#include "Balancer.hpp"
#include "utils.hpp"

int main() {
    Splitwise engine;
    int userCount;

    std::cout << "Enter number of users: ";
    std::cin >> userCount;
    std::cin.ignore();

    for (int i = 0; i < userCount; ++i) {
        std::string name;
        std::cout << "Enter name of user " << i + 1 << ": ";
        std::getline(std::cin, name);
        engine.addUser(name);
    }

    int txnCount;
    std::cout << "\nEnter number of transactions: ";
    std::cin >> txnCount;
    std::cin.ignore();

    for (int i = 0; i < txnCount; ++i) {
        std::string payer, line;
        double amount;

        std::cout << "\nTransaction " << i + 1 << ":\n";
        std::cout << "Payer name: ";
        std::getline(std::cin, payer);

        std::cout << "Amount: ";
        std::cin >> amount;
        std::cin.ignore();

        std::cout << "Enter participants (comma-separated): ";
        std::getline(std::cin, line);
        std::vector<std::string> participants = split(line, ',');

        if (!engine.userExists(payer)) {
            std::cerr << "Error: Payer '" << payer << "' is not a registered user.\n";
            --i;
            continue;
        }

        bool allValid = true;
        for (const auto& p : participants) {
            if (!engine.userExists(p)) {
                std::cerr << "Error: Participant '" << p << "' is not a registered user.\n";
                allValid = false;
                break;
            }
        }

        if (!allValid) {
            --i;
            continue;
        }

        engine.addTransaction(Transaction(payer, amount, participants));
    }

    std::cout << "\nSimplified Balances:\n";
    auto balances = engine.getBalances();
    minimizeTransactions(balances);

    return 0;
}
