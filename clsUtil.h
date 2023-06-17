#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "clsDate.h"
#include "clsInputValidate.h"
#include "clsString.h"
using namespace std;


class clsUtil
{

protected:

	static int countEvenNumberInArray(int array[], int len) {
		int cnt{};
		for (int i = 0; i < len; i++)
			if (isEven(array[i]))
				++cnt;

		return cnt;
	}

	static int countOddNumberInArray(int array[], int arrayLen) {
		int cnt{};
		for (int i = 0; i < arrayLen; i++)
			if (isOdd(array[i]))
				++cnt;
		return cnt;
	}

	static int countPositiveNumbersInArray(int array[], int arrayLength) {
		int cnt{};
		for (int i = 0; i < arrayLength; i++)
			if (array[i] > 0)
				++cnt;
		return cnt;
	}

	static int countNegativeNumbersInArray(int array[], int arrayLength) {
		int cnt{};
		for (int i = 0; i < arrayLength; i++)
			if (array[i] < 0)
				++cnt;
		return cnt;
	}

	static int countZerosInArray(int array[], int arrayLength) {
		int cnt{};
		for (int i = 0; i < arrayLength; i++)
			if (array[i] == 0)
				++cnt;
		return cnt;
	}

	static int countNonPositiveNumbersInArray(int array[], int arrayLength) {
		// ignore return countZerosInArray() + countNegativeNumbersInArray()
		// in case you had 1,000,000 numbers the only last two ones are zero and negative
		// why to loop over 1,000,000 positive numebrs twice!
		int cnt{};
		for (int i = 0; i < arrayLength; i++)
			if (array[i] <= 0)
				++cnt;
		return cnt;
	}

	static int countNonNegativeNumbersInArray(int array[], int arrayLength) {
		// ignore return countZerosInArray() + countNegativeNumbersInArray()
		// in case you had 1,000,000 numbers the only last two ones are zero and negative
		// why to loop over 1,000,000 positive numebrs twice!
		int cnt{};
		for (int i = 0; i < arrayLength; i++)
			if (array[i] >= 0)
				++cnt;
		return cnt;
	}

	

public:

	static void swap(int& n1, int& n2) {
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}

	static void swap(double& n1, double& n2) {
		double temp{ n1 };
		n1 = n2;
		n2 = temp;
	}

	static void swap(string& str1, string& str2) {
		string temp{str1};
		str1 = str2;
		str2 = temp;
	}

	static void swap(clsDate& date1, clsDate& date2) {
		clsDate tempDate = date1;
		date1 = date2;
		date2 = tempDate;
	}

	static int reverseNumber(int number) {
		int res{}, rem{};
	
		while (number != 0) {
			rem = number % 10;
			res = (res * 10) + rem;
			number /= 10;
		}
		return res;
	}

	static int absolute(int n) {
		return (n < 0) ? n * -1 : n;
	}

	static double absolute(double n) {
		return (n < 0) ? n * -1 : n;
	}

	static double getFractionPart(double n) {
		return n - int(n);
	}

	static int round(double number) {
		int integerPart = int(number);
		double fraction = getFractionPart(number);

		if (absolute(fraction) > 0.5) 
			(number > 0) ? ++integerPart : --integerPart;

		return integerPart;
	}

	static int ceil(double number) {
		int integerPart = int(number);
		double fraction = getFractionPart(number);

		if (fraction == 0) return integerPart;

		return (integerPart > 0)? ++integerPart : integerPart;
	}

	static bool isPrime(int n) {
		int half = round(double(n / 2));
		for (int i = 2; i < half; i++)
			if (n % i == 0)
				return false;
		return true;
	}

	static bool isNumberInArray(int array[100], int arrayLength, int key) {
		for (int i = 0; i < arrayLength; i++)
			if (key == array[i])
				return true;
		return false;
	}

	static bool isNumberDistinctInArray(int array[100], int arrayLength, int key) {
		int cnt{};

		for (int i = 0; i < arrayLength; i++)
			if (key == array[i])
				++cnt;

		return (cnt == 1) ? true : false;

	}

	static void turnOnRandomMode() {
		srand((unsigned)time(NULL));
	}

