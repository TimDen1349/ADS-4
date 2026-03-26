// Copyright 2025 NNTU-CS
#include <iostream>
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int k = right - left + 1;
                count += k * (k - 1) / 2;
                break;
            } else {
                int leftCount = 1;
                while (left + leftCount < right &&
                       arr[left + leftCount] == arr[left]) {
                    ++leftCount;
                }
                int rightCount = 1;
                while (right - rightCount > left &&
                       arr[right - rightCount] == arr[right]) {
                    ++rightCount;
                }
                count += leftCount * rightCount;
                left += leftCount;
                right -= rightCount;
            }
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        int target = value - arr[i];
        if (target < arr[i + 1]) {
            continue;
        }
        const int *first = std::lower_bound(arr + i + 1, arr + len, target);
        const int *last = std::upper_bound(arr + i + 1, arr + len, target);
        count += (last - first);
    }
    return count;
}
