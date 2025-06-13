#include <iostream>
using namespace std;

class MathOperations 
{
    public:
    int a, b;
    float c;

    float division() 
	{
        cout<<"Enter Your First Number: ";
        cin>>a;
        cout<<"Enter Your Second Number: ";
        cin>>b;

        if (b==0) 
		{
            throw "Division by zero is not allowed.";
        }

        c = (float)a / b;
        return c;
    }
};

int main() 
{
    MathOperations mo;

    try {
        float result = mo.division();
        if (result<0)
		{
            throw 1;
        }
        cout<<"Result is: "<<result<<endl;
    }
    catch (const char* msg) 
	{
        cout<<msg<<endl;
    }
    catch (int) 
	{
        cout<<"Division of entered values cannot be negative."<<endl;
    }

}

/*
Enter Your First Number: 1
Enter Your Second Number: 2
Result is: 0.5

Enter Your First Number: 1
Enter Your Second Number: 0
Division by zero is not allowed.

Enter Your First Number: 1
Enter Your Second Number: -3
Division of entered values cannot be negative.
*/