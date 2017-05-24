change :: Integer -> [[Integer]]
change num | num <= 0  = [[]]
           | otherwise = [(x:xs) | x <- [1 .. num], xs <- change (num - x), x <= num]