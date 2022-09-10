#include "BankAccount.h"

using namespace std;


int main()
{
    cout << "-bankAccount1-" << endl;
    bankAccount bankAccount1("Okan", "Arik",15000, "05555555555");
    cout << "Name    : " << bankAccount1.getPersonName() << endl;
    cout << "Surname : " << bankAccount1.getPersonSurname() << endl;
    cout << "Phone   : " << bankAccount1.getPersonPhone() << endl;
    cout << "Balance : " << bankAccount1.getPersonBalance() << endl;

    cout << "\n-bankAccount2-" << endl;
    bankAccount bankAccount2 = bankAccount1;
    cout << "Name    : " << bankAccount2.getPersonName() << endl;
    cout << "Surname : " << bankAccount2.getPersonSurname() << endl;
    cout << "Phone   : " << bankAccount2.getPersonPhone() << endl;
    cout << "Balance : " << bankAccount2.getPersonBalance() << endl;

    bankAccount1.credit(50);
    bankAccount1.displayProfile();
    bankAccount1.withdraw(155);
    bankAccount1.displayProfile();

    bankAccount bankAccount3 = bankAccount1;
    bankAccount1.displayProfile();

    bankAccount1.sendMoney(bankAccount3, 14000);
    bankAccount1.displayProfile();
    bankAccount3.displayProfile();

    bankAccount bankAccount4("Kerem", "Arik");
    bankAccount1.sendMoney(bankAccount4, 895);
    bankAccount4.displayProfile();
    bankAccount1.displayProfile();

    return 0;
}
