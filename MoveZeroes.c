// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Input : [0,1,0,3,12]
// Output : [1,3,12,0,0]

// Note : 1. You must do this in-place without making a copy of the array --> no return --> void
//        2. Minimize the total number of operation

// 保留原本的順序

/*

void moveZeroes(int * nums, int numsSize){
    1. 怎麼知道我還沒有完成 ?
    for (int i = 0; i < numsSize; i++){
        if(nums[i] == 0 && nums[i+1] != 0){ ...(nums[4], nums[5]) => 會超出範圍 你沒有5號 改成下面
            // 代表沒有完成
        }
    }

    for (int i = 0; i + 1 < numsSize; i++){ 終止條件變成用 i+1 來判斷 
        if(nums[i] == 0 && nums[i+1] != 0){ 
            // 代表沒有完成
            int t = nums[i];
            nums[i] = nums[i+1];
            nums[i+1] = t;
            break;
        }
    }
    // 你前面的有可能還是錯的 [3,0,0,12,1]
    //                      [3,0,12,0,1]  => while重複做

    while(true){
        for (int i = 0; i + 1 < numsSize; i++){ 終止條件變成用 i+1 來判斷 
            if(nums[i] == 0 && nums[i+1] != 0){ 
                // 代表沒有完成
                int t = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = t;
                break;
            }
        }
    }
    // 要怎麼知道該停了 ?

    while(true){
        int count == 0;  // 給一個計數器 會計次 = 無敵 (重要技巧)
        for (int i = 0; i + 1 < numsSize; i++){ 
            if(nums[i] == 0 && nums[i+1] != 0){ 
                count++;
                int t = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = t;
                break;
            }
        }
        if(count == 0){
            break;
        }
    }         // TLE 
              // 加 break 反而比較慢

    while(true){
        int count == 0;  // 給一個計數器 會計次 = 無敵 (重要技巧)
        for (int i = 0; i + 1 < numsSize; i++){ 
            if(nums[i] == 0 && nums[i+1] != 0){ 
                count++;
                nums[i] = nums[i+1];
                nums[i+1] = 0;
            }
        }
        if(count == 0){
            break;
        }
    }

    套用泡沫排序的精神 ( while不知道會跑幾次 )
    // 先學會檢查
    // 試著局部修正
    // 重複執行直到沒有錯誤
    for(int k = 1; k <= numsSize; k++){  // numsSize次
        for(int i = 0; i+1 < numsSize; i++){
            if(nums[i] == 0 && nums[i+1] != 0){
                nums[i] = nums[i+1];
                nums[i+1] = 0;
            }
        }
    }
*/

// 思路 2 : 每次完成一部分 (子問題)
// 找到一個 0, 往最右邊搬, 找到一個 0, 往最右邊搬, ...

// 思路 3 : 直接寫答案
// nums : [0,1,0,3,12]
// i :             ^ 
// j :         ^
//         1, 3, 12
/*
void moveZeroes(int * nums, int numsSize){
    int j = 0; // 下一個放的位置
// 先放不是 0 的
    for(int i = 0; i < numsSize; i++){
        if (nums[i] != 0){
            nums[j] = nums[i];
            j++;
        }
    }
// 再放 0 的
    for(j = j; j < numsSize; j++){  // j = j 有寫跟沒寫一樣
        nums[j] = 0;
    }

    while(j < numsSize){
        nums[j] = 0;
        j++;
    }
}

// nums : [1,3,12,0,0]
*/


// 直接寫出答案
// => 有些會需要額外空間 int ans[numsSize];
// => 觀察寫入跟讀取的位置, 如果寫入後的東西不會再被讀取就不需要額外空間
#include <stdio.h>
void moveZeroes(int * nums, int numsSize){
    // in-place (原地)
    int j = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != 0){
            nums[j] = nums[i];
            j++;
        }
    }

    while(j < numsSize){
        nums[j] = 0;
        j++;
    }
}