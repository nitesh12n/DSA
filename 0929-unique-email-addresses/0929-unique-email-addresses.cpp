class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string>validEmails;
        
        for(auto email : emails)
        {
            string temp;
            int i=0;
            while(email[i] != '@')
            {
                if (email[i]=='+')
                {
                    while(email[i] != '@')
                        i++;
                    break;
                }
                if(email[i]!='.')
                    temp+=email[i];
                i++;
            }
            temp+=email.substr(i, email.size()-i);
            validEmails.insert(temp);
        }
        return validEmails.size();
    }
};