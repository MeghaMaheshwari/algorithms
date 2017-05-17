//There are two sorted arrays nums1 and nums2 of size m and n respectively.

//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int Compare(string, string);

int main()
{
	    vector<int> nums1;
		nums1.push_back(1);
		nums1.push_back(2);

		vector<int> nums2;
		nums2.push_back(3);
		nums2.push_back(4);


	    int final_array = nums1.size() + nums2.size();
        
        std::vector<int> final = nums1;
        final.insert(final.end(), nums2.begin(), nums2.end());
        
        sort(final.begin(),final.end());
        
        float median;
        
        if(final_array % 2 != 0)
        {
           median = final[final_array/2];    
        }
        else
        {
			float val1 = final[final_array/2];
			float val2 = final[(final_array/2)-1];
            median = (final[final_array/2] + final[(final_array/2)-1])/2.0;
			median = (val1+val2)/2;
        }
        
        return median;
	
}

