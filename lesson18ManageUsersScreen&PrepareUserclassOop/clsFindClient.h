#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"

class clsFindClient: protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card : ";
		cout << "\n_________________________";
		cout << "\nFirst Name    : " << Client.FirstName;
		cout << "\nLast Name     : " << Client.LastName;
		cout << "\nFull Name     : " << Client.FullName();
		cout << "\nEmail         : " << Client.Email;
		cout << "\nPhone         : " << Client.Phone;
		cout << "\nAcc.Number    : " << Client.AccountNumber();
		cout << "\nPassword      : " << Client.PinCode;
		cout << "\nBalance       : " << Client.AccountBalance;
		cout << "\n___________________________";

	}
public:
	static void ShowFindClient()
	{
		_DrawScreenHeader("\t Find Client Screen ");
		string AccountNumber;
		cout << "\nEnter Account Number ? ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found , choose another one.";
			AccountNumber = clsInputValidate::ReadString();

		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		if (!Client.IsEmpty())
		{
			cout << "\nclient found :-) \n";
		}
		else
		{
			cout << "\n client was not found :-( \n";
		}
		_PrintClient(Client);
	}
};

