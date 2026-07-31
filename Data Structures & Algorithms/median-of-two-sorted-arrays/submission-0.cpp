class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // first lets use binary search on the smaller array to determine how many elements we want to use from here
        // condition is that array A left must be <= than B right and B left <= Aright
        vector<int>& A = nums1, &B=nums2;
        // let A be the smaller array
        if(A.size() > B.size()) swap(A,B);
        int totalSize = A.size() + B.size();
        int half = totalSize/2;
        int l = 0, r = A.size(); // let l and r be HOW MANY elements we choosing from A
        while(l <= r){
            int numA = l + (r-l)/2;
            int numB = half - numA;
            int Aleft = numA-1 < 0 ? INT_MIN : A[numA-1];
            int Aright = numA == A.size() ? INT_MAX : A[numA];
            int Bleft = numB-1 < 0? INT_MIN : B[numB-1];
            int Bright = numB == B.size() ? INT_MAX : B[numB];

            if(Aleft <= Bright && Bleft <= Aright){
                if(totalSize%2) return min(Aright, Bright);
                return float(max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }

            if(Aleft > Bright) r = numA - 1;
            else l = numA + 1;
        }

        return 0.0;
    }
};
