# include "SegmentTree.h"

int main() {
    int arr[] = {1, 3, 4, 4};
    SegmentTree segmentTree(arr, 4);
    cout << segmentTree;
    return 0;
}