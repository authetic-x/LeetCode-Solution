package golang

func findTargetSumWays(nums []int, s int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		if nums[0] == s || nums[0] == -s {
			if (nums[0] == 0) {
				return 2
			}
			return 1;
		} else {
			return 0;
		}
	}
	var ans int
	ans += findTargetSumWays(nums[1:], s-nums[0])
	ans += findTargetSumWays(nums[1:], s+nums[0])
	return ans
}