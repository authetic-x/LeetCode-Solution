
// 从数组的右上角开始查找，每次要么删除一列，要么删除一行
bool Find(int* matrix, int rows, int columns, int target) {
    bool found = false;
    if (matrix != nullptr && rows > 0 && columns > 0) {
        int row = 0;
        int column = columns-1;
        while (row < rows && column >= 0) {
            if (matrix[row*columns + column] == target) {
                return true;
            } else if (matrix[row*columns + column] > target) {
                column--;
            } else {
                row++;
            }
        }
    }
}