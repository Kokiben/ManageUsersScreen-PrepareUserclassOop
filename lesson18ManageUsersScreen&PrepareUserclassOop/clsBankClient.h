#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include <fstream>
using namespace std; 


class clsBankClient:public clsPerson
{
private:
	enum enMode{EmptyMode = 0, UpDateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkedForDelete = false;
	
	static clsBankClient _ConvertLineToCLientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpDateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConvertClientObjecttoLine(clsBankClient Client, string Seperator = "#//#")
	{
		string vClientReocrd = "";
		vClientReocrd += Client.FirstName + Seperator;
		vClientReocrd += Client.LastName + Seperator;
		vClientReocrd += Client.Email + Seperator;
		vClientReocrd += Client.Phone + Seperator;
		vClientReocrd += Client.AccountNumber() + Seperator;
		vClientReocrd += Client.PinCode + Seperator;
		vClientReocrd += to_string(Client.AccountBalance);
		return vClientReocrd;
	}
	static vector<clsBankClient> _LoadClientObjectFromFile()
	{
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToCLientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;

	}
	static void _SaveClientObjectToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		string DataLine;
		if (MyFile.is_open())
		{
			for (clsBankClient c : vClients)
			{
				DataLine = _ConvertClientObjecttoLine(c);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}

	void _UpDate()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientObjectFromFile();
		for (clsBankClient c : _vClients)
		{
			if (c.AccountNumber() == AccountNumber())
			{
				c = *this;
				break;
			}
		}
		_SaveClientObjectToFile(_vClients);
	}
	void _AddDatalineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out || ios::app);
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}
	void _AddNew()
	{
		_AddDatalineToFile(_ConvertClientObjecttoLine(*this));
	}


	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;

		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	bool IsEmpty()
	{
		return (_Mode = enMode::EmptyMode);
	}
	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}
	string AccountNumber()
	{
		return _AccountNumber;

	}
	void SetPinCode(string Pincode)
	{
		_PinCode = Pincode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;
	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))string AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{
		
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			if (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToCLientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;

				}

			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	  }
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToCLientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();


		}
		return _GetEmptyClientObject();
	}
	enum enSaveResults{svFaildEmpty = 0, svSucceeded = 1, svFaildAccountNumberExist = 2};
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmpty;
			}
		}
		case enMode::UpDateMode:
		{
			_UpDate();
			return enSaveResults::svSucceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExist;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpDateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}
		}
	}
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}
	bool Delete()
	{
		vector<clsBankClient> vClients;
		vClients = _LoadClientObjectFromFile();
		for (clsBankClient c : vClients)
		{
			if (c.AccountNumber() == AccountNumber())
			{
				c._MarkedForDelete = true;
				break;
			}
		}
		_SaveClientObjectToFile(vClients);
		*this = _GetEmptyClientObject();
		return true;
	}
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	static vector <clsBankClient> GetClientList()
	{
		return _LoadClientObjectFromFile();
	}
	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}
	bool WithDraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			AccountBalance -= Amount;
			Save();
			return true;
		}
	}
	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientList();
		double TotalBalance = 0;
		for (clsBankClient client : vClients)
		{
			TotalBalance += client.AccountBalance;
		}
		return TotalBalance; 
	}
};

