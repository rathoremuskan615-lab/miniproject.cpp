#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Expense {
private:
    int id;
    string title;
    float amount;

public:
    // Constructor
    Expense(int i = 0, string t = "", float a = 0.0) {
        id = i;
        title = t;
        amount = a;
    }

    void input() {
        cout << "Enter Expense ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Amount: ";
        cin >> amount;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Amount: " << amount << endl;
        cout << "----------------------" << endl;
    }

    int getId() {
        return id;
    }

    string getData() {
        return to_string(id) + "," + title + "," + to_string(amount);
    }
};

void addExpense() {
    Expense e;
    e.input();

    ofstream file("expenses.txt", ios::app);
    file << e.getData() << endl;
    file.close();

    cout << "Expense Added Successfully!\n";
}

void viewExpenses() {
    ifstream file("expenses.txt");
    string line;

    cout << "\n--- All Expenses ---\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void searchExpense() {
    ifstream file("expenses.txt");
    string line;
    int searchId;
    bool found = false;

    cout << "Enter ID to search: ";
    cin >> searchId;

    while (getline(file, line)) {
        int fileId = stoi(line.substr(0, line.find(",")));

        if (fileId == searchId) {
            cout << "Expense Found: " << line << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Expense Not Found!\n";

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== Personal Finance Tracker =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Search Expense\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                searchExpense();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}