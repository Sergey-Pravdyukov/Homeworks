infix 6 :+:
infix 7 :*:
infixr 6 :-:
infixr 7 :/:
data Expr = Const Int | X Int | Expr :+: Expr | Expr :*: Expr | Expr :/: Expr | Expr :-: Expr deriving (Read, Eq)

instance Show Expr where
    show e = showExpr (simplify e) where
        showExpr (Const c) | c >= 0    = show c
                           | otherwise = "(" ++ show c ++ ")"
        showExpr (X deg)               = if (deg == 1) then "x"
                                         else "x^" ++ show deg
        showExpr (eA :+: eB)           = "(" ++ showExpr eA ++ " + " ++ showExpr eB ++ ")"
        showExpr (eA :-: eB)           = "(" ++ showExpr eA ++ " - " ++ showExpr eB ++ ")"
        showExpr (eA :*: eB)           = "(" ++ showExpr eA ++ " * " ++ showExpr eB ++ ")"
        showExpr (eA :/: eB)           = "(" ++ showExpr eA ++ " / " ++ showExpr eB ++ ")"

derivative :: Expr -> Expr
derivative (Const _)            = Const 0
derivative (X deg) | (deg == 1) = Const 1
                   | otherwise  = (Const deg) :*: (X (deg - 1))
derivative (eA :+: eB)          = simplify ((derivative eA) :+: (derivative eB))
derivative (eA :*: eB)          = simplify (((derivative eA) :*: eB) :+: (eA :*: (derivative eB)))
derivative (eA :-: eB)          = derivative (eA :+: (Const (-1)) :*: eB)
derivative (eA :/: eB)          = simplify (((derivative eA) :*: eB :-: eA :*: (derivative eB)) :/: (eB :*: eB))

simplify :: Expr -> Expr
simplify ((Const 0) :+: eB)                     = simplify eB
simplify ((Const 0) :-: eB)                     = (Const (-1)) :*: simplify eB
simplify ((Const 0) :*: eB)                     = Const 0
simplify ((Const 0) :/: eB)                     = Const 0
simplify (eA :+: (Const 0))                     = simplify eA
simplify (eA :-: (Const 0))                     = simplify eA
simplify (eA :*: (Const 0))                     = Const 0
simplify e@(eA :*: eB) | hasDivision e == False = makeExpr (simplify' e)
                       | otherwise              = (simplify eA) :*: (simplify eB)
simplify e@(eA :+: eB) | hasDivision e == False = makeExpr (simplify' e)
                       | otherwise              = (simplify eA) :+: (simplify eB)
simplify e@(eA :-: eB) | hasDivision e == False = makeExpr (simplify' e)
                       | otherwise              = (simplify eA) :-: (simplify eB)
simplify (eA :/: eB)                            = (simplify eA) :/: (simplify eB)
simplify e                                      = makeExpr (simplify' e)

hasDivision :: Expr -> Bool
hasDivision (eA :/: eB) = True
hasDivision (Const _)   = False
hasDivision (X _)       = False
hasDivision (eA :+: eB) = hasDivision eA || hasDivision eB
hasDivision (eA :-: eB) = hasDivision eA || hasDivision eB
hasDivision (eA :*: eB) = hasDivision eA || hasDivision eB

simplify' :: Expr -> [(Int, Int)]
simplify' (Const coeff) = [(0, coeff)]
simplify' (X deg)       = [(deg, 1)]
simplify' (eA :+: eB)   = add (simplify' eA) (simplify' eB)
simplify' (eA :*: eB)   = multiply (simplify' eA) (simplify' eB)
simplify' (eA :-: eB)   = simplify' (eA :+: (Const (-1) :*: eB))

add :: [(Int, Int)] -> [(Int, Int)] -> [(Int, Int)]
add [] e     = e
add e []     = e
add (x:xs) e = (foldl summarize x e) : (add xs (filter (isDifferentDegree (fst x)) e)) where
    summarize :: (Int, Int) -> (Int, Int) -> (Int, Int)
    summarize (d1, f1) (d2, f2) | d1 == d2  = (d1, f1 + f2)
                                | otherwise = (d1, f1)

    isDifferentDegree :: Int -> (Int, Int) -> Bool
    isDifferentDegree d (a, b) = (a /= d)

multiply :: [(Int, Int)] -> [(Int, Int)] -> [(Int, Int)]
multiply [] _     = []
multiply _ []     = []
multiply (x:xs) e = map (func x) e `add` multiply xs e where 
    func :: (Int, Int) -> (Int, Int) -> (Int, Int)
    func (d1, f1) (d2, f2) | f1 == 0 || f2 == 0 = (0, 0)
                           | otherwise          = (d1 + d2, f1 * f2)

makeExpr :: [(Int, Int)] -> Expr
makeExpr [(d, f)] | d == 0 = Const f
                  | f == 1 = X d
                  | otherwise = (Const f) :*: (X d)
makeExpr (x:xs) = makeExpr [x] :+: makeExpr xs 

a = Const 5
b = X 1
c = X 4
d = a :+: b
e = b :*: c