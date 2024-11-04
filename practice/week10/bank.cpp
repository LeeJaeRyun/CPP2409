#include <iostream>
#include <string>
using namespace std;

class BankAccount {
  private:
    string accountHolderName;
    double balance;
  public:
    BankAccount(string name, double initialBalance){
      accountHolderName = name;
      balance = initialBalance;
    }
    double getBalance() const{
      return balance;
    }
    void deposit(double amount){
      if(amount>0){
        balance+=amount;
        cout<<amount<<"deposited. Current balance: "<<balance<<endl;
      }
    }
    void withdraw(double amount){
      if(amount>0&&amount<=balance){
        balance-=amount;
        cout << amount << "withdrawn. Current balance: "<<balance<<endl;
      }else {
        cout << "Insufficient balance or invalid amount!"<<endl;
      }
    }
};

int main(){
  BankAccount myAccount("Alice", 1000);
  cout << "Initial Balance: " << myAccount.getBalance() <<endl;

  myAccount.deposit(500);
  myAccount.withdraw(200);

  // myAccount.balance = 5000;
  // myAccount.accountHolderName="Bob";

  return 0;
}