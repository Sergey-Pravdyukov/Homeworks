reversing :: [a] -> [a]
reversing list = rev list [] where
  rev [] reversedList = reversedList
  rev (a:as) reversedList = rev as (a:reversedList)