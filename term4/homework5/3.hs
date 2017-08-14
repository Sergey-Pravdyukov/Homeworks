last' :: [Int] -> Int
last' [] = (maxBound::Int)
last' l  = last l

maxAmongNeighbsList :: [Int] -> [Int]
maxAmongNeighbsList list = do
    x <- list
    True <- return ((last' (takeWhile' (/= x) list)) < x && last' (takeWhile' (/= x) (reverse' list)) < x)
    return (x)

maxAmongNeighbs :: [Int] -> Int
maxAmongNeighbs = head . maxAmongNeighbsList

reverse' :: [Int] -> [Int]
reverse' l = do
    True <- return (l /= [])
    ((reverse' (tail l)) ++ [head l])

takeWhile' :: (Int -> Bool) -> [Int] -> [Int]
takeWhile' p l = do
    True <- return (l /= [] && p (head l))
    (head l) : (takeWhile' p (tail l))