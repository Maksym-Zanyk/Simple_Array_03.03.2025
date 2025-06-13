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
        printf("[%d]=%d\t", i, *(tab+i));
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

void EditNumberByIndex(int *tab) {
    printf("Index of number: ");

    int ind;
    scanf("%d", &ind);

    if (ind < 0 || ind > 9) {
        printf("ERROR\n");
    }
    else {
        printf("New value: ");
        scanf("%d", tab + ind);
    }
}


void menu(){
    printf("0. Exit\n");
    printf("1. Print an array\n");
    printf("2. Enter numbers to array\n");
    printf("3. Print MIN value\n");
    printf("4. Print MAX value\n");
    printf("5. Print average value\n");
    printf("6. Print median value\n");
    printf("7. Edit number\n\n");


    printf("\tSelect an option: ");

}

int main() {

    printf("Simple array program\n");

    int numbers[LENGTH] = {0,0,0,0,0,0,0,0,0,0};

    int option;

    do{
        menu();
        scanf("%d", &option);

        switch (option) {
            case 0:
                break;
            case 1:
                PrintTab(numbers);
                break;
            case 2:
                EnterNumbersToTab(numbers);
                break;
            case 3:
                printf("Min= %d \n", SearchMin(numbers));
                break;
            case 4:
                printf("Max= %d \n", SearchMax(numbers));
                break;
            case 5:
                printf("Average= %.2f\n", CalculateAverage(numbers));
                break;
            case 6:
                printf("Median= %.2f\n", SearchMedian(numbers));
                break;
            case 7:
                EditNumberByIndex(numbers);
                break;
            default:
                printf("No such option. Try again\n\n");


        }
        puts("");

    }while(option != 0);


    return 0;

}
