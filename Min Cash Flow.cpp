////
https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
////

#include<iostream>
using namespace std;

// Number of persons (or vertices in the graph)
#define N 3

// A utility function that returns index of minimum value in arr[]
int getMin(int arr[])
{
    int minInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}

// A utility function that returns index of maximum value in arr[]
int getMax(int arr[])
{
    int maxInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}
void minCashFlowRec(int amount[])
{
  // Find the indexes of minimum and maximum values in amount[]
    // amount[mxCredit] indicates the maximum amount to be given
    //                  (or credited) to any person .
    // And amount[mxDebit] indicates the maximum amount to be taken
    //                  (or debited) from any person.
    // So if there is a positive value in amount[], then there must
    // be a negative value

    int maxCredit = getMax(amount);
    int maxDebit = getMin(amount);

    // base case
   if (amount[maxCredit] == 0 && amount[maxDebit] == 0)
        return;

    // find the min of two amounts
   int min = std::min(-amount[maxDebit],amount[maxCredit]);

   // reduce the amounts from the amount array , money owned is reduced and also money to get also reduced
   amount[maxDebit]+=min;
   amount[maxCredit]-=min;

     // If minimum is the maximum amount to be
    cout << "Person " << maxDebit << " pays " << min
         << " to " << "Person " << maxCredit << endl;

    // Recur for the amount array.  Note that it is guaranteed that
    // the recursion would terminate as either amount[mxCredit]
    // or  amount[mxDebit] becomes 0
    minCashFlowRec(amount);

}

void minCashFlow(int graph[][N]){
 int amount[N] = {0};
// create an amount array which keeps Net amount for a person
// which is maximum Credit - maximum Debit

for(int p = 0 ; p<N;p++){
  for(int i = 0 ; i<N;i++){
  amount[p]+=(graph[i][p] - graph[p][i]);
  }
}
 minCashFlowRec(amount);
}




int main()
{
    // graph[i][j] indicates the amount that person i needs to
    // pay person j
    int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0},};

    // Print the solution
    minCashFlow(graph);
    return 0;
}
