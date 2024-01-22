class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVolume = 0;
        int start = 0;
        int end = height.size() - 1;
        while (start < end)
        {
            int volume = min(height[start], height[end]) * (end - start); // calculate volume of container
            maxVolume = max(maxVolume, volume); // move the shorter line closer to the other
            if (height[start] < height[end])
                start++;
            else 
                end--;
        }
    return maxVolume;
    }
};
