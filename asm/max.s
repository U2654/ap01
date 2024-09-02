.text
    la x1, numbers      #address of bytes array
    li x2, 4            #number of bytes - 1
    lb x3, 0(x1)        #first number 
    addi x1, x1, 1      #to next number
loop:
    lb x4, 0(x1)        #load current byte
    blt x4, x3, next    #less than current max? cont
    mv  x3, x4          #else new max
next:
    addi x1, x1, 1      #next byte

    addi x2, x2, -1
    bgtz x2, loop

    li a0, 10
    ecall  

.data
numbers:
    .byte 5, 4, 5, 15, 10
