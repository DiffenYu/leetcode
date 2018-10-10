/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.

Example:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
Note: 
You may assume that nums' length ≥ k-1 and k ≥ 1.
*/

#include<iostream>
#include<functional>
#include<queue>
#include<vector>

using namespace std;

class KthLargest {
    public:
    KthLargest(int k, vector<int> nums) {
        _k = k;
        for (auto& num : nums) {
            _pq.push(num);
        }
        while(_pq.size() > _k) {
            _pq.pop();
        }
    }
    
    int add(int val) {
        _pq.push(val);
        if (_pq.size() > _k) {
            _pq.pop();
        }
        return _pq.top();
    }

    void printpq() {
        if (_pq.empty()) {
            cout << "empty" << endl;
            return;
        }

        priority_queue<int, vector<int>, greater<int> > pqtmp(_pq);
        while(!pqtmp.empty()) {
            cout << pqtmp.top() << endl;
            pqtmp.pop();
        }
        cout << "printpq end" << endl;
        
    }
    
    private:
    int _k;
    priority_queue<int, vector<int>, greater<int> > _pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */


void test()
{
    int arr[4] = {4, 5, 8, 2};
    vector<int> nums(arr, arr + 4);
    KthLargest obj = KthLargest(3, nums);
    //kthLargest.add(3);   // returns 4
    //kthLargest.add(5);   // returns 5
    //kthLargest.add(10);  // returns 5
    //kthLargest.add(9);   // returns 8
    //kthLargest.add(4);   // returns 8
    cout << "======test 1=====" << endl;
    cout << obj.add(3) << endl;
    cout << obj.add(5) << endl;
    cout << obj.add(10) << endl;
    cout << obj.add(9) << endl;
    cout << obj.add(4) << endl;
}

void test2()
{
    int arr[11] = {-10, 1, 3, 1, 4, 10, 3, 9, 4, 5, 1};
    vector<int> nums(arr, arr + 11);
    KthLargest obj = KthLargest(7, nums);
    cout << "======test 2=====" << endl;
    obj.printpq();
    cout << obj.add(3) << endl; // return 3
    cout << "======add 3=========" << endl;
    obj.printpq();
    cout << obj.add(2) << endl; // return 3
    cout << "======add 2=========" << endl;
    obj.printpq();
    cout << obj.add(3) << endl; // return 3
    cout << "======add 3=========" << endl;
    obj.printpq();
    cout << obj.add(1) << endl; // return 3
    cout << "======add 1=========" << endl;
    obj.printpq();
    cout << obj.add(2) << endl; // return 3
    cout << "======add 2=========" << endl;
    obj.printpq();
}


int main()
{
    //test();
    test2();
}
