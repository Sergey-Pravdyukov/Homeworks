import Data.List

data Polynomial = Polynomial [(Int, Int)]

coeffSign :: (Num a, Ord a) => a -> [Char]
coeffSign coeff | coeff > 0 = "+"
                | otherwise = ""

showCoeff :: (Num a, Ord a, Show a) => a -> [Char]
showCoeff 0 = ""
showCoeff c = (coeffSign c) ++ show c 

showDeg :: (Eq a, Num a, Show a) => a -> [Char]
showDeg 0 = ""
showDeg d = "*x^" ++ show d

showTerm :: (Eq a1, Num a, Num a1, Ord a, Show a, Show a1) => a -> a1 -> [Char]
showTerm c d = (showCoeff c) ++ (showDeg d)

show' (Polynomial [])          = ""
show' (Polynomial ((c, d):ps)) = (showTerm c d) ++ (show' (Polynomial ps))

instance Show Polynomial where
    show p | head(show' p) == '+' = tail(show' p)
           | otherwise            = show' p

add :: (Num t, Ord a) => [(t, a)] -> [(t, a)] -> [(t, a)]
add []             []                        = []
add ((cA, dA):psA) []                        = ((cA, dA):psA)
add []             ((cB, dB):psB)            = ((cB, dB):psB)
add ((cA, dA):psA) ((cB, dB):psB) | dA == dB = ((cA + cB, dA):(add psA psB))
                                  | dA <  dB = ((cA,dA):(add psA ((cB,dB):psB)))
                                  | dA >  dB = ((cB,dB):(add ((cA,dA):psA) psB))

addition :: Polynomial -> Polynomial -> Polynomial
addition (Polynomial a) (Polynomial b) = Polynomial (sortBy cmp (add a b))

mul :: (Num t, Num t1) => [(t, t1)] -> [(t, t1)] -> [(t, t1)] -> [(t, t1)]
mul []             _              _     = []
mul ((cA, dA):psA) []             fullB = mul psA fullB fullB
mul ((cA, dA):psA) ((cB, dB):psB) fullB = (cA * cB, dA + dB) : (mul ((cA, dA):psA) psB fullB)

multiplication :: Polynomial -> Polynomial -> Polynomial
multiplication (Polynomial a) (Polynomial b) = Polynomial (sortBy cmp (removeSuchTerms(reverse(addSuchTerms(mul a b b)))))

tail' :: [t] -> [t]
tail' [] = []
tail' l  = tail l

cmp :: Ord a => (t, a) -> (t1, a) -> Ordering
cmp (cA, dA) (cB, dB) | dA > dB   = LT
                      | otherwise = GT

addSuchTerms :: (Eq a, Num t) => [(t, a)] -> [(t, a)]
addSuchTerms ((cA,dA):psA) = helper ((cA, dA):psA) psA where
    helper []    _  = []
    helper (p:psA) [] = p:(helper psA (tail' psA))
    helper ((cA, dA):psA) ((cB, dB):psB) | dA == dB  = helper ((cA + cB, dA):psA) psB
                                         | otherwise = helper ((cA, dA):psA) psB

removeSuchTerms :: (Eq a, Num t) => [(t, a)] -> [(t, a)]
removeSuchTerms ((cA, dA):psA) = helper ((cA, dA):psA) psA where 
    helper []    _  = []
    helper (p:psA) [] = p:(helper psA (tail' psA))
    helper ((cA, dA):psA) ((cB, dB):psB) | dA == dB  = helper psA (tail psA)
                                         | otherwise = helper ((cA, dA):psA) psB   