#pragma once
#include <iomanip>
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"

 class clsDeleteClientScreen : protected clsScreen
{
private:
	 static void _PrintClientInfo(clsBankClient Client)
	 {
		 cout << "\nCLient Card : ";
		 cout << "\n_________________________";
		 cout << "\nFirst Name     :  " << Client.FirstName;
		 cout << "\nLast Name      : " << Client.LastName;
		 cout << "\nFull Name      : " << Client.FullName();
		 cout << "\nEmail          : " << Client.Email;
		 cout << "\nPhone          : " << Client.Phone;
		 cout << "\nAcc.Number     : " << Client.AccountNumber();
		 cout << "\nPassword       : " << Client.PinCode;
		 cout << "\nBalance        : " << Client.AccountBalance;
	 }
public:
	static void ShowDeleteClientScreen()
	{
		_DrawScreenHeader("\t Delete CLient Screen");
		string AccountNumber = "";

		cout << "\nENter Account Number ? ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found , Choose another one.";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient client1 = clsBankClient::Find(AccountNumber);
		_PrintClientInfo(client1);

		cout << "\nAre you sure do want delete this client ?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (client1.Delete())
			{
				cout << "\nClient Deleted successfully.\n";
				_PrintClientInfo(client1);
			}
			else
			{
				cout << "\nError Client was not deleted ! \n";
			}
		}

		
	}

};

