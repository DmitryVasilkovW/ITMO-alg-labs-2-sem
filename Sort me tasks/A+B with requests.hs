main = do
    t <- getLine
    mapM_ (\_ -> do
        line <- getLine
        let [a, b] = map read (words line)
        putStrLn $ show (a + b)) [1..(read t :: Int)]
