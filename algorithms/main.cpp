#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (hashMap[nums[i]])
                return true;
            else
                hashMap[nums[i]] = 1;
        }

        return false;
    }

    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length())
            return false;

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        return s == t;
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void swap(std::vector<int>& arr1, std::vector<int>& arr2) {
        for (int i = 0; i < arr1.size(); i++) {
            arr1[i] = arr1[i] + arr2[i];
            arr2[i] = arr1[i] - arr2[i];
            arr1[i] = arr1[i] - arr2[i];
        }
    }

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left != right) {
            if (nums[left] + nums[right] == target) {
                return { left, right };
            }

            if (nums[left] + nums[right] > target)
                right--;

            if (nums[left] + nums[right] < target)
                left++;
        }

        return { 0, 0 };
    }

    std::vector<int> deleteItemsFromVector(std::vector<int> arr, int element) {
        int count = 0, index = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != element) {
                arr[index] = arr[i];
                index++;
            }
            else {
                count++;
            }
        }

        arr.erase(arr.end() - count, arr.end());

        return arr;
    }

    std::vector<int> merge_sorted_arr(std::vector<int> arr1, std::vector<int> arr2) {
        int fstindex = 0, sndindex = 0, index = 0;
        int size1 = arr1.size(), size2 = arr2.size();
        std::vector<int> arr(size1 + size2);

        while (fstindex < size1 && sndindex < size2) {
            if (arr1[fstindex] > arr2[sndindex]) {
                arr[index] = arr2[sndindex];
                sndindex++;
            }
            else {
                arr[index] = arr1[fstindex];
                fstindex++;
            }
            index++;
        }

        while (fstindex < size1) {
            arr[fstindex + sndindex] = arr1[fstindex];
            fstindex++;
        }

        while (sndindex < size2) {
            arr[fstindex + sndindex] = arr2[sndindex];
            sndindex++;
        }

        return arr;
    }

    int max_in_vector(std::vector<int> arr, int size) {
        int max = arr[0];
        for (int i = 0; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        return max;
    }

    int gcdlcm(int first, int second, bool mode) {
        int minimum = first, maximum = second;

        if (first > second) {
            maximum = first;
            minimum = second;
        }

        if (mode) {
            for (int i = minimum; i > 2; i--) {
                if (!(minimum % i || maximum % i))
                    return i;
            }

            return -1;
        }

        for (int i = maximum; i < minimum * maximum + 1; i += maximum) {
            if (!(i % minimum || i % maximum))
                return i;
        }

        return 1;
    }

    void generateSubsequences(
        const std::string& s,
        int index,
        std::string current,
        long long current_hash,
        long long current_power,
        int p,
        int m,
        std::map<int, std::vector<std::string>>& hashMap
    ) {
        if (index == s.length()) {
            if (!current.empty()) {
                hashMap[current_hash].push_back(current);
            }
            return;
        }

        // Включаем символ s[index]
        generateSubsequences(
            s,
            index + 1,
            current + s[index],
            (current_hash + s[index] * current_power) % m,
            (current_power * p) % m,
            p,
            m,
            hashMap
        );

        // Не включаем символ s[index]
        generateSubsequences(
            s,
            index + 1,
            current,
            current_hash,
            current_power,
            p,
            m,
            hashMap
        );
    }

    int getLastEvenDigit(std::vector<int> arr) {
        int last = -1;

        for (int i : arr) {
            if (i % 2 == 0)
                last = i;
        }

        return last;
    }

    int binarySearch(std::vector<int> data, int target) {
        int left = 0;
        int right = data.size() - 1;
        int middle;

        if (target < data[left])
            return 0;

        if (target > data[right])
            return right + 1;

        while (left < right) {
            middle = (right + left) / 2;
            if (data[middle] == target) {
                return middle;
            }
            else if (data[middle] > target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return right;
    }

    int binarySearchSqrt(int target) {
        int left = 0;
        int right = target;
        int middle;

        while (left < right) {
            middle = (right + left) / 2;
            if (middle * middle == target) {
                return middle;
            }

            if (middle * middle > target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return right;
    }

    int ternarySearch(std::vector<int> data, int target) {
        int left = 0;
        int right = data.size() - 1;
        
        while (left <= right) {
            int m1 = left + (right - left) / 2;
            int m2 = right - (right - left) / 2;

            if (data[m1] == target) {
                return m1;
            }

            if (data[m2] == target) {
                return m2;
            }

            if (data[m1] > target) {
                right = m1 - 1;
            }

            if (data[m2] < target) {
                left = m2 + 1;
            }

            if (data[m1] < target && target < data[m2]) {
                left = m1 + 1;
                right = m2 - 1;
            }
        }
        return -1;
    }

    int expSearch(std::vector<int> data, int target) {
        if (data[0] == target)
            return 0;

        int border = 1;
        int right = data.size() - 1;

        while (border < right && data[border] < target) {
            if (data[border] == target)
                return border;
            border *= 2;
        }

        int left = border / 2;
        right = std::min(border, right);

        int middle;
        while (left <= right) {
            middle = (right + left) / 2;
            if (data[middle] == target) {
                return middle;
            }

            if (middle > target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        return -1;
    }

    int countInArray(std::vector<int>& arr) {
        std::unordered_map<int, int> hashMap;
        for (int i = 0; i < arr.size(); i++) {
            if (hashMap[arr[i]])
                hashMap[arr[i]]++;
            else
                hashMap[arr[i]] = 1;

            if (hashMap[arr[i]] > arr.size() / 2)
                return arr[i];
        }

        return -1;
    }

    std::vector<int> getFourDivisors(int a, int b, int c, int d) {
        std::vector<int> divisors;
        int minimum = std::min(std::min(a, b), std::min(c, d));
        for (int i = 1; i < minimum + 1; i++) {
            if (a % i == 0 && b % i == 0 && c % i == 0 && d % i == 0) {
                divisors.push_back(i);
            }
        }
        return divisors;
    }

    void bubbleSorting(std::vector<int>& arr) {
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for (int i = 0; i < arr.size() - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    sorted = false;
                }
            }
        }
    }

    std::vector<int> mergeSorting(std::vector<int>& arr) {
        if (arr.size() < 2)
            return arr;

        int middle = arr.size() / 2;

        std::vector<int> rightSide(arr.begin(), arr.begin() + middle);
        std::vector<int> leftSide(arr.begin() + middle, arr.end());

        return merge_sorted_arr(mergeSorting(rightSide), mergeSorting(leftSide));
    }
    
    void quickSorting(std::vector<int>& arr, int left, int right) {
        if (left >= right) {
            return;
        }

        int point = arr[(left + right) / 2];

        int i = left, j = right;

        while (i <= j) {
            while (arr[i] < point) i++;
            while (arr[j] > point) j--;

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if(j > 0)
            quickSorting(arr, left, j);

        if(i < arr.size())
            quickSorting(arr, i, right);
    }

    void sort(std::vector<int>& arr) {
        quickSorting(arr, 0, arr.size() - 1);
    }

    bool isSubsequence(std::string& a, std::string& b) {
        Queue q;
        for (char c : a) {
            q.push(c);
        }

        for (char c : b) {
            if (!q.isEmpty() && q.getChar() == c)
                q.pop();
        }

        return q.getSize() == 0;
    }

    bool isPalindrome(std::string& a) {
        Stack st;
        for (char c : a) {
            st.push(c);
        }

        for (char c : a) {
            if (c != st.getChar())
                return false;

            st.pop();
        }

        return true;
    }

    int maxRepeat(std::string& str) {
        std::unordered_map<char, int> hashMap;
        int maxCount = 0;

        for (char c : str) {
            if (hashMap[c])
                hashMap[c]++;
            else
                hashMap[c] = 1;

            if (hashMap[c] > maxCount)
                maxCount = hashMap[c];
        }

        return maxCount;
    }
};

int main() {
    std::unordered_map<char, int> hashMap;
    std::string str;
    std::cin >> str;
    int maxCount = 0;

    for (char c : str) {
        if (hashMap[c])
            hashMap[c]++;
        else
            hashMap[c] = 1;

        if (hashMap[c] > maxCount)
            maxCount = hashMap[c];
    }

    std::cout << maxCount;
    return 0;
}