package main

import (
 "fmt"
)

func main() {
 var s string
 fmt.Scan(&s)

 
 stack := make([]rune, 0)


 for _, c := range s {
  if c == '(' {
  
   stack = append(stack, c)
  } else if c == ')' {
  
   if len(stack) > 0 && stack[len(stack)-1] == '(' {
  
    stack = stack[:len(stack)-1]
   } else {
   
    fmt.Println("NO")
    return
   }
  }
 }


 if len(stack) == 0 {
  fmt.Println("YES")
 } else {
  fmt.Println("NO")
 }
}
