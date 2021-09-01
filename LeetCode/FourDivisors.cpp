class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long totalSum = 0;

			for(int i=0;i<nums.size();i++){
					int number = nums[i];
					int count = 0;
					long long sum = 0;
					
					for(int j=1;j*j<=number;j++){
						// cout<<"_>"<<count<<endl;

							if(number%j==0){
									if(j*j==number){
											count+=1;
											sum += j;
									}else{
											count+=2;
											sum += j;
											sum += number/j;
									}
							}
					}
					// cout<<i<<":"<<count<<endl;
					if(count==4){
							totalSum +=sum;
					}
			}
				
				// cout<<totalSum<<endl;
        return totalSum;
    }
};
