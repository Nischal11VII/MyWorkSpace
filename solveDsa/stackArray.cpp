#include <iostream>

//#define MAX 100;

void push();
void pop();
void display();
void exit();

int stackArr[100];
int top = -1;
int n;

int main() {
  std::cout << "Enter the total stack element : ";
  std::cin >> n;
 // int top = -1;

 int choice;
 
 do {
    std::cout << "Enter 1 for Push" << std::endl;
    std::cout << "Enter 2 for Pop" << std::endl;
    std::cout << "Enter 3 for display" << std::endl;
    std::cout << "Enter 4 for Exit" << std::endl;
    std::cout << "Choose : ";
    std::cin >> choice;

    switch (choice) {

    case 1: {
      push();
      break;
    }

    case 2: {
      pop();
        break;
    }

    case 3: {
        display();
        break;
    }

    case 4: {
        std::cout << "Exiting" << std::endl;
        break;
    }

    default:{
                std::cout << "Enter a valid choice 1|2|3|4" << std::endl;

            }
    }

  } while (choice != 4);
  return 0;

}

void push() {

  if (top > (n - 1)) {

    std::cout << "Stack is OverFlow" << std::endl;
  }
  else {
    top++;
    std::cout << "Enter the value to be pushed : ";
    std::cin >> stackArr[top];
  }
}

void pop() {
    if(top < 0)
    {
    std::cout << "Stack is underflowed" << std::endl;
    }
    else {
    top--;
    }
}

void display()
    {
    for(int i = top ; i >= 0 ; i--)
    {
    std::cout << stackArr[i] << std::endl;
    }
    }


