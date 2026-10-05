/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node*
_bottomRight) { val = _val; isLeaf = _isLeaf; topLeft = _topLeft; topRight = _topRight; bottomLeft =
_bottomLeft; bottomRight = _bottomRight;
    }
};
*/


class Solution {
public:
    bool allone(int i, int j, int l, int h,
                vector<vector<int>>& grid) {
        for (int x = i; x <= j; x++) {
            for (int y = l; y <= h; y++) {
                if (grid[x][y] == 0) return false;
            }
        }
        return true;
    }

    bool allzero(int i, int j, int l, int h,
                 vector<vector<int>>& grid) {
        for (int x = i; x <= j; x++) {
            for (int y = l; y <= h; y++) {
                if (grid[x][y] == 1) return false;
            }
        }
        return true;
    }

    Node* func(int i, int j, int l, int h,
               vector<vector<int>>& grid) {
        if (allone(i, j, l, h, grid)) {
            return new Node(1, 1);
        }

        if (allzero(i, j, l, h, grid)) {
            return new Node(0, 1);
        }

        Node* node = new Node(1, 0);

        int midRow = (i + j) / 2;
        int midCol = (l + h) / 2;

        node->topLeft = func(i, midRow, l, midCol, grid);
        node->topRight = func(i, midRow, midCol + 1, h, grid);
        node->bottomLeft = func(midRow + 1, j, l, midCol, grid);
        node->bottomRight = func(midRow + 1, j, midCol + 1, h, grid);

        return node;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return func(0, n - 1, 0, n - 1, grid);
    }
};