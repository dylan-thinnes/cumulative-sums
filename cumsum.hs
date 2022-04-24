main :: IO ()
main = interact $ unlines . map show . scanl (+) 0 . map read . lines
