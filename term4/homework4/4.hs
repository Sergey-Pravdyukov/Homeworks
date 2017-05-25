import Control.Monad
import System.IO
import Data.List hiding (find)
import System.Directory

data Subscriber = Subscriber { name :: String, phoneNumber :: String}
data Phonebook  = Phonebook  [Subscriber]    deriving (Show)

instance Show Subscriber where
    show s = (name s) ++ " " ++ (phoneNumber s)

printCommands :: IO ()
printCommands = do
    putStrLn "0 - exit"
    putStrLn "1 - add an entry (name and phone number)"
    putStrLn "2 - find phone number by name"
    putStrLn "3 - find name by phone number"
    putStrLn "4 - save the current data to a file"
    putStrLn "5 - read data from file"

readName :: IO (String)
readName = putStr "Input name: " >> (getLine >>= \name -> return (name))

readPhoneNumber :: IO (String)
readPhoneNumber = putStr "Input phone number: " >> (getLine >>= \phoneNumber -> return (phoneNumber))

readNewSubscriber :: IO (Subscriber)
readNewSubscriber = readName >>= (\name -> readPhoneNumber >>= (\number -> return (Subscriber name number)))

readComand :: IO (Int)
readComand = do
    printCommands
    putStr "Input command: "
    command <- getLine
    if (((read command) < 0) || (5 < (read command))) then readComand
    else return (read command)

handler :: Phonebook -> IO()
handler phonebook = do
    command <- readComand
    if (command == 1) then readNewSubscriber >>= (\sub -> (handler (Phonebook (add sub phonebook))))
    else if (command == 2) then find readName        findByName   phonebook
    else if (command == 3) then find readPhoneNumber findByNumber phonebook
    else if (command == 4) then writeFile "io.txt" (toUnparsedString phonebook) >> handler (Phonebook [])
    else if (command == 5) then do
        isExist <- doesFileExist "io.txt"
        if (isExist == True) then readFile "io.txt" >>= (\readingString -> (removeFile "io.txt" >> handler (Phonebook (fromUnparsedStrings (map (words) (lines readingString))))))
        else putStrLn "io.txt does not exist" >> handler phonebook
    else putStrLn "Good bye!"

add :: Subscriber -> Phonebook -> [Subscriber]
add s (Phonebook subs) = (s : subs)

find :: IO (String) -> (Phonebook -> String -> Subscriber) -> Phonebook -> IO()
find reader finder phonebook = reader >>= (\param -> putStrLn (show (finder phonebook param)) >> handler phonebook)

findByName :: Phonebook -> String -> Subscriber
findByName (Phonebook [])         wantedName                            = Subscriber "not" "found"
findByName (Phonebook (sub:subs)) wantedName | (name sub) == wantedName = sub
                                             | otherwise                = findByName (Phonebook subs) wantedName

findByNumber :: Phonebook -> String -> Subscriber
findByNumber (Phonebook [])         wantedNumber                                     = Subscriber "not" "found"
findByNumber (Phonebook (sub:subs)) wantedNumber | (phoneNumber sub) == wantedNumber = sub
                                                 | otherwise                         = findByNumber (Phonebook subs) wantedNumber 

toUnparsedString :: Phonebook -> String
toUnparsedString (Phonebook [])         = ""
toUnparsedString (Phonebook (sub:subs)) = (show sub) ++ "\n" ++ (toUnparsedString (Phonebook subs)) 

fromUnparsedStrings :: [[String]] -> [Subscriber]
fromUnparsedStrings []                        = []
fromUnparsedStrings ((name:[phoneNumber]):ps) = (Subscriber name phoneNumber) : (fromUnparsedStrings ps)

main = do
    handler (Phonebook [])