	static int random(int from, int to) {
		/*
		* include <cstdlib>
			srand((unsigned)time(NULL)); in main
		*/
		return rand() % (to - from + 1) + from;
	}

	static void printArray(int array[], int arrayLength) {
		for (int i = 0; i < arrayLength; i++) {
			printf("%3d ", array[i]);
		}
		cout << endl;
	}

	static void printArray(double array[], int arrayLength) {
		for (int i = 0; i < arrayLength; i++)
			printf("%3f", array[i]);
		cout << endl;
	}

	static void printArray(string array[], int arrayLength) {
		for (int i = 0; i < arrayLength; i++)
			cout << array[i] << " ";
		cout << endl;
	}

	static int maxInArray(int array[], int arrayLength) {
		// let max be minimum integer
		int max{INT_MIN};

		for (int i = 0; i < arrayLength; i++)
			if (array[i] > max)
				max = array[i];
		return max;
	}

	static double maxInArray(double array[], int arrayLength) {
		// let max be minimum integer
		double max{ DBL_MIN };

		for (int i = 0; i < arrayLength; i++)
			if (array[i] > max)
				max = array[i];
		return max;
	}

	static int minInArray(int array[], int arrayLength) {
		// let min be max integer
		int min{ INT_MAX };

		for (int i = 0; i < arrayLength; i++)
			if (array[i] < min)
				min = array[i];
		return min;
	}

	static double minInArray(double array[], int arrayLength) {
		// let min be max integer
		double min{ DBL_MAX };

		for (int i = 0; i < arrayLength; i++)
			if (array[i] < min)
				min = array[i];
		return min;
	}

	static int sumArray(int array[], int arrayLength) {
		int sum{};

		for (int i = 0; i < arrayLength; i++)
			sum += array[i];
		return sum;
	}

	static double sumArray(double array[], int arrayLength) {
		double sum{};

		for (int i = 0; i < arrayLength; i++)
			sum += array[i];
		return sum;
	}

	static double averageArray(int array[], int arrayLength) {
		return (double)sumArray(array, arrayLength) / arrayLength;
	}

	static double averageArray(double array[], int arrayLength) {
		return sumArray(array, arrayLength) / arrayLength;
	}

	static void copyArray(int sourceArray[], int targetArray[], int arrayLength) {
		// arrays are parameterized by REF by DEFAULT!
		for (int i = 0; i < arrayLength; i++)
			targetArray[i] = sourceArray[i];
	}

	static void copyArray(double sourceArray[], double targetArray[], int arrayLength) {
		// arrays are parameterized by REF by DEFAULT!
		for (int i = 0; i < arrayLength; i++)
			targetArray[i] = sourceArray[i];
	}

	static void copyArray(string sourceArray[], string targetArray[], int arrayLength) {
		// arrays are parameterized by REF by DEFAULT!
		for (int i = 0; i < arrayLength; i++)
			targetArray[i] = sourceArray[i];
	}

	// capacity of sent array must be declared --> array[1000]
	static void storeNumberInArray(int array[], int key, int& arrayLength) {
		array[arrayLength++] = key;
	}
	
	// capacity of sent array must be declared --> array[1000]
	static void storeNumberInArray(double array[], double key, int& arrayLength) {
		array[arrayLength++] = key;
	}

	// capacity of sent array must be declared --> array[1000]
	static void storeStringInArray(string array[], string key, int& arrayLength) {
		array[arrayLength++] = key;
	}

	static void incrementArray(int array[], int& len) {
		int number{}; bool  reply{};
		do {
			storeNumberInArray(array, clsInputValidate::readPositiveIntNumber("Enter a number"), len);

			cout << "Do you want to add more numbers [0] no - [1] yes? ";
			cin >> reply;

		} while (reply);
	}

	static bool isEven(int num) {
		return (num % 2 == 0 && num > 0);
	}

	static bool isOdd(int number) {
		// ignore this
		//return !isEven(number) && number > 0;
		return (number % 2 != 0 && number > 0);
	}

