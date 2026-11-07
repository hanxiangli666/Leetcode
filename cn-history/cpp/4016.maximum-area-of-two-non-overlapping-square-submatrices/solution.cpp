class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int rows = mat.size();
        int columns = mat[0].size();
        vector<vector<int>> prefix(
            rows + 1,
            vector<int>(columns + 1, 0)
        );

        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                prefix[row + 1][column + 1] =
                    mat[row][column]
                    + prefix[row][column + 1]
                    + prefix[row + 1][column]
                    - prefix[row][column];
            }
        }

        auto canChooseTwo = [&](int sideLength) {
            int minimumRow = rows;
            int maximumRow = -1;
            int minimumColumn = columns;
            int maximumColumn = -1;

            for (int topRow = 0;
                 topRow + sideLength <= rows;
                 ++topRow) {

                for (int leftColumn = 0;
                     leftColumn + sideLength <= columns;
                     ++leftColumn) {

                    int bottomRow = topRow + sideLength;
                    int rightColumn = leftColumn + sideLength;

                    int numberOfOnes =
                        prefix[bottomRow][rightColumn]
                        - prefix[topRow][rightColumn]
                        - prefix[bottomRow][leftColumn]
                        + prefix[topRow][leftColumn];

                    if (numberOfOnes ==
                        sideLength * sideLength) {

                        minimumRow = min(minimumRow, topRow);
                        maximumRow = max(maximumRow, topRow);

                        minimumColumn =
                            min(minimumColumn, leftColumn);
                        maximumColumn =
                            max(maximumColumn, leftColumn);

                        if (maximumRow - minimumRow >= sideLength ||
                            maximumColumn - minimumColumn >= sideLength) {
                            return true;
                        }
                    }
                }
            }

            return false;
        };

        int lowSide = 1;
        int highSide = min(rows, columns);
        int bestSide = 0;

        while (lowSide <= highSide) {
            int middleSide =
                lowSide + (highSide - lowSide) / 2;

            if (canChooseTwo(middleSide)) {
                bestSide = middleSide;
                lowSide = middleSide + 1;
            } else {
                highSide = middleSide - 1;
            }
        }

        return bestSide * bestSide;
    }
};
