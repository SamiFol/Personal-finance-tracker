#include <iostream>
#include <vector>
#include <string>
#include <pthread.h>
#include <mutex>
#include <fstream>

struct Transaction {
    std::string type; // "income" or "expense"
    double amount;
    std::string description;
};

std::mutex finance_mutex;
std::vector<Transaction> transactions;

void* addTransaction(void* arg) {
    Transaction* trans = (Transaction*)arg;
    std::lock_guard<std::mutex> lock(finance_mutex);
    transactions.push_back(*trans);
    std::cout << (trans->type == "income" ? "Income" : "Expense") 
              << " added: " << trans->amount << " - " << trans->description << std::endl;
    return nullptr;
}

void displayBalance() {
    double balance = 0;
    std::lock_guard<std::mutex> lock(finance_mutex);
    for (const auto& trans : transactions) {
        if (trans.type == "income") {
            balance += trans.amount;
        } else if (trans.type == "expense") {
            balance -= trans.amount;
        }
    }
    std::cout << "Current balance: " << balance << std::endl;
}

void saveTransactions() {
    std::lock_guard<std::mutex> lock(finance_mutex);
    std::ofstream file("transactions.txt");
    for (const auto& trans : transactions) {
        file << trans.type << " " << trans.amount << " " << trans.description << std::endl;
    }
    file.close();
    std::cout << "Transactions saved to file." << std::endl;
}

void loadTransactions() {
    std::lock_guard<std::mutex> lock(finance_mutex);
    std::ifstream file("transactions.txt");
    Transaction trans;
    while (file >> trans.type >> trans.amount) {
        std::getline(file, trans.description);
        if (!trans.description.empty() && trans.description[0] == ' ')
            trans.description = trans.description.substr(1);
        transactions.push_back(trans);
    }
    file.close();
    std::cout << "Transactions loaded from file." << std::endl;
}

int main() {
    pthread_t thread;
    int choice;
    loadTransactions();
    
    do {
        std::cout << "1. Add Income\n2. Add Expense\n3. Display Balance\n4. Save and Exit\nChoose an option: ";
        std::cin >> choice;
        
        if (choice == 1 || choice == 2) {
            Transaction trans;
            trans.type = (choice == 1) ? "income" : "expense";
            std::cout << "Enter amount: ";
            std::cin >> trans.amount;
            std::cin.ignore();
            std::cout << "Enter description: ";
            std::getline(std::cin, trans.description);

            pthread_create(&thread, nullptr, addTransaction, &trans);
            pthread_join(thread, nullptr);
        } else if (choice == 3) {
            displayBalance();
        }
    } while (choice != 4);
    
    saveTransactions();
    return 0;
}
