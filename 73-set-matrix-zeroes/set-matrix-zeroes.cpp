class Solution {
public:
void setZeroes(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    // These two variables remember whether
    // the FIRST ROW or FIRST COLUMN originally had a zero.
    //
    // We cannot directly use the first row/column as markers
    // because they themselves may need to be converted to zero.
    bool firstRow = false;
    bool firstCol = false;


    // -------------------------------------------------------
    // STEP 1: Check whether the FIRST ROW contains any zero
    // -------------------------------------------------------

    for (int j = 0; j < n; j++) {

        if (matrix[0][j] == 0)
            firstRow = true;
    }


    // -------------------------------------------------------
    // STEP 2: Check whether the FIRST COLUMN contains any zero
    // -------------------------------------------------------

    for (int i = 0; i < m; i++) {

        if (matrix[i][0] == 0)
            firstCol = true;
    }


    // -------------------------------------------------------
    // STEP 3: Use first row and first column as MARKERS
    //
    // If matrix[i][j] == 0:
    //
    //     matrix[i][0] = 0  -> mark entire row i
    //
    //     matrix[0][j] = 0  -> mark entire column j
    //
    // We start from 1 because row 0 and column 0
    // are being used as marker storage.
    // -------------------------------------------------------

    for (int i = 1; i < m; i++) {

        for (int j = 1; j < n; j++) {

            if (matrix[i][j] == 0) {

                // Mark this row
                matrix[i][0] = 0;

                // Mark this column
                matrix[0][j] = 0;
            }
        }
    }


    // -------------------------------------------------------
    // STEP 4: Use the markers to actually make cells zero
    //
    // If:
    //
    // matrix[i][0] == 0
    //      -> row i has to become zero
    //
    // OR
    //
    // matrix[0][j] == 0
    //      -> column j has to become zero
    //
    // So matrix[i][j] becomes zero.
    // -------------------------------------------------------

    for (int i = 1; i < m; i++) {

        for (int j = 1; j < n; j++) {

            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }


    // -------------------------------------------------------
    // STEP 5: Handle the FIRST ROW separately
    //
    // We stored whether the original first row contained
    // a zero in firstRow.
    //
    // If yes, make the complete first row zero.
    // -------------------------------------------------------

    if (firstRow) {

        for (int j = 0; j < n; j++)
            matrix[0][j] = 0;
    }


    // -------------------------------------------------------
    // STEP 6: Handle the FIRST COLUMN separately
    //
    // We stored whether the original first column contained
    // a zero in firstCol.
    //
    // If yes, make the complete first column zero.
    // -------------------------------------------------------

    if (firstCol) {

        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;
    }
}
};