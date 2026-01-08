#include<iostream>
using namespace std;
void createAccount(int accNo[], int pin[],float balance[], int *total);
int login(int accNo[], int pin[], int total);
void atmMenu(float balance[], int index);

int main(){
    int accNo[10], pin[10];
    float balance[10];
    int totalAccounts = 0;
    int choice;
    do {
        cout << "\n===== MINI BANKING SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Login to Account\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            createAccount(accNo, pin, balance, &totalAccounts);
            break;

        case 2: {
            int index = login(accNo, pin, totalAccounts);
            if (index != -1) {
                atmMenu(balance, index);
            }
            break;
        }

        case 3:
            cout << "Thank you for using the banking system!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }while (choice != 3);
    return 0;

}
void createAccount(int accNo[], int pin[],float balance[], int *total){
    if (*total>=10){
        cout<<"Account limit reached!\n";
        return;
    }
    cout<<"Enter account number: ";
    cin>>accNo[*total];
    cout<<"Set your PIN: ";
    cin>>pin[*total];
    cout<<"Enter initial balance: ";
    cin>>balance[*total];
    (*total)++;

    cout<<"Account created successfully!\n";

}
int login(int accNo[], int pin[], int total){
    int accno, enteredPin;
    cout<<"Enter account number: ";
    cin>>accno;
    cout<<"Enter PIN: ";
    cin>>enteredPin;
    for (int i=0;i<total;i++){
        if (accNo[i]==accno)
        {
            cout<<"Entered PIN: "<<enteredPin<<endl;
            if (pin[i]==enteredPin){
                cout<<"Login successful!\n";
                return i;
            }    
            else{
                cout<<"Incorrect PIN!\n";
                return -1;
            }
    }
}
    cout<<"Account not found!\n";
    return -1;
}

void atmMenu(float balance[], int index){
    int choice;
    float amount;
    do {
        cout << "\n===== ATM MENU =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Current Balance: $" << balance[index] << endl;
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                if (amount > 0){
                balance[index] += amount;
            }

                else{
                cout << "Invalid amount!\n";
            }

                break;
             case 3:  
               cout << "Enter amount to withdraw: $";
               cin >> amount;
               if (amount > 0 && amount <= balance[index]){
                     balance[index] -= amount;
                     cout << "Withdrawal successful!\n";
                                   } 
                else{
                        cout<< "Insufficient balance or invalid amount!\n";
                }                   
                break;
                case 4:
                    cout << "Logged out successfully!\n";
                    break;
                    
                default:
                    cout << "Invalid choice!\n";    

    } 
 }while (choice != 4);
}