	enum enWhichToCount {enEVEN_NUMEBRS = 0, enODD_NUMBERS = 1, enPOSITIVE_NUMBERS = 2, enNEGATIVENUMBERS = 3, enNON_POSITIVE_NUMBERS = 4, enNON_NEGATIVE_NUMBERS = 5, enZEROS = 6};

	static int countInArray(int array[], int arrayLength, enWhichToCount whichToCount = enWhichToCount::enPOSITIVE_NUMBERS) {
		switch (whichToCount) {
		case enWhichToCount::enEVEN_NUMEBRS:
			return countEvenNumberInArray(array, arrayLength);

		case enWhichToCount::enODD_NUMBERS:
			return countOddNumberInArray(array, arrayLength);

		case enWhichToCount::enPOSITIVE_NUMBERS:
			return countPositiveNumbersInArray(array, arrayLength);

		case enWhichToCount::enNEGATIVENUMBERS:
			return countNegativeNumbersInArray(array, arrayLength);

		case enWhichToCount::enNON_POSITIVE_NUMBERS:
			return countNonPositiveNumbersInArray(array, arrayLength);

		case enWhichToCount::enNON_NEGATIVE_NUMBERS:
			return countNonNegativeNumbersInArray(array, arrayLength);

		case enWhichToCount::enZEROS:
			return countZerosInArray(array, arrayLength);
		}
	}

	enum enCharCase{ enSMALL_CASE = 0, enCAPITAL_CASE = 1, enDIGITS = 2, enMIX_CHAR = 3 };

	// you have to turn on random mode; random()'s included in here!
	static char getRandomChar(enCharCase charCase = enCharCase::enMIX_CHAR) {

		if (charCase == enCharCase::enMIX_CHAR)
			charCase = (enCharCase)random(0, 2);

		switch (charCase) {
		case enCharCase::enCAPITAL_CASE:
			return (char)random(65, 90);
		case enCharCase::enSMALL_CASE:
			return (char)random(97, 122);
		case enCharCase::enDIGITS:
			return (char)random(48, 57);
		
		}
	}

	// you have to turn on random mode; random()'s included in here!
	static string generateWord(enCharCase charCase, int wordLength = 4) {
		string temp{};

		for (int i = 0; i < wordLength; i++)
			temp += getRandomChar(charCase);
		return temp;
	}

	// you have to turn on random mode; random()'s included in here!
	static string generateKey(enCharCase charCase = enCharCase::enCAPITAL_CASE, int subKeyLength = 4, int keyLength = 4) {
		string key{};
		for (int i = 0; i < keyLength; i++)
			key += generateWord(charCase, subKeyLength) + "-";
		// ignore post "-"
		return key.substr(0,key.length() -1);
	}

	// you have to turn on random mode; random()'s included in here!
	static vector<string> generateNumberOfKeys(int keys, enCharCase charCase = enCharCase::enCAPITAL_CASE, int subKeyLength = 4, int keyLength = 4) {
		vector<string> vKeys;

		for (int i = 0; i < keys; i++)
			 vKeys.push_back(generateKey(charCase, subKeyLength, keyLength));

		return vKeys;
	}

	static void printVector(const vector<string>& vRECORDS) {
		int cnt{1};
		for (const string& STR : vRECORDS) {
			printf("[%03d] ", cnt++);
			clsString::printStr(STR);
		}
			
	}

	// you have to turn on random mode; random()'s included in here!
	static void fillArrayRandomly(int array[], int arrayLength, int from, int to) {
		for (int i = 0; i < arrayLength; i++)
			array[i] = random(from, to);
	}

	static void fillArrayRandomly(string array[], int arrayLength, enCharCase charCase, int wordLength ) {
		for (int i = 0; i < arrayLength; i++)
			array[i] = generateWord(charCase, wordLength);
	}

	static void fillArrayRandomly(string array[], int arrayLength, enCharCase charCase, int subKeyLength , int keyLength ) {
		for (int i = 0; i < arrayLength; i++)
			array[i] = generateKey(charCase, subKeyLength, keyLength);
	}

	static int power(int base, int exponent) {
		int res{1};
		while (exponent--)
			res *= base;
		return res;
	}

	static int sqrt(int number) {
		int i = 1;
		while (true) {
			if (i * i == number)
				return i;
			i++;
		}
	}

};

