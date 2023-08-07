#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <regex>
#include <exception>


class Wallet
{
private:
    std :: string cardHolderName;
    std :: string cardNumber;
    double balance;

public:
    Wallet(const std::string& cardHolderName, const std::string& cardNumber, double balance) {
        this->cardHolderName = cardHolderName;
        this->cardNumber = cardNumber;
        this->balance = balance;
    }

    std::string getCardHolderName() const {
        return cardHolderName;
    }

    std :: string getCardNumber() const {
        return cardNumber;
    }

    void deposit(double amount) {
        balance += amount;
    }

    double getBalance() const {
        return balance;
    }

};



class Expense {
private:
    std :: string ExpenseCategory;
    double amount;
    std::string date;

public:

    Expense() = default;

    Expense(const std::string& ExpenseCategory, double amount, std::string date) : ExpenseCategory(ExpenseCategory), amount(amount), date(date) {}

    std :: string getCategory() const {
        return ExpenseCategory;
    }

    double getAmount() const {
        return amount;
    }

    std :: string getDate() const {
        return date;
    }

};

class FinanceManager {
private:
    std :: vector<Wallet> wallets;
    std :: vector<Expense> expenses;


public:
    void addWallet(const Wallet& wallet) {
        wallets.push_back(wallet);
    }

    void addExpenses() {
        if (wallets.empty()){
            std :: cout << "You dont have any cards. Add card first." << std::endl;
            return;
        }

        double amount{};
        std :: string ExpenseCategory;
        std :: string date;

        try {
            std::cout << "Enter category of expense: ";
            std::cin >> ExpenseCategory;
            std::cin.ignore();
            if (!ExpenseCategoryRegex(ExpenseCategory))
                throw std :: invalid_argument("Invalid category entered!");
        } catch (std::exception& e) {
            std :: cout << "Error: " << e.what() << std :: endl;
        }

        try {
            std::cout << "Enter date of expense(DD-MM-YYYY): ";
            std::cin >> date;
            std::cin.ignore();
            if (!dateRegex(date))
                throw std::invalid_argument("Invalid date entered!");
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std :: endl;
        }
        try {
            std::cout << "Enter the amount spent: ";
            std::cin >> amount;
            if (!std::cin) {
                throw std::invalid_argument("Invalid amount entered!");
            }
        }catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std :: endl;
        }

        Expense newExpense(ExpenseCategory,amount,date);

        expenses.push_back(newExpense);

