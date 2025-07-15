#ifndef MODELS_HPP
#define MODELS_HPP
#include <string>
#include <vector>

struct User {
    std::string name;
    User(const std::string& name);
};

struct Transaction {
    std::string payer;
    double amount;
    std::vector<std::string> participants;

    Transaction(std::string payer, double amt, std::vector<std::string> parts);
};

#endif