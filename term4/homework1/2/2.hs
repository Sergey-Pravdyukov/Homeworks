fibonacci :: Integer -> Integer
fibonacci n | n == 0 = 0
            | n == 1 = 1
            | n == -1 = 1
            | n > 1 = positiveHelper 0 1 n
            | n < -1 = negativeHelper 0 1 n

positiveHelper a b n | n == 0 = a
                     | n > 0 = positiveHelper b (a + b) (n - 1)

negativeHelper a b n | n == 0 = a
                     | n < 0 = negativeHelper b (a - b) (n + 1)