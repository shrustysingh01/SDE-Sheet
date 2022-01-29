/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W 
to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 
*/

/*
Time: O(n * lg n)
Space: O(1)
Greedy.
Sort the items on their value per unit weight in descending order
Now iterate over all items and get the maximum weight you can choose for current item and 
    multiply it by its unit value and add it to the result
Decrement the total weight by the weight used above
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    // bool compare(Item a , Item b){
    //     double r1 = (double)a.value/(double)a.weight;
    //     double r2 = (double)b.value/(double)b.weight;
    //     return r1 > r2;
    // }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        //sort(arr,arr+n,compare);
        sort(arr,arr+n,[&](Item &a,Item &b){
            double r1 = (double)a.value/(double)a.weight;
            double r2 = (double)b.value/(double)b.weight;
            return r1 > r2;
        });
        
        // for(int i = 0 ; i < n ; i++){
        //     cout<<arr[i].weight<<" "<<arr[i].value<<"\n";
        // }
        
        int currentweight = 0;
        double finalValue = 0.0;
        for(int i = 0 ; i < n ; i++){
            if(currentweight + arr[i].weight <= W){
              currentweight = currentweight + arr[i].weight;
              finalValue = finalValue + arr[i].value;
            }
            else{
                double remain = W-currentweight;
                finalValue += ((double)arr[i].value/arr[i].weight)*(double)remain;
                break;
            }
            // finalValue += (double)min(arr[i].weight, W) * ((double)arr[i].value / arr[i].weight);
        
            // W -= min(arr[i].weight, W);
        }
        
        return finalValue;
    }
        
};
