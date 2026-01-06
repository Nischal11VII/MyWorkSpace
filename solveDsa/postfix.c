#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 
1. / , *
2. + , -

 */

int opValue(char z)
    {
        if(z == '/' || z == '*')
        {
            return 2;
        }
        else if(z == '+' || z == '-')
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }


// if stack prec is greater or equal to upcoming operator than -pop- the stack operator
bool checkPrec()
    {
if(opValue(stack[top]) >= )


    }

//void makeResult()

void stack(char val)
        {
            

        

        }


int main ()
    {
char eq[] = "a+b*c+d";
char result[] = "";
char stackValue[] = "";
int top = -1;

 
        







    }
