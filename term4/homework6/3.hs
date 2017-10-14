import Prelude  hiding (id)
import Data.List
import Control.Monad.State

data Edge = Edge { weight :: Int, from :: Int, to :: Int }

instance Show Edge where
    show (Edge _ from to) = show from ++ "->" ++ show to

data Vertex = Vertex { id :: Int, label :: Maybe (State [Edge] Int) }

instance Eq Vertex where
    (==) a b = id a == id b

instance Show Vertex where
    show (Vertex id Nothing)   = "(" ++ show id ++ " - no path)"
    show (Vertex id (Just m)) = "(" ++ show id ++ " " ++ show (evalState m []) ++ ": " ++ show (execState m []) ++ ")"

instance Ord Vertex where
    compare (Vertex _ Nothing)    (Vertex _ Nothing)    = EQ
    compare (Vertex _ (Just wr))  (Vertex _ Nothing)    = LT
    compare (Vertex _ Nothing)    (Vertex _ (Just wr))  = GT
    compare (Vertex _ (Just m1)) (Vertex _ (Just m2))   = compare (evalState m1 []) (evalState m2 []) 

data Graph = Graph [Vertex] [Edge]

findEdge :: Int -> Int -> [Edge] -> Maybe Edge
findEdge _   _   []                                           = Nothing
findEdge id1 id2 (e : ess) | id1 == (from e) && id2 == (to e) = Just e
                           | otherwise                        = findEdge id1 id2 ess

dijkstra :: Graph -> [Vertex]
dijkstra (Graph vs es) = dijkstra' [] vs
    where dijkstra' used []     = used
          dijkstra' used unused =
              let closest = minimum unused
                  newUsed = closest : used
                  newUnused = delete closest (map (updVertex closest) unused)
                  updVertex v1 v2 = min (Vertex (id v2) (addEdge (label v1) (findEdge (id v1) (id v2) es))) v2
                  addEdge :: Maybe (State [Edge] Int) -> Maybe Edge -> Maybe (State [Edge] Int)
                  addEdge Nothing   Nothing   = Nothing
                  addEdge Nothing   (Just wr) = Nothing
                  addEdge (Just wr) Nothing   = Nothing
                  addEdge (Just wr) (Just e)  = Just (addEdge' wr e)
                  addEdge' :: State [Edge] Int -> Edge -> State [Edge] Int
                  addEdge' wr e = do
                    dist <- wr
                    put (execState wr [] ++ [e])
                    return (dist + (weight e))
              in dijkstra' newUsed newUnused

g2 = Graph [(Vertex 1 Nothing), (Vertex 2 Nothing), (Vertex 3 Nothing), (Vertex 4 Nothing), (Vertex 5 (Just (state (\st -> (0, st)))))] [(Edge 1 1 3), (Edge 1 1 4), (Edge 4 3 2), (Edge 1 3 4), (Edge 6 4 2), (Edge 1 4 3), (Edge 3 5 3), (Edge 1 5 4)]
g3 = Graph [(Vertex 1 (Just (state (\st -> (0, st))))), (Vertex 2 Nothing), (Vertex 3 Nothing), (Vertex 4 Nothing), (Vertex 5 Nothing), (Vertex 6 Nothing)] [(Edge 14 1 6), (Edge 14 6 1), (Edge 9 1 3), (Edge 9 3 1), (Edge 7 1 2), (Edge 7 2 1), (Edge 10 2 3), (Edge 10 3 2), (Edge 15 2 4), (Edge 15 4 2), (Edge 11 3 4), (Edge 11 4 3), (Edge 2 3 6), (Edge 2 6 3), (Edge 6 4 5), (Edge 6 5 4), (Edge 9 5 6), (Edge 9 6 5)]