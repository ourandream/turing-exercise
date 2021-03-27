#include<iostream>
#include<vector>
#include<string>

using namespace std;

//注意vInt反向存储数字，如123被存为{3，2，1}
class vInt:public vector<int>{
public:
    friend istream& operator>>(istream &,vInt &);
    friend ostream& operator<<(ostream &,vInt &);
};

istream& operator>>(istream & is,vInt & num){
    string temp;
    cin>>temp;
    for(int i=temp.size()-1;i>=0;--i){
        num.push_back(temp[i]-'0');
    }

    return is;
}

ostream& operator<<(ostream &os,vInt &num){
    for(int i=num.size()-1;i>=0;--i){
        cout<<num[i];
    }

    return os;
}

vInt operator+(vInt &A, vInt &B)
{
    if (A.size() < B.size()) return operator+(B, A);

    vInt C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t);
    return C;
}

vInt operator-(vInt a,vInt b){
    vInt c;
    int t=0;
    for(int i=0;i<a.size();++i){
        t=a[i]-t;
        if(i<b.size()){
            t-=b[i];
        }
        c.push_back((t+10)%10);
        if(t<0){
            t=1;
        }
        else{
            t=0;
        }
    }
    while(c.size()>1 && c.back()==0){
        c.pop_back();
    }
    return c;
}

int main(){
    vInt a,b;
    cin>>a>>b;
    vInt c=a+b;
    cout<<c<<endl;

    return 0;
}
