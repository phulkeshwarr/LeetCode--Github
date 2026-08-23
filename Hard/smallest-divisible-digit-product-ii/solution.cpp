class Solution {
    static bool initialized;
    static string dp_str[50][35];
    static int dp_len[50][35];

    static void init() {
        if (initialized) return;
        initialized = true;
        
        // Initialize DP table with infinity-like values
        for (int i = 0; i < 50; ++i) {
            for (int j = 0; j < 35; ++j) {
                dp_len[i][j] = 1000; 
                dp_str[i][j] = "";
            }
        }
        
        dp_len[0][0] = 0;
        dp_str[0][0] = "";
        
        // Precompute the shortest string of digits to get at least i 2-factors and j 3-factors
        for (int i = 0; i < 50; ++i) {
            for (int j = 0; j < 35; ++j) {
                if (i == 0 && j == 0) continue;
                
                string best_s = "";
                int best_l = 1000;
                
                // Try appending valid digits that provide 2s and 3s
                for (int d : {2, 3, 4, 6, 8, 9}) {
                    int f2 = (d == 8) ? 3 : (d == 4) ? 2 : (d == 2 || d == 6) ? 1 : 0;
                    int f3 = (d == 9) ? 2 : (d == 3 || d == 6) ? 1 : 0;
                    
                    int pi = max(0, i - f2);
                    int pj = max(0, j - f3);
                    
                    if (dp_len[pi][pj] + 1 < best_l) {
                        best_l = dp_len[pi][pj] + 1;
                        best_s = dp_str[pi][pj] + to_string(d);
                        sort(best_s.begin(), best_s.end());
                    } else if (dp_len[pi][pj] + 1 == best_l) {
                        string cand = dp_str[pi][pj] + to_string(d);
                        sort(cand.begin(), cand.end());
                        if (cand < best_s) {
                            best_s = cand;
                        }
                    }
                }
                dp_len[i][j] = best_l;
                dp_str[i][j] = best_s;
            }
        }
    }

public:
    string smallestNumber(string num, long long t) {
        init(); // O(1) Precomputation step
        
        long long temp = t;
        int t2 = 0, t3 = 0, t5 = 0, t7 = 0;
        while (temp % 2 == 0) { temp /= 2; t2++; }
        while (temp % 3 == 0) { temp /= 3; t3++; }
        while (temp % 5 == 0) { temp /= 5; t5++; }
        while (temp % 7 == 0) { temp /= 7; t7++; }
        
        // If t has prime factors other than 2, 3, 5, 7, it's impossible.
        if (temp > 1) return "-1"; 
        
        int n = num.length();
        vector<int> pref2(n + 1, 0), pref3(n + 1, 0), pref5(n + 1, 0), pref7(n + 1, 0);
        int zero_idx = -1;
        
        // Precalculate prime factors for every prefix of 'num'
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0' && zero_idx == -1) {
                zero_idx = i;
            }
            int d = num[i] - '0';
            pref2[i+1] = pref2[i] + (d == 8 ? 3 : d == 4 ? 2 : (d == 2 || d == 6) ? 1 : 0);
            pref3[i+1] = pref3[i] + (d == 9 ? 2 : (d == 3 || d == 6) ? 1 : 0);
            pref5[i+1] = pref5[i] + (d == 5 ? 1 : 0);
            pref7[i+1] = pref7[i] + (d == 7 ? 1 : 0);
        }
        
        // Greedily match prefixes from longest to shortest
        for (int i = n; i >= 0; --i) {
            // If the prefix we are trying to keep contains a '0', it's invalid
            if (zero_idx != -1 && i > zero_idx) continue;
            
            if (i == n) {
                int rem2 = max(0, t2 - pref2[n]);
                int rem3 = max(0, t3 - pref3[n]);
                int rem5 = max(0, t5 - pref5[n]);
                int rem7 = max(0, t7 - pref7[n]);
                
                // If the exact number works, return it
                if (rem2 == 0 && rem3 == 0 && rem5 == 0 && rem7 == 0) {
                    return num;
                }
            } else {
                int start_d = num[i] - '0' + 1;
                for (int d = start_d; d <= 9; ++d) {
                    int p2 = pref2[i] + (d == 8 ? 3 : d == 4 ? 2 : (d == 2 || d == 6) ? 1 : 0);
                    int p3 = pref3[i] + (d == 9 ? 2 : (d == 3 || d == 6) ? 1 : 0);
                    int p5 = pref5[i] + (d == 5 ? 1 : 0);
                    int p7 = pref7[i] + (d == 7 ? 1 : 0);
                    
                    int rem2 = max(0, t2 - p2);
                    int rem3 = max(0, t3 - p3);
                    int rem5 = max(0, t5 - p5);
                    int rem7 = max(0, t7 - p7);
                    
                    int req_len = dp_len[rem2][rem3] + rem5 + rem7;
                    int rem_places = n - 1 - i;
                    
                    // If we have enough remaining digits to fit the required factors
                    if (req_len <= rem_places) {
                        string suff = dp_str[rem2][rem3] + string(rem5, '5') + string(rem7, '7');
                        suff += string(rem_places - req_len, '1'); // Pad with 1s
                        sort(suff.begin(), suff.end());
                        return num.substr(0, i) + to_string(d) + suff;
                    }
                }
            }
        }
        
        // If no string of length `n` works, create the optimal string of longer length
        int req_len = dp_len[t2][t3] + t5 + t7;
        int L = max(n + 1, req_len);
        
        string ans = dp_str[t2][t3] + string(t5, '5') + string(t7, '7');
        ans += string(L - req_len, '1');
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Initialize static variables
bool Solution::initialized = false;
string Solution::dp_str[50][35];
int Solution::dp_len[50][35];