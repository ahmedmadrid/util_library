#pragma once // include once!
#include<iostream>
#include <string>
#include<vector>
using namespace std;



class clsString
{
	enum enWhichCaseToCount { enLOWER_CASE = 0, enUPPER_CASE = 1, enSPECIAL_CHARS = 2 ,enDIGITS = 3,enTwoCases = 4 };


	string _value;
	string _message;
	enWhichCaseToCount _whichToCount;

	// abstraction principle
	static bool _isUpperChar(const char& C) {
		return (C >= 65 && C <= 90);
	}

	static bool _isLowerChar(const char& C) {
		return (C >= 97 && C <= 122);
	}

	static void _convertToLowerChar(char& c) {
		if (_isUpperChar(c))
			c += 32;
	}

	static void _convertToUpperChar(char& c) {
		if (_isLowerChar(c))
			c -= 32;
	}

	static bool _isSpecialChar(const char& C) {
		return (C >= 33 && C <= 47) || (C >=58 && C <= 64) || (C >= 91 && C <= 64);
	}

	static bool _isDigit(const char& C) {
		return (C >= 48 && C <= 57);
	}


protected: // i want to force the user to use MOTHER method having enums

	/*========== count capital, small, special letters, and digits in a string*/
	static short countUpperLetters(string str) {
		short cnt{};
		for (const char& C : str) {
			if (_isUpperChar(C))
				cnt++;
		}
		return cnt;
	}

	short countUpperLetters() {
		return countUpperLetters(_value);
	}

	static short countLowerLetters(string str) {
		short cnt{};
		for (const char& C : str) {
			if (_isLowerChar(C))
				cnt++;
		}
		return cnt;
	}

	short countLowerLetters() {
		return countLowerLetters(_value);
	}

	static short countSpecialChars(string str) {
		short cnt{};
		for (const char& C : str) {
			if (_isSpecialChar(C))
				cnt++;
		}
		return cnt;
	}

	short countSpecialChars() {
		return countSpecialChars(_value);
	}

	static short countDigits(string str) {
		short cnt{};
		for (const char& C : str)
			if (_isDigit(C))
				cnt++;
		return cnt;
	}

	short countDigits() {
		return countDigits(_value);
	}

public:
	// dummy constrcutor
	clsString() {
		_value = "";
		_message = "";
	}

	clsString(string value) {
		_value = value;
		_message = "";
		_whichToCount = enWhichCaseToCount::enLOWER_CASE;
	}

	void setString(string value) {
		_value = value;
	}

	string getString() {
		return _value;
	}

	__declspec(property(get = getString, put = setString)) string value;

	/*====== set and get enum */

	void setWhichCaseToCountToEnum(int choice) {
		_whichToCount = (enWhichCaseToCount) choice;
	}

	enWhichCaseToCount getWhichCaseToCountEnum() {
		return _whichToCount;
	}

	__declspec(property(get = getWhichCaseToCountEnum, put = setWhichCaseToCountToEnum)) enWhichCaseToCount whichCaseToCount;

	/*================ get string length*/

	static int strLength(string str) {
		return str.length();
	}

	int strLength() {
		return _value.length();
	}

	/*=========== count words*/

	// generic
	static short countWords(string str, string delimeter = " ") {
		// locate delimeter position
		int delimPos{};
		// count words
		short cnt{0};
		// find token
		string token{};
		while ((delimPos = str.find(delimeter)) != std::string::npos) {
			token = str.substr(0, delimPos);
			// ignore pre-element and adjacent delimeters
			if (token != "")
				cnt++;
			// remove old token
			str.erase(0, delimPos + delimeter.length());
		}
		// ignore post-delimeter and consider single word case
		if (str != "")
			cnt++;
		return cnt;
	}

	// specific
	short countWords(string delimeter= " ") {
		/*return countWords(*this->_value);*/
		return countWords(_value,delimeter);
	}

	/*========is all upper case*/

	static bool isAllUpperCase(string str) {
		for (const char& C : str)
			// ignore white spaces
			if (_isLowerChar(C) && C != ' ')
				return false;

		return true;
	}

	bool isAllUpperCase() {
		return isAllUpperCase(_value);
	}

	/*======= is all lower case*/

	static bool isAllLowerCase(string str) {
		for (const char& C : str)
			// ignore white spaces
			if (_isUpperChar(C) && C != ' ')
				return false;

		return true;
	}

	bool isAllLowerCase() {
		return isAllLowerCase(_value);
	}

	/*============== convert to lower case*/

	static string lowerCaseWholeString(string str) {
		for (char& c : str)
			_convertToLowerChar(c);
		return str;
	}

	void lowerCaseWholeString() {
		_value = lowerCaseWholeString(_value);
	}

	/*================= convert to upper case*/

	static string upperCaseWholeString(string str) {
		for (char& c : str)
			_convertToUpperChar(c);
		return str;
	}

	void upperCaseWholeString() {
		_value =  upperCaseWholeString(_value);
	}

