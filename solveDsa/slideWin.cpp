#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

class solution 
    {
    public:
        std::vector<int> wSlide(std::vector<int>& nums , int k)
        {
            std::queue<int> q;
         //   std::queue<int> q2;
            std::vector<int> result;
            int largest;
            int tempArr[k];
            int temp;

            for(int x : nums)
            {
            q.push(x);
            }

            
// first initialize the tempArr to store 1st k digits in queue.

            for(int i = 0 ; i < k ; i++)
                {
                    temp = q.front();
                    tempArr[i] = temp;
                    q.pop();
                }
                largest = tempArr[0];
//check largest;
            
            while(true)
                {
                    //this loops find the largest value in k windows
            for(int i = 0 ; i < k ; i++)
            {
                if(tempArr[i] > largest)
                {
                    largest = tempArr[i];
                }
            }
            result.push_back(largest);
            largest = tempArr[0]; 
            for(int i = 0 ; i < (k-1) ; i++)
                    {
                    tempArr[i] = tempArr[i+1];
                    }
            if(q.empty())
            {
                break; 
            }
                 tempArr[k-1] = q.front();
            q.pop();
            
            


                }

            return result;

        }


    };


int main()
    {
        int k;
        std::vector<int> nums;
        std::vector<int> result;
    //    int arr[8] = { 1 ,3,-1,-3,5,3,6,7};
        int arr[2] = {1 , -1};
        for(int i : arr)
            {
            nums.push_back(i);
            }

        std::cout << "Enter the Max : ";
        std::cin >> k;

        solution s1;
        result = s1.wSlide(nums , k);

        for(int i = 0 ; i < result.size() ; i++) 
            {
            
            std::cout << result[i] << std::endl;
            }
        return 0;
    }
