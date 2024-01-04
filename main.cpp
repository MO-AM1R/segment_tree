# include "SegmentTree.h"

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    SegmentTree segmentTree(arr, 6);
    cout << segmentTree << endl ;
    cout << segmentTree.getSum(0, 1);
    return 0;
}