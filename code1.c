/*
* Name: Megan Svoren
* Class: EECS 348
* Lab Time: Wednesday at 1:00pm
* Lab Number: Lab05
* Purpose: Reads 12 monthly sales and generates a sales report that includes a monthly sales report, a sales summary report, a six-month moving average report, and a sales report organized from highest to lowest.
*/
#include <stdio.h>
#include <stdlib.h>

// Prints the month name
void print_month(char month_name[])
{
    for (int i = 0; month_name[i] != '\0'; i++)
    {
        printf("%c", month_name[i]);
    }
    
}

// Prints the monthly sales report
void print_monthly_sales_report(float sales_figs[12], char* months[])
{
    printf("Monthly Sales Report for 2024\nMonth\t\tSales\n");
    for (int i = 0; i < 12; i++)
    {
        print_month(months[i]);
        // Prints in neat columns (tab space is adjusted for longer months)
        if (i == 1 || i == 8 || i == 10 || i == 11) // If month is February, September, November, or December, only one tab space is needed
        {
            printf("\t%.2f\n", sales_figs[i]);
        }
        else
        {
            printf("\t\t%.2f\n", sales_figs[i]);
        }
    }
}

// Prints the sales summary report
void print_sales_summary_report(float sales_figs[12], char* months[])
{
    printf("\nSales Summary Report:");
    float min = sales_figs[0];
    int minMonthIndex = 0;
    float max = sales_figs[0];
    int maxMonthIndex = 0;
    float total = 0;
    for (int i = 1; i < 12; i++)
    {
        if (sales_figs[i] < min)
        {
            min = sales_figs[i];
            minMonthIndex = i;
        }
        else if (sales_figs[i] > max)
        {
            max = sales_figs[i];
            maxMonthIndex = i;
        }
        total += sales_figs[i];
    }
    float average = total / 12;

    // Prints the minimum sales and the month it happened in
    printf("\nMinimum sales: %.2f (", min);
    print_month(months[minMonthIndex]);
    printf(")");

    // Prints the maximum sales and the month it happened in
    printf("\nMaximum sales: %.2f (", max);
    print_month(months[maxMonthIndex]);
    printf(")");

    // Prints the average sales
    printf("\nAverage sales: %.2f\n", average);
}

// Prints the six-month moving average
void print_six_month_moving_avg(float sales_figs[12], char* months[])
{
    printf("\nSix-Month moving average report:\n");
    for (int i = 0, j = 5; j < 12; i++, j++)
    {
        float tempTotal = 0;
        for (int k = i; k <= j; k++)
        {
            tempTotal += sales_figs[k];
        }
        float sixMonthAvg = tempTotal / 6;

        print_month(months[i]);
        printf("-");
        print_month(months[j]);
        printf("\t %0.2f\n", sixMonthAvg);

    }
}

// Prints the sales report from highest to lowest
void print_descending_order(float sales_figs[12], char* months[12])
{
    char months_copy[12];
    float sorted_sales_figs[12];

    printf("\nSales report (highest to lowest):\n");
    // Iterates through each index in sales_figs
    for (int i = 0; i < 12; i++)
    {
        // Iterates through each index in sales_figs
        int tempMaxIndex = i;
        for (int j = 0; j < 12; j++)
        {
            if (sales_figs[j] > sales_figs[tempMaxIndex])
            {
                tempMaxIndex = j;
            }
        }
        print_month(months[tempMaxIndex]);
        // Prints in neat columns (tab space is adjusted for longer months)
        if (tempMaxIndex == 1 || tempMaxIndex == 8 || tempMaxIndex == 10 || tempMaxIndex == 11) // If month is February, September, November, or December, only one tab space is needed
        {
            printf("\t%.2f\n", sales_figs[tempMaxIndex]);
        }
        else
        {
            printf("\t\t%.2f\n", sales_figs[tempMaxIndex]);
        }
        //printf(" %0.2f", sales_figs[tempMaxIndex]);
        sales_figs[tempMaxIndex] = 0;
    }

}



int main()
{
    char sales_chars[24][9];
    FILE *file;
    file = fopen("inputs.txt","r");

    // Read file and store contents to the array 'sales_chars'
    int line = 0;
    while (!feof(file) && !ferror(file))
    {
        if (fgets(sales_chars[line], sizeof(sales_chars[line]), file) != NULL && line < 24)
        {
            line++;
        }
    }
    fclose(file);
    
    // Converts the char "strings" of numbers to floats
    float sales_figures[12];
    for (int i = 0; i < 12; i++)
    {
        sales_figures[i] = (float)atof(sales_chars[2*i]);
    }

    char* months[12] = {"January\0", "February\0", "March\0", "April\0", "May\0", "June\0", "July\0", "August\0", "September\0", "October\0", "November\0", "December\0"};

    print_monthly_sales_report(sales_figures, months);
    print_sales_summary_report(sales_figures, months);
    print_six_month_moving_avg(sales_figures, months);
    print_descending_order(sales_figures, months);

    return 0;
}