#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function prototypes
float findMin(float arr[], int size);
float findMax(float arr[], int size);
float calculateAverage(float arr[], int size);
int findIndexOf(float arr[], int size, float num);
int countOccurrences(float arr[], int size, float num);
void printFirst100(float arr[]);
float calculateMedian(float arr[], int size, int *flag);
float calculateMode(float arr[], int size);
float calculateRange(float arr[], int size);
float calculateStandardDeviation(float arr[], int size, float mean);
float calculateVariance(float arr[], int size, float mean);
void sortArray(float arr[], int size, int *flag);

int main() {
    // Declare an array of 1000 floats (for demo purposes, we initialize it with random numbers)
    float balance[1000];
    int size = 1000;
    float num = 0;
    float option = 0;
    int sorted_array = 0;

    // Initialize the array with random values between 0 and 100
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++) {
        balance[i] = ((float)rand()/(float)(RAND_MAX)) * 100.0; // Random float values from 0 to 100
    }

    //Add your code here for the command line interface and interacting with the program
    
    while (option != 13)
    {
        printf("Welcome to the Data Explorer: Building Essential Data Analysis Tools in C! Please choose an option by entering the corresponding number:\n");
        printf("1: Find the minimum value\n2: Find the maximum value\n3: Calculate the average\n4: Find the index of a given number\n5: Count occurrences of a given number\n6: Print the first 100 elements\n7: Calculate the median\n8: Calculate the mode\n9: Calculate the range\n10: Calculate the standard deviation\n11: Calculate the variance\n12: Sort the array\n13: Exit\n");
        printf("\nEnter your command: ");
        scanf("%f", &option);

        if (option == 1){
            float min = findMin(balance, size);
            printf("The minimum value is: %.2f\n", min);
        }
        else if (option == 2){
            float max = findMax(balance, size);
            printf("The maximum value is: %.2f\n", max);
        }
        else if (option == 3){
            float avg = calculateAverage(balance, size);
            printf("The average value is: %.2f\n", avg);
        }
        else if (option == 4){
            printf("Enter the number to find: ");
            scanf("%f", &num);
            int index = findIndexOf(balance, size, num);
            if (index != -1)
                printf("The number %.2f first appears at index %d.\n", num, index);
            else
                printf("The number %.2f is not found in the array.\n", num);
        }
        else if (option == 5){
            printf("Enter the number to count: ");
            scanf("%f", &num);
            int count = countOccurrences(balance, size, num);
            printf("The number %.2f occurs %d times in the array.\n", num, count);
        }
        else if (option == 6){
            printFirst100(balance);
        }
        else if (option == 7){
            float median = calculateMedian(balance, size, &sorted_array);
            printf("The median is: %.2f\n", median);
        }
        else if (option == 8){
            float mode = calculateMode(balance, size);
            printf("The mode is: %.2f\n", mode);
        }
        else if (option == 9){
            float range = calculateRange(balance, size);
            printf("The range is: %.2f\n", range);
        }
        else if (option == 10){
            float avg = calculateAverage(balance, size);
            float std_deviation = calculateStandardDeviation(balance, size, avg);
            printf("The standard deviation is: %.2f\n", std_deviation);
        }
        else if (option == 11){
            float avg = calculateAverage(balance, size);
            float variance = calculateVariance(balance, size, avg);
            printf("The variance is: %.2f\n", variance);
        }
        else if (option == 12){
            sortArray(balance, size, &sorted_array);
            printf("The array has been sorted.\n");
        }
        else if (option == 13){
            printf("Goodbye!\n");
            break;
        }
        else
            printf("Please select from the given options(1 - 13).\n");
    }
}

//Add code here for the implementation of the above function prototypes
float findMin(float arr[], int size){
    float min = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

float findMax(float arr[], int size){
    float max = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

float calculateAverage(float arr[], int size){
    float sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum / size;
}

int findIndexOf(float arr[], int size, float num){
    for (int i = 0; i < size; i++){
        if (fabs(arr[i] - num) < .10)
            return i;
    }
    return -1;
}

int countOccurrences(float arr[], int size, float num){
    int count = 0;
    
    for (int i = 0; i < size; i++){
        if (fabs(arr[i] - num) < .10)
            count++;
    }
    return count;
}

void printFirst100(float arr[]){
    printf("First 100 elements of the array: \n");
    for (int i = 0; i < 100; i++){
        printf("%.2f ", arr[i]);

        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    printf("\n");
}

void sortArray(float arr[], int size, int *flag){
    for (int i = 1; i < size; i++){
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]){
            float temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--; 
        }
    }
    *flag = 1;
}

float calculateMedian(float arr[], int size, int *flag){
    if(*flag == 0)
        sortArray(arr, size, flag);

    if (size % 2 == 0)
        return (arr[size / 2 - 1]+ arr[size / 2]) / 2.0;
    else
        return arr[size / 2];
}

float calculateMode(float arr[], int size){
    float mode = arr[0];
    int max_count = countOccurrences(arr, size, mode);

    for (int i = 1; i < size; i++){
        int initial_count = countOccurrences(arr, size, arr[i]);
        if (initial_count > max_count){
            max_count = initial_count;
            mode = arr[i];
        }
    }  
    return mode;
}

float calculateRange(float arr[], int size){
    float min = findMin(arr, size);
    float max = findMax(arr, size);

    return max - min;
}

float calculateVariance(float arr[], int size, float mean){
    float modified_sum = 0;
    
    for (int i = 0; i < size; i++){
        float diff = arr[i] - mean;
        modified_sum += diff * diff;
    }
    return modified_sum / size;
}

float calculateStandardDeviation(float arr[], int size, float mean){
    float variance = calculateVariance(arr, size, mean);
    return sqrt(variance);
}