// dp標準題型

// nums:[-2,1,-3,4,-1,2,1,-5,4] numsSize: 9

/*

int maxSubArray(int * nums, int numsSize){
    // 選一個起點和一個終點
    int i; // 不是個定值 i : 0 ~ (numsSize - 1)
    int j; // 不是個定值 j : i ~ (numsSize - 1)
    // 計算從起點到終點的和
    int sum = 0;
    for(int k = i; k <= j; k++){
        sum += nums[k];
    }
}

*/

/*

int maxSubArray(int * nums, int numsSize){
    int max = INT_MIN; 不給初值下面會產生<未定義行為>
    // 選擇一個起點
    for(int i = 0; i < numsSize; i++){
        // 選擇一個終點
        for(int j = i; j < numsSize; j++){
            // 計算從起點到終點的和
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += nums[k];
            }
            if(sum > max){ // <未定義行為>
                max = sum;
            }
        }
    }
    return max;
}

// 但他如果陣列給你一個array只有一個數字 -1 那你就爆了, 因為你要 return - 1 而不是INT_MIN
*/

// 優化技巧 : 重複計算 重複的東西 算一次就好

// sum = 0
// i : 0, j : 0 => sum = sum + nums[0]
// i : 0, j : 1 => sum = sum + nums[1]
// i : 0, j : 2 => sum = sum + nums[2]
// ...
// i : 0, j : 8 => sum = sum + nums[8]

/* 暴力法

int maxSubArray(int * nums, int numsSize){
    int max = nums[0];
    // 選擇一個起點
    for(int i = 0; i < numsSize; i++){
        int sum = 0;
        // 選擇一個終點
        for(int j = i; j < numsSize; j++){
            // 計算從起點到終點的和
            sum += nums[j];
            if(sum > max){ 
                max = sum;
            }
        }
    }
    return max;
}

*/

// 動態規劃 sum儲存使用上一個數字的連續和，sum加上當前位置數字，如果和大於0，則說明可以繼續向後；小於0則說明，當前位置是一個負數，應該從下一個數字重新開始。同時也要不斷更新max。
int maxSubArray(int* nums, int numsSize) {
    int i = 0, sum = 0;
    int max = nums[0];
    for(i = 0; i < numsSize; i++) {
        sum += nums[i];
        if(max < sum)
            max = sum;
        if(sum < 0)
            sum = 0;
    }
    return max;
}


// 貪婪法 尋找從開始位置的最小和，開始位置到當前位置連續和與其前邊的最小值差值sum - min，即為到當前位置前邊的最大連續和。

int maxSubArray(int* nums, int numsSize) {
    int i = 0, sum = 0, min = 0;
    int max = nums[0];
    for(i = 0; i < numsSize; i++) {
        sum += nums[i];
        if(sum - min > max)
            max = sum - min;
        if(sum < min)
            min = sum;
    }
    return max;
}