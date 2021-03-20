#include "country-scanner.h"

#include <iostream>
#include <unordered_set>

void scan(int countryCode, int startRow, int startCol,
          std::vector<std::vector<bool>>& validIndexes,
          std::vector<std::vector<int>>& countryMap) {
    // Check one left
    // If we find a match and the index is valid, start the scan again from that
    // point
    int nextRow = startRow + 1;
    if (nextRow < countryMap.size()) {
        int nextCountryCode = countryMap[nextRow][startCol];
        int validIndex = validIndexes[nextRow][startCol];
        if (validIndex && countryCode == nextCountryCode) {
            validIndexes[nextRow][startCol] = false;
            scan(countryCode, nextRow, startCol, validIndexes, countryMap);
        }
    }

    // Scan one down down
    // If we find a match, make that index false and start the scan again from
    // that point
    int nextCol = startCol + 1;
    if (nextCol < countryMap[startRow].size()) {
        int nextCountryCode = countryMap[startRow][nextCol];
        int validIndex = validIndexes[startRow][nextCol];
        if (validIndex && countryCode == nextCountryCode) {
            validIndexes[startRow][nextCol] = false;
            scan(countryCode, startRow, nextCol, validIndexes, countryMap);
        }
    }
}

int solution(std::vector<std::vector<int>>& countryMap) {
    if (countryMap.size() == 0) return -1;

    int rowCount = countryMap.size();
    int colCount = countryMap[0].size();

    // // Create another index matrix to track squares that haven't been
    // // claimed by another country before
    std::vector<std::vector<bool>> validIndexes(
        rowCount, std::vector<bool>(colCount, true));

    int countryCode;
    int countryCount = 0;

    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < colCount; col++) {
            bool validIndex = validIndexes[row][col];
            if (validIndex) {
                // Get the current valid country code
                countryCode = countryMap[row][col];

                // Scan to invalidate all other indexes that belong to this
                // country
                scan(countryCode, row, col, validIndexes, countryMap);

                ++countryCount;
            }
        }
    }

    return countryCount;
}

TEST_CASE("Testing the country scanner") {
    std::vector<std::vector<int>> countryMap{
        {5, 5, 3, 5}, {5, 5, 5, 5}, {3, 4, 5, 1}, {7, 2, 2, 3}, {4, 2, 1, 1}};
    CHECK(solution(countryMap) == 11);
}