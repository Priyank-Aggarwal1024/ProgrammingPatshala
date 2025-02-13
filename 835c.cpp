#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q,c;
    cin>>n>>q>>c;
    vector<vector<int>>v(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    int check[101][101] = {0};
    for(int i=0;i<n;i++){
        check[v[i][0]][v[i][1]]=1;
    }
    int arr[c][101][101] = {0};
    for(int i=0;i<n;i++){
        arr[0][v[i][0]][v[i][1]] = v[i][2];
    }
    for(int i=1;i<c;i++){
        for(int j=0;j<101;j++){
            for(int k=0;k<101;k++){
                if(check[j][k]){
                    arr[i][j][k] = (arr[i-1][j][k]+1)>c?0:arr[i-1][j][k]+1;
                }
            }
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<101;j++){
            for(int k=1;k<101;k++){
                arr[i][j][k] = arr[i][j][k-1]+arr[i][j][k];
            }
        }
        for(int j=1;j<101;j++){
            for(int k=0;k<101;k++){
                arr[i][j][k] = arr[i][j-1][k]+arr[i][j][k];
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<q;i++){
        int t,x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        int rem = t%c;
        int sum = arr[rem][x2][y2];
        if(x1!=0){
            sum-=arr[rem][x1-1][y2];
        }
        if(y1!=0){
            sum-=arr[rem][x2][y1-1];
        }
        if(x1!=0 && y1!=0){
            sum+=arr[rem][x1-1][y1-1];
        }
        ans.push_back(sum);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}