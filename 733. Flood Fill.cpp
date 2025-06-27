// problem link : https://leetcode.com/problems/flood-fill/
//this problem is similar like 200. Number of Island.


class Solution {
public:

    bool isValid(vector<vector<int>>& image, int i, int j, int m, int n, int color) {
        return (i >= 0 && i < m && j >= 0 && j < n && image[i][j] == color);
    }

    void floodFillRec(vector<vector<int>>& image, int i, int j, int m, int n, int color, int newColor) {
        image[i][j] = newColor;

        if (isValid(image, i + 1, j, m, n, color))
            floodFillRec(image, i + 1, j, m, n, color, newColor);

        if (isValid(image, i - 1, j, m, n, color))
            floodFillRec(image, i - 1, j, m, n, color, newColor);

        if (isValid(image, i, j + 1, m, n, color))
            floodFillRec(image, i, j + 1, m, n, color, newColor);

        if (isValid(image, i, j - 1, m, n, color))
            floodFillRec(image, i, j - 1, m, n, color, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int color = image[sr][sc];

        // Prevent infinite recursion
        if (color == newColor)
            return image;

        floodFillRec(image, sr, sc, m, n, color, newColor);
        return image;
    }
};
