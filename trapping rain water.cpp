int findWater(int arr[], int n) {

int water_level ;
int total_water = 0 ;
int left[n];
int right[n] ;

//fill the left max array , max value to te left for all indices

left[0] = arr[0];
for(int i = 1 ; i<n ; i++ )
    left[i] = max(left[i-1],arr[i]);

//max to right

right[n-1] = arr[n-1];
for(int i = n-2 ; i>=0 ; i-- )
    right[i] = max(right[i+1], arr[i]);


//find total trapped water
for(int i = 1 ; i<n-1 ; i++) {

        water_level = min(left[i-1],right[i+1]);

        if(water_level > arr[i]) {
         total_water+= water_level-arr[i];

        }


}

return total_water ;
}
