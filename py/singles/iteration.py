# init y and z to zero
y = 0
z = 0
# 10 times
for i in range(10): 
    y = y + 1 # increment y by one
# here is y = 10 

# and bring y to zero again
# y is 10, so this runs 10 times
while y > 0:
    y = y - 1   # decrement y by one
    z = z + 2   # increment z by two

# thus, z is 20
print(z)
