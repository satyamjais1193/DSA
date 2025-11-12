#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
    string convertDateToBinary(string date) {
        // Extract year, month, day
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        // Convert to binary without leading zeros
        string yearBin = toBinary(year);
        string monthBin = toBinary(month);
        string dayBin = toBinary(day);
        
        return yearBin + "-" + monthBin + "-" + dayBin;
    }
    
private:
    string toBinary(int n) {
        if (n == 0) return "0";
        string binary = "";
        while (n > 0) {
            binary = to_string(n % 2) + binary;
            n /= 2;
        }
        return binary;
    }
};