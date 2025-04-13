#pragma once
#include "iomanip"
#include "clsScreen.h"
#include "clsBankClient.h"

class clsAddNewClientScreen : protected clsScreen
{
private:
	static void _ReacClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\n Enter Last Name : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();

	}
	static void _PrintNewClient(clsBankClient Client)

	{
		cout << "\nCLient Info  : ";
		cout << "\n_________________________";
		cout << "\nFirst Name    : " << Client.FirstName;
		cout << "\nLast Name     : " << Client.LastName;
		cout << "\nEmail         : " << Client.Email;
		cout << "\nPhone         : " << Client.Phone;
		cout << "\nAcc.Number    : " << Client.AccountNumber();
		cout << "\nPassword      : " << Client.PinCode;
		cout << "\nBalance       : " << Client.AccountBalance;

	}
public:
	static void ShowAddNewClient()
	{
		_DrawScreenHeader("\t Add New CLient ");
		string AccountNumber = "";

		cout << "\nEnter Account Number ?";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number is already Used , Choose another one.";
			AccountNumber = clsInputValidate::ReadString();

		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReacClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResults;
		SaveResults = NewClient.Save();

		switch (SaveResults)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nNew client added succesfully.";
			_PrintNewClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmpty:
		{
			cout << "\nError account number was not saved cos it's Empty!";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExist:
		{
			cout << "\nError account number was not saved cos account number is Used";
			break;
		}
		}

	}



};

