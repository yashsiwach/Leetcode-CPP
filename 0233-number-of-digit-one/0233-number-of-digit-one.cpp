class Solution {
public:
    int countDigitOne(int n) {
        if(n==0)return 0;
        if(n<10)
        {
            return 1;
        }
       string numStr = to_string(n);
        int base = (numStr.length() > 1) ? pow(10, numStr.length() - 1) : 1;
        int oneinbase= n/base==1 ? n-base+1:base;
        return (n/base)*countDigitOne(base-1)+countDigitOne(n%base)+oneinbase;


    }
};