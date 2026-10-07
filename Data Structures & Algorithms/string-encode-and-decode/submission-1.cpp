class Solution {
public:

    string encode(vector<string>& strs) {
        string sum = "";
        for (const auto& str : strs)
        {
            for (char c : str)
            {
                sum += c;
            }
            sum += (char)1;
        }
        return sum;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string buffer = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 1)
            {
                strs.push_back(buffer);
                buffer = "";
            }
            else
            {
                buffer += s[i];
            }
        }
        return strs;
    }
};
