#include<bits/stdc++.h>
using namespace std;


int power(int a,int b,int n){
    int res = 1;
    vector<int>bin;
   
    while(b){
        if(b & 1)
            bin.push_back(1);
        else
            bin.push_back(0);
        b /= 2;
    }


    for(int i=bin.size()-1;i>=0;i--){
        res = (res*res)%n;
        if(bin[i])
            res = (res*a)%n;
    }
    return res;
}


vector<pair<int,int>> curve_points(int a,int b,int p){
    int x = 0;
    vector<pair<int,int>>ans;
    while(x < p){
        int w = ((x*x*x)+(a*x)+b);
        if(power(w,(p-1)/2,p) == 1){
            while(ceil(sqrt(w)) != floor(sqrt(w))){
                w += p;
            }
            int p1 = sqrt(w);
            int p2 = 0-p1;
            p1 %= p;
            while(p2 < 0)
                p2 += p;
            ans.push_back({x,p1});
            ans.push_back({x,p2});
        }
        x++;
    }
    return ans;
}


int main(){
    int a,b,p;


    cout << "Enter point a:- ";
    cin >> a;
    cout << "Enter point b:- ";
    cin >> b;
    cout << "Enter point p:- ";
    cin >> p;
    vector<pair<int,int>>ans = curve_points(a,b,p);
    if(ans.size() == 0){
        cout << "Any Elliptic curve not possible." << endl;
    }
    else{
        cout << "Elliptic Points:- " << endl;
        int two = 1;
        for(auto i:ans){
            if(two--)
                cout << "(" <<  i.first << "," << i.second << ") ";
            else{
                cout << "(" <<  i.first << "," << i.second << ")" << endl;
                two = 1;
            }      
        }
    }
    return 0;
}


/*
Output:-
Enter point a:- 1
Enter point b:- 1
Enter point p:- 13
Elliptic Points:-
(0,1) (0,12)
(1,4) (1,9)
(4,11) (4,2)
(5,12) (5,1)
(8,12) (8,1)
(10,6) (10,7)
(11,11) (11,2)
(12,5) (12,8)
*/