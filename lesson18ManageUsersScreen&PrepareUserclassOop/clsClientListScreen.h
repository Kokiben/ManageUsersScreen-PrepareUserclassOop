#pragma once
#include <iomanip>
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
class clsClientListScreen: protected clsScreen
{
private:
	static void PrintRecordLine(clsBankClient Client)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(20) << left << Client.AccountBalance;
	} 
public:
	static void ShowClientList()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientList();

		string Title = "\tClient List Screen\n";
		string Subtilte = "\t  (" + to_string(vClients.size()) + ") client(s)";

		_DrawScreenHeader(Title, Subtilte);


		cout << setw(8) << left << "" << "\t________________________________________________________";
		cout << "____________________________________________________\n" << endl;


		cout << setw(8) << left << "" << "| " << setw(15) << left << "client Number " ;
		cout << "| " << left << setw(20) << "CLient Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password ";
		cout << "| " << left << setw(20) << "Balance";

		cout << setw(8) << left << "" << "\t_________________________________________________________";
		cout << "________________________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\t no client  available in the system! ";
		else
			for (clsBankClient client : vClients)
			{
				PrintRecordLine(client);
				cout << endl;
		}
		cout << setw(8) << left << "" << "___________________________________________________________";
		cout << "________________________________________________________\n" << endl;
	} 
};

 