#include <iostream>   
#include <vector>     
#include <string>     
#include <pthread.h>  
#include <mutex>      // For using mutex for thread synchronization
#include <fstream>    

// Structure to represent a financial transaction
struct Transaction {
    std::string type;    // "income" or "expense"
    double amount;       
    std::string description; 
};


std::mutex finance_mutex;                // Mutex to protect shared data
std::vector<Transaction> transactions;   // Vector to store transactions


void* addTransaction(void* arg) {
    Transaction* trans = (Transaction*)arg; // Cast the argument to a Transaction pointer
    std::lock_guard<std::mutex> lock(finance_mutex); // Lock the mutex to protect shared data
    transactions.push_back(*trans); // Add the transaction to the vector
    std::cout << (trans->type == "income" ? "Income" : "Expense") 
              << " added: " << trans->amount << " - " << trans->description << std::endl; // Print confirmation
    return nullptr; 
}


void displayBalance() {
    double balance = 0; 
    std::lock_guard<std::mutex> lock(finance_mutex); 
    for (const auto& trans : transactions) { // Iterate over all transactions
        if (trans.type == "income") {
            balance += trans.amount; // Add income to balance
        } else if (trans.type == "expense") {
            balance -= trans.amount; // Subtract expense from balance
        }
    }
    std::cout << "Current balance: " << balance << std::endl; 
}

// Function to save transactions to a file
void saveTransactions() {
    std::lock_guard<std::mutex> lock(finance_mutex); 
    std::ofstream file("transactions.txt"); // Open the file for writing
    for (const auto& trans : transactions) { // Iterate over all transactions
        file << trans.type << " " << trans.amount << " " << trans.description << std::endl; // Write transaction to file
    }
    file.close(); 
    std::cout << "Transactions saved to file." << std::endl; 
}

// Function to load transactions from a file
void loadTransactions() {
    std::lock_guard<std::mutex> lock(finance_mutex); 
    std::ifstream file("transactions.txt"); // Open the file for reading
    Transaction trans; // Temporary variable to hold a transaction
    while (file >> trans.type >> trans.amount) { // Read type and amount
        std::getline(file, trans.description); // Read description
        if (!trans.description.empty() && trans.description[0] == ' ')
            trans.description = trans.description.substr(1); // Remove leading space
        transactions.push_back(trans); // Add transaction to vector
    }
    file.close(); 
    std::cout << "Transactions loaded from file." << std::endl; 
}


int main() {
    pthread_t thread; 
    int choice; 
    loadTransactions(); 
    
    do {
        // Display menu options
        std::cout << "1. Add Income\n2. Add Expense\n3. Display Balance\n4. Save and Exit\nChoose an option: ";
        std::cin >> choice;         
        if (choice == 1 || choice == 2) {
            // If the user chooses to add income or expense
            Transaction trans; // Create a new transaction
            trans.type = (choice == 1) ? "income" : "expense"; // Set type based on user's choice
            std::cout << "Enter amount: ";
            std::cin >> trans.amount; // Read amount
            std::cin.ignore(); // Ignore the newline character
            std::cout << "Enter description: ";
            std::getline(std::cin, trans.description); 

            // Create a new thread to add the transaction
            pthread_create(&thread, nullptr, addTransaction, &trans);
            pthread_join(thread, nullptr); // Wait for the thread to finish
        } else if (choice == 3) {
            // If the user chooses to display balance
            displayBalance(); 
        }
    } while (choice != 4); // Continue until the user chooses to save and exit
    
    saveTransactions(); 
    return 0; 
}
