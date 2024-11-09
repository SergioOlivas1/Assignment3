using namespace std;
#include <iostream>
#include <vector>

//Linear search for last occurence of target
template <typename Item_Type>
int linear_search(vector<Item_Type>& items, Item_Type&
	target, size_t pos_first) {
    if (pos_first == items.size())
        return -1;  // Search the whole vector

    // Search the rest of the vector
    int result = linear_search(items, target, pos_first + 1);

    // If target was found after the first occurrence
    if (result != -1)
        return result;

    // Otherwise, check the current position
    if (items[pos_first] == target)
        return pos_first;

    return -1;  // Target not found
}