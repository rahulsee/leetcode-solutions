// https://leetcode.com/problems/24-game


class Solution {
    bool answer=false;
public:
     int precedence(char c){
		if(c=='+' || c=='-')
			return 1;
		if(c=='*' || c=='/')
			return 2;
		return 0;
	}

	string infixToPostfix(string expr){
		stack<char>s;
		string answer;
		for(int i=0;i<expr.length();i++){
			if(expr[i]>='0' && expr[i]<='9'){
				answer.push_back(expr[i]);
			}
			else{
				if(expr[i]=='(')
				{
					s.push(expr[i]);
				}
				else if(expr[i]==')'){
					while(!s.empty() && s.top()!='('){
						answer.push_back(s.top());
						s.pop();

					}
					s.pop();
				}
				else{
					while(!s.empty() && precedence(expr[i]) <= precedence(s.top()))
					{
						answer.push_back(s.top());
						s.pop();
					}
					s.push(expr[i]);
				}
			}
		}
		while(!s.empty()){
			answer.push_back(s.top());
			s.pop();
		}
		return answer;
	}

	double apply_op(double a,double b,char op){
		if(op=='+')
			return a+b;
		if(op=='-')
			return a-b;
		if(op=='/' && b)
			return a/b;
		if(op=='*')
			return a*b;
		return 0;

	}

	double postfixEval(string pf){
		stack<double>s;
		for(int i=0;i<pf.length();i++){
			if(pf[i]>='0' && pf[i]<='9')
				s.push(pf[i]-'0');
			else
			{
				double a=s.top();
				s.pop();
				double b=s.top();
                s.pop();
				s.push(apply_op(b,a,pf[i]));

			}
		}
		return s.top();
	}

    string form_expr(string expr,vector<char>&brackets)
    {
    	//cout<<expr<<endl;
    	// for(int i=0;i<brackets.size();i++)
    	// 	cout<<brackets[i];
    	// cout<<endl;
        string final_exp;
        for(int i=0;i<expr.length();i++){
            if(expr[i]>='0' && expr[i]<='9')
            {
            	// cout<<expr[i]<<endl;
                if(brackets[i/2]=='(')
                {
                    final_exp.push_back(brackets[i/2]);
                	final_exp.push_back(expr[i]);
                }
                else if(brackets[i/2]==')')
                {
                	final_exp.push_back(expr[i]);
                	final_exp.push_back(brackets[i/2]);
                }
                else
                {
                	final_exp.push_back(expr[i]);
                }
            }
            else
            {
                final_exp.push_back(expr[i]);
            }
        }
        //cout<<final_exp<<endl;
        return final_exp;
    }
    
    
    void putbracket(vector<int>nums,string expr,vector<char> &brackets, int open, int closed,int cur){
        
        if(closed > open){
            return;
        }
        
        if(cur==brackets.size()){
            if(closed==open){
            	// cout<<expr<<endl;
            	string res=form_expr(expr,brackets);
            	string pf=infixToPostfix(res);
            	// cout<<pf<<endl;
            	//cout<<res<<endl;
            	double result=postfixEval(pf);
            	// cout<<pf<<" "<<result<<endl;
                answer=max(answer,abs(result-24)<=0.001);
            }
            return;
        }
        
        
        brackets[cur]='(';
        putbracket(nums, expr,brackets,open+1,closed,cur+1);
        brackets[cur]=' ';

        if(open > closed){
	        brackets[cur]=')';
	        putbracket(nums, expr,brackets,open,closed+1,cur+1);
	        brackets[cur]=' ';
    	}
        
        
        putbracket(nums,expr,brackets,open,closed,cur+1);   
    }
    
    
    void dfs(vector<int>nums,string &expr,int cur){
        if(cur==expr.size())
        {
            vector<char>bracket(nums.size(),' ');
            //cout<<expr<<endl;
            putbracket(nums,expr,bracket,0,0,0);
            return;
        }
        if(expr[cur]==' ')
        {
            expr[cur]='+';
            dfs(nums,expr,cur+1);
            expr[cur]=' ';
            
            expr[cur]='-';
            dfs(nums,expr,cur+1);
            expr[cur]=' ';
            
            expr[cur]='/';
            dfs(nums,expr,cur+1);
            expr[cur]=' ';
            
            expr[cur]='*';
            dfs(nums,expr,cur+1);
            expr[cur]=' ';
            
        }
        else{
        dfs(nums,expr,cur+1);
        }

    }
    
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        do{
    		string expr;
	        for(int i=0;i<nums.size()-1;i++){
	            expr.push_back(nums[i]+'0');
	            expr.push_back(' ');
	        }
	        expr.push_back(nums[nums.size()-1]+'0');
	        // cout<<expr<<endl;
    		// cout<<"YES"<<endl
    		dfs(nums,expr,0);
            if(answer==true)
                break;
        } while(next_permutation(nums.begin(),nums.end()));
        return answer;
    }
    
};