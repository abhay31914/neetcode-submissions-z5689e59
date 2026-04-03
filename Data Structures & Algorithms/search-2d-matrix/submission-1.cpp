class Solution {
public:
    bool binary_search(vector<int>& arr, int target){
    int l = 0;
    int r = arr.size()-1;

    while(l <= r){
        int mid = l + (r-l)/2;

        if(arr[mid] == target) return true;

        if(arr[mid] < target){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target){

    int l = 0;
    int r = matrix.size()-1;
    int n = matrix[0].size()-1;
    int prev = -1;

    while(l < r){

        int mid = l + (r-l)/2;

        if(target <= matrix[mid][n]){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    return binary_search(matrix[l], target);

}

};
