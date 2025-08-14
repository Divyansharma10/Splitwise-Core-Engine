#include <iostream>
#include "Splitwise.hpp"
#include "Balancer.hpp"
#include "utils.hpp"
using namespace std;

int main() {
    Splitwise engine;
    int userCount;

    cout << "Enter number of users: ";
    cin >> userCount;
    cin.ignore();

    for (int i = 0; i < userCount; ++i) {
        string name;
        cout << "Enter name of user " << i + 1 << ": ";
        getline(std::cin, name);
        engine.addUser(name);
    }

    int txnCount;
    cout << "\nEnter number of transactions: ";
    cin >> txnCount;
    cin.ignore();

    for (int i = 0; i < txnCount; ++i) {
        string payer, line;
        double amount;

        cout << "\nTransaction " << i + 1 << ":\n";
        cout << "Payer name: ";
        getline(std::cin, payer);

        cout << "Amount: ";
        cin >> amount;
        cin.ignore();

        cout << "Enter participants (comma-separated): ";
        getline(std::cin, line);
        vector<string> participants = split(line, ',');

        if (!engine.userExists(payer)) {
            cerr << "Error: Payer '" << payer << "' is not a registered user.\n";
            --i;
            continue;
        }

        bool allValid = true;
        for (const auto& p : participants) {
            if (!engine.userExists(p)) {
                cerr << "Error: Participant '" << p << "' is not a registered user.\n";
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

    cout << "\nSimplified Balances:\n";
    auto balances = engine.getBalances();
    minimizeTransactions(balances);

    return 0;
}
