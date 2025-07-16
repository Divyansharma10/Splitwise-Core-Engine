# Splitwise Core Engine

A backend-only C++ project that implements the core functionality of a Splitwise-style expense-sharing system. This system handles the internal logic for managing users, tracking group expenses, and optimizing the number of transactions needed to settle balances efficiently. Designed to demonstrate backend logic and algorithmic thinking without involving any frontend, database, or networking components.

---

## Features

* Add and manage users
* Record expenses for individuals and groups
* Maintain and update individual balances
* Compute minimal transactions to settle debts within a group
* Focused on clean data structures and modular backend logic

---

## Technologies Used

* C++ (STL, object-oriented programming)
* Command-line interface for input/output (no UI)
* Header files and classes to separate logic and definitions

---

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/Divyansharma10/Splitwise-Core-Engine
cd Splitwise-Core-Engine
```

### 2. Compile the Project

```bash
g++ -std=c++17 main.cpp -o splitwise
```

### 3. Run the Executable

```bash
./splitwise
```

You can input commands to simulate adding users, expenses, and triggering balance settlements.

## Example Usage

```text
> add_user Alice
> add_user Bob
> add_user Charlie

> record_expense Alice 300 2 Bob Charlie
> show_balances

Bob owes Alice: 150
Charlie owes Alice: 150

> minimize_transactions
Bob pays Alice: 150
Charlie pays Alice: 150
```
