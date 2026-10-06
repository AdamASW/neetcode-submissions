class Solution {
public:

    string encode(vector<string>& strs) {
        string n;
        string encoded_string = "";
        for (string str : strs) {
            n = to_string(str.size());
            while (n.size() < 4) {
                n = "0" + n;
            }
            // String length is less than 100, so we can represent n as 4 digits.
            encoded_string.append(n);
            encoded_string.append(str);
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string = {};
        int n;
        int l = 0;
        string curr_n, curr_substr;
        while(l < s.size()) {
            curr_n = s.substr(l,4);
            n = stoi(curr_n);
            l += 4;
            curr_substr = s.substr(l,n);
            decoded_string.push_back(curr_substr);
            l += n;
        }
        return decoded_string;
    }
};
