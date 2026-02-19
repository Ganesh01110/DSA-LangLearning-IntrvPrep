#include<vector>
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i = 0, j = 0;
    vector<int> ans;
    while(i<n && j<m) {
    
    if(arr1[i]==arr2[j])
    {
    	ans.push_back(arr1[i]);
        i++;
        j++;
    }
    else if (arr1[i] < arr2[j]) {
  		i++;
    }
    else
    {
    	j++;
    }
    
    }
    return ans;
}

// or
// as brute force->compare all element so use if condition to make a break where ever lloop finnds an higher number
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{ 
    vector<int> ans;
    for(int i=0;i<n;i++){
        int element = arr1[i];
        for(int j=0;j<n;j++){

          if(element<arr2[j]){
            break;
          }
          
          if(element==arr2[j]){
            ans.push_back(element);
            arr2[j]=INT_MIN;
            break;
          }
        }
    }

    return ans;
}