// permutations in string
class Solution {
    private:
    bool checkEqual(int a[26],int b[26])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                return 0;
            }
        }
        return 1;
    }
    public:
    bool checkInclusion(string s1,string s2)
    {
        // counting characters in the array whose inclusion is to be checked
        int count1[26]={0};
        int number;
        for(int i=0;i<s1.length();i++)
        {
            number= s1[i]-'a';
            count1[number]++;
        }
        //traverse string s2 in the window of size s1 and compare
        int i=0;
        int windowSize=s1.length();
        int count2[26]={0};
        //running the first window
        while (i< windowSize && i<s2.length()){
            int index=s2[i]-'a';
            count2[index]++;
            i++;
        }
        if(checkEqual(count1,count2))
        return 1;

        //aage window process kro
        while(i<s2.length())
        {
            char newChar=s2[i];
            int index= newChar -'a';
            count2[index]++;
            char oldChar=s2[i-windowSize];
            index=oldChar-'a';
            count2[index]--;
            i++;
            if(checkEqual(count1,count2))
            {
                return 1;
            }

        }
        return 0;
    }

};
