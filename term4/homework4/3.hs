import Data.Foldable

data Tree a = Leaf a | Node (Tree a) a (Tree a) deriving (Show)

tree = (Node (Node (Leaf 3) 6 (Leaf 2)) 5 (Leaf 7))

instance Foldable Tree where
    foldr f z (Leaf x)     = f x z
    foldr f z (Node l x r) = foldr f (f x (foldr f z r)) l