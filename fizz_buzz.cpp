// https://leetcode.com/problems/fizz-buzz/

class Solution
{
private:
    struct Output {
        Output(function<bool(int)> fnCondition, function<string(int)> fnPrint)
        {
            condition = fnCondition;
            print = fnPrint;
        }
        
        function<bool(int)> condition;
        function<string(int)> print;
    };
    
    vector<Output> m_outputs;
    
    void InitOutputs()
    {
        m_outputs.emplace_back(
            [](int n)->bool { return n%3==0 && n%5==0; },
            [](int n)->string { return "FizzBuzz"; }
        );

        m_outputs.emplace_back(
            [](int n)->bool { return n%3==0; },
            [](int n)->string { return "Fizz"; }
        );

        m_outputs.emplace_back(
            [](int n)->bool { return n%5==0; },
            [](int n)->string { return "Buzz"; }
        );

        m_outputs.emplace_back(
            [](int n)->bool { return true; },
            [](int n)->string { return to_string(n); }
        );
    }
    
public:
    Solution()
    {
        InitOutputs();
    }
    
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> answer;
        
        for(int m = 1; m <= n; m++)
        {
            for(Output o : m_outputs)
            {
                if(o.condition(m))
                {
                    answer.insert(answer.end(), o.print(m));
                    break;
                }
            }
        }
        
        return answer;
    }
};
