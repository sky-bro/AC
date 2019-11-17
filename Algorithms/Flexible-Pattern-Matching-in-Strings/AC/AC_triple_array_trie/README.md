## Compile 编译

```shell
g++ main.cpp -o main
```

## Run 运行

```shell
# ./input.txt contains strings to be matched
# ./patterns.txt contains patterns to be matched against.
# In the main() func, I use patterns_in.getline(buf, 256) to get patterns, so in the patterns.txt file, each line coressponds to a pattern
$ ./main > out.txt
```

## Example 示例

1. simple start:

   ```shell
   $ cat patterns.txt
   he
   she
   hers
   his
   
   $ cat input.txt
   ushers how is she?
   dont touch her!
   
   $ ./main          
   *base
   -103    -99     -101    -110    -110    -94     -107    0       0       0
   
   *next
   0       1       3       5       6       7       4       8       9       0       0       0       2
   next表占用: 9/13 0.769231
   
   *check
   0       0       0       1       1       2       3       4       5       6
   
   *failures
   0       0       0       0       0       1       0       2       3       2
   
   *outputs
   index 0: 
   index 1: 
   index 2: 
   index 3: he
   index 4: 
   index 5: 
   index 6: 
   index 7: his
   index 8: she    he
   index 9: hers
   
   At index: 4:
           she he 
   At index: 6:
           hers 
   At index: 17:
           she he 
   At index: 32:
           he
   ```

   ![simple start](simple_start.gif)

2. then I used vimtutor text
   * matched against these patterns:

    ```
    this
    who
    that
    the
    next
    Vim
    time
    commands
    ```

   * turn out to be alright:

   ![test with vimtutor text](test_with_vimtutor_text.gif)