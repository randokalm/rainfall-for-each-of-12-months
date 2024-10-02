#include <iostream>
#include <iomanip> // For setprecision
#include <string>

const int MONTHS = 12;

int main() {
    double rainfall[MONTHS];
    double total = 0;
    double average = 0;
    double highest = 0;
    double lowest = 0;
    std::string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Input loop
    for (int i = 0; i < MONTHS; ++i) {
        std::cout << "Enter rainfall for " << months[i] << ": ";
        std::cin >> rainfall[i];

        // Input validation for negative values
        while (rainfall[i] < 0) {
            std::cout << "invalid data (negative rainfall) -- retry\n";
            std::cout << "Enter rainfall for " << months[i] << ": ";
            std::cin >> rainfall[i];
        }

        // Calculate total
        total += rainfall[i];
    }

    // Calculate average
    average = total / MONTHS;

    // Find highest and lowest rainfall
    highest = rainfall[0];
    lowest = rainfall[0];
    int highestIndex = 0;
    int lowestIndex = 0;
    for (int i = 1; i < MONTHS; ++i) {
        if (rainfall[i] > highest) {
            highest = rainfall[i];
            highestIndex = i;
        }
        if (rainfall[i] < lowest) {
            lowest = rainfall[i];
            lowestIndex = i;
        }
    }

    // Output results
    std::cout << "Total rainfall: " << total << std::endl;
    std::cout << "Average rainfall: " << average << std::endl;
    std::cout << "Least rainfall in: " << months[lowestIndex] << std::endl;
    std::cout << "Most rainfall in: " << months[highestIndex] << std::endl;

    return 0;
}
