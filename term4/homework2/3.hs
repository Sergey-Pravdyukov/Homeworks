mSum :: Integer -> Integer
mSum n = digitsSum 0 n where
  digitsSum result n | n == 0 = result
                     | otherwise = digitsSum (result + (abs n `mod` 10)) (abs n `div` 10)