//
//  main.cpp
//  QuickSort
//
//  Created by 王雪琪 on 5/26/20.
//  Copyright © 2020 Xueqi Wang. All rights reserved.
//

#include <iostream>
using namespace std;

int partition(int nums[], int left, int right){
    int i = left;
    int j = right;
    int temp = nums[i];
    
    while(i < j){
        // 从右往左找比temp小的数
        while(i < j && nums[j] >= temp)
            j--;
        if(i < j){
            nums[i] = nums[j];
            i++;
        }
        // 从左往右找比temp大的数
        while(i < j && nums[i] <= temp)
            i++;
        if(i < j){
            nums[i] = nums[j];
            j++;
        }
    }
    nums[i] = temp;
    return i;
}

void QuickSort(int nums[], int left, int right){
    if(left < right){
        int i = partition(nums, left, right);
        QuickSort(nums, left, i-1);
        QuickSort(nums, i+1, right);
    }
}

int main(int argc, const char * argv[]) {
    int nums[6] = {5,4,3,2,1,10};
    
    QuickSort(nums, 0, 5);
    
    for(int i=0; i<6; i++)
        cout << nums[i];
    cout << endl;
    
    return 0;
}
