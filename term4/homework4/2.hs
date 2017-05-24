import Control.Monad
import System.IO

printCommands :: IO ()
printCommands = do
    putStrLn "0 - exit "
    putStrLn "1 - add value to sorted list " 
    putStrLn "2 - remove value from list " 
    putStrLn "3 - print list"

readComand :: IO (Int)
readComand = do
    printCommands
    putStr "Input command: "
    command <- getLine
    if (((read command) < 0) || (3 < (read command))) then readComand
    else return (read command)

readValue :: IO (Int)
readValue = putStr "Input value: " >> (getLine >>= (\value -> return (read value)))

handler :: [Int] -> IO ()
handler list = do
    command <- readComand 
    if (command == 1) then do
        value <- readValue
        putStrLn ((show value) ++ " added")
        handler (add value [] list)
    else if (command == 2) then do
        value <- readValue
        putStrLn ((show value) ++ " removed")
        handler (remove value [] list)
    else if (command == 3) then do
        putStrLn (show list)
        handler list
    else do
        putStrLn "Good bye!" 

maximum' :: [Int] -> Int
maximum' []     = (minBound::Int)
maximum' (e:es) = max e (maximum' es)

add :: Int -> [Int] -> [Int] -> [Int]
add value prev []                                                     = prev ++ [value]
add value []   next | value <= head next                              = value : next
add value prev next | maximum' prev < value && value <= head next = prev ++ (value : next) 
                    | otherwise                                       = add value (prev ++ [head next]) (tail next)

remove :: (Eq a) => a -> [a] -> [a] -> [a]
remove value prev next | next  == []        = prev
                       | value == head next = prev ++ (tail next)
                       | otherwise          = remove value (prev ++ [head next]) (tail next)

main = do
    handler []