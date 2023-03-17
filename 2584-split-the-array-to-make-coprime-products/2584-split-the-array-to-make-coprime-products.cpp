class Solution {
public:
    vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; n > 1 && i < 1000; i += 1 + (i % 2))
        if (n % i == 0) {
            res.push_back(i);
            while(n % i == 0)
                n /= i;
        }
    if (n > 1)
        res.push_back(n);
    return res;
}
int findValidSplit(vector<int>& nums) {
    unordered_map<int, int> fi;
    int line[10001] = {};
    for (int i  = 0; i < nums.size(); ++i)
        for (int f : factorize(nums[i])) {
            if (fi.count(f) == 0)
                fi[f] = i;
            ++line[fi[f]];
            --line[i];
        }
    partial_sum(begin(line), end(line), begin(line));
    int res = find(begin(line), end(line), 0) - begin(line);
    return res < nums.size() - 1 ? res : -1;
}
};