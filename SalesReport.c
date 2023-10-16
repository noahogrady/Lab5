#include <stdio.h>

float monthly_earnings[] = {23458.01,40112.00,56011.85,37820.88,37904.67,60200.22,72400.31,56210.89,67230.84,68233.12,80950.34,95225.22};
char months[][10] = {"January","February","March","April", "May", "June", "July", "August", "September", "October", "November", "December"};

void salesReport(char months[][10], float nums[]){
    printf("Monthly Sales Report for 2022:\nMonth\tSales");
    for (int i=0; i<12; i++){
        printf("\n%s\t$%f", months[i], nums[i]);
    }
}

void salesSummary(char months[][10], float nums[]){
    int min_index = 0;
    int max_index = 0;
    float sum;
    float average;
    for (int i=1; i<12; i++){
        if (nums[i] < nums[min_index]){
            min_index = i;
        }
    }
    for (int i=1; i<12; i++){
        if (nums[i] > nums[max_index]){
            max_index = i;
        }
    }
    for (int i=0;i<12;i++){
        sum += nums[i];
    }
    average = (sum)/12;

    printf("\n\nSales Summary:\nMinimum Sales: $%f  (%s)\nMaximum Sales: $%f  (%s)\nAverage Sales: $%.2f",nums[min_index], months[min_index], nums[max_index], months[max_index], average);

    
}

void movingReport(char months[][10], float nums[]){
    printf("\n\nSix-Month Moving Average Report:");
    for(int i=0;i<7;i++){
        float moving_sum = 0;
        for(int x=i;x<i+6;x++){
            moving_sum += nums[x];
        }
        float moving_average = (moving_sum/6);
        printf("\n%s - %s\t$%.2f", months[i], months[i+5], moving_average);
    }
}

void rankedReport(char months[][10], float nums[]){
    printf("\n\nSales Report (Highest to Lowest):");
    for(int i=0; i<12;i++){
        int max_index = 0;
        for (int i=1; i<12; i++){
            if (nums[i] > nums[max_index]){
                max_index = i;
            }
        }
        printf("\n%s $%.2f", months[max_index], nums[max_index]);
        nums[max_index] = 0;
    }
}

int main(){
    salesReport(months, monthly_earnings);
    salesSummary(months, monthly_earnings);
    movingReport(months, monthly_earnings);
    rankedReport(months, monthly_earnings);
    return 0;
}