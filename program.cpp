#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void printDp(const std::vector<std::vector<bool>>& dp) {
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Min Br

bool abbreviation(string a, string b) {
    std::vector<std::vector<bool>> dp(a.size() + 1, std::vector<bool>(b.size() + 1, false));
    dp[0][0] = true;
    // init first row
    for (int i = 1; i < dp[0].size(); ++i) {
        dp[0][i] = false;
    }
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 0; j < dp[0].size(); ++j) {
            char lastA = a[i - 1]; // b
            char lastB = j >= 1 ? b[j - 1] : ' '; // A
            if (islower(lastA)) {
                // del
                if (dp[i - 1][j]) dp[i][j] = true;
            } 
            // cast if needed
            if (j >= 1 && toupper(lastA) == lastB) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
            } 
        }
    }
    printDp(dp);
    return dp[dp.size() - 1][dp[0].size() - 1];
}

int main(void) {
    std::string s1 = "BFZZVHdQYHQEMNEFFRFJTQmNWHFVXRXlGTFNBqWQmyOWYWSTDSTMJRYHjBNTEWADLgHVgGIRGKFQSeCXNFNaIFAXOiQORUDROaNoJPXWZXIAABZKSZYFTDDTRGZXVZZNWNRHMvSTGEQCYAJSFvbqivjuqvuzafvwwifnrlcxgbjmigkms";
    std::string s2 = "BFZZVHQYHQEMNEFFRFJTQNWHFVXRXGTFNBWQOWYWSTDSTMJRYHBNTEWADLHVGIRGKFQSCXNFNIFAXOQORUDRONJPXWZXIAABZKSZYFTDDTRGZXVZZNWNRHMSTGEQCYAJSF";
    bool res = abbreviation(s1, s2);
    std::cout << "res: " << std::boolalpha << res << std::endl;
    return 0;
}

// Take string a and try to modif it into a string b, such that by capitalizing some a's letters
// Or can go to any letter of a, and delete all other lowercase letters in a 
// If possible to first capitalize some of a's lower case letter, and delete all remaining lowecase -> becomes b

// AbcDE ABcDE ABDE
// ABDE
// AbcDE 
// ADEF
// all the upper case in A -> preseved, 
// optionally includeing some of orignal lwoer case 
// lower case: Abc -> Ab; ABC
// a, b: 
// AbD
// ABD
    // "" A B D
// ""  t  f f f
// A   f  t f f
// b   f  t t f 
// D   f  f f t
// beFgH
// EFH
// should be true

