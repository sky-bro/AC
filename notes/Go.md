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

* **Exported Names**: a name is exported if it begins with a **capital** letter

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
    
  * **Function values**

    * ```go
      func compute(fn func(float64, float64) float64) float64 {
      	return fn(3, 4)
      }
      
      func main() {
      	hypot := func(x, y float64) float64 {
      		return math.Sqrt(x*x + y*y)
      	}
      	fmt.Println(hypot(5, 12))
      
      	fmt.Println(compute(hypot))
      	fmt.Println(compute(math.Pow))
      }
      ```

  * **Function closures**

    * ```go
      func adder() func(int) int {
      	sum := 0
      	return func(x int) int {
      		sum += x
      		return sum
      	}
      }
      ```

    * ```go
      func fibonacci() func() int {
      	a, b := 1, 0
      	return func() int {
      		a, b = b, a+b
      		return a
      	}
      }
      
      func main() {
      	f := fibonacci()
      	for i := 0; i < 10; i++ {
      		fmt.Println(f())
      	}
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

* **Types**

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
      
  * `type` keyword: `type myint int`

  * **Structs**

      * ```go
          type Vertex struct {
          	X int
          	Y int
          }
          
          // struct literals
          var (
          	v1 = Vertex{1, 2}  // has type Vertex
              v2 = Vertex{X: 1}  // Y:0 is implicit (subset of fields, order not relavant)
          	v3 = Vertex{}      // X:0 and Y:0
          	p  = &Vertex{1, 2} // has type *Vertex
  )
          
          func main() {
              v := Vertex{1, 2}
              v.X = 4
          	fmt.Println(v.X, v.Y)
          }
          ```
          
      
  * **Arrays** and **Slices**

      * **zero value of  a slice** is `nil`, `nil` slice has `0 len` and `0 cap`, but doesn't mean a `0 len` and `0 cap` slice is `nil`

          * ```go
          var a []int
              a == nil // true
          
              []int{} == nil // false
          
              // both have 0 len and 0 cap
              ```
      
      * An array has a **fixed size**. A slice, on the other hand, is a **dynamically-sized**

      * An array's **length** is part of its type: `var a [10]int`
      
      * The type `[]T` is a **slice** with elements of type `T`.
      
      * **Slices are like references to arrays**: A slice does not store any data, it just describes a section of an underlying array.
      
      * ```go
          primes := [6]int{2, 3, 5, 7, 11, 13} // array literal
          []int{1, 2, 3} // slice literal (without length)
          []bool{true, true, false} // slice literal
      var s []int = primes[1:4] // slice an array {3, 5, 7}
          primes[0:]
          primes[:3]
          primes[0:6]
          primes[:]
          ```
          
      * slice **length** and **capacity**: `len(s), cap(s)`, can **extend a slice's length** by re-slicing it, provided it has sufficient capacity
      
      * create slice with **make**
      
          * ```go
              a := make([]int, 5) // 5 len, 5 cap, [0, 0, 0, 0, 0]
              b := make([]int, 0, 5) // 0 len, 5 cap, []
              ```
      
      * **slices of slices/arrays**
      
      * **appending to a slice**
      
          * ```go
              // func append(s []T, vs ...T) []T, return a new slice, original slice not touched
              // this may change the underlying array
              	//if cap is big enough to hold new elements)
              // if not, original array not touched, move elements to a new array (extend the cap)
              
              var s []int
              
              // append works on nil slices.
              s = append(s, 0)
              
              // The slice grows as needed.
              s = append(s, 1)
              
              // We can add more than one element at a time.
              s = append(s, 2, 3, 4)
              ```
      
  * **Maps**

      * **zero value** of map is `nil`, has no keys, nor can keys be added

      * **map literals** are like struct literals, but **keys are required**

      * **delete element**: `delete(m, key)`

      * ```go
          // make
          var m map[string]Vertex // a map from string to Vertex, nil
          m = make(map[string]Vertex) // initialized and ready for use
          // m := make(map[string]Vertex)
          m["Bell Labs"] = Vertex{ // insert or update
              40.68433, -74.39967,
          }
          fmt.Println(m["Bell Labs"])
          
          // map literals
          var m = map[string]Vertex{
          	"Bell Labs": Vertex{
          		40.68433, -74.39967,
          	},
          	"Google": Vertex{
          		37.42202, -122.08408,
          	},
          }
          
          // literals continued: omit type name
          var m = map[string]struct {
          	x int
          	y int
          }{
          	"Bell Labs": {1, 2},
          	"Google":    {3, 4},
          }
          
          // two value assignment
          elem, ok := m[key] // if key is in m, ok = true, if not, ok = false
          ```

      * 

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
    
  * The **range** form of the `for` loop iterates over a slice or map.

    * ```go
      var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}
      
      func main() {
          for i, v := range pow { // returns index, value (copy)
      		fmt.Printf("2**%d = %d\n", i, v)
      	}
      }
      
      // skip index or value
      for i, _ := range pow
      for i := range pow // only index, omit second variable
      for _, value := range pow
      ```

    * 

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

  * no `break`，has `fallthrough`

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
    
  * stacking defers: **LIFO** manner

* **Pointers**

  * `var p *int` has **zero** value `nil`

  * ```go
    i := 42
    j := &i // j is of type *int
    ```

  * go has no pointer arithmetic

  * pointer to structs

    * ```go
      v := Vertex{1, 2}
      p := &v
      p.X = 1e9 // no need to use (*p).X
      ```

* **Methods**

  * Go does not have classes. However, you can define methods on types.

  * a method is a function, with a special **receiver argument** (between `func` keyword and method name)

  * ```go
    type Vertex struct {
    	X, Y float64
    }
    
    func (v Vertex) Abs() float64 {
    	return math.Sqrt(v.X*v.X + v.Y*v.Y)
    }
    ```

  * You can only declare a method with a receiver whose type is defined in the same package as the method.

    * ```go
      type MyFloat float64
      // func (f float64) Abs() float64 {}, wrong!
      func (f MyFloat) Abs() float64 {
      	// ...
      }
      ```

  * **Pointer receivers** and **Value receivers**

    * Methods with pointer receivers can modify the value to which the receiver points 
    * often need to modify their receiver, pointer receivers are more common
    * with value receiver, operates on a copy of the original
    * two reasons to **use a pointer receiver**
      * the first is so that the method can **modify the value** that its receiver points to
      * **avoid copying** the value on each method call
      * In general, all methods on a given type should have either value or pointer receivers, but not a mixture of both

  * Methods and pointer **indirection**

    * functions with a **pointer/value argument** must take a **pointer/value**

    * methods with **pointer/value receivers** take either a **value** or a **pointer** as the receiver when they are called

    * ```go
      var v Vertex
      
      // pointer argument/receiver
      ScaleFunc(v, 5)  // Compile error!
      ScaleFunc(&v, 5) // OK
      
      v.Scale(5)  // OK
      p := &v
      p.Scale(10) // OK
      
      // value argument/receiver
      fmt.Println(AbsFunc(v))  // OK
      fmt.Println(AbsFunc(&v)) // Compile error!
      
      fmt.Println(v.Abs()) // OK
      p := &v
      fmt.Println(p.Abs()) // OK
      ```

* **Interfaces**

  * http://127.0.0.1:3999/methods/9
