package main

import (
 "fmt"
)

func check(logs []int, k, length int) bool {
 cuts := 0
 for _, log := range logs {
  cuts += (log - 1) / length
  if cuts > k {
   return false
  }
 }
 return true
}

func main() {
 var n, k, maxLen, lo, hi, ans int
 fmt.Scan(&n, &k)
 logs := make([]int, n)
 maxLen = 0
 for i := 0; i < n; i++ {
  fmt.Scan(&logs[i])
  maxLen = max(maxLen, logs[i])
 }
 lo = 1
 hi = maxLen
 for lo <= hi {
  mid := lo + (hi-lo)/2
  if check(logs, k, mid) {
   ans = mid
   hi = mid - 1
  } else {
   lo = mid + 1
  }
 }
 fmt.Println(ans)
}

func max(a, b int) int {
 if a > b {
  return a
 }
 return b
}
