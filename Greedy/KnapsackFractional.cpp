#include<bits/stdc++.h>
using namespace std;

int main(){
 int n,i,capacity;
 float value[10],weight[10],ratio[10];
 cout<<"Enter the number of item :"<<endl;
 cin>>n;
 cout<<"Enter capacity: "<<endl;
 cin>>capacity;
 cout<<"Enter the value :"<<endl;
 for(i=0; i<n; i++){
 cin>>value[i];
 }
 cout<<"Enter the weight :"<<endl;
 for(i=0; i<n; i++){
 cin>>weight[i];
 }

 for(i=0;i<n-1; i++){
    for(int j=0; j<n-i-1;j++){
        float r1 = value[j]/weight[j];
        float r2 = value[j+1]/weight[j+1];

        if(r1<r2){
            float temp = value[j];
            value[j] = value[j+1];
            value[j+1] = temp;

            temp = weight[j];
            weight[j] = weight[j+1];
            weight[j+1]= temp;
        }
    }
 }

 float total_val = 0.0;
 int rem_cap = capacity;
 for(i=0; i<n; i++){
    if(weight[i]<=rem_cap){
        total_val +=value[i];
        rem_cap -= weight[i];
    }
    else{
        float frac = rem_cap/weight[i];
        total_val += value[i]*frac;
        break;
    }
 }
 cout<<"Total value : "<<total_val<<endl;
 return 0;


}
