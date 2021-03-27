//strassen's method to multiply matrix,具体算法细节见CLRS笔记。简单来说是通过构造中间matrix减少递归次数。

#include<iostream>

using namespace std;

class matrix{
    private:
        int **array;
        int len;
        int width;
    public:
        matrix();
        matrix(const matrix &);
        matrix(int **inArray,int iL,int iW);
        ~matrix();
        matrix operator+(matrix &);
        matrix operator-(matrix &);
        matrix operator=(matrix &);
        matrix operator*(matrix &);
        void show();
};

matrix::matrix(){
    array=nullptr;
    len=0,width=0;
}

matrix::matrix(const matrix &inM){
    array=new int*[inM.width];
    for(int i=0;i<inM.width;++i){
        array[i]=new int[inM.len];
    }
    len=inM.len,width=inM.width;
    for(int i=0;i<width;++i){
        for(int j=0;j<len;++j){
            array[i][j]=inM.array[i][j];
        }
    }
}

matrix::matrix(int **inArray,int iL,int iW){
    len=iL,width=iW;
    array=new int*[width];
    for(int i=0;i<width;++i){
        array[i]=new int[len];
    }
    for(int i=0;i<width;++i){
        for(int j=0;j<len;++j){
            array[i][j]=inArray[i][j];
        }
    }
}

matrix::~matrix(){
    if(len!=0 && width!=0){
        for(int i=0;i<width;++i){
            delete []array[i];
        }
        delete []array;
    }
}

matrix matrix::operator+(matrix &inM){
    if(inM.len!=len || inM.width!=width){
        matrix eMatrix;
        return eMatrix;
    }

    matrix result;
    result.len=len,result.width=width;
    result.array=new int*[width];
    for(int i=0;i<width;++i){
        result.array[i]=new int[len];
    }
    for(int i=0;i<width;++i){
        for(int j=0;j<len;++j){
            result.array[i][j]=array[i][j]+inM.array[i][j];
        }
    }
    return result;
}

matrix matrix::operator-(matrix &inM){
    if(inM.len!=len || inM.width!=width){
        matrix eMatrix;
        return eMatrix;
    }

    matrix result;
    result.len=len,result.width=width;
    result.array=new int*[width];
    for(int i=0;i<width;++i){
        result.array[i]=new int[len];
    }
    for(int i=0;i<width;++i){
        for(int j=0;j<len;++j){
            result.array[i][j]=array[i][j]-inM.array[i][j];
        }
    }
    return result;
}

matrix matrix::operator=(matrix &inM){
    if(len!=0 && width!=0){
        for(int i=0;i<width;++i){
            delete []array[i];
        }
        delete []array;
    }
    len=inM.len,width=inM.width;
    array=new int*[width];
    for(int i=0;i<width;++i){
        array[i]=new int[len];
    }
    
    for(int i=0;i<width;++i){
        for(int j=0;j<len;++j){
            array[i][j]=inM.array[i][j];
        }
    }

    return *this;
}

int main(){
    
    
    return 0;
}