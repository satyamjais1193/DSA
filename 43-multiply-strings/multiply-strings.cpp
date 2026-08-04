class Solution {
public:
    string multiply(string num1, string num2) {

        int n = num1.size();
        int m = num2.size();

        vector<int> v(n + m + 1, 0);

        // Store all products
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                v[(n - 1 - i) + (m - 1 - j)] +=
                    (num1[i] - '0') * (num2[j] - '0');
            }
        }
        
        for(int i : v)cout<<i<<" ";cout<<endl;

        // Handle carry
        for (int i = 0; i < n + m; i++) {
            v[i + 1] += v[i] / 10;
            v[i] %= 10;
        }
        for(int i : v)cout<<i<<" ";

        reverse(v.begin(), v.end());

        int first = 0;
        while (first < v.size() && v[first] == 0)
            first++;

        if (first == v.size())
            return "0";

        string ans = "";
        while (first < v.size())
            ans += char(v[first++] + '0');

        return ans;
    }
};