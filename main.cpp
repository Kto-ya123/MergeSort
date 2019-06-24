#include <iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if(range_end - range_begin < 2){
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    MergeSort(elements.begin(), elements.begin() + elements.size()/2);
    MergeSort(elements.begin() + elements.size()/2,elements.end());
    merge(elements.begin(), elements.begin() + elements.size()/2, (elements.begin() + elements.size()/2), elements.end(), range_begin);
}
int main()
{
    try{
        vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
        MergeSort(begin(v), end(v));
        for (int x : v) {
        cout << x << " ";
        }
    }catch(exception ex){
        cout << ex.what();
    }
    cout << endl;
    return 0;
}
