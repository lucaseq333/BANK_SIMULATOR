#include <iostream>
#include <fmt/core.h>
#include <vector>

struct Client{
public:
    std::string name, surname, dateOfBirth;
    std::vector<int> PESEL[11];
    std::vector<int> PIN[4];
    Client(std::string const &name, std::string const &surname, std::string const &dateOfBirth, int const &PESEL, int const &PIN){

    }
};

struct BankAccount{
public:
    std::string login,password;
    double balance = 0;
    std::vector<int> PIN[4];
    BankAccount(std::string const &login, std::string const &password, double balance, int const &PIN){

    }
public:
    static auto setPINcode(){
        fmt::println("Set your 4-digits PIN code");
        int PINcode;
        std::cin >> PINcode;
        for(int i=0; i<=4; i++){
            std::cin >> PINcode;
        }
    }
};

auto createAccount(){

}

auto logIn(std::string const &login){
    fmt::println("Login: {}",login);
}

auto deposit(int PIN, double ammount, double balance){
    fmt::println("PIN {}, Money ammount {}",PIN,ammount);
    return ammount+=balance;
}

auto withdraw(int PIN, double ammount, double balance){
    &deposit;
}

auto accountBalance(){

}

int main() {
    std::vector<std::string> operations = {
            "Create account", "Log in", "Deposit/Withdraw", "Account balance", "Quit"
    };

    fmt::println("Welcome in Bank! Select 1-5:");
    for(int i=0; i<5; i++) {
        fmt::println("{}.{}", (i + 1), operations[i]);
    }

    int selectedNumber;
    std::cin >> selectedNumber;

    switch(selectedNumber){
        case 1:
            createAccount();
            break;
        case 2:
            fmt::println("");
            break;
        case 3:
            if(selectedNumber==3){
                std::cout << "Give credentials: ";
                int PIN, amount, balance;
                std::cin>>PIN>>amount>>balance;
                deposit(PIN, amount,balance);
            }
            break;
        case 4:
            fmt::println("");
            break;
        case 5:
            accountBalance();
            break;
        case 6:
            fmt::println("Thank you for using our services! Have a nice day!");
            break;

    }
}