
/* O(N^2)
int singleNumber(int * nums, int numsSize){
    //nums: [2, 2, 1], numsSize: 3
    for(int i = 0; i < numsSize; i++){ //       i: 0, 1, 2
        printf("%d\n", nums[i]);       // nums[i]: 2, 2, 1

        int count = 0;
                                           //       i: 2
                                           // nums[i]: 1
        for(int j = 0; j < numsSize; j++){ //       j: 0, 1, 2
            if(nums[j] == nums[i]){       // nums[j]: 2, 2, 1
                count++;                   // count  : 0, 0, 1
            }
        }
        // count: 1
        if(count == 1){
            return nums[i];  // nums[i]: 1
        }
    }
    return -1;
}
*/

int singleNumber(int * nums, int numsSize){
    // nums: [2, 2, 1], numsSize: 3

    // n = nums[0] ^ nums[1] ^ nums[2] // bitwise XOR (bitwise => bit為單位做運算)

    // sizeof(int) == 4 bytes 00000000 00000000 00000000 00000010 == 2
    //                      & 00000000 00000000 00000000 00000001 == 1
    //                    --------------------------------------------------
    //                        00000000 00000000 00000000 00000000 == 2 & 1  bitwise AND
    // 1 bytes = 8 bits, [0][0][1][0][1][1][0][0] => 00101100b
    // 1 bit= [0] or [1]

    //   0  1     0 ^ 0 => 0,  0 ^ 1 => 1,  1 ^ 0 => 1,  1 ^ 1 => 0
    // 0 0  1
    // 1 1  0     XOR 不一樣的得 1
    //                        00000000 00000000 00000000 00000110 == 6
    //                      ^ 00000000 00000000 00000000 00000101 == 5
    //                    --------------------------------------------------
    //                        00000000 00000000 00000000 00000011 == 3  bitwise XOR 6 ^ 5 == 3
    //
    //
    // A ^ A => 1. 0 ^ 0 => 0
    //          2. 1 ^ 1 => 0
    // A ^ A => always 0
    // A ^ 0 => always A
    // A ^ B => B ^ A 先後沒有差 交換律

    //nums:[2, 2, 1]
    //   n: 2^2^1 => 0^1 => 1^0 => 1

    //nums:[4, 1, 2, 1, 2]
    //   4^1^2^1^2
    //   1^4^2^1^2
    //   1^4^1^2^2
    //   1^1^4^2^2
    //   1^1^2^4^2
    //   1^1^2^2^4 => 0^2^2^4 => 0^0^4 => 4
    
    int n = nums[0];
    for (int i = 1; i < numsSize; i++){
        n ^= nums[i];
    }
    return n;
}