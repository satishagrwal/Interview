#include<iostream>
using namespace std;

class deepCopy
{
    public:
    
      int length;
      int *breadth;
      int height;
      
    deepCopy()
    {
      breadth = new int();  
    }
    
    deepCopy(const deepCopy& rhs)
    {
        length = rhs.length;
        breadth = new int();
        *breadth = *(rhs.breadth);
        height = rhs.height;
    }
    
    deepCopy& operator=(const deepCopy& rhs)
    {
        if(this != &rhs)
        {
           delete breadth;
           
           breadth = new int();
           *breadth = *(rhs.breadth);
           
           length = rhs.length;
           height = rhs.height;
        }
    }
    
    ~deepCopy()
    {
        if(breadth)
        {
            delete breadth;
        }
    }
    
    void setDimension(int l, int b, int h)
    {
        length = l;
        *breadth = b;
        height = h;
    }
    
    void show()
    {
        std::cout <<"length: "<<length<< std::endl;
        std::cout <<"breadth: "<<*breadth<< std::endl;
        std::cout <<"height: "<<height<< std::endl;
    }
};

int main()
{
    deepCopy d;
    d.setDimension(1,2,3);
    d.show();
    
    deepCopy c;
    c= d;
    c.setDimension(4,5,6);
    c.show();
    
    d.show();
    d.setDimension(7,8,9);
    d.show();
    c.show();
    return 0;
}
