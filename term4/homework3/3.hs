maxNeighbors :: (Num a, Ord a) => [a] -> a
maxNeighbors list = findIndex list 2 (-1) undefined where
  findIndex (_:_:[])   _ _      maxId                   = maxId
  findIndex (l:m:r:es) i maxSum maxId | l + r <= maxSum = findIndex (m:r:es) (i+1) maxSum maxId
                                      | otherwise       = findIndex (m:r:es) (i+1) (l+r)  i