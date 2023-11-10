#pragma once
#include <vector>

void findMax(const std::vector<int>& vec, int start, int end, int& result);
void findMin(const std::vector<int>& vec, int start, int end, int& result);
void calculateSquares(const std::vector<int>& source, int startIndex, int endIndex, std::vector<int>& result);
void calculateCubes(const std::vector<int>& source, int startIndex, int endIndex, std::vector<int>& result);
void calculateSum(const std::vector<int>& source, int start, int end, long& result);