printX :: (Eq a, Num a) => a -> [Char]
printX 0 = ""
printX n = 'x' : printX(n-1)

printSpaces :: (Eq a, Num a) => a -> [Char]
printSpaces 0 = ""
printSpaces n = ' ' : printSpaces(n-1)

printRow :: (Eq a, Num a) => a -> a -> [[Char]]
printRow n 0 = [printX(n*2-1)] 
printRow n i = concat [printSpaces(i), printX((n-i)*2-1), printSpaces(i)] : printRow n (i-1)

printer n = mapM_ print (printRow n (n-1) ++ tail (reverse(printRow n (n - 1))))