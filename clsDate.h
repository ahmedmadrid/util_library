#pragma once
#pragma warning (disable : 4996)
#include<iostream>
#include <ctime>
#include <string>
#include "clsString.h"
using namespace std;


class clsDate
{
	int _days;
	int _month;
	int _year;

	// abstraction principle
	static bool _isLeapYear(int year) {
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}

	static int _dayIndexInTheWeek(clsDate date) {
		int a = (14 - date.month) / 12;
		int y = date.year - a;
		int m = date.month + 12 * a - 2;
		return (date.days + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	static string _daysName(int dayIndex) {
		string daysName[]{ "", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return daysName[dayIndex];
	}

	static string _monthsName(int month) {
		string monthsName[]{ "","Jan","Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return monthsName[month];
	}

	static bool _isMultipleOf7(int days) {
		return (days % 7 == 0);
	}

	static void _letDate1BeTheSmallest(clsDate& date1, clsDate& date2) {
		clsDate tempDate;
		if (isDate1AfterDate2(date1, date2)) {
			tempDate = date1;
			// overwrite date1
			date1 = date2;
			date2 = tempDate;
		}
	}

	static bool _isEndOfWeek(clsDate date) {
		// week ends on:sat
		return (_dayIndexInTheWeek(date) == 6);
	}

	static bool _isWeekEnd(clsDate date) {
		int dayIndex = _dayIndexInTheWeek(date);
		// weekend on : fri, sat
		return (dayIndex == 5 || dayIndex == 6);
	}

	static bool _isBusinessDay(clsDate date) {
		return !_isWeekEnd(date);
	}

	static bool _isEndOfMonth(clsDate date) {
		return (date._days == numOfDaysInMonth(date));
	}

	static bool _isEndOfYear(clsDate date) {
		return (date._days == 31) && (date._month == 12);
	}


public:

	// defualt constructor initializes date to current date
	clsDate() {
		time_t t = time(0);
		tm* currentTime = localtime(&t);

		_days = currentTime->tm_mday;
		_month = currentTime->tm_mon +1;
		_year = currentTime->tm_year + 1900;
	}

	clsDate(string date, string delimeter = "/") {

		vector<string> vDate = clsString::splitString(date, delimeter);
		vector<string>::iterator ptrDate = vDate.begin();
		_days = stoi(*ptrDate++);
		_month = stoi(*ptrDate++);
		if (ptrDate != vDate.end())
			_year = stoi(*ptrDate);
		else
			_year = 2023;
	}

	clsDate(int days, int month, int year) {
		_days = days;
		_month = month;
		_year = year;
	}

	clsDate(int days, int year) {
		clsDate date = clsDate::dateAfterAddingNDaysVersion2(days, clsDate(1, 1, year));
		_days = date._days;
		_month = date._month;
		_year = date._year;
	}

	/*------------------------- properties */
	void setDays(int days) {
		_days = days;
	}

	int getDays() {
		return _days;
	}

	__declspec(property(get = getDays, put = setDays)) int days;

	void setMonth(int month) {
		_month = month;
	}

	int getMonth() {
		return _month;
	}

	__declspec(property(get = getMonth, put = setMonth)) int month;

	void setYear(int year) {
		_year = year;
	}

	int getYear() {
		return _year;
	}

	__declspec(property(get = getYear, put = setYear)) int year;

	/*------------------------- print date*/
	static void printDate(clsDate date) {
		cout << date._days << "/" << date._month << "/" << date._year << endl;
	}

	void printDate() {
		printDate(*this);
	}

	static void printDateInDetails(clsDate date) {
		// get day name
		cout << "Today is " << dayName(date) << ", ";
		printDate(date);
	}

	void printDateInDetails() {
		printDateInDetails(*this);
	}

	/*---------------------------- daet to string*/
	
	static string dateToString(clsDate date) {
		return to_string(date._days) + "/" + to_string(date._month) + "/" + to_string(date._year);
	}

	string dateToString() {
		return dateToString(*this);
	}


	/*---------------- leap year*/

	static void isLeapYear(clsDate date) {
		(_isLeapYear(date._year)) ? cout << date._year << " is a leap year\n" : cout << date._year << " is not a leap year\n";
	}

	void isLeapYear() {
		isLeapYear(*this);
	}

	/*------------------cnt # days, hrs, ....*/
	static int numOfDaysInYear(int year) {
		return (_isLeapYear(year)) ? 366 : 365;
	}

	int numOfDaysInYear() {
		return numOfDaysInYear(this->_year);
	}

	static int numOfHoursInYear(int year) {
		return numOfDaysInYear(year) * 24;
	}

	int numOfHoursInYear() {
		return numOfHoursInYear(this->_year);
	}

	static int numOfMinutesInYear(int year) {
		return numOfHoursInYear(year) * 60;
	}

	int numOfMinutesInYear() {
		return numOfMinutesInYear(this->_year);
	}

	static int numOfSecondsInYear(int year) {
		return numOfMinutesInYear(year) * 60;
	}

	int numOfSecondsInYear() {
		return numOfSecondsInYear(this->_year);
	}

	static int numOfDaysInMonth(clsDate date) {
		int daysOfMonths[]{0,31,28,31,30,31,30,31,31,30,31,30,31};
		return(date._month == 2 && _isLeapYear(date._year)) ? 29 : daysOfMonths[date._month];
	}

	int numOfDaysInMonth() {
		return numOfDaysInMonth(*this);
	}

	static int numOfHoursInMonth(clsDate date) {
		return numOfDaysInMonth(date) * 24;
	}

	int numOfHoursInMonth() {
		return numOfHoursInMonth(*this);
	}

	static int numOfMinutesInMonth(clsDate date) {
		return numOfHoursInMonth(date) * 60;
	}

	int numOfMinutesInMonth() {
		return numOfMinutesInMonth(*this);
	}

	static int numOfSecondsInMonth(clsDate date) {
		return numOfMinutesInMonth(date) * 60;
	}

	int numOfSecondsInMonth() {
		return numOfSecondsInMonth(*this);
	}

	/*-------------------- day name*/

	static string dayName(clsDate date) {
		string daysName[]{"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
		return daysName[_dayIndexInTheWeek(date)];
	}

	string dayName() {
		return dayName(*this);
	}

	/*---------------------- calender*/

	static void printMonthCalendar(clsDate date) {
		// set date's day to 1; begining of the calander
		date.days = 1;
		// get name of the month
		string nameOfTheMonth = _monthsName(date._month);
		// define the day when the calender begins
		int dayOrder = _dayIndexInTheWeek(date);
		// calender header
		cout << " ____________ " << nameOfTheMonth << " ____________\n\n";

		// week days
		cout << " Sun Mon Tue Wed Thu Fri Sat\n";

		// first line: emptiness
		int i;
		for (i = 0; i < dayOrder; i++)
			cout << "    ";
		
		// print numbers
		int daysLimit = clsDate::numOfDaysInMonth(date);
		while (date.days <= daysLimit) {
			if ( i > 6) {
				cout << '\n';
				i = 0;
			} 
			printf("%4d", date.days++);
			i++;
		}
		cout << "\n _____________________________\n\n";

	}

	void printMonthCalendar() {
		printMonthCalendar(*this);
	}

	static void printYearCalendar(clsDate date) {
		cout << "____________________________________\n\n";
		printf("%20s - %d\n", "Calendar", date._year);
		cout << "____________________________________\n\n";

		date._days = 1;
		date._month = 1;
		for (int i = 0; i < 12; i++) {
			printMonthCalendar(date);
			date._month++;
		}
			
	}

	void printYearCalendar() {
		printYearCalendar(*this);
	}

	/*--------------------- days from 1/1/year upto current date*/

	static int daysFromBeginningOfTheYear(clsDate date) {
		int cnt = 0;
		int wholeMonths = date._month - 1;
		date._month = 1;
		for (int i = 0; i < wholeMonths; i++) {
			cnt += numOfDaysInMonth(date);
			date._month++;
		}
		return cnt += date._days;
	}

	int daysFromBeginningOfTheYear() {
		return daysFromBeginningOfTheYear(*this);
	}

	static clsDate daysToDate(int days, clsDate date) {
		int remainingDays = days;
		// set month to 1; begining of the year
		date.month = 1;
		while (remainingDays > numOfDaysInMonth(date)) {
			remainingDays -= numOfDaysInMonth(date);
			// go to next month
			date._month++;
		}
		date._days = remainingDays;
		return date;
	}

	clsDate daysToDate(int days) {
		return daysToDate(days, *this);
	}

	/*----------------------- add days to date */
	
	static clsDate dateAfterAddingNDays(int days, clsDate date) {
		int remainingDays = days;

		// moving from 1/m/y makes it easy to reach next month
		if (date._days > 1) {
			remainingDays += date._days;
			date._days = 1;
		}
		
		// days failed to make up a new month
		if (remainingDays < numOfDaysInMonth(date))
			while (remainingDays != date.days)
				date.days++;
		else {
			// subtracting days matching adding a new month 
			while (remainingDays >= numOfDaysInMonth(date)) {
				remainingDays -= numOfDaysInMonth(date);
				// move to the next month
				date.month++;
				// reaching a new year
				if (date.month > 12) {
					date.month = 1;
					date.year++;
				}
			}
			// begining of the month
			if (remainingDays == 0)
				date.days = 1;
			else
				date.days = remainingDays;
		}
		return date;
	}

	void dateAfterAddingNDays(int days) {
		*this = dateAfterAddingNDays(days, *this);
	}

	/*---------------------------- compare two dates*/

	static bool isDate1BeforeDate2(clsDate date1, clsDate date2) {
		/*return date1.year < date2.year ?
			true : (date1.year == date2.year) && (date1.month < date2.month) ?
			true : (date1.year == date2.year) && (date1.month < date2.month) && (date1.days < date2.days) ?
			true : false;
*/

		return date1.year < date2.year ?
			true : (date1.year == date2.year) && (date1.month < date2.month) ?
			true : (date1.year == date2.year) && (date1.month == date2.month) && (date1.days < date2.days);
		
	}

	bool isDate1BeforeDate2(clsDate date2) {
		return isDate1BeforeDate2(*this, date2);
	}

	static bool isDate1EqualToDate2(clsDate date1, clsDate date2) {
		return (date1._year == date2._year && date1._month == date2._month && date1._days == date2._days);
	}

	bool isDate1EqualToDate2(clsDate date2) {
		return isDate1EqualToDate2(*this, date2);
	}

	static bool isDate1AfterDate2(clsDate date1, clsDate date2) {
		return !(isDate1EqualToDate2(date1, date2) || isDate1BeforeDate2(date1, date2));
	}

	bool isDate1AfterDate2(clsDate date2) {
		return isDate1AfterDate2(*this, date2);
	}

	static int compareTwoDates(clsDate date1, clsDate date2) {
		// if you include isDate1AfterDate2()
		// you would consume isDate1BeforeDate2() & isDate1EqualToDate2() more than it should be
		return isDate1EqualToDate2(date1, date2) ? 0 : isDate1BeforeDate2(date1, date2) ? -1 : 1;
	}

	int compareTwoDates(clsDate date2) {
		return compareTwoDates(*this, date2);
	}


	/*------------------------- isLdast day/month */
	static bool isLastDay(clsDate date) {
		return (date._days == numOfDaysInMonth(date));
	}

	bool isLastDay() {
		return isLastDay(*this);
	}

	static bool isLastMonth(clsDate date) {
		return (date._month == 12);
	}

	bool isLastMonth() {
		return isLastMonth(*this);
	}

	/*------------------------ add one day*/

	static clsDate dateAfterAddingOneDay(clsDate date) {
		bool dayIsLast = isLastDay(date);
		bool monthIsLast = isLastMonth(date);

		if ( dayIsLast && monthIsLast) {
			date._days = 1;
			date._month = 1;
			date._year++;
		}
		else if (dayIsLast) {
			date._days = 1;
			date._month++;
		}
		else
			date._days++;

		return date;
	}

	void dateAfterAddingOneDay() {
		*this = dateAfterAddingOneDay(*this);
	}

	// to add n days, divide the problem to think through how to add one day in a right manner and just repeat the process. it's much easier
	static clsDate dateAfterAddingNDaysVersion2(int days, clsDate date) {
		while (days--)
			date = dateAfterAddingOneDay(date);
		return date;
	}

	void dateAfterAddingNDaysVersion2(int days) {
		*this = dateAfterAddingNDaysVersion2(days, *this);
	}

	/*----------------------- diff in dates*/
	
	static int differenceBetweenDate1AndDate2(clsDate date1, clsDate date2, bool includeEndDay = false) {
		_letDate1BeTheSmallest(date1, date2);
		int days = 0;

		// the user would like to include end day, and dates are already equal
		if (isDate1EqualToDate2(date1, date2))
			return days;


		while (!isDate1EqualToDate2(date1, date2)) {
			// get date1 to reach date2
			date1 = dateAfterAddingOneDay(date1);
			days++;
		}

		return (includeEndDay) ? ++days : days;

	}

	int differenceBetweenDate1AndDate2(clsDate date2, bool includeEndDay = false) {
		return differenceBetweenDate1AndDate2(*this, date2, includeEndDay);
	}

	/*------------------------- increase date*/

	static clsDate dateAfterAddingOneWeek(clsDate date) {
		return dateAfterAddingNDaysVersion2(7, date);
	}

	void dateAfterAddingOneWeek() {
		*this = dateAfterAddingOneWeek(*this);
	}

	static clsDate dateAfterAddingNWeeks(int weeks, clsDate date) {
		while (weeks--) {
			date = dateAfterAddingOneWeek(date);
		}
		return date;
	}

	void dateAfterAddingNWeeks(int weeks) {
		*this = dateAfterAddingNWeeks(weeks, *this);
	}

	static clsDate dateAfterAddingOneMonth(clsDate date) {
		/*if (date._month == 12) date.month = 1;*/
		return dateAfterAddingNDaysVersion2(numOfDaysInMonth(date), date);
	}

	void dateAfterAddingOneMonth() {
		*this = dateAfterAddingOneMonth(*this);
	}

	static clsDate dateAfterAddingNMonths(int months, clsDate date) {
		while (months--) {
			date = dateAfterAddingOneMonth(date);
		}
		return date;
	}

	void dateAfterAddingNMonths(int months) {
		*this = dateAfterAddingNMonths(months, *this);
	}

	static clsDate dateAfterAddingOneYear(clsDate date) {
		return dateAfterAddingNMonths(12,date); // 29-2-2020 should n't be 29-2-2030 after adding 10 years, since 2030 isn't a leap year. it should be 1-3-2030
	}

	void dateAfterAddingOneYear() {
		*this = dateAfterAddingOneYear(*this);
	}

	static clsDate dateAfterAddingNYears(int years, clsDate date) {
		while (years--) {
			date = dateAfterAddingOneYear(date);
		}
		return date;
	}

	void dateAfterAddingNYears(int years) {
		*this = dateAfterAddingNYears(years, *this);
	}

	static clsDate dateAfterAddingOneDecade(clsDate date) {
		return dateAfterAddingNYears(10,date);
	}

	void dateAfterAddingOneDecade() {
		*this = dateAfterAddingOneDecade(*this);
	}

	static clsDate dateAfterAddingNDecades(int decades, clsDate date) {
		while (decades--)
			date = dateAfterAddingOneDecade(date);
		return date;
	}

	void dateAfterAddingNDecades(int decades) {
		*this = dateAfterAddingNDecades(decades, *this);
	}

	static clsDate dateAfterAddingOneCentury(clsDate date) {
		return dateAfterAddingNDecades(10,date);
	}

	void dateAfterAddingOneCentury() {
		*this = dateAfterAddingOneCentury(*this);
	}

	static clsDate dateAfterAddingOneMillennium(clsDate date) {
		for (int i = 0; i < 10; i++)
			date = dateAfterAddingOneCentury(date);
		return date;
	}

	void dateAfterAddingOneMillennium() {
		*this = dateAfterAddingOneMillennium(*this);
	}

	/*-------------------- Businees day (printing) */

	static void isItEndOfWeek(clsDate date) {
		(_isEndOfWeek(date)) ? cout << "Yes, It's end of week\n" : cout << "No, Not end of week\n";
	}

	void isItEndOfWeek() {
		isItEndOfWeek(*this);
	}

	static void isItWeekEnd(clsDate date) {
		_isWeekEnd(date) ? cout << "Yes, It's a week end\n" : cout << "No, Not a week end\n";
	}

	void isItWeekEnd() {
		isItWeekEnd(*this);
	}

	static void isItBusinessDay(clsDate date) {
		_isBusinessDay(date) ? cout << "Yes, It's a business day\n" : cout << "No, Not a business day\n";
	}

	void isItBusinessDay() {
		isItBusinessDay(*this);
	}

	static int daysUntilEndOfWeek(clsDate date, bool includeEndDay = false) {
		int days{};

		if (_isEndOfWeek(date))
			return days;

		while (!_isEndOfWeek(date)) {
			days++;
			date = dateAfterAddingOneDay(date);
		}

		return (includeEndDay) ? ++days : days;

	}

	int daysUntilEndOfWeek(bool includeEndDay = false) {
		return daysUntilEndOfWeek(*this, includeEndDay);
	}

	static int daysUntilEndOfMonth(clsDate date, bool incudeEndDay = false) {
		int days{};

		if (_isEndOfMonth(date))
			return days;

		while (!_isEndOfMonth(date)) {
			days++;
			date = dateAfterAddingOneDay(date);
		}

		//return (incudeEndDay) ? days++ : days; // return this increase -:)

		return (incudeEndDay)? ++days : days;
	}

	int daysUntilEndOfMonth(bool includeEndDay = false) {
		return daysUntilEndOfMonth(*this, includeEndDay);
	}

	static int daysUntilEndOfyear(clsDate date, bool includeEndDay = false) {
		int days{};

		if (_isEndOfYear(date))
			return days;

		while (!_isEndOfYear(date)) {
			days++;
			date = dateAfterAddingOneDay(date);
		}
		return (includeEndDay) ? ++days : days;
	}

	int daysUntilEndOfyear(bool includeEndDay = false) {
		return daysUntilEndOfyear(*this, includeEndDay);
	}

	/*------------------ calculate vacation days*/

	static int calculateActualVacationDays(clsDate date1, clsDate date2, bool includeEndDay = false) {
		// get diff
		int vacataionDays = differenceBetweenDate1AndDate2(date1, date2, includeEndDay);
		_letDate1BeTheSmallest(date1, date2);

		// as long as you didn't consume the whole vacation
		while (!isDate1EqualToDate2(date1,date2)) {
			if (_isWeekEnd(date1))
				--vacataionDays;
			date1 = dateAfterAddingOneDay(date1);
		}

		return vacataionDays;
	}

	int calculateActualVacationDays(clsDate date2, bool includeEndDay = false) {
		return calculateActualVacationDays(*this, date2, includeEndDay);
	}

	// suppossedly don't do it
	static clsDate vacatationReturnDate(int days, clsDate date) {

		// as long as we have a vacatation quota
		while (days)
		{
			/*if (_isWeekEnd(date))
				date._days++;
			else
				days--;*/

			if (!_isWeekEnd(date))
				days--;

			date = dateAfterAddingOneDay(date);
		}

		return date;
	}

	clsDate vacatationReturnDate(int days) {
		return vacatationReturnDate(days, *this);
	}

	/*-------------------------- validate date*/

	static bool isValidDate(clsDate date) {
		if (date._days > 0 && date._month > 0 && date._year > 0)
			return (date._days <= numOfDaysInMonth(date)) && date._month <= 12;
		return false;
	}

	bool isValidDate() {
		return isValidDate(*this);
	}

	/*------------------------ calculate age*/

	static int getAgeInDays(clsDate birthDate, bool includeEndDay = false) {
		return clsDate::differenceBetweenDate1AndDate2(birthDate, clsDate(), includeEndDay);
	}

	
};