	/*============== upper case first letter in each word*/

	static string upperCaseFirstLetterInEachWord(string str, string delimeter = " ") {
		// locate delimeter position
		int delimPos{};
		string token{}, newString{};

		while ((delimPos = str.find(delimeter)) != std::string::npos) {
			token = str.substr(0, delimPos);
			if (token != "") {
				_convertToUpperChar(token[0]);
				newString += token+" ";
			}
				
			str.erase(0, delimPos + delimeter.length());
		}
		if (str != "") {
			_convertToUpperChar(str[0]);
			newString += str;
		}
		
		return newString;
	}

	void upperCaseFirstLetterInEachWord(string delimeter = " ") {
		_value =  upperCaseFirstLetterInEachWord(_value, delimeter);
	}

	/*=================== lower case first letter in each word*/

	static string lowerCaseFirstLetterInEachWord(string str, string delimeter = " ") {
		// locate delimeter position
		int delimPos{};
		string token{}, newString{};

		while ((delimPos = str.find(delimeter)) != std::string::npos) {
			token = str.substr(0, delimPos);
			if (token != "") {
				_convertToLowerChar(token[0]);
				newString += token +" ";
			}

			str.erase(0, delimPos + delimeter.length());
		}
		if (str != "") {
			_convertToLowerChar(str[0]);
			newString += str;
		}

		return newString;
	}

	void lowerCaseFirstLetterInEachWord(string delimeter = " ") {
		_value = lowerCaseFirstLetterInEachWord(_value, delimeter);
	}

	/*=============== read a string*/

	// no need for non-static function member since have setters!
	static string readString(const string& MESSAGE) {
		cout << MESSAGE << endl;
		string temp{};
		cin >> temp;
		return temp;
	}

	static string readEntireLine(const string& MESSAGE) {
		cout << MESSAGE << endl;
		string temp{};
		getline(cin >> ws, temp);
		return temp;
	}

	/*======= print first char */

	static void printFirstLetterOfEachWord(string str, string delimeter = " ") {
		// locate delimeter position
		int delimPos{};
		string token{};
		while ((delimPos = str.find(delimeter)) != std::string::npos) {
			token = str.substr(0, delimPos);
			if (token != "")
				cout << token[0] << endl;
			str.erase(0, delimPos + delimeter.length());
		}
		if (str != "")
			cout << str[0] << endl;
	}

	void printFirstLetterOfEachWord(string delimeter = " ") {
		printFirstLetterOfEachWord(_value, delimeter);
	}

	/*====== invert all letters case*/

	static string invertLettersCase(string str) {

		for (char& c : str) {
			if (_isLowerChar(c))
				_convertToUpperChar(c);
			else
				_convertToLowerChar(c);
		}
		return str;

	}

	void invertLettersCase() {
		_value = invertLettersCase(_value);
	}

	/*========= count letters case*/

	 short countWhichCase(enWhichCaseToCount whichCaseToCount = enWhichCaseToCount::enLOWER_CASE) {
		switch (whichCaseToCount) {
		case enWhichCaseToCount::enLOWER_CASE:
			return countLowerLetters(_value);
		case enWhichCaseToCount::enUPPER_CASE:
			return countUpperLetters(_value);
		case enWhichCaseToCount::enSPECIAL_CHARS:
			return countSpecialChars(_value);
		case enWhichCaseToCount::enDIGITS:
			return countDigits(_value);
		case enWhichCaseToCount::enTwoCases:
			return countLowerLetters(_value) + countUpperLetters(_value);
		}
	}

	/*================ count char repeatitions*/

	 // case sinsitive!
	 static short countCharRepeatitionCaseSinsitive(string str, char c) {
		 short cnt{};
		 for (const char& C : str) {
			 if (C == c)
				 cnt++;
		 }
		 return cnt;
	 }

	 short countCharRepeatitionCaseSinsitive(char c) {
		 return countCharRepeatitionCaseSinsitive(_value, c);
	 }

	 static short countCharRepeatitionCaseInsinsitive(string str, char c) {
		 str = lowerCaseWholeString(str);
		 _convertToLowerChar(c);
		 return countCharRepeatitionCaseSinsitive(str, c);
	 }

	 short countCharRepeatitionCaseInsinsitive(char c) {
		 return countCharRepeatitionCaseInsinsitive(_value, c);
	 }

	 /*============ count is a vowel*/

	 static bool isVowelCaseInsinsitive(char c) {
		 _convertToLowerChar(c);
		 return (c == 97 || c == 101 || c == 105 || c == 111 || c == 117);
	 }

	 /*================== count vowels*/

	 static short countVowelsCaseInsinsitive(string str) {
		 short cnt{};
		 for (const char& C : str)
			 if (isVowelCaseInsinsitive(C))
				 cnt++;
		 return cnt;
	 }

	 short countVowelsCaseInsinsitive() {
		 return countVowelsCaseInsinsitive(_value);
	 }

	 /*========== print vowels*/

	 static void printVowelsCaseInsinsitive(string str) {
		 for (const char& C : str) {
			 if (isVowelCaseInsinsitive(C))
				 cout << C << " ";
		 }
		 cout << endl;
	 }

	 void printVowelsCaseInsinsitive() {
		 return printVowelsCaseInsinsitive(_value);
	 }

	 /*=============== split string*/

	 static vector<string> splitString(string str, string delimeter = " ") {
		 // define a container
		 vector<string> vTokens{};
		 // locate delimeter position
		 int delimPos{};
		 // find token
		 string token{};
		 while ((delimPos = str.find(delimeter)) != std::string::npos) {
			 token = str.substr(0, delimPos);
			 // ignore pre-element and adjacent delimeters
			 if (token != "")
				 vTokens.push_back(token);
			 // remove old token
			 str.erase(0, delimPos + delimeter.length());
		 }
		 // ignore post-delimeter and consider single word case
		 if (str != "")
			 vTokens.push_back(str);
		 return vTokens;
	 }

	 vector<string> splitString(string delimeter = " ") {
		 return splitString(_value, delimeter);
	 }

	 /*============== print each word*/

	 static void printEachWord(string str, string delimeter) {
		 vector<string> vTokens = splitString(str, delimeter);
		 vector<string>::iterator ptr = vTokens.begin();
		 while (ptr != vTokens.end()) {
			 cout << *ptr++ << " ";
		 }
		 cout << endl;
	 }

	 void printEachWord(string delimeter) {
		 printEachWord(_value, delimeter);
	 }

	 /*==================== print string*/
	 static void printStr(string str) {
		 cout << str << endl;
	 }

	 void printStr() {
		 printStr(_value);
	 }

	 /*======= trim string; change space with a special char to check!*/

	 static string trimLeft(string str) {
		 for (int i = 0; i < str.length(); i++) {
			 if (str[i] == ',')
				 continue;
			 else {
				 return str.erase(0, i);

			 }

		 }
	 }

	 string trimLeft() {
		 return trimLeft(_value);
	 }

	 static string trimright(string str) {
		 int i = str.length() - 1;
		 while (i--) {
			 if (str[i] == ',')
				 continue;
			 else
				 return str.erase(i+1, str.length() - i);
		 }
	 }

	 string trimright() {
		 return trimright(_value);
	 }

	 static string trim(string str) {
		 return trimLeft(trimright(str));
	 }

	 string trim() {
		 return trim(_value);
	 }

	 /*============== join string*/

	 static string joinString(vector<string> vTokens, string delimeter = " ") {
		 string temp{};

		 vector<string>::iterator ptr = vTokens.begin();
		 while (ptr != vTokens.end() -1)
			 temp += *ptr++ + delimeter;
		 
		 return temp += *ptr;
	 }

	 static string joinString(string array[], int length, string delimeter = " ") {
		 string temp{};
		 for (int i = 0; i < length; i++)
			 temp += array[i] + delimeter;
		 return temp.substr(0, temp.length() - delimeter.length());
	 }

	 /*================ reverse string in right order*/

	 static string reverseString(string str, string delimeter = " ") {
		 // get each token
		 vector<string> vTokens = splitString(str, delimeter);
		 // vTokens.end() ---> points at its right side which is NULL since there's nothing after end
		 // however, this will point at the right to the last value!
		 vector<string>::iterator ptr = vTokens.end() -1;
		 
		 string temp{};
		 while (ptr != vTokens.begin())
			 temp += *ptr-- + delimeter;
		 temp += *ptr;
		 return temp;
	 }

	 void reverseString(string delimeter = " ") {
		 _value = reverseString(_value, delimeter);
	 }

	 /*================ replace string*/

	 static string replaceString(string str,string oldWord, string newWord, string delimeter, bool matchCase = true) {
		 // get tokens
		 vector<string> vTokens = splitString(str,delimeter);
		 for (int i = 0; i < vTokens.size(); i++) {
			 if (!matchCase) {
				 if (lowerCaseWholeString(vTokens[i]) == lowerCaseWholeString(oldWord))
					 vTokens[i] = newWord;
			 }
			 else if (vTokens[i] == oldWord)
					vTokens[i] = newWord;
		 }
		
		 return joinString(vTokens, delimeter);
	 }

	 void replaceString(string oldWord, string newWord, string delimeter, bool matchCase = true) {
		 _value =  replaceString(_value, oldWord, newWord, delimeter, matchCase);
	 }

	 /*=================== remove punctuation*/

	 static string removePunctuation(string str) {
		 string temp{};
		 for (const char& C : str) {
			 if (!_isSpecialChar(C))
				 temp += C;
		 }
		 return temp;
	}

	 void removePunctuation() {
		 _value = removePunctuation(_value);
	 }

	 /*------------------------- repeat string*/

	 static string repeatString(string str, int times) {
		 string temp{};
		 while (times--)
			 temp += str;
		 return temp;
	 }

	 string repeatString(int times) {
		 return repeatString(_value, times);
	 }

};

