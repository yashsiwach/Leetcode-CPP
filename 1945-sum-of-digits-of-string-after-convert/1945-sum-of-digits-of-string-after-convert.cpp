class Solution {
public:
    int getLucky(string& s, int k) {
        int num=0;
        // convert letters to digits
        for (char c: s){
            int x=c-'a'+1;
            auto [q, r]=div(x, 10);// x may has 1~2 digits
            num+=q+r;
        }
    //    cout<<num<<endl;
        if (k==1) return num;
        k--;
        for(int x=num; x>=10 && k>0; k--){
            for(num=0; x>0; ){
                auto [q, r]=div(x, 10);
                num+=r;
                x=q;
            }
    //        cout<<"k="<<k<<", num="<<num<<endl;
            x=num;
        }
        return num;
    }
};