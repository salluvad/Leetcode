int findPlatform(int arr[], int dep[], int n)
{
sort(arr, arr+n);
sort(dep , dep+n);

int platforms = 1;
int result = 1;
int i = 1 ;
int j = 0;

while(i<n && j <n) {
if(arr[i] < dep[j]) {
   platforms++;
   i++;

} else if (arr[i] > dep[j]) {
     platforms--;
     j++;
   }
if(platforms > result){
   result = platforms;
}

}
 return result;
}
