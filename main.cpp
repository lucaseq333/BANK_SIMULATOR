#include <iostream>
#include <fmt/core.h>
#include <vector>
#include <ctime>
#include <fstream>
#include <map>

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
    std::string name, surname, dateOfBirth, typeOfAccount;

    fmt::print("Your name: {}",name);
    std::cin >> name;

    fmt::print("Your surname: {}",surname);
    std::cin >> surname;

    fmt::print("Your date of birth: {}",dateOfBirth);
    std::cin >> dateOfBirth;

    fmt::print("Type of account (saving, standard): {}",typeOfAccount);
    std::cin >> typeOfAccount;

    std::time_t timestamp = std::time(nullptr);
    fmt::println("Congratulations {}! You have been successfully created your account on: {}",name,std::asctime(std::localtime(&timestamp)));
}

auto logIn(){
    std::string const login="login";
    std::string const password="password";

    std::string userLogin, userPassword;

    fmt::print("Type your login: {}",userLogin);
    std::cin >> userLogin;
    fmt::print("Type your password: {}",userPassword);
    std::cin >> userPassword;

    if(userLogin!=login | userPassword!=password){
        fmt::println("Wrong credentials!");
    } else {fmt::println("You have logged in successfully!");};
}

auto depositOrWithdraw(int PIN, double ammount, std::string operationName){
    if(operationName=="deposit"){
        fmt::println("chosen operation: deposit");
    }; if(operationName=="withdraw"){
        fmt::println("chosen operation: withdraw");
    };
    fmt::print("PIN {}, Money ammount: {}",PIN,ammount);
    double balance;
    return ammount+=balance;
}

auto accountBalance(){
    int PIN = 1234;
    int userPIN;
    int balance = 10000;

    fmt::print("Your PIN code: ");
    std::cin >> userPIN;
    if(PIN!=userPIN){
        fmt::print("Wrong PIN code! Try again: ");
        std::cin >> userPIN;
        if(PIN!=userPIN){fmt::println("Wrong PIN code!");}
    } else {
        std::time_t timestamp = std::time(nullptr);
        fmt::print("Balance of your account: {} PLN\n{}", balance,std::asctime(std::localtime(&timestamp)));
    }
}

auto convertCurrency(){
    std::map<std::string, double> currencies;
    currencies["USD"]=4.01;
    currencies["EUR"]=4.31;
    currencies["CHF"]=4.44;
    currencies["MXN"]=0.22;

    double ammount,currencyValue,*afterConversion;
    *afterConversion=ammount*currencyValue;

    return *afterConversion;
}

auto transfer(Client from, double amount, Client to){

}

int main() {
    std::vector<std::string> operations = {
            "Create account", "Log in", "Deposit/Withdraw", "Account balance", "Transfer", "Quit"
    };

    fmt::println("Welcome in Bank! Select 1-5:");
    for(int i=0; i<6; i++) {
        fmt::println("{}.{}", (i + 1), operations[i]);
    }

    int selectedNumber;
    std::cin >> selectedNumber;

    switch(selectedNumber){
        case 1:
            createAccount();
            break;
        case 2:
            logIn();
            break;
        case 3:
            if(selectedNumber==3){
                std::cout << "Give credentials:\nPIN: ";
                int PIN, amount;
                std::string operation;

                std::cin>>PIN;
                fmt::print("Deposit or withdraw?: ");
                std::cin>>operation;
                fmt::print("Ammount: ");
                std::cin>>amount;
                if(amount<=0){
                    fmt::println("Wrong data!");
                }
            }
            break;
        case 4:
            accountBalance();
            break;
        case 5:

        case 6:
            fmt::println("Thank you for using our services! Have a nice day!");
            break;
    }
}