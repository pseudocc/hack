# HACK

we have a main program that calculate the exponentiation,
whose result is the return value of `int_pow`.
then we find the position of that function, and replace it
with another function `fake` in machine code.

## make and run

1. main program

    ```
    make 
    ./main 9 5
    ```

    and the program tells us that '9 to the 5 is 59049'.

2. inject program and fake machine code

    ```
    make inject
    make fake.raw
    ```

    fake is a very easy implementaion of addition operation.

3. copy main and hack it

    ```
    make hack
    ./hack 9 5
    ```

    and this time, the program tells us that '9 to the 5 is 14',
    which means our hack succeeds.
