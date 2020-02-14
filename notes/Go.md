* Every Go program is made up of packages. Programs start running in **package `main`.**

* **package name** is the same as the last element of the import path, the `"math/rand"` package comprises files that begin with the statement `package rand`.

* **import packages**

  * ```go
    import "fmt"
    import "math"
    
    // or recommended ("factored" import statement.)
    import (
    	"fmt"
    	"math"
    )
    ```

* **Exported Names**: a name is exported if it begins with a capital letter

* **Functions**

  * ```go
    func add(x int, y int) int {
    	return x + y
    }
    
    // omit the type from all but the last.
    func add(x, y int) int {
    	return x + y
    }
    
    // A function can return any number of results.
    func swap(x, y string) (string, string) {
    	return y, x
    }
    
    
    ```

  * **Named return values**: A `return` statement without arguments returns the named return values. ("naked" return) ---- should be used only in short functions

    * ```go
      func split(sum int) (x, y int) {
      	x = sum * 4 / 9
      	y = sum - x
      	return
      }
      ```

* **`var` statement**:

  * can be at package or function level

  * with initializers: `var i, j int = 1, 2`, can omit type: `var c, python, java = true, false, "no!"` (**Type Inference**)

  * variable declarations may be "factored" into blocks, as with import statements.

    * ```go
      var (
      	ToBe   bool       = false
      	MaxInt uint64     = 1<<64 - 1
      	z      complex128 = cmplx.Sqrt(-5 + 12i)
      )
      ```

* **short variable declaration**: `:=`, only inside function

* **Basic Types**

  * ```go
    bool
    
    string
    
    int  int8  int16  int32  int64
    uint uint8 uint16 uint32 uint64 uintptr
    
    byte // alias for uint8
    
    rune // alias for int32
         // represents a Unicode code point
    
    float32 float64
    
    // import "math/cmplx"
    complex64 complex128
    ```

* **Zero Values**: Variables declared without an explicit initial value are given their *zero value*.

* **Type Conversions**:

  * The expression `T(v)` converts the value `v` to the type `T`.
  * Unlike in C, in Go assignment between items of different type requires an explicit conversion.

* **Constants**: `const Pi float32 = 3.14`

  * **Numeric constants** are high-precision *values*.

    * ```go
      // not understood yet
      const (
      	// Create a huge number by shifting a 1 bit left 100 places.
      	// In other words, the binary number that is 1 followed by 100 zeroes.
      	Big = 1 << 100
      	// Shift it right again 99 places, so we end up with 1<<1, or 2.
      	Small = Big >> 99
      )
      ```

  * An untyped constant takes the type needed by its context.

* **For**

  *  no parentheses surrounding the three components of the `for` statement and the braces `{ }` are always required.

  * ```go
    for i := 0; i < 10; i++ {
        sum += i
    }
    
    // for is Go's while
    for sum < 1000 {
        sum += sum
    }
    
    for {
        // forever
    }
    ```

* **If**

  * Go's `if` statements are like its `for` loops; the expression need not be surrounded by parentheses `( )` but the braces `{ }` are required.

  * ```go
    // basic
    if x < 0 {
        
    }
    
    // if with a short statement
    if x := a+b; x != 0 {
        return x
    }
    
    // if - else
    if a == 0 {
        
    } else {
        
    }
    ```

* **Switch**

  * no `break`，have `fallthrough`

  * cases need not be constants

  * values involved need not be integers.

  * ```go
    switch os := runtime.GOOS; os {
    case "darwin":
        fmt.Println("OS X.")
    case "linux":
        fmt.Println("Linux.")
    default:
        // freebsd, openbsd,
        // plan9, windows...
        fmt.Printf("%s.\n", os)
    }
    
    // switch with no condition
    // a clean way to write long if-then-else chains
    // same as switch true.
    switch {
    case t.Hour() < 12:
        fmt.Println("Good morning!")
    case t.Hour() < 17:
        fmt.Println("Good afternoon.")
    default:
        fmt.Println("Good evening.")
    }
    ```

* **Defer**

  * A defer statement defers the execution of a function until the surrounding function returns

  * ```go
    func main() {
        // arguments are evaluated immediately, but the function call is not executed until the surrounding function returns
    	defer fmt.Println("world")
    
    	fmt.Println("hello")
    }
    
    // last-in-first-out order
    for i := 0; i < 10; i++ {
        defer fmt.Println(i)
    }
    ```

* 