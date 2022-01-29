/*
Dora, the explorer, visits India and decides to try the famous Indian food. 
However, the restaurant accepts only Indian currency i.e. [1, 2, 5, 10, 20, 50, 100, 500, 1000] valued coins.
So, Dora goes to a bank that has an infinite supply of each of the denominations to make a change
for a given ‘Amount’ of money. 
As a cashier at the bank, your task is to provide Dora the minimum number of coins 
that add up to the given ‘Amount’.
*/

/*
Time: O(n || nlogn if array is not sorted)
Space; O(1) depends on sorting algorithm
Greedy.

We will start from the back and will see if the current element is less than equal to the amount.
then we will see till it is less than amount we will keep decreasing it and increasing count.

*/


int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int>money= {1, 2, 5, 10, 20, 50, 100, 500, 1000};
      int n = money.size();
      int c = 0;
      for(int i = n-1 ; i >= 0 ; i--){
          if(amount >= money[i]){
          	while(amount >= money[i]){
              amount = amount - money[i];
                c++;
          	} 
           }
      }
    return c;
}