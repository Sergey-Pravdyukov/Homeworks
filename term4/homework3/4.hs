import Data.Char

isOpenBracket :: Char -> Bool
isOpenBracket c | c == '[' || c == '(' || c == '{' = True
                | otherwise                        = False

isSameTypeBrackets :: Char -> Char -> Bool
isSameTypeBrackets open close | open == '(' && close == ')' = True
                              | open == '[' && close == ']' = True
                              | open == '{' && close == '}' = True
                              | otherwise                   = False

checkCorrect :: [Char] -> [Char] -> Bool
checkCorrect []     []     = True
checkCorrect []     _      = False
checkCorrect (c:cs) bs | isOpenBracket c       = checkCorrect cs (c:bs)
                       | isAlpha c || c == ' ' = checkCorrect cs bs
checkCorrect (c:cs) [] = False
checkCorrect (c:cs) (b:bs) | isSameTypeBrackets b c = checkCorrect cs bs
                           | otherwise              = False

correctBracketSeq :: [Char] -> Bool
correctBracketSeq list = checkCorrect list []