        std :: cout << "Expense added." << std::endl;
    }

    void saveToFile(const std::string& filename) const {
        std :: ofstream file(filename);
        if(file.is_open()){
            for(const auto& wallet : wallets) {
                file << "Wallet | " << wallet.getCardHolderName() << " | " << wallet.getCardNumber() << " | " << wallet.getBalance() << std :: endl;
            }
            for (const auto& expense : expenses) {
                file << "Expense | " << expense.getCategory() << " | " << expense.getAmount() << " | " << expense.getDate() << std::endl;
            }
        }

        file.close();

    }

    bool dateRegex(const std::string& date){
        std :: regex dateR(R"(^(0?[1-9]|[12][0-9]|3[01])-(0?[1-9]|1[0-2])-(\d{4})$)");
        return std :: regex_match(date,dateR);
    }
    bool ExpenseCategoryRegex(const std::string& expenseCategory) {
        std::regex expenseCategoryR(R"(^[a-zA-Z\s\-]{2,30}$)");
        return std::regex_match(expenseCategory, expenseCategoryR);
    }
    bool AmountRegex(const std::string& amount) {
        std::regex amountR(R"(^\d+(\.\d+)?$)");
        return std::regex_match(amount, amountR);
    }


    void addExpensesConsole(const Expense& expense)
    {
        expenses.push_back(expense);

    }

    void expensesReport()
    {
        double totalAmount{};
        int choice{};
        std :: string date;

        std :: cout << "What report would you like to see?" << std::endl
                    << "1.By day" << std::endl
                    << "2.By month" << std :: endl;
        std :: cin >> choice;

        switch(choice) {
            case 1:
            {
                std :: cout << "Enter date(DD-MM-YYYY): ";
                std :: cin >> date;

                for (const auto& expense : expenses)
                {
                    if (expense.getDate() == date) {
                        std :: cout << expense.getCategory() << " - " << expense.getAmount() << std :: endl;
                        totalAmount += expense.getAmount();
                    }
                }
                std :: cout << "In total spent on " << date << ": " << totalAmount << " " << std::endl;

                break;
            }
            case 2:
            {
                std :: string month;
                std :: cout << "Enter month and year(MM-YYYY): ";
                std :: cin >> month;

                for (const auto& expense : expenses)
                {
                    if (expense.getDate().substr(3,7) == month) {
                        std :: cout << expense.getCategory() << " - " << expense.getAmount() << std::endl;
                        totalAmount += expense.getAmount();
                    }
                }
                std :: cout << "In total spent on " << month << " month " << totalAmount << " " << std::endl;

                break;
            }
            default:
            {

                break;
            }
        }
    }

    void top3ExpensesReportByMonth()
    {
        std :: string month;
        std :: cout << "Enter month to get TOP 3 expenses(MM-YYYY): " ;
        std :: cin >> month;

        std :: vector<Expense> expenseByMonth;

        for (const auto& expense : expenses)
        {
            if (expense.getDate().substr(3,7) == month)
            {
                expenseByMonth.push_back(expense);
            }
        }

        if (expenseByMonth.empty())
        {
            std :: cout << "No expense in this month" << std::endl;
            return;
        }

        std :: sort( expenseByMonth.begin(), expenseByMonth.end(), [](const Expense& first, const Expense& second )
        {
            return first.getAmount() > second.getAmount();
        });

        std :: cout << "Top 3 expenses for month: " << std::endl;
        for (size_t i = 0; i < 3; ++i)
        {
            const auto& expense = expenseByMonth[i];
            std :: cout << "#" << i + 1 << " " << expense.getCategory() << expense.getAmount() << std::endl;
        }

    }

    void top3CategoryByMonth()
    {
        std :: string month;
        std :: cout << "Enter month to get TOP 3 categories(MM-YYYY): " ;
        std :: cin >> month;

        std::map<std::string, double> expensesByCategory;


        for (const auto& expense : expenses)
        {
            if (expense.getDate().substr(3,7) == month)
            {
                expensesByCategory[expense.getCategory()] += expense.getAmount();
            }
        }

        if (expensesByCategory.empty())
        {
            std :: cout << "No expense in this month" << std:: endl;
            return;
        }

        std :: vector<std :: pair<std::string, double>> sortedCategories;
        for (const auto& entry : expensesByCategory)
        {
            sortedCategories.push_back(entry);
        }

        std :: sort(sortedCategories.begin(), sortedCategories.end(), [](const std::pair<std::string, double>& a, const std:: pair<std::string, double>& b) {
            return a.second > b.second;
        });

        std :: cout << "Top 3 categories: " << std:: endl;
        for (size_t i = 0; i < 3; ++i) {
            const auto& category = sortedCategories[i];
            std :: cout << "#" << i + 1 << " " << category.first << ": " << category.second << std::endl;
        }
    }


    void createNewCard() {
        std :: string cardHolderName;
        std :: string cardNumber;
        double balance;

        try {
            std::cout << "Enter Card Holder name: ";
            std::cin >> cardHolderName;
            std::cin.ignore();
            if (!cardHolderNameRegex(cardHolderName))
                throw std :: invalid_argument("Invalid card holder name!");
        } catch(const std::exception& e) {
            std :: cout << "Error: " << e.what() << std::endl;
        }

        try {
            std::cout << "Enter Card Number: ";
            std::cin >> cardNumber;
            std::getchar();
            if (!cardNumberRegex(cardNumber))
                throw std :: invalid_argument("Invalid card number!");
        } catch(const std::exception& e) {
            std::cout << "Error: " << e.what() << std :: endl;
        }

        try {
            std::cout << "Enter Balance: ";
            std::cin >> balance;
            std::getchar();
            if (!std :: cin) {
                throw std :: invalid_argument("Invalid balance enter!");
            }
            if (balance < 0) {
                throw std :: invalid_argument("Balance cannot be negative!");
            }
        } catch(const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std :: endl;
        }


        Wallet newCard(cardHolderName, cardNumber, balance);
        wallets.push_back(newCard);
        std :: cout << "New card added! " << std::endl;


    }



    bool cardHolderNameRegex(const std::string& cardHolderName){
        std :: regex cardHolderNameR(R"(^[a-zA-Z\s\-]{2,50}$)");
        return std::regex_match(cardHolderName, cardHolderNameR);
    }
    bool cardNumberRegex(const std::string& cardNumber){
        std :: regex cardNumberR(R"(^\d{16}$)");
        return std :: regex_match(cardNumber,cardNumberR);
    }
    bool balanceRegex(const std::string& balance){
        std :: regex balanceR(R"(^\d+(\.\d+)?$)");
        return std:: regex_match(balance, balanceR);
    }

    void depositMoneyToCard()
    {
        if (wallets.empty())
        {
            std :: cout << "You dont have any cards. Add card to deposit money." << std::endl;
            return;
        }

        for(size_t i = 0; i < wallets.size(); i++)
        {
            std :: cout << i + 1 << '.' << " Card Number: " << wallets[i].getCardNumber() << "   Balance: " << wallets[i].getBalance() << std::endl;
        }

        int choice{};
        do {
            std::cout << "Enter number of card to deposit money( 0 to cancel ): ";
            std::cin >> choice;
        } while (choice < 0 || choice > wallets.size());

        if (choice == 0){
            return;
        }

        double moneyToDeposit{};
        std :: cout << "Enter the amount to replenish: ";
        std::cin >> moneyToDeposit;

        wallets[choice - 1].deposit(moneyToDeposit);
        std :: cout << "Balance replenished successfully!" << std::endl;

        std :: cout << "New balance : " << wallets[choice - 1].getBalance() << std::endl;

    }
};






