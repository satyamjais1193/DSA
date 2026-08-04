class Solution {
public:
    vector<string> result;

    void generateExpressions(string &num,
                             int target,
                             int currentIndex,
                             string currentExpression,
                             long long currentValue,
                             long long previousOperand) {

        // If all digits are used
        if (currentIndex == num.size()) {
            if (currentValue == target) {
                result.push_back(currentExpression);
            }
            return;
        }

        long long currentNumber = 0;
        string currentNumberString = "";

        // Form every possible number starting from currentIndex
        for (int index = currentIndex; index < num.size(); index++) {

            // Prevent numbers like 05, 007, etc.
            if (index > currentIndex && num[currentIndex] == '0')
                break;

            currentNumber = currentNumber * 10 + (num[index] - '0');
            currentNumberString += num[index];

            // First number (no operator before it)
            if (currentIndex == 0) {

                generateExpressions(num,
                                    target,
                                    index + 1,
                                    currentNumberString,
                                    currentNumber,
                                    currentNumber);
            }
            else {

                // Addition
                generateExpressions(num,
                                    target,
                                    index + 1,
                                    currentExpression + "+" + currentNumberString,
                                    currentValue + currentNumber,
                                    currentNumber);

                // Subtraction
                generateExpressions(num,
                                    target,
                                    index + 1,
                                    currentExpression + "-" + currentNumberString,
                                    currentValue - currentNumber,
                                    -currentNumber);

                // Multiplication
                generateExpressions(num,
                                    target,
                                    index + 1,
                                    currentExpression + "*" + currentNumberString,
                                    currentValue - previousOperand + previousOperand * currentNumber,
                                    previousOperand * currentNumber);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        generateExpressions(num, target, 0, "", 0, 0);

        return result;
    }
};