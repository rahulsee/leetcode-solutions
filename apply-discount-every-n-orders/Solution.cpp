// https://leetcode.com/problems/apply-discount-every-n-orders

class Cashier {
public:
    
    unordered_map<int,int>id_to_index;
    vector<int>prices;
    vector<int>productids;
    int num_transactions;
    int n;
    double discount;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        productids=products;
        this->prices=prices;
        for(int i=0;i<productids.size();i++)
            id_to_index[productids[i]]=i;
        num_transactions=0;
        this->n=n;
        this->discount=discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double sum=0;
        for(int i=0;i<product.size();i++)
        {
            int index=id_to_index[product[i]];
            //cout<<index<<endl;
            sum+=(amount[i]*prices[index]);
        }
        num_transactions++;
        if(num_transactions % n == 0)
        {
            sum=sum-(discount*sum)/100;
        }
        return sum;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */