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
    vector<typename RandomIt::value_type> partOfElements;
    MergeSort(elements.begin(), elements.begin() + elements.size()/3);
    MergeSort(elements.begin() + elements.size()/3, elements.begin() + (2 * elements.size())/3);
    MergeSort(elements.begin() + (2 * elements.size())/3, elements.end());
    merge(elements.begin(), elements.begin() + elements.size()/3,
            elements.begin() + elements.size()/3, elements.begin() + (2 * elements.size())/3, back_inserter(partOfElements));
    merge(partOfElements.begin(), partOfElements.end(), elements.begin() + (2 * elements.size())/3, elements.end(), range_begin);
}
int main()
{
    try{
        vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
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
