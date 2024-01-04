# ifndef SEGMENTTREE_SEGMENTTREE_H
# define SEGMENTTREE_SEGMENTTREE_H
# include <iostream>
using namespace std;

/**
 * @brief Class Segment Tree
 * @author Mohamed Amir
 * @version 1.0
 */
class SegmentTree {
    int* arr;
    int length;

    /**
     * A private method which will build the Tree
     * @param arr represent the array which contains the numbers
     */
    void build(const int arr[]){

    }

public:
    SegmentTree() = default;

    /**
     * @brief A parameterized constructor that initialize the @property length and arr
     * @param size represent the size of the array
     */
    explicit SegmentTree(int size) : length(size){
        arr = new int[length];
    }

    /**
     * A parameterized constructor that initialize the @property length and arr
     *
     * and build the Tree
     * @param nums represent the array which contains the numbers
     * @param n represent the size of the array
     */
    explicit SegmentTree(const int nums[], int n) : length(n){
        arr = new int[length];
        build(nums);
    }

    /**
     * A destructor which will free the tree
     */
    ~SegmentTree(){
        delete[] arr;
        length = 0;
    }
};

# endif //SEGMENTTREE_SEGMENTTREE_H