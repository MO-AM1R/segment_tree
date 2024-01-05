# include "SegmentTree.h"

/**
 * @brief main function to test program
 */
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    SegmentTree segmentTree(arr, 6);
    cout << segmentTree << endl ; // Segment Tree: [36, 9, 27, 4, 5, 16]

    cout << segmentTree.getSum(0, 3) << endl ; // 16

    segmentTree.update(1, 10); // {1, 10, 5, 7, 9, 11}
    cout << segmentTree.getSum(0, 3) << endl ; // 23

    segmentTree.update(0, 0); // {0, 10, 5, 7, 9, 11}
    cout << segmentTree.getSum(0, 3) << endl ; // 22

    // Example on exception
    segmentTree.update(6, 1);

    return 0;
}