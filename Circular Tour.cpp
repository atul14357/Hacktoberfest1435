/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

// Here we will use another variable to substitute the extra loop from start till the latest found start point. The variable will store the sum of utilized petrol from 0 till the latest start petrol pump.

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.

    // The function returns starting point if there is a
    // possible solution, otherwise returns -1

    int tour(petrolPump p[],int n)
    {
       //Your code here

      // prev_petrol is used to store the value of the curr_petrol as
      // soon as the value of curr_petrol becomes negative so as
      // not to traverse the array twice in order to get the
      // solution

      int prev_petrol = 0;
      int curr_petrol = 0;
      int start = 0;
      for (int i = 0; i < n;i++)
      {
        curr_petrol += p[i].petrol - p[i].distance;
        if(curr_petrol<0)
        {

          // If this particular step is not done then the
          // between steps would be redundant

          prev_petrol += curr_petrol;
          curr_petrol = 0;
          start = i + 1;
        }
      }
      return (prev_petrol + curr_petrol > 0) ? start : -1;
    }
};
