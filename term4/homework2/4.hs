find :: Integer -> [Integer] -> Int
find value list = helper value list 1 where
  helper _ [] _ = (maxBound::Int)
  helper value (x:xs) index | x == value = min index (helper value xs (index + 1))
                            | otherwise = helper value xs (index + 1)