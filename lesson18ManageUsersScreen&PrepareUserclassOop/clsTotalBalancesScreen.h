#pragma once
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include <string>

class clsTotalBalancesScreen: protected clsScreen
{
private:
	static void _PrintClientRecordBalance(clsBankClient Client)
	{
		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << left << Client.FullName();
		cout << "| " << left << Client.AccountBalance;
	}
public:
	static void ShowTotalBalance()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientList();
		string title = "\t Total Balance Screen.";
		string SubTitle = "\t  (" + to_string(vClients.size()) + ") client(s)";

		_DrawScreenHeader(title, SubTitle);

		cout << setw(25) << left << "" << "\n\t\t___________________________________________________________";
		cout << "______________________________________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << setw(15) << left << "Account Number ";
		cout << "| " << left << setw(40) << "client Name ";
		cout << "| " << left << setw(12) << "Balance ";

		cout << setw(25) << left << "" << "\n\t\t__________________________________________________________";
		cout << "_______________________________________________________n" << endl;


		double TotalBalance = clsBankClient::GetTotalBalances();
		if (vClients.size() == 0)
			cout << "\nno clients available in the system!";
		else
			for (clsBankClient client : vClients)
			{
				_PrintClientRecordBalance(client);
				cout << endl;

			}
		cout << setw(25) << left << "" << "\n\t\t________________________________________________________";
		cout << "__________________________________________________________\n";

		cout << setw(8) << left << "" << "\t\t\t\t\t\t\t Total Balance " << TotalBalance << endl;
		cout << setw(8) << left << "" << "\t\t\t\t (" << clsUtil::NumberToText(TotalBalance) << ")";
 
	}
};

