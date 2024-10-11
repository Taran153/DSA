#include <stdlib.h>

// A structure to represent each element in the hash map
typedef struct {
    int value;
    int index;
} HashMapItem;

// Hash map utility functions
int hash(int key, int size) {
    return abs(key) % size;
}

void insert(HashMapItem* hashMap[], int key, int index, int size) {
    int pos = hash(key, size);
    while (hashMap[pos] != NULL && hashMap[pos]->value != key) {
        pos = (pos + 1) % size; // Linear probing for collision resolution
    }
    if (hashMap[pos] == NULL) {
        hashMap[pos] = (HashMapItem*)malloc(sizeof(HashMapItem));
    }
    hashMap[pos]->value = key;
    hashMap[pos]->index = index;
}

int find(HashMapItem* hashMap[], int key, int size) {
    int pos = hash(key, size);
    while (hashMap[pos] != NULL) {
        if (hashMap[pos]->value == key) {
            return hashMap[pos]->index; // Return index if found
        }
        pos = (pos + 1) % size; // Linear probing
    }
    return -1; // Return -1 if key is not found
}

// Function to find two indices such that the numbers add up to the target
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Hash map size is twice the size of numsSize for better collision resolution
    int hashMapSize = numsSize * 2;
    HashMapItem* hashMap[hashMapSize];
    for (int i = 0; i < hashMapSize; i++) {
        hashMap[i] = NULL; // Initialize hash map
    }

    // Allocate memory for the result
    int* result = (int*)malloc(2 * sizeof(int));

    // Traverse through the array
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        // Check if the complement exists in the hash map
        int complementIndex = find(hashMap, complement, hashMapSize);
        if (complementIndex != -1) {
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            return result; // Return the result as soon as the solution is found
        }

        // Insert the current element into the hash map
        insert(hashMap, nums[i], i, hashMapSize);
    }

    *returnSize = 0; // No solution found
    return NULL; // Return NULL if no solution exists
}
