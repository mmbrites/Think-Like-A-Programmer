#include <iostream>
using std::cout;

double arrayAverage(int intArray[], int ARRAY_SIZE) {

    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
        if(intArray[i] != -1)
            sum += intArray[i];

    double average = sum / ARRAY_SIZE;
    return average;

}

int compareFunc(const void* voidA, const void* voidB) {

    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);

    return *intA - *intB;

}

int main() {

    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {-1, -1, -1, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, -1, -1, -1, -1, -1},
        {-1, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, -1}
    };

    int highestSales = sales[0][0];
    for (int agent = 0; agent < NUM_AGENTS; agent++)
        for (int month = 0; month < NUM_MONTHS; month++)
            if (sales[agent][month] > highestSales)
                highestSales = sales[agent][month];

    cout << "Highest Monthly Sale: " << highestSales << "\n";

    double highestAverage = arrayAverage(sales[0], NUM_MONTHS);
    for (int agent = 1; agent < NUM_AGENTS; agent++) {
        double agentAverage = arrayAverage(sales[agent], NUM_MONTHS);
        if (agentAverage > highestAverage)
            highestAverage = agentAverage;
    }

    cout << "Highest Monthly Average: " << highestAverage << "\n";

    int highestMedianSale;

    for (int agent = 0; agent < NUM_AGENTS; agent++) {

        qsort(sales[agent], NUM_MONTHS, sizeof(int), compareFunc);

        int middleArrayPosition = NUM_MONTHS / 2;
        double median;
        if (NUM_MONTHS % 2 == 0) {

            if (sales[agent][middleArrayPosition - 1] == -1)
                sales[agent][middleArrayPosition - 1] = 0;
            if (sales[agent][middleArrayPosition] == -1)
                sales[agent][middleArrayPosition] = 0;

            median = (sales[agent][middleArrayPosition - 1] + sales[agent][middleArrayPosition]) / 2.0;
        }
        else {

            if (sales[agent][middleArrayPosition] == -1)
                sales[agent][middleArrayPosition] = 0;
            median = sales[agent][middleArrayPosition];
        
        }

        if (agent == 0)
            highestMedianSale = median;
        else if (median > highestMedianSale)
            highestMedianSale = median;

    }

    cout << "Highest Median Sale: " << highestMedianSale << "\n";

}