import System.Random

data BST a = Empty | Leaf a | Node (BST a) a (BST a) 

instance Eq a => Eq (BST a) where
    Empty == Empty = True
    Leaf x == Leaf y = x == y
    Node l x r == Node l' x' r' = l == l' && x == x' && r == r'

instance Show a => Show (BST a) where
    show Empty        = "Empty"
    show (Leaf x)     = "(Leaf " ++ show x ++ ")"
    show (Node l x r) = "(Node " ++ show l ++ " " ++ show x ++ " " ++ show r ++ ")"

tree = (Node (Node (Leaf 3) 4 (Empty)) 9 (Leaf 10))

replace :: (Num a, Show t, Show a, Random a) => BST t -> (a, a) -> IO ()
replace (Leaf _)            (l, r) = do
    g <- newStdGen
    putStr (show (Leaf (fst (randomR (l + 1, r - 1) g))) ++ " ")
replace (Node left _ right) (l, r) = do
    g <- newStdGen
    putStr "(Node "
    replace left (l, fst (randomR(l+1, r-1) g)-1) 
    putStr (show (fst (randomR(l+1, r-1) g)) ++ " ")
    replace right (fst (randomR(l+1, r-1) g)+1, r)
    putStr ") "
replace Empty                   _      = putStr (show Empty)

add :: (Ord a) => BST a -> a -> BST a
add Empty        val             = Leaf val
add (Leaf x)     val | val < x   = Node (Leaf val) x Empty     
                     | otherwise = Node Empty      x (Leaf val)
add (Node l x r) val | val < x   = Node (add l val) x r
                     | otherwise = Node l           x (add r val)

findRightMost :: (Eq a) => BST a -> BST a
findRightMost Empty        = Empty
findRightMost (Leaf x)     = Leaf x
findRightMost (Node l x r) | r == Empty = Leaf x
                           | otherwise  = findRightMost r

remove :: (Eq a, Ord a) => BST a -> a -> BST a
remove t value = case t of
    Empty        -> Empty
    Leaf x       -> if (x == value) then Empty
                    else Leaf x
    (Node l x r) -> if (x == value) then 
                        case (findRightMost l) of
                            Empty  -> Empty   
                            Leaf y -> case (remove l y) of 
                                Empty  -> if (r == Empty) then Leaf y
                                          else Node Empty y r
                                Leaf x -> Node (Leaf x) y r 
                    else if (value < x) then Node (remove l value) x r
                    else Node l x (remove r value)

find :: (Ord a, Show a) => BST a -> a -> IO ()
find Empty    value                  = putStrLn ("value " ++ (show value) ++ " not found")
find (Leaf x) value     | value /= x = putStrLn ("value " ++ (show value) ++ " not found")
                        | otherwise  = putStrLn ("value " ++ (show value) ++ " found")
find (Node l x r) value | value < x  = find l value
                        | value > x  = find r value
                        | otherwise  = putStrLn ("value " ++ (show value) ++ " found")

height :: BST a -> Int
height Empty        = 0
height (Leaf x)     = 1
height (Node l x r) = 1 + (max (height l) (height r))

size :: BST a -> Int
size Empty        = 0
size (Leaf x)     = 1
size (Node l x r) = 1 + (size l) + (size r)
