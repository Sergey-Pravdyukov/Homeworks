import Prelude  hiding (id)
import Data.List
import Control.Monad.Writer.Lazy

data Edge = Edge { weight :: Int, from :: Int, to :: Int }

instance Show Edge where
    show (Edge _ from to) = show from ++ "->" ++ show to

data Vertex = Vertex { id :: Int, label :: Maybe (Writer [Edge] Int) }

instance Eq Vertex where
    (==) a b = id a == id b

instance Show Vertex where
    show (Vertex id Nothing)   = "(" ++ show id ++ " - no path)"
    show (Vertex id (Just wr)) = "(" ++ show id ++ " " ++ show (fst (runWriter wr))++ ": " ++ show (snd (runWriter wr)) ++ ")"

instance Ord Vertex where
    compare (Vertex _ Nothing)    (Vertex _ Nothing)    = EQ
    compare (Vertex _ (Just wr))  (Vertex _ Nothing)    = LT
    compare (Vertex _ Nothing)    (Vertex _ (Just wr))  = GT
    compare (Vertex _ (Just wr1)) (Vertex _ (Just wr2)) = compare (fst (runWriter wr1)) (fst (runWriter wr2))

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
                  addEdge :: Maybe (Writer [Edge] Int) -> Maybe Edge -> Maybe (Writer [Edge] Int)
                  addEdge Nothing   Nothing   = Nothing
                  addEdge Nothing   (Just wr) = Nothing
                  addEdge (Just wr) Nothing   = Nothing
                  addEdge (Just wr) (Just e)  = Just (addEdge' wr e)
                  addEdge' :: Writer [Edge] Int -> Edge -> Writer [Edge] Int
                  addEdge' wr e = do
                    dist <- wr
                    tell (e : [])
                    return (dist + (weight e))
              in dijkstra' newUsed newUnused

g2 = Graph [(Vertex 1 Nothing), (Vertex 2 Nothing), (Vertex 3 Nothing), (Vertex 4 Nothing), (Vertex 5 (Just (writer (0, []))))] [(Edge 1 1 3), (Edge 1 1 4), (Edge 4 3 2), (Edge 1 3 4), (Edge 6 4 2), (Edge 1 4 3), (Edge 3 5 3), (Edge 1 5 4)]