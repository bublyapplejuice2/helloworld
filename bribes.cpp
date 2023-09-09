#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Each person wears sticker with initial position: 1 - n
// Any can bribe directly in front to (left) to swap positions, but wear orgiinal numbe
// Bribe at most 2 other people
// minimum of swaps (total) to get to a specific ordering
// [1,2,3,4,5,6,7,8]
// 5 bribes 4
// [1,2,3,5,4,6,7,8] 1 bribe
// 4 brib 5
// [1,2,3,4,5,6,7,8]
// print too choatic if anyone has bribed 2 ppl, attempts a 3rd bribe
// initialize the array of ordering: 1 - n
// q = target
// [1, 2, |3, 4, 5, |]
// [2, 1, |5, 3, 4|] .. [2, 5, 1, 3, 4] no work
//  1   0    2   0  0   0  0  2  1  1 num elemts before me that is smaller
                             3   0    0  0  num elemnts after me that is smaller
                             //sort incr :  1 2 3 4 5
//                      [1, 2, 3, 4, 5]
// 4 3 5 1
// 4 5 3 1
// 5 4 3 1
// 5 3 4 1
// 5 3 1 4

// 3 5 4 1 1
// 5 3 4 1 2
// 5 3 1 4 3

// [2, 1, 5, 3, 6, 4]
// c num left larger -> sw
// 0   1  0  1  0   2
// [1, 2, 3, 5, 4, 6]


// // [2, 1, |5, 3, 4|]
//    0   1   0  1   1
//        3 
// how many elemnts before me are larger

// 
// 5 bribes 4, 5 bribes 3
// 2 bribes 1
// print 3
// [1, 2, 5, 4]
// [1, 2, 3, 4, 5, 6]
// [3, 1, 4, 2, 6, 5]
// [2  0  1  0  1  0]
// 4 swaps?
// [1  3  4  2  6  5]
// [2, 1, 5, 3, 4]
// [1, 2, 3, 4, 5]
// [1, 1, 2, 1, 1] = diff
// 6

// [1, 2, 3, 4, 5, 6, 7]
// [2, 3, 1, 6, 7, 4, 5]
// diff
// 1   1  0  2  2  0  0 -> count elemtns to the right that are smaller -> 6
// [1  1  2  2  2  2  2] -> 2 + 2 * 5 = 12 diff / 2
// 6 swaps
void minimumBribes(vector<int>& q) {

    // 1...n (sorted)
    // while not sorted
        // iterate over the entirety of q
        // if the value to yuor right is smaller
            // then you must have swapped
            // another array which holds the number of swaps per person
            // go to that index, increment it
            // swap the elements

    int totalBribes = 0;
    // loop through elem backwards, starting their, count how many elemts to the right are smaler
    // > 2, print chaotic
    // add to sum
    for (int i = q.size() - 1; i >= 0; --i) {
        int num = q[i];
        int smallerElems = 0;
        for (int j = i + 1; j < q.size(); ++j) {
            if (q[j] < num) {
                ++smallerElems;
                if (smallerElems > 2) {
                    std::cout << "Too Chaotic" << std::endl;
                    return;
                }
            }
            totalBribes += smallerElems;
            // 5        3
            // 3        5
            q[i] = q[j]
            
        }
    }
    std::cout <<  totalBribes << std::endl;
}

int main() {
    return 0;
}