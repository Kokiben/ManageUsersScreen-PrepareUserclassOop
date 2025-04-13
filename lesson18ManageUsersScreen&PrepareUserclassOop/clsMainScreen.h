#pragma once
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsDeleteClientScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsFindClient.h"
#include "clsClientListScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsers.h"

class clsMainScreen: protected clsScreen
{
private:
	enum enMainMenueOptions { eListClient = 1, eAddNewClient = 2, eDeleteClient = 3, eUpDateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6, eShowManageUsers = 7, eMainMenue = 8 };
	static short _ReadMainMeuneOptions()
	{
		cout << setw(37) << left << "choose what do you want to do ? 1 to 8";

		short choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between 1 and 8?");
		return choice;
	}
	static void _GoBackToMainMenue()
	{
		cout << "\nPress any key to go back to main menue...";
		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllCleintList()
	{
		clsClientListScreen::ShowClientList();
	}
	static void _ShowAddNewClientcreen()
	{
		clsAddNewClientScreen::ShowAddNewClient();
	}
	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _ShowUpDateClientScreen()
	{ 
		clsUpdateClientScreen::ShowUpdateCLientScreen();
	}
	static void _ShowFindClientScreen()
	{
		clsFindClient::ShowFindClient();
	}
	static void _ShowTransactionsMeune()
	{
		clsTransactionsScreen::ShowTransactionMenue();

	}
	static void _ShowManageUsersScreen()
	{
		clsManageUsers::ShowManageUsersMenue();
	}
	static void _ShowMainMenue()
	{}
	static void _PerFormMainMenueOption(enMainMenueOptions MainMenueOptions)
	{
		switch (MainMenueOptions)
		{
		case enMainMenueOptions::eListClient:
		{
			system("cls");
			_ShowAllCleintList();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientcreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eUpDateClient:
		{
			system("cls");
			_ShowUpDateClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionsMeune();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eShowManageUsers:
		{
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eMainMenue:
		{

		}
		}
	}

public:
	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t Main Screen\n");

		cout << setw(37) << left << "" << "=======================================================\n";
		cout << setw(37) << left << "" << "\t\t\t Main Menue\n";
		cout << setw(37) << left << "" << "=======================================================\n";

		cout << setw(37) << left << "" << "\t[1]Show Client Screen.\n";

		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client Screen.\n";
		cout << setw(37) << left << "" << "\t[4] UpDate Client Screen.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client Screen.\n";
		cout << setw(37) << left << "" << "\t[6] Transaction Menue.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users .\n";
		cout << setw(37) << left << "" << "\t[8] Main Menue.\n";
		cout << setw(37) << left << "" << "=====================================================\n";
		_PerFormMainMenueOption((enMainMenueOptions)_ReadMainMeuneOptions());

	}

};

