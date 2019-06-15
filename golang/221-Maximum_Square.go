package golang

func maximalSquare(matrix [][]byte) int {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
        return 0
    }
    m, n := len(matrix), len(matrix[0])
    dp := make([][]int, m)
    for i := range dp {
        dp[i] = make([]int, n)
    }
    var maxL int
    for i := 0; i < m; i ++ {
        for j := 0; j < n; j ++ {
            if matrix[i][j] == '1' {
                if i == 0 || j == 0{
                    dp[i][j] = 1
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1
                }
                if maxL < dp[i][j] {
                    maxL = dp[i][j]
                }
            }
        }
    }
    return maxL * maxL
}

func min(a ...int) int {
    min := math.MaxInt32
    for i := 0; i < len(a); i ++ {
        if a[i] < min {
            min = a[i]
        }
    }
    return min
}