#include <iostream>
using std::cout;

int compareFunc(const void* voidA, const void* voidB) {

    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);

    return *intA - *intB;

}

int main() {

    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    int highestMedianSale;

    for (int agent = 0; agent < NUM_AGENTS; agent++) {

        qsort(sales[agent], NUM_MONTHS, sizeof(int), compareFunc);

        int middleArrayPosition = NUM_MONTHS / 2;
        double median;
        if (NUM_MONTHS % 2 == 0)
            median = (sales[agent][middleArrayPosition - 1] + sales[agent][middleArrayPosition]) / 2.0;
        else
            median = sales[agent][middleArrayPosition];

        if (agent == 0)
            highestMedianSale = median;
        else if (median > highestMedianSale)
            highestMedianSale = median;

    }

    cout << "Highest Median Sale: " << highestMedianSale << "\n";

}