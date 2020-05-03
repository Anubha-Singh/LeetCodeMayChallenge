Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

//My Solution

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      unordered_map<char,int>mp;
        int count=0,flag=0;
        for(int i=0;i<magazine.length();i++)
            mp[magazine[i]]++;
        for(int i=0;i<ransomNote.length();i++)
        { if (mp.find(ransomNote[i])!=mp.end())
        {     mp[ransomNote[i]]--;
              if(mp[ransomNote[i]]==0)
                  mp.erase(ransomNote[i]);
              count++;
         }
         else 
         {
             flag=1;
             break;
         }
             
         }
        if(count==ransomNote.length() && flag!=1)
            return true;
        return false;

    }
};
