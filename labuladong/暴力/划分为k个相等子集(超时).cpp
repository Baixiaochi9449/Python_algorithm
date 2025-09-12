//��������Ϊbool�Ļ���
class Solution {
private:
    vector<int> everysum;
    bool backtracking(vector<int>& nums,int target,int start,int k){
        if(start==nums.size()){  //���ֱ�������
            for(int i=0;i<k;i++){
                if(everysum[i]!=target) return false;
            }
            return true;
        }

        for(int i=0;i<k;i++){
            if(nums[start]+everysum[i]>target) continue;
            everysum[i]+=nums[start];
            if(backtracking(nums,target,start+1,k)){
                return true;
            }
            everysum[i]-=nums[start];
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //�ݹ����֣��൱�ڱ������֡� ��ÿ�εݹ��ʱ��for(ÿ��Ͱ)�� �൱�������ֵ��ӽǣ�ÿ�����ֿ��Է���4��Ͱ� ����4��Ͱ�Ĺ����ǲ��еģ����Կ����ڲ��ѡ�������
        //�����ڷ����������ʱ�򣬿���ѡ���ӽǣ���˭����˭�м���ѡ��
        int sum=0;
        int maxnum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxnum=max(maxnum,nums[i]);
        }
        int target=sum/k;
        if(sum%k!=0) return false;
        if(maxnum>target) return false;
        everysum=vector<int>(k,0);
        return backtracking(nums,target,0,k);

    }
};
