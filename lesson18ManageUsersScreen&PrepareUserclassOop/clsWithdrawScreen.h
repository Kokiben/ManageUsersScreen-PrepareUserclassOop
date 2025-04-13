#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

class clsWithdrawScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient client)
	{
		cout << "\nClient card  : ";
		cout << "\n________________________";
		cout << "\nFirst Name    : " << client.FirstName;
		cout << "\nLast Name     : " << client.LastName;
		cout << "\nFullName      : " << client.FullName();
		cout << "\nEmail         : " << client.Email;
		cout << "\nPhone         : " << client.Phone;
		cout << "\nAcc.Number    : " << client.AccountNumber();
		cout << "\nPassword      : " << client.PinCode;
		cout << "\nBalance       : " << client.AccountBalance;
		cout << "\n_________________________";

	}
	static string _ReadClientInfo()
	{
		string AccountNumber = "";
		cout << "Please enter account number ?";
		cin >> AccountNumber;
		return AccountNumber;
	}

public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t WithDraw Screen \n");
		string AccountNumber = _ReadClientInfo();
		cout << "enter account number ? ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "client with this [" << AccountNumber << "] does  not exist ";
			AccountNumber = _ReadClientInfo();
		}

		clsBankClient client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(client1);

		double Amount = 0;
		cout << "Please enter withdraw amount ? ";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre sure yo want to perform this transaction?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (client1.WithDraw(Amount))
			{
				cout << "\nAmount withdraw is successfully .";
				cout << "\n New Balance is : " << client1.AccountBalance;

			}
			else
			{
				cout << "\ncannot withdraw , insuffecient balance !";
				cout << "\n Amount to withdraw is " << Amount;
				cout << "\nyour balance is " << client1.AccountBalance;
			}
		}
		else
		{
			cout << "\nOperation was cancelled !";
		}


	}
};

