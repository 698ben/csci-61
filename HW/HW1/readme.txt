use g++ HW1_final.cpp to complie it

input
  infix to prefix
    make sure it is fully parenthised
    can be numbers or letters(uppercase or lowercase)
    +, -, *, / are the only supported operators
    put sapces after the numbers and letters if you  want the out put to be readable
  prefix to infix
    make sure that you substitute the numbers in your input for letters
    again +, -, *, / are the only supported operators
    don't put any spaces or parenthisies

Ex: input and output

  prefix to infix
    input: +--+AB/*CDEFG
    output: ((((A+B)-((C*D)/E))-F)+G)

  infix to prefix
    input: ((((1 +3 )-((12 *F )/2 ))-z )+17 )
    output: +--+1 3 /*12 F 2 z 17
