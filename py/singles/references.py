array_1 = [1, 2, 3]         # init the array_1 
array_2 = array_1           # array_2 is a reference, not a copy
array_3 = array_1.copy()    # this creates a copy
array_2.append(4)           # there is only one array
array_1.append(5)           # both references this one
array_1.pop(0)
print(array_1)              # output: [1, 2, 3, 4, 5]
print(array_2)              # output: [1, 2, 3, 4, 5]
print(array_3)              # output: [1, 2, 3]