int main()
{
    int choice{};
    FinanceManager manager;

    Wallet walletTest("Test", "1234567812345678", 1000);
    manager.addWallet(walletTest);

    Expense expenseTest("Food", 150, "03-04-2022");
    Expense expenseTest1("Cinema", 90, "12-04-2022");
    Expense expenseTest2("Flowers", 190, "18-04-2022");
    Expense expenseTest3("Shopping", 50, "29-04-2022");
    Expense expenseTest4("Products", 200, "30-04-2022");

    Expense expenseTest5("Products", 120, "05-05-2022");
    Expense expenseTest6("Shopping", 103, "05-05-2022");
    Expense expenseTest7("Food", 101, "10-05-2022");
    Expense expenseTest8("Products", 89, "10-05-2022");
    Expense expenseTest9("Shopping", 29, "19-05-2022");
    Expense expenseTest10("Food", 88, "21-05-2022");
    Expense expenseTest11("Shopping", 100, "22-05-2022");
    Expense expenseTest12("Products", 222, "22-05-2022");
    Expense expenseTest13("Cinema", 500, "29-05-2022");

    manager.addExpensesConsole(expenseTest);
    manager.addExpensesConsole(expenseTest1);
    manager.addExpensesConsole(expenseTest2);
    manager.addExpensesConsole(expenseTest3);
    manager.addExpensesConsole(expenseTest4);
    manager.addExpensesConsole(expenseTest5);
    manager.addExpensesConsole(expenseTest6);
    manager.addExpensesConsole(expenseTest7);
    manager.addExpensesConsole(expenseTest8);
    manager.addExpensesConsole(expenseTest9);
    manager.addExpensesConsole(expenseTest10);
    manager.addExpensesConsole(expenseTest11);
    manager.addExpensesConsole(expenseTest12);
    manager.addExpensesConsole(expenseTest13);




    std :: cout << "Welcome to personal finance management system!" << std::endl;

    try {
        do {
            std::cout << "----------------------------------------------" << std::endl;
            std::cout << "1. Create a new debit card." << std::endl;
            std::cout << "2. Deposit money." << std::endl;
            std::cout << "3. Entering costs." << std::endl;
            std::cout << "4. Generation of reports on costs by category." << std::endl;
            std::cout << "5. Generate Top 3 expenses by month." << std::endl;
            std::cout << "6. Generate Top 3 categories by month." << std::endl;
            std::cout << "7. End of program." << std::endl;
            std::cout << "----------------------------------------------" << std::endl;

            std::cout << "Choose what you need to do: ";
            std::cin >> choice;
            std :: getchar();

            switch (choice) {
                case 1: {
                    manager.createNewCard();
                    break;
                }
                case 2: {
                    manager.depositMoneyToCard();
                    break;
                }
                case 3: {
                    manager.addExpenses();
                    break;
                }
                case 4: {
                    manager.expensesReport();
                    break;
                }
                case 5: {
                    manager.top3ExpensesReportByMonth();
                    break;
                }
                case 6: {
                    manager.top3CategoryByMonth();
                    break;
                }
                case 7: {
                    std::cout << "End program. See you later." << std::endl;
                    break;
                }
                default: {
                    std::cout << "Incorrect choice! Re-enter your choice: " << std::endl;
                    break;

                }
            }
            manager.saveToFile("finances.csv");


        } while (choice != 7);
    }catch (const std::exception& excep) {
        std :: cout << "Error: " << excep.what() <<  std::endl;
    }








    return 0;
}
