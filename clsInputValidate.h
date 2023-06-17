#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsString.h"

using namespace std;




class clsInputValidate
{
	// abstraction principle
	static bool _isStringInsteadOfNumber(bool isString, string message) {
		if (isString) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << "\n  ";
		}

		return isString;

	}

	static void _letDate1BeforeDate2(clsDate& date1, clsDate& date2) {
		clsDate temp;
		if (clsDate::isDate1AfterDate2(date1, date2)) {
			temp = date1;
			date1 = date2;
			date2 = temp;
		}	
	}

	static void _swap(int& n1, int& n2) {
		int temp{n1};
		n1 = n2;
		n2 = temp;
	}

	static void _swap(double& n1, double& n2) {
		double temp{ n1 };
		n1 = n2;
		n2 = temp;
	}


public:

	static bool isNumberBetween(int key, int from, int to) {
		// begin from smaller to larger
		if (from > to)
			_swap(from, to);

		return (key >= from && key <= to);
	}

	static bool isNumberBetween(double key, double from, double to) {
		if (from > to)
			_swap(from, to);

		return (key >= from && key <= to);
	}

	static bool isDateBetween(clsDate key, clsDate from, clsDate to) {
		_letDate1BeforeDate2(from, to);
		return !key.isDate1BeforeDate2(from) && !key.isDate1AfterDate2(to);
	}

	static int readIntNumber(string message) {
		int number{};
		bool isFailed{};
		do {
			cout << message << " --> ";
			cin >> number;

			isFailed = _isStringInsteadOfNumber(cin.fail(), "Invalid input, Enter again!");

		} while (isFailed);

		return number;

	}

	static int readPositiveIntNumber(string message) {
		int number{ 1 };
		bool isFailed{};
		do {
			cout << message << " --> ";
			cin >> number;

			isFailed = _isStringInsteadOfNumber(cin.fail(), "Invalid input, Enter again!");

			if (number <= 0) {
				cout << "Zero and negatives are invalid inupt!!\n ";
				isFailed = 1;
			}

		} while (isFailed);

		return number;
	}

	static int readIntNumberBetween(string message, int from, int to, string warning) {
		int number{};
		do {
			number = readIntNumber(message);

			if (number <from || number >to)
				cout << warning << "\n  ";

		} while (number < from || number > to);
		return number;
	}

	static double readDBLNumber(string message) {
		double temp{};
		bool isFailed{};

		do {
			cout << message << " --> ";
			cin >> temp;

			isFailed = _isStringInsteadOfNumber(cin.fail(), "Invalid input, Enter again!");

		} while (isFailed);
		return temp;
	}


};

