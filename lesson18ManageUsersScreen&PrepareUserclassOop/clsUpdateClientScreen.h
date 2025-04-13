#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"

 class clsUpdateClientScreen : protected clsScreen
{
	 static void _PrintClient(clsBankClient Client)
	 {
		 cout << "\nClient Card  : ";
		 cout << "\n_____________________________";
		 cout << "\nFirst Name   : " << Client.FirstName;
		 cout << "\nLast  Name   : " << Client.LastName;
		 cout << "\nFull Name    : " << Client.FullName();
		 cout << "\nEmail        : " << Client.Email;
		 cout << "\nPhone        : " << Client.Phone;
		 cout << "\nAcc.Number   : " << Client.AccountNumber();
		 cout << "\nPassword     : " << Client.PinCode;
		 cout << "\nBalance      : " << Client.AccountBalance;
	 }
	 static void _ReadClientInfo(clsBankClient& Client)
	 {
		 cout << "ENter First Name   : " << Client.FirstName;
		 Client.FirstName = clsInputValidate::ReadString();

		 cout << "\nEnter Last Name  : " << Client.LastName;
		 Client.LastName = clsInputValidate::ReadString();

		 cout << "\nEnter Email      : ";
		 Client.Email = clsInputValidate::ReadString();

		 cout << "\nEnter phone      : ";
		 Client.Phone = clsInputValidate::ReadString();

		 cout << "\nEnter pincode    : ";
		 Client.PinCode = clsInputValidate::ReadString();

		 cout << "\nENter Balance    : "; 
		 Client.AccountBalance = clsInputValidate::ReadDblNumber();

	 }
public:
	static void ShowUpdateCLientScreen()
	{
		_DrawScreenHeader("\t Update CLient screen");

		string AccountNumber = "";

		cout << "\nENter Account number : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found , choose another one.";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient client = clsBankClient::Find(AccountNumber);
		_PrintClient(client);

		cout << "\nAre you sure you want to update this client? y/n";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n update CLient info :  ";
			cout << "\n_____________________________\n";

			_ReadClientInfo(client);
			clsBankClient::enSaveResults SaveResults;
			SaveResults = client.Save();

			switch (SaveResults)
			{
			case clsBankClient::enSaveResults::svSucceeded:
			{
				cout << "\naccount updated successfully :-) ";
				_PrintClient(client);
				break;
			}
			case clsBankClient::enSaveResults::svFaildEmpty:
			{
				cout << "\nError account was not saved , cos it's empty.";
				break;
			}
	
			}

		}
	}

};

