sum1 :: Num a => [a] -> a
sum1 []     = 0
sum1 (a:as) = a 

remainder :: Num a => [a] -> [a]
remainder []     = []
remainder (a:as) = as

sum3 :: Num a => [a] -> [a] -> [a] -> [a]
sum3 []     []     []     = []
sum3 a      b      c      = (sum1 a + sum1 b + sum1 c) : sum3 (remainder a) (remainder b) (remainder c) 
