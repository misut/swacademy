#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

typedef unsigned int uint;

int main() {
    uint N = 0, K = 0;
    uint cases = 0;

    cin >> cases;
    for(int h=0; h<cases; ++h) {
        string cnums;

        cin >> N >> K;
        cin >> cnums;
        uint nlen = N/4;
        vector<uint> nums(N, 0);
        for(int i=0; i<N; ++i) {
            uint ch = cnums[i];
            uint num = ch>'9' ? ch-'A'+10 : ch-'0';
            uint sixteens = 1;
            for(int j=0; j<nlen; ++j) {
                nums[(i+j)%N] += num*sixteens;
                sixteens *= 16;
            }
        }
        set<uint> s(nums.begin(), nums.end());
        nums.assign(s.begin(), s.end());
        sort(nums.begin(), nums.end(), greater<uint>());
        cout << '#' << h+1 << ' ' << nums[K-1] << endl;
    }
}
