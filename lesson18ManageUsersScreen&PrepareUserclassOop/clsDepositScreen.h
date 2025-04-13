#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsDepositScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient client)
	{
		cout << "\nCLient card  : ";
		cout << "\n_______________________";
		cout << "\nFirst Name      : " << client.FirstName;
		cout << "\nLast Name       : " << client.LastName;
		cout << "\nFull Name       : " << client.FullName();
		cout << "\nEmail           : " << client.Email;
		cout << "\nPhone           : " << client.Phone;
		cout << "\nAcc.Number      : " << client.AccountNumber();
		cout << "\nPassword        : " << client.PinCode;
		cout << "\nBalance         : " << client.AccountBalance;
		cout << "\n______________________\n";
	}
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "Please enter account number ? ";
		return AccountNumber;
	}
public:
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t Deposit Screen");
		string AccountNumber = "";
		cout << "\nPlease enter account Number ?";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found , choose another one.";
			AccountNumber == clsInputValidate::ReadString();
		}
		clsBankClient client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(client1);

		double Amount = 0;
		cout << "\nPlease enter deposit amount?";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure you want to perform this transaction ? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			client1.Deposit(Amount);
			cout << "\nAmount deposited successfully!";
			cout << "\nNew Balance is : " << client1.AccountBalance;

		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

	}
};

