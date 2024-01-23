#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int removeDuplicates(vector<int>& nums) {
    //unique()�������ظ���Ԫ�طŵ�vector��β�� Ȼ�󷵻�ָ���һ���ظ�Ԫ�صĵ�����
    //����erase�������������Ԫ�ص����Ԫ�ص����е�Ԫ��
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    return nums.size();
}

int removeDuplicates(vector<int>& nums)
{
    if (nums.empty()) return 0;
    int index = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[index] != nums[i])
            nums[++index] = nums[i];
    }
    return index + 1;
}


int main()
{

    return 0;
}
