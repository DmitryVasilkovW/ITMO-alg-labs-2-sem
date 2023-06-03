import Control.Monad

isBalanced :: String -> Bool
isBalanced s = go s [] where
  go [] [] = True
  go [] _ = False
  go (x:xs) stack
    | x `elem` "({" = go xs (x:stack)
    | null stack = False
    | x == ')' && head stack == '(' = go xs (tail stack)
    | x == '}' && head stack == '{' = go xs (tail stack)
    | otherwise = False

main :: IO ()
main = do
  s <- getLine
  if isBalanced s
    then putStrLn "YES"
    else putStrLn "NO"
