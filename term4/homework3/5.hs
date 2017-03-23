fibonacci :: Integer -> Integer
fibonacci n | n == 0 = 0
            | n == 1 = 1
            | n == -1 = 1
            | n > 1 = positiveHelper 0 1 n
            | n < -1 = negativeHelper 0 1 n

positiveHelper acc b n | n == 0 = acc
                       | n > 0  = positiveHelper b (acc + b) (n - 1)


negativeHelper acc b n | n == 0 = acc
                       | n < 0  = negativeHelper b (acc - b) (n + 1)

