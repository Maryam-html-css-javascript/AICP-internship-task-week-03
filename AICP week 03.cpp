#include <iostream>
#include <iomanip>
#ifdef _WIN32
    #include <windows.h> // For Windows system
#else
    #define RESET "\033[0m"
    #define GREEN "\033[32m"
    #define YELLOW "\033[33m"
    #define CYAN "\033[36m"
#endif

using namespace std;

void setConsoleColor(int color) {
    #ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    #endif
}

// Function to calculate and display cost for a given slab
void displayBillForSlab(int matrix[][3], int slabIndex, const string& studentID, int unitRangeStart, int unitRangeEnd, int costPerUnit) {
    cout << "\t\t\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\t\tStudent ID: " << studentID << endl;

    cout << "\t\t\t\t\tBill for Slab " << slabIndex + 1 << " is:\n";
    for (int i = 0; i < 3; ++i) {
        int units = matrix[slabIndex][i]; // Units for the current slab
        int totalCost = units * costPerUnit;
        cout << "\t\t\t\t\tUnit " << i + 1 << ": " << setw(4) << units << " units, Cost: Rs. " << setw(4) << totalCost << endl;
    }

    int totalUnits = matrix[slabIndex][0] + matrix[slabIndex][1] + matrix[slabIndex][2];
    int grandTotal = totalUnits * costPerUnit;

    cout << "\t\t\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\t\tTotal Units: " << totalUnits << ", Grand Total: Rs. " << grandTotal << endl;
}

int main() {
    const string studentID = "Maryam Siddiqui(BCS-027)"; // Student ID

    // Source data matrix
    int sourceMatrix[3][3] = {
        {55, 65, 75},
        {120, 150, 170},
        {210, 230, 240}
    };

    char choice;

    cout << "\t\t\t\t\tWelcome, " << studentID << "!\n";

    do {
        // Display the menu with the student's ID
        cout << "\t\t\t------------------------------------------------------------\n";
        cout << "\t\t\t\t\tEnter your choice:\n";
        cout << "\t\t\t\t\t1. Display the bill of Slab 1 and Slab 2\n";
        cout << "\t\t\t\t\t2. Display the bill of Slab 3\n";
        cout << "\t\t\t\t\tEnter any other key to exit\n";
        cout << "\t\t\t------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t";
		cin >> choice;

        switch (choice) {
            case '1':
                setConsoleColor(11); // Yellow color
                displayBillForSlab(sourceMatrix, 0, studentID, 0, 100, 10); // Slab 1
                displayBillForSlab(sourceMatrix, 1, studentID, 101, 200, 15); // Slab 2
                break;
            case '2':
                setConsoleColor(14); // Cyan color
                displayBillForSlab(sourceMatrix, 2, studentID, 201, 300, 20); // Slab 3
                break;
            default:
                cout << "\t\t\t\t\tExiting the program. Thank you for using our enhanced billing system.\n";
                break;
        }

        setConsoleColor(15); // Reset color
    } while (choice == '1' || choice == '2');

    return 0;
}

