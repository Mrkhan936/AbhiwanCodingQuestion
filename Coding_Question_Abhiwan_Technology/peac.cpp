int find_peak_element(vector<int> arr){
    int i = 0;
    int j = arr.size() - 1;
    while (j > i)
    {
        int mid = i + (j - i)/2;

        if (arr[mid] < arr[mid + 1]) {
            i = mid + 1;
        } else{
            j = mid;
        }
    }
    return arr[i];
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {0,1,2,3,4,5,10,11,4,3,2,1,0,-1,-5};
    cout << find_peak_element(nums);
    return 0;
}