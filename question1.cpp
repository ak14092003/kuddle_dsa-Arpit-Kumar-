#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--){
       int N,K;
       vector<int> A(N) ,B(N);
       for(int i=0;i<N;i++){
        cin>>A[i];
       }
        for(int i=0;i<N;i++){
            cin>>B[i];
        }
        unordered_map<int,int> category_time;

        for(int i=0 ; i<N ;i++){
            if(category_time.find(A[i])==category_time.end()){
                category_time[A[i]] = B[i];
            }
            else{
                category_time[A[i]] = min(category_time[A[i]],B[i]);
            }
        }
        if(category_time.size()<K){
            cout<<-1<<endl;
            continue;
        }

        vector<int> times;
        for(auto& pair :category_time){
            times.push_back(pair.second);
        }
        sort(times.begin(),times.end());

        int min_time = 0;
        for(int i=0; i<K; i++){
            min_time+=times[i];
        }
        cout<< min_time <<endl;
       
    }
    return 0;
}