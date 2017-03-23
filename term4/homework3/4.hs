import Data.Char

isOpenBracket :: Char -> Bool
isOpenBracket c | c == '[' || c == '(' || c == '{' = True
                | otherwise                        = False

isSameTypeBrackets :: Char -> Char -> Bool
isSameTypeBrackets open close | open == '(' && close == ')' = True
                              | open == '[' && close == ']' = True
                              | open == '{' && close == '}' = True
                              | otherwise                   = False

correctBracketSeq :: [Char] -> [Char] -> Bool
correctBracketSeq []     []     = True
correctBracketSeq []     _      = False
correctBracketSeq (c:cs) (b:bs) | isAlpha c || isSeparator c = correctBracketSeq cs (b:bs)
                                | isOpenBracket c            = correctBracketSeq cs (c:b:bs)
                                | isSameTypeBrackets c b     = correctBracketSeq cs bs
                                | otherwise                  = False