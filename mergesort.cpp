#include <iostream>
#include <vector>
using namespace std;
// ---------------------------------------------------------------
// Task 1: Define a MergeSort Class 
// ---------------------------------------------------------------
// Below is a class for merge sort. 
// 
// It has a private vector "list" that holds the list to sort.
// All member functions should operate on "list". 
// 
// It has several public member functions. 
// 1. SetList: assign a vector (to sort) to "list". 
// 2. GetList: return the current "list"
// 3. SortList: sort "list" based on the merge sort algorithm.  
//
// Parts of the SortList function are given to you. 
// You need to complete this function based on the given parts 
// (but feel free to add additional functions as you like).
//  
// A key feature in the given SortList function is to call 
// a recursive function "RecursiveSort", which recursively 
// splits the input list, sorts each split, and merges the splits 
// Note "RecursiveSort" takes input by value and returns a sorted input. 
// 
// Your job is to complete the following functions:
// -- SetList() // 
// -- GetList() // 
// -- SortList() // 
// -- RecursiveSort() // 
class MergeSort {
public:
    void SetList(vector<int> InputList);
    vector<int> GetList();
    void SortList();
private:
    vector<int> list;
    vector<int> RecursiveSort(vector<int> x);
};

void MergeSort::SetList(vector<int> InputList) {
    list = InputList;
}

vector<int> MergeSort::GetList() {
    return list;
}

// Below is a template for the MergeSort function.  
// Note it is not recursive. Only "RecursiveSort" is recursive. 
void MergeSort::SortList() {
    vector<int> list2 = RecursiveSort(list);
    list = list2;
}

vector<int> MergeSort::RecursiveSort(vector<int> x) {
    if (x.size() == 1) { // if size of input vector is 1, return vector as is
        cout << "size 1 of x reached" << endl;
        return x;
    }
    else {
        cout << "current size is " << x.size()  << endl;
        int midpoint = (x.size()) / 2;
        // split vectors
        vector<int> x_l(x.begin(), x.begin() + midpoint); cout << "  hello. x_l size is " << x_l.size() << endl;
        cout << "    Current x_l: " << endl;
        for (int x = 0; x < x_l.size(); x++) {
            cout << x_l[x] << endl;
        }
        vector<int> x_l2 = RecursiveSort(x_l); // Should eventually reach the point where x_l2 has size = 1, ending recursion




        vector<int> x_r(x.begin() + midpoint, x.end()); cout << "  hi. x_r size is " << x_r.size() << endl;
        cout << "    Current x_r: " << endl;
        for (int x = 0; x < x_r.size(); x++) {
            cout << x_r[x] << endl;
        }
        vector<int> x_r2 = RecursiveSort(x_r);

        // Create result vector
        vector<int> result;
        vector<int> result2;

        vector<int> a1;
        vector<int> a2;
        if (x_l2[0] < x_r2[0]) { // 3 < 5
            a1 = x_l2;
            a2 = x_r2;
        }
        else { // 5 > 3. Swap them so that our code is simpler.
            a1 = x_r2;
            a2 = x_l2;
        }
        
        
        cout << "a1 = " << endl;
        for (int i = 0; i < a1.size(); i++) { cout << a1[i] << endl; }
        cout << "a2 = " << endl;
        for (int i = 0; i < a2.size(); i++) { cout << a2[i] << endl; }

        for (int i = 0; i < a1.size(); i++) { // designed to iterate through smaller array
            if (a1[i] < a2[0]) { // if element i of array 1 is smaller than first element of array 2
                result.push_back(a1[i]); cout << a1[i] << " < " << a2[0] << endl;
            }
            else {
                result2.push_back(a1[i]);
            }
        }
        result.insert(result.end(), a2.begin(), a2.end());
        result.insert(result.end(), result2.begin(), result2.end());
        cout << "result:" << endl;
        for (int i = 0; i < result.size(); i++) { cout << result[i] << endl; }
        return result;

        // Determine whether left or right vector is larger.
        // When size of each vector is 1, this sorts the two vectors into a single array of size 2.
        // For future vector, this simply indicates whether the left or right vector contains smaller values.
        /*
        if (x_l2[0] < x_r2[0]) { // left vector is smaller
            cout << "x_l2[0] is smaller than x_r2[0]: " << x_l2[0] << " < " << x_r2[0] << endl;
            result.insert(result.end(), x_l2.begin(), x_l2.end());
            result.insert(result.end(), x_r2.begin(), x_r2.end());
            cout << "merged x_l2 and x_r2 into: " << endl;
            for (int i = 0; i < result.size(); i++) {
                cout << "  " << result[i] << endl;
            }
        }
        else { // left vector is larger
            cout << "x_l2[0] is larger than x_r2[0]: " << x_l2[0] << " > " << x_r2[0] << endl;
            result.insert(result.end(), x_r2.begin(), x_r2.end());
            result.insert(result.end(), x_l2.begin(), x_l2.end());
            cout << "merged x_l2 and x_r2 into: " << endl;
            for (int i = 0; i < result.size(); i++) {
                cout << "  " << result[i] << endl;
            }
        }
        */
        // Problem identified: We can sort arrays just fine for a while.
        // But if we have 3,4,9 and 5,8, it will identify 5>3 and append it to the end of the first array.
        // What we need is an insert feature where it first finds which array has a lesser starting value,
        //  then inserts the second array in the place right before it encounters a larger number in array 1.
        
    }

};
// ---------------------------------------------------------------
int main()
{
    // The main function is given to you. 
    // We first input an arbitrary number of non-repeated integers into a vector. 
    // The input of this list will terminate when we give an non-integer input e.g., letter 'a'.
    // Then, we pass this vector to the MergeSort object. 
    // Then, we run your implemented functions. 
        vector<int> InputList;
    vector<int> TestList;
    int temp, mode;
    MergeSort x;
    // takie inputs
    cin >> mode;
    while (cin >> temp) {
        InputList.push_back(temp);
    }
    x.SetList(InputList);
    // start testing functions 
    switch (mode) {
    case 1: // check if input is correct 
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 2: // check if SortList is correct 
        x.SortList();
        TestList = x.GetList(); cout << "TESTING" << endl;
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    }
    return 0;
}
