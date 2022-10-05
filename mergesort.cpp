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
        return x;
    }
    else {

        int midpoint = (x.size()) / 2;
        // split vectors
        vector<int> xLeftInit(x.begin(), x.begin() + midpoint); 
        vector<int> xL = RecursiveSort(xLeftInit); // Should eventually reach the point where x_l2 has size = 1, ending recursion

        vector<int> xRightInit(x.begin() + midpoint, x.end()); 

        vector<int> xR = RecursiveSort(xRightInit);

        // Create result vector
        vector<int> result;

        int i;

        vector<int> a1;
        vector<int> a2;

        // find vector with smaller size
        if (xL.size() < xR.size()) {
            a1 = xL;
            a2 = xR;
        }
        else {
            a1 = xR;
            a2 = xL;
        }

        while (a1.size() > 0 && a2.size() > 0)
        {
            bool l = true;
            // find lowest value out of all vectors
            int lowestL = a1[0];
            int lowestLIdx = 0;
            for (int x = 1; x < a1.size(); x++) {
                if (a1[x] < lowestL) {
                    lowestL = a1[x];
                    lowestLIdx = x;
                }
            }

            int lowestR = a2[0]; 
            int lowestRIdx = 0;
            for (int x = 1; x < a2.size(); x++) {
                if (a2[x] < lowestR) {
                    lowestR = a2[x];
                    lowestRIdx = x;
                }
            }

            int lowest;
            if (lowestL < lowestR) {
                lowest = lowestL;
            }
            else {
                lowest = lowestR;
                l = false;
            }


            if (l == true) {
                a1.erase(a1.begin() + lowestLIdx);
            }
            else { // l is false
                a2.erase(a2.begin() + lowestRIdx);
            }

            result.push_back(lowest);

        }
        
        if (a1.size() > 0) {
            result.insert(result.end(), a1.begin(), a1.end());
        }
        if (a2.size() > 0) {
            result.insert(result.end(), a2.begin(), a2.end());
        }
        return result;
      
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
        TestList = x.GetList(); 
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    }
    return 0;
}
