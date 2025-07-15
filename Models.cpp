#include "Models.hpp"

User::User(const std::string& name) : name(name) {}
Transaction::Transaction(std::string payer, double amt, std::vector<std::string> parts)
    : payer(payer), amount(amt), participants(std::move(parts)) {}