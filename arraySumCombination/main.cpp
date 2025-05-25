#include <iostream>
#include <vector>

// Function to extract the largest number from an array and remove it
int extractLargestNum(int *arr, int &size) {
    int largest = arr[0];
    int largestIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
            largestIndex = i;
        }
    }

    for (int i = largestIndex; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size--;

    return largest;
}

// Function to log array elements
void arrLogger(int arr[], int size) {
    std::cout << "[ ";
    for(int i = 0; i < size; i++) {
        std::cout << arr[i];
        if(i != (size - 1)) {
            std::cout << ", ";
        }
    }
    std::cout << " ]";
}

// Function to find combinations that sum to target and return them
std::vector<std::vector<int>> sumCombinations(int target, int *arr, int size) {
    int possibleCombinations = 1 << size;
    std::vector<std::vector<int>> foundCombinations;

    for (int i = 0; i < possibleCombinations; ++i) {
        int sum = 0;
        std::vector<int> currentCombination;

        for (int j = 0; j < size; ++j) {
            if (i & (1 << j)) {
                sum += arr[j];
                currentCombination.push_back(arr[j]);
            }
        }

        if (sum == target) {
            foundCombinations.push_back(currentCombination);
        }
    }

    return foundCombinations;
}

int main() {
    int inputSize = 6;
    int inputArr[inputSize];
    std::cout << "Enter "<< inputSize << " numbers: \n";
    for (int i = 0; i < inputSize; ++i) {
        std::cin >> inputArr[i];
    }
    std::cout << "You entered:: ";
    arrLogger(inputArr, inputSize);

//    int arr[] = {13, 65, 1, 9, 92, 5, 57, 12, 56, 84};
    int sizeOfArray = sizeof(inputArr) / sizeof(inputArr[0]);

    int max = extractLargestNum(inputArr, sizeOfArray);
    std::cout << " - the largest is: " << max << "\n";

    std::vector<std::vector<int>> combinations = sumCombinations(max, inputArr, sizeOfArray);

    if (!combinations.empty()) {
        std::cout << "This Array (without largest): ";
        arrLogger(inputArr, sizeOfArray);
        std::cout << " has " << combinations.size() << " combination(s) that can add up to: " << max << "\n";
        std::cout << "They are: " << "\n";

        for (int i = 0; i < combinations.size(); ++i) {
            const std::vector<int>& storedCombinations = combinations[i];

            std::cout << "[ ";
            for (int j = 0; j < storedCombinations.size(); ++j) {
                std::cout << storedCombinations[j];
                if(j < storedCombinations.size() - 1) {
                    std::cout << " + ";
                }
            }
            std::cout << " ] = " << max << "\n";

        }
    } else {
        std::cout << "NO number combinations in array that can add up to: " << max << std::endl;
    }
}