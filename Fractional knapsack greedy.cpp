https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/

// Algo
Sort the array based on value/weight ratio , since we have weight is fixed we need to pick up items which maximizes value

ifcurrent weight is < toatl Weight , pick the whole element , and decrement the total weight

otherwise find the fractional weight and m,ultiply by remaining available weight of knap sack

struct Item {
   int value;
   int weight;
};
class Solution {
   public:
      bool static comp(Item a, Item b) {   //comparator
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
   double fractionalKnapsack(int W, Item arr[], int n) {

      sort(arr, arr + n, comp);
      int curWeight = 0;
      double finalvalue = 0.0
        
  for (int i = 0; i < n; i++) {`
    if (curWeight + arr[i].weight <= W) {
      curWeight += arr[i].weight;
      finalvalue += arr[i].value;
    }else {
            double remain = W - curWeight;
            finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;
    }
                               
      return finalvalue;

   }
   }
