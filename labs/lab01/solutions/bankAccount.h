class bankAccount
{
    public:
        bankAccount();
        bankAccount(double amount);
        ~bankAccount();
        
        double withdraw(double amount);
        double deposit(double amount);
        double getBalance();

    private:
        double balance;
};