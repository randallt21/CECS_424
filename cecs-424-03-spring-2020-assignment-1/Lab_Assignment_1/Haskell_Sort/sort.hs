
-- CECS 424 Spring 2020 Project 1
-- Name: Randall Thornton
-- I.D. #016032222
-- Start Date: 1-21-2020
-- End Date: 2-11-2020
-- Description: This is a merge sort
-- and quick sort algorithm that sorts
-- an unsorted array of any given length

-- Declaration of module Sort
module Sort where

merge :: Ord a => [a] -> [a] -> [a] -- merge two sorted lists to a sorted list
merge [] ys = ys                    -- if one
merge xs [] = xs                    --   or the other list is empty merging is trivial
merge (x:xs) (y:ys)                 -- merge two non-empty lists
  | x <= y    = x : merge xs (y:ys)     -- if the left element is smaller then output it first
  | otherwise = y : merge (x:xs) ys     --   otherwise output the right element first

msort :: Ord a => [a] -> [a]    -- Divides halves an unsorted list
msort [] = []                   -- If list is empty return empty
msort [x] = [x]                 -- Return single value since it is a sorted array
msort xs = merge (msort left) (msort right) -- Calls merge of split halves after each half is split again
    where
        left = take (length xs `div` 2) xs  -- Takes first half of the list
        right = drop (length xs `div` 2) xs -- Takes second half of the list

qsort :: Ord a => [a] -> [a]    -- quickly sort an unsorted list given a pivot
qsort [] = []                   -- If array is empty, return empty
qsort [x] = [x]                 -- if array is one value, return it
qsort (pivot : xs) = left ++ [pivot] ++ right   -- Select head as pivot, append left and right with pivot in middle
    where
        left = qsort [y | y <- xs, y <= pivot]  -- sort values of numbers less than pivot
        right = qsort [z | z <- xs, z > pivot]  -- sort values of numbers greater than pivot

main = do 
  let ms = [4,65,2,-31,0,99,2,83,782,1] -- Instantiate arrays
  let qs = [4,65,2,-31,0,99,2,83,782,1]
  print(ms)   -- Print original array
  print(msort ms) -- Print merge sorted array
  print(qs)   -- Original array
  print(qsort qs) -- Quuick sort array