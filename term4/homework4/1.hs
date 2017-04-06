evens :: Integral a => [a] -> Int
evens l = length $ filter (\x -> even x) l

evens' :: Integral a => [a] -> a
evens' l = sum (map (\x -> 1 - (x `mod` 2)) l)

evens'' :: (Integral b, Foldable t) => t b -> b
evens'' l = foldr (\x y -> y + (1 - (x `mod` 2))) 0 l