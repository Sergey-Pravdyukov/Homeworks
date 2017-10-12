import Control.Monad

maxAmongNeigbors :: [Int] -> Maybe Int
maxAmongNeigbors list = foldl mplus Nothing (getMax list)

getMax :: [Int] -> [Maybe Int]
getMax _                                                                       = []
getMax (previous:current:next:elements) | previous < current && current > next = Just current : getMax (current:next:elements)
                                        | otherwise                            = Nothing : getMax (current:next:elements)