#include <iostream>
#include <memory>

// most of the time replacement of new keyword is smart pointer

// types of smart pointer
   // -> shared_ptr   : std::shared_ptr<datatype>  || can be shared with other pointer || use_count()...
   // -> unique_ptr   : std::unique_ptr<datatype>  || can only be used by 1 owner
   // -> weak_ptr     :std:weak_ptr

    // b.use_count() -> counts how many pointer is allowed to manage it..
    

// unique ptr
    /*
       auto c = std::move(oldPointer_Name); 
       pass the old pointer to new pointer
    use if statement to check if the pointer is empty with unique ptr

     * */


// shared example
std::shared_ptr<int> smartValue()
    {
//        std::shared_ptr<int> a = std::make_shared<int>(5);
        auto a = std::make_shared<int>(5);
        return a; 
    }


// traditional method is to use new , delete  

/*
    int* getValue()
    {
        int* a = new int(5);
        return a;
     }

*/


int main()
    {
//    int* b = getValue();
      //  std::shared_ptr<int> b = smartValue();
        auto b = smartValue(); // stared ptr
        std::weak_ptr weak = b;

        //trying to access weak pointer - by creaking a new ptr
        auto shared =  weak.lock();


        std::cout << *b << std::endl;
        if(shared) {

        std::cout << *shared << std::endl;
        std::cout << *b+(*shared) << std::endl;
           
        }

        //    delete(b);
    }








