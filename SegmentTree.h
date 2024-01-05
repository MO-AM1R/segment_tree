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
    int* segmentArray;
    int* nums;
    int size;
    int length;

    /**
     * A private method which will build the Tree
     * @param nums represent the array of the numbers
     * @param l represent the left of the current interval
     * @param r represent the right of the current interval
     * @param index represent the index of the current node
     */
    int build(const int& l, const int& r, const int& index){
        if (l == r){
            segmentArray[index] = nums[l];
            return segmentArray[index];
        }

        int midIndex = (r + l) / 2;
        segmentArray[index] = build(l, midIndex, index * 2 + 1) +
                build(midIndex + 1, r, index * 2 + 2);

        return segmentArray[index];
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
    [[nodiscard]] int getSum(const int& l, const int& r, const int& queryLeft, const int& queryRight, const int& index){
        if (l >= queryLeft && r <= queryRight){ // case 1 -> Total overlap
            return segmentArray[index];
        }
        else if (l > queryRight || r < queryLeft){ // case 2 No overlap
            return 0;
        }

        int midIndex = (l + r) / 2;
        return getSum(l, midIndex, queryLeft, queryRight, 2 * index + 1)
        + getSum(midIndex + 1, r, queryLeft, queryRight, 2 * index + 2) ;
    }

    /**
     * A private method its role to update specific value in the array
     * @param l represent the current left interval
     * @param r represent the current right interval
     * @param diff represent the difference between the old and new value
     * @param index represent the index of the current node
     * @param position represent the index of the old value
     */
    void update(const int& l, const int& r, const int& diff, const int& index, const int& position){
        if (l > position || r < position){
            return;
        }

        segmentArray[index] += diff;
        if (r != l){
            int midIndex = (l + r) / 2;
            update(l, midIndex, diff, 2 * index + 1, position);
            update(midIndex + 1, r, diff, 2 * index + 1, position);
        }
    }

public:
    SegmentTree() = default;

    /**
     * A parameterized constructor that initialize the @property size and segmentArray
     *
     * and build the Tree
     * @param nums represent the array which contains the numbers
     * @param n represent the size of the array
     * @throw invalid_argument exception if the size is invalid
     */
    explicit SegmentTree(const int nums[], const int& _size) : length(_size){
        if (_size < 0){
            throw invalid_argument("Invalid size");
        }
        int height = (int)(ceil(log2(_size)));
        size = 2 * (int)pow(2, height) - 1;
        segmentArray = new int[size] {0};
        this->nums = new int [length];

        for (int i = 0; i < _size; ++i) {
            this->nums[i] = nums[i];
        }
        build(0, length - 1, 0);
    }

    /**
     * A wrapper function to get the sum of specific interval
     * @param l represent the current left interval
     * @param r represent the current right interval
     * @return an integer value represent the sum of the interval
     */
    [[nodiscard]] int getSum(const int& l, const int& r){
        return getSum(0, length - 1, l, r, 0);
    }

    /**
     * A wrapper function to update specific value in the array
     * @param nums represent the array which contains the numbers
     * @param index represent the index which contains the old value
     * @param newVal represent the new value
     * @throw out_of_range exception if the index is invalid
      */
    void update(const int& index, const int& newVal){
        if (index >= length || index < 0){
            throw out_of_range("Invalid index");
        }
        int diff = newVal - nums[index];
        nums[index] = newVal ;
        update(0, length - 1, diff, index, 0);
    }

    /**
     * A friend function its role to print the segment array
     * @param os
     * @param tree
     * @return
     */
    friend ostream& operator <<(ostream& os, const SegmentTree& tree) {
        os << "Segment Tree: [";

        for (int i = 0; i < tree.length; ++i) {
            if (i == tree.length - 1){
                os << tree.segmentArray[i];
                break;
            }
            os << tree.segmentArray[i] << ", ";
        }
        os << "]";
        return os;
    }

    /**
     * A destructor which will free the tree
     */
    ~SegmentTree(){
        delete[] segmentArray;
        size = 0;
    }
};

# endif //SEGMENTTREE_SEGMENTTREE_H