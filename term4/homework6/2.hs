import Control.Monad.Random
import Data.Monoid (mempty, (<>))
  
data BST a = Empty | Node (BST a) a (BST a)

instance Eq a => Eq (BST a) where
    Empty == Empty = True
    Node l x r == Node l' x' r' = l == l' && x == x' && r == r'

instance Show a => Show (BST a) where
    show Empty        = "Empty"
    show (Node l x r) = "(Node " ++ show l ++ " " ++ show x ++ " " ++ show r ++ ")"

instance Functor BST where
    fmap _ Empty        = Empty
    fmap f (Node l x r) = Node (fmap f l) (f x) (fmap f r)

instance Foldable BST where
    foldMap _ Empty        = mempty
    foldMap f (Node l x r) = (foldMap f l) <> (f x) <> (foldMap f r)

instance Traversable BST where
   traverse _ Empty        = pure Empty
   traverse f (Node l x r) = Node <$> traverse f l <*> f x <*> traverse f r

tree = (Node (Node (Node Empty 2 Empty) 4 (Empty)) 9 (Node Empty 10 Empty))

replace t = mapM (const $ getRandomR (1, 10000)) t

add :: (Ord a) => BST a -> a -> BST a
add Empty        val             = Node Empty val Empty 
add (Node l x r) val | val < x   = Node (add l val) x r
                     | otherwise = Node l           x (add r val)

findRightMost :: (Eq a) => BST a -> BST a
findRightMost Empty        = Empty
findRightMost (Node l x r) | r == Empty = Node Empty x Empty 
                           | otherwise  = findRightMost r

remove :: (Eq a, Ord a) => BST a -> a -> BST a
remove t value = case t of
    Empty        -> Empty
    (Node l x r) -> if (x == value) then 
                        case (findRightMost l) of
                            Empty  -> Empty   
                            Node Empty y Empty -> case (remove l y) of 
                                Empty  -> if (r == Empty) then Node Empty y Empty
                                          else Node Empty y r
                                Node Empty x Empty -> Node (Node Empty x Empty) y r 
                    else if (value < x) then Node (remove l value) x r
                    else Node l x (remove r value)

find :: (Ord a, Show a) => BST a -> a -> IO ()
find Empty    value                  = putStrLn ("value " ++ (show value) ++ " not found")
find (Node l x r) value | value < x  = find l value
                        | value > x  = find r value
                        | otherwise  = putStrLn ("value " ++ (show value) ++ " found")

height :: BST a -> Int
height Empty        = 0
height (Node l x r) = 1 + (max (height l) (height r))

size :: BST a -> Int
size Empty        = 0
size (Node l x r) = 1 + (size l) + (size r)
