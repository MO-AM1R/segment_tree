# ifndef SEGMENTTREE_SEGMENTTREE_H
# define SEGMENTTREE_SEGMENTTREE_H
# include <iostream>
# include <cmath>

using namespace std;

/**
 * @brief Class Segment Tree
 * @author Mohamed Amir
 * @version 1.0
 */
class SegmentTree {
    int* arr;
    int size;
    int length;

    /**
     * A private method which will build the Tree
     * @param nums represent the array of the numbers
     * @param l represent the left of the current interval
     * @param r represent the right of the current interval
     * @param index represent the index of the current node
     */
    int build(const int nums[], int l, int r, int index){
        if (l == r){
            arr[index] = nums[l];
            return arr[index];
        }

        int midIndex = (r + l) / 2;
        arr[index] = build(nums, l, midIndex, index * 2 + 1) +
                build(nums, midIndex + 1, r, index * 2 + 2);

        return arr[index];
    }

    /**
     * A private method its role to get the sum of specific interval
     * @param l represent the current left interval
     * @param r represent the current right interval
     * @param queryLeft represent the left interval of the target
     * @param queryRight represent the right interval of the target
     * @param index represent the index of the current node
     * @return an integer value represent the sum of the interval
     */
    [[nodiscard]] int getSum(int l, int r, int queryLeft, int queryRight, int index){
        if (l >= queryLeft && r <= queryRight){ // case 1 -> Total overlap
            return arr[index];
        }
        else if (l > queryRight || r < queryLeft){ // case 2 No overlap
            return 0;
        }

        int midIndex = (l + r) / 2;
        return getSum(l, midIndex, queryLeft, queryRight, 2 * index + 1)
        + getSum(midIndex + 1, r, queryLeft, queryRight, 2 * index + 2) ;
    }
public:
    SegmentTree() = default;

    /**
     * A parameterized constructor that initialize the @property size and arr
     *
     * and build the Tree
     * @param nums represent the array which contains the numbers
     * @param n represent the size of the array
     */
    explicit SegmentTree(const int nums[], int _size) : length(_size){
        int height = (int)(ceil(log2(_size)));
        size = 2 * (int)pow(2, height) - 1;
        arr = new int[size] {0};

        build(nums, 0, length - 1, 0);
    }

    /**
     * A wrapper function to get the sum of specific interval
     * @param l represent the current left interval
     * @param r represent the current right interval
     * @return an integer value represent the sum of the interval
     */
    [[nodiscard]] int getSum(int l, int r){
        return getSum(0, length - 1, l, r, 0);
    }

    friend ostream& operator <<(ostream& os, const SegmentTree& tree) {
        os << "Segment Tree: [";

        for (int i = 0; i < tree.length; ++i) {
            if (i == tree.length - 1){
                os << tree.arr[i] << "]";
                break;
            }
            os << tree.arr[i] << ", ";
        }

        return os;
    }

    /**
     * A destructor which will free the tree
     */
    ~SegmentTree(){
        delete[] arr;
        size = 0;
    }
};

# endif //SEGMENTTREE_SEGMENTTREE_H