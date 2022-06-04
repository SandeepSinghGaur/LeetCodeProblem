    vector<int>ans;
    stack<int>look_up_container;
    for(int i=0;i<A.size();i++){
        while(!look_up_container.empty() && look_up_container.top()>=A[i]){
            look_up_container.pop();
        }
        if(!look_up_container.empty()){
            ans.push_back(look_up_container.top());
        }else{
            ans.push_back(-1);
        }
        look_up_container.push(A[i]);
    }
    return ans;