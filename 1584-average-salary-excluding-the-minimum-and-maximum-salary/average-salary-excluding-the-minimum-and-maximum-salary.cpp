class Solution {
public:
    double average(vector<int>& salary)
    {
      mergeSort(salary, 0, salary.size() - 1);

     double totalSum = 0;
        for(int i = 1; i<salary.size()-1; i++)
        {
            totalSum += salary[i];
        }
        return totalSum / (salary.size() - 2);
    }
private:    
    void merge(vector<int>& salary, int left, int mid, int right){
        int m1 = mid - left + 1;
        int m2 = right - mid;

        vector<int> leftArray(m1);
        vector<int> rightArray(m2); 

        for(int i = 0; i < m1; i++)
        {
            leftArray[i] = salary[left + i];
        }
        for(int i = 0; i < m2; i++)
        {
            rightArray[i] = salary[mid + 1 +i];
        }
        int i = 0, j = 0; 
        int k = left;
        while(i < m1 && j < m2)
        {
            if(leftArray[i] <= rightArray[j])
            {
                salary[k++] = leftArray[i++];
            }
            else
            {
                salary[k++] = rightArray[j++];
            }
        }
        while(i < m1)
        {
            salary[k++] = leftArray[i++];
        }
        while(j < m2)
        {
            salary[k++] = rightArray[j++];
        }
    }

    void mergeSort(vector<int>& salary, int left, int right){
        if(left < right)
        {
            int mid = (left + right) / 2;

            mergeSort(salary, left, mid);
            mergeSort(salary, mid + 1, right);

            merge(salary, left, mid, right);
        }
    }
};