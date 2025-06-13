#include <iostream>
#include <stdio.h>
#define LENGTH 10

void EnterNumbersToTab(int *tab) {

    for(int i = 0; i<LENGTH; i++) {

        printf("enter %d number: ", i+1);
        scanf("%d", tab+i);
    }
    printf("\n");
}

void PrintTab(const int *tab) {

    for(int i = 0; i<10; i++) {
        printf("%d\t", *(tab+i));
    }
    printf("\n");
}

int SearchMax(const int *tab) {
    int max = *(tab);

    for(int i = 0; i<LENGTH; i++) {
        if(max < *(tab+i)) {
            max = *(tab+i);
        }
    }

    return max;
}


int SearchMin(const int *tab) {
    int min = *(tab);

    for(int i = 0; i<LENGTH; i++) {
        if(min > *(tab+i)) {
            min = *(tab+i);
        }
    }

    return min;
}


float CalculateAverage(const int *tab) {
    int sum = 0;

    for(int i = 0; i<LENGTH; i++) {
        sum += *(tab+i);
    }

    return sum/LENGTH;

}



float SearchMedian(const int *tab) {
    int SortedTab[LENGTH];

    for(int i = 0; i<LENGTH; i++) {
        *(SortedTab+i) = *(tab+i);
    }


    for(int i = 0; i<LENGTH-1; i++) {
        for(int j = 0; j<LENGTH-1-i; j++){
            if(*(SortedTab+j) > *(SortedTab+j+1)) {
                int temp = *(SortedTab+j);
                *(SortedTab+j) = *(SortedTab+j+1);
                *(SortedTab+j+1) = temp;
            }
        }
    }

    float median;

    if(LENGTH % 2 == 0) {
        int index_of_middle_num = (LENGTH/2)-1;
        int first_num = *(SortedTab+index_of_middle_num);
        int second_num = *(SortedTab+index_of_middle_num+1);
        median = ((float)first_num + (float)second_num)/2;
    }
    else {
        median = (float) *(SortedTab + ((LENGTH+1)/2) );
    }

    printf("\n\nSorted tab:\n");
    PrintTab(SortedTab);

    return median;
}

int main() {

    int numbers[LENGTH];


    EnterNumbersToTab(numbers);

    PrintTab(numbers);

    printf("Min= %d \n", SearchMin(numbers));
    printf("Max= %d \n", SearchMax(numbers));
    printf("Average= %.2f\n", CalculateAverage(numbers));
    printf("Median= %.2f", SearchMedian(numbers));

    return 0;
}
