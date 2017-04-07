
genRow n 0 rowIndex = []
genRow n ind rowIndex = (max rowIndex (n-ind+1)) : genRow n (ind-1) rowIndex

matrix n = reverse (genRows n n) where
  genRows n 1 = [genRow n n 1]
  genRows n ind = genRow n n ind : genRows n (ind-1)