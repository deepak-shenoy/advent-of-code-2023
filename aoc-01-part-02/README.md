# Day 1
## Part Two
### Overview
This was an opportunity to look at ways to use various data structures to facilitate solving the problem.  I did think about hashing the constant tokens (e.g. words representing the numbers in the input file"one", "two", "three"...) but the hashing of all the various different combination of words take up too much time computing hashes and comparing them against a dictionary.

### Balanced Binary Search Tree
The data was searched manually due to the small size.  That is an exercise to come back and improve or incorporate into another problem.

#### Pseudocode

```c++
function CreateBalancedTree(OrderedListArray , StartPositionInList, EndPositionInList) {
    
    if StartPositionInList > EndPositionInList return NULL
    
    MiddleIndex = (StartPositionInList + EndPositionInList) / 2
            
    Create a root that has an attribute for the value and two child nodes 'left' and 'right'
    
    Attach the search value to the Root
    
    From the StartPositionInList to the MiddleIndex of the OrderedList recursively:
        Left node of the Root = CreateBalancedTree(OrderedListArray, StartPositionInList, MiddleIndex - 1)
        Right node of the Root = CreateBalancedTree(OrderedListArray, MiddleIndex + 1, EndPositionInList)
                
    Return Root
}
```
