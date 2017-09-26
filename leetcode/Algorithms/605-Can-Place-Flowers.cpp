class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int _size = flowerbed.size();
        int count = 0;
        for(int i=0; i<_size; ++i){
            if(flowerbed[i] == 0 && (i==0||flowerbed[i-1]==0) && (i==_size-1||flowerbed[i+1]==0)){
                flowerbed[i] = 1;
                count++;
            }
            if(count >= n) return true;
        }
        return false;
    }
};

