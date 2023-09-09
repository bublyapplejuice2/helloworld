#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <string>

using namespace std;

// facts parser

// <12 in, 1 ft>
// <1ft, 2m>
// <1 yd, 3 ft>
// <1 hr, 3600 sec>
// <365 day, 1 yr>
// <60 min, 1 hr>

// 5 in, return ft you should be to do this
// 5 in, yr cannot do this

class FactParser {
public:
    FactParser(const std::vector<std::pair<std::string, std::string>>& facts) {
        // extract unit1, val1, unit2, val2
        for (const auto& p : facts) {
            int index = p.first.find(' ');
            std::string left = p.first.substr(0, index);
            std::string unit1 = p.first.substr(index + 1);
            int val1 = stoi(left);
            
            index = p.second.find(' ');
            left = p.second.substr(0, index);
            std::string unit2 = p.second.substr(index + 1);
            int val2 = stoi(left);

            double proportion = static_cast<double>(val2) / val1;
            proportions[unit1][unit2] = proportion;

            double backwardProportion = static_cast<double>(val1) / val2;
            proportions[unit2][unit1] = backwardProportion;
        }
        printMap();
    }

    void query(const std::string& info1, const std::string& unit2) {
        int index = info1.find(' ');
        std::string left = info1.substr(0, index);
        std::string unit1 =info1.substr(index + 1);
        int unit1Amount = stoi(left);
        std::unordered_set<std::string> visited;
        std::queue<std::pair<std::string, double>> q; // <unit, propFroStart>
        double accumulatedProp = 1;
        visited.insert(unit1);
        q.push({unit1, 1});
        while (!q.empty()) {
            std::string node = q.front().first; 
            double currProp = q.front().second;
            if (node == unit2) {
                double res = unit1Amount * currProp;
                std::cout << unit1Amount << " " << unit1 << " is equal to " << res << " " << unit2 << std::endl; 
                return;
            }
            q.pop();
            for (const auto& kv : proportions[node]) {
                std::string nextNode = kv.first;
                double prop = kv.second;
                if (visited.count(nextNode)) continue;
                double nextProp = currProp * prop;
                visited.insert(nextNode);
                q.push({nextNode, nextProp});
            }
        }
        std::cout << "Not Available Conversion" << std::endl;
        return;
    }

private:
    std::unordered_map<std::string, std::unordered_map<std::string, double>> proportions;

    void printMap() {
        for (const auto& kv : proportions) {
            for (const auto& pair : kv.second) {
                std::cout << "u1, u2, proportion: " << kv.first << ",  " << pair.first << ", " << pair.second << std::endl;
            }
        }
    }
};

int main() {
    std::vector<std::pair<std::string, std::string>> facts {{"12 in", "1 ft"}, {"1 yd", "3 ft"}, {"5280 ft", "1 mi"}, {"1 hr", "3600 sec"}, {"365 day", "1 yr"}, {"60 min", "1 hr"}, {"24 hr", "1 day"}, {"7 day", "1 week"}};
    FactParser fp(facts);
    fp.query("1 in", "yr");
    fp.query("178 week", "yr");
    fp.query("9 sec", "week");
}