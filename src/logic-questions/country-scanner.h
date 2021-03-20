#pragma once
#include <doctest/doctest.h>
#include <vector>


/**
 * The scan function takes the country code and starts recursively looking for
 * all indexes that form a valid country for this code, first checking to the
 * right, and then down.
 *
 * Solution works on the premise that you are scanning from left to right, and
 * from up to down,so you assume that the stages before you will handle the
 * indexes before the scan point you've been given.
 *
 */
void scan(int countryCode, int startRow, int startCol,
          std::vector<std::vector<bool>>& validIndexes,
          std::vector<std::vector<int>>& countryMap);


/**
 * Entry point for the solution of finding countries in a two dimensional vectors 
 */
int solution(std::vector<std::vector<int>>& countryMap);


