#include <iostream>
#include <cmath>
#include "clsUtil.h"
using namespace std;



int main()
{



    int array[100]{};
    int len{};

    clsUtil::incrementArray(array, len);
    clsUtil::printArray(array, len);



	return 0;
}




/*




void incrementArray(int array[], int& len) {
    int number{}; bool  reply{};
    do {
        storeNumberInArray(readPositiveNumber("please,Enter a number", ""), array, len);

        cout << "Do you want to add more numbers [0] no - [1] yes? ";
        cin >> reply;

    } while (reply);
}

int countEvenNumberInArray(int array[], int len) {
    int cnt{};
    for (int i = 0; i < len; i++) {
        if (array[i] % 2 == 0)
            cnt++;
    }
    return cnt;
}

string repearString(string str, int numOfRepeatition) {
    string key{ "" };
    for (int number = 0; number < numOfRepeatition; number++)
        key += str;
    return key;
}

void gameOverScreen() {
    cout << '\n' << repearString("\t", 4) << repearString("_", 60) << '\n';
    cout << '\n' << repearString("\t", 5) << "+++ Game Over +++\n";
    cout << '\n' << repearString("\t", 4) << repearString("_", 60) << '\n';
}
*/