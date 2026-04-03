class Solution {
public:
    int mySqrt(int x) {

        if (x == 0 || x == 1) return x;
    int i = 0;
    int j = x;

    while (i < j) {
        int mid = i + (j - i) / 2;
        long long sq = 1LL * mid * mid;

        if (sq > x) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }

    return i - 1;
}
};