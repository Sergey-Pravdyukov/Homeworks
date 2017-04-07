predicate :: (t -> Bool) -> [t] -> Bool
predicate pr list = f pr list 0 where
  f pr [] ind | ind == 0  = error "list is empty"
              | otherwise = True
  f pr (x : xs) ind = (pr x) && f pr xs (ind+1)