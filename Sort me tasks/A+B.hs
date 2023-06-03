main = do
  input <- getLine
  let [a, b] = map read (words input) :: [Int]
  print (a + b)
