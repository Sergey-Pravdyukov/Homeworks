powerOfTwo :: Integer -> [Integer]
powerOfTwo n = helper n 1 where
  helper 0 acc = []
  helper n acc = (acc) : helper (n - 1) (acc * 2)