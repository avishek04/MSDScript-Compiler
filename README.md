## MSDScript Interpreter

This is a C++ based scripting language interpreter which has it's own syntax that performs various complex operations and calculations.  
  
Project Owner: Avishek Choudhury

## Video Walkthrough

## Tech Stack
* C++
* QT
  
## Key Features

### Grammar Parsing Rule
MSDScript parses input based on specified grammar rules, such as:

  ```c++
  <expr> = <number>
         | <expr> + <expr>
         | <expr> * <expr>
         | <variable>
  ```
### Mathematical Expression Support
Supports mathematical expressions following BODMAS rules, including Brackets, Multiplication, Addition, and Subtraction. It adheres to the precedence rules:

  - Example: `1 + 4 interps 5`
  - Example: `(2 * 20) + 1 interps to 41 `

### Let Binding and Functions 
MSDScript allows for let binding and defining functions. For example:

  ```c++
  5 * (_let x = 5
       _in  x) + 1
  ```

  ```c++
  _let factrl = _fun (factrl)
                  _fun (x)
                    _if x == 1
                    _then 1
                    _else x * factrl(factrl)(x + -1)
  _in  factrl(factrl)(10)
  ```

### Booleans and Conditions  
MSDScript supports booleans and conditional statements. For example:

  ```
  _let same = 1 == 2
  _in  _if 1 == 2
       _then _false + 5
       _else 88
  ```

### MSDscript handles exceptions  
Interpreting the following expression should raise an exception because 5 is not a boolean:

  ```c++
  _if 4 + 1
  _then 2
  _else 3
  ```

### Additional Examples 
  - `1==2+3` interprets as `_false`
  - `(1==2)+3` interprets with an error message: "Adding non-numbers"
  - `1+1 == 2+0` evaluates to `_true`

### MSDScript UI    
The MSDScript interpreter includes a user-friendly graphical user interface (UI) developed with Qt, enhancing the overall user experience.
The UI offers the following key features:  

* Expression: Provides a text view where users can easily write and input expressions.
* Interp Button: Includes "Interpret" button for executing the entered expression.
* Pretty Print Button: Offers a "Print" button feature for displaying the interpreted result.
* Resut: Provide a text view where user can see their interpretation and prints.
* Reset: Includes a "Reset" feature that allows users to clear both the entered expression and any selected radio buttons.  
  
Thank you for visiting! 
  
Feel free to connect with me on [LinkedIn](https://www.linkedin.com/in/avishekchoudhury/).
