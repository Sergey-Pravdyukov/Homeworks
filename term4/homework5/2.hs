pairs :: (Enum b, Num b) => b -> [b]
pairs n = do
    x <- [1..n] 
    y <- [1..n] 
    return (x * y)