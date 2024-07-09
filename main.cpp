#include <iostream>
#include <fmt/core.h>
#include <vector>
#include <ctime>
#include <fstream>
#include <map>
#include <set>

struct Client{
    std::string name, surname, dateOfBirth;
    std::vector<int> PESEL[11];
    std::vector<int> PIN[4];

    /*Client(std::string const &name, std::string const &surname, std::string const &dateOfBirth, int const &PESEL, int const &PIN){

    }*/

};

struct BankAccount{
    std::string login,password, typeOfAccount;
    double balance = 0;

    auto setPINcode(){
        fmt::println("Set your 4-digits PIN code: ");
        int PINcode;
        std::cin >> PINcode;
        for(int i=0; i<=4; i++){
            std::cin >> PINcode;
        }
    }

};

std::fstream paymentHistory("paymentHistory.txt");

auto createAccount(){
    const std::vector<Client> clients;
    Client client;
    BankAccount bankAccount;

    std::string name, surname, dateOfBirth, typeOfAccount;
    std::vector<int> PESEL[11];

    fmt::print("Your name: {}",name);
    std::cin >> client.name;

    fmt::print("Your surname: {}",surname);
    std::cin >> client.surname;

    fmt::print("Your date of birth: {}",dateOfBirth);
    std::cin >> client.dateOfBirth;

    fmt::print("Type of account (saving, standard): {}",typeOfAccount);
    std::cin >> bankAccount.typeOfAccount;

    std::time_t timestamp = std::time(nullptr);
    auto time = std::asctime(std::localtime(&timestamp));

    fmt::println("Congratulations {}! You have been successfully created your account on: {}",client.name,time);

    try{
        std::fstream file("file.txt");
        if(file.is_open(), file.out | file.app){
            file << "" << client.name << " " << client.surname << " " << client.dateOfBirth << "\nAccount type: " << bankAccount.typeOfAccount << "\nCreated: " << time;
            file.close();
        }
    } catch (error_t) {
        fmt::println("Fatal error!");
    }
}

bool isLogged = false;

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
    } else {
        isLogged=true;
        fmt::println("You have logged in successfully!");
    };
}

double balance = 0;

auto depositOrWithdraw(int PIN, double amount, std::string operationName){
    auto &myBalance = balance;

    std::cout << "Declared amount: ";
    std::cin >> amount;

    std::cout << "Operation: ";
    std::cin >> operationName;

    if(operationName=="deposit"){
        fmt::println("Chosen operation: deposit");
        if(amount>0){
            balance+=amount;
            fmt::println("Balance: {} PLN",balance);
        }
    } if(operationName=="withdraw"){
        fmt::println("Chosen operation: withdraw");
        if(amount>0 && amount<=balance){
            balance-=amount;
            fmt::println("Balance: {} PLN",balance);
        }
    } else{
        fmt::print("Wrong operation!");
    }
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
        if(PIN!=userPIN){
            fmt::println("Wrong PIN code!");
        }
    } else {
        std::time_t timestamp = std::time(nullptr);
        fmt::print("Balance of your account: {} PLN\n{}", balance,std::asctime(std::localtime(&timestamp)));
    }
}

auto transfer(BankAccount from, double amount, BankAccount to){

    if(amount>0 && amount<=from.balance){
        from.balance-=amount;
        to.balance+=amount;
    } else{
        fmt::println("Wrong operation! Try again.");
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

auto main() -> int {
    std::vector<std::string> operations = {
            "Create account", "Log in", "Deposit/Withdraw", "Account balance", "Transfer", "Quit"
    };

    fmt::println("Welcome in Bank! Select 1-6:");
    for(int i=0; i<6; i++) {
        fmt::println("{}.{}", (i + 1), operations[i]);
    }

    int selectedNumber;
    std::cin >> selectedNumber;

    std::set<Client> clientsSet;

    std::set<BankAccount> accountsSet;
    BankAccount bankAccount1;
    BankAccount bankAccount2;
    bankAccount1.balance=1000;
    bankAccount2.balance=5000;

    transfer(bankAccount1,2000,bankAccount2);

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
                depositOrWithdraw(PIN,amount,operation);
                std::cin>>operation;
                std::cin>>amount;
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