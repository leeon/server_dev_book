#include <iostream>



void test_type_conversion()
{
    printf("\n%s Run:%s():\n", __TIME__,__FUNCTION__);
    
    int i = -12;
    unsigned int ui = 100;
    unsigned int result = ui + i;
    printf("%u\n", result);

}

void swap_ptr(int* &x, int* &y)
{
    int* p;
    p = x;
    x = y;
    y = p;
}


void swap_ptr(int **x, int **y)
{
    int *p;
    p = *x;
    *x = *y;
    *y = p;
}

void test_sizeof()
{
    printf("\n%s Run:%s():\n", __TIME__,__FUNCTION__);
    printf("sizeof char %lu\n", sizeof(char) );
    printf("sizeof unsigned char %lu\n", sizeof( unsigned char) );
    
    printf("sizeof short %lu\n", sizeof(short) );
    printf("sizeof unsigned short %lu\n", sizeof(unsigned short));

    printf("sizeof int %lu\n", sizeof(int) );
    printf("sizeof unsigned int %lu\n", sizeof(unsigned int) );
    
    printf("sizeof long %lu\n", sizeof(long) );
    printf("sizeof long long %lu\n", sizeof(long long) );

    printf("sizeof float %lu\n", sizeof(float) );
    printf("sizeof double %lu\n", sizeof(double) );
}


enum eA
{
    a_on = 2,
};

enum eB
{
    b_on = 2,
};

enum eTable
{
    A = 2,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
};

eTable getEnum()
{
    return eTable(-3);
}


void test_enum()
{
    printf("\n%s Run:%s():\n", __TIME__,__FUNCTION__);

    printf("sizeof(eTable): %lu\n", sizeof(eTable));
    eTable e = D;
    eTable e2;    
    int ie = e;
    e = getEnum();
    printf(" e2 = %d\n", e2);
    printf(" E = %d\n", E);
    printf(" C = %d\n", C);
    printf(" D = %d\n", D);
    printf(" F = %d\n", F);

    printf("%d\n", C == 2 );
    
    // eA on = a_on;
    // int ii = on;
    // printf("a_on = b_on %d\n", ii == b_on );    
    // printf("sizeof(e)%lu\n", sizeof(e));
    // printf("%d\n", e);

    // int i = e;
    // printf("default e = %d\n", A);
    // printf("from e to i = %d\n", i);

}

void diff_array_with_ptr()
{

    printf("\n%s Run:%s():\n", __TIME__,__FUNCTION__);

    int aVal [] = {1,2,3};
    int *ptr = aVal;

    // about the meaning
    printf("%lu\n", sizeof(aVal));
    printf("%lu\n", sizeof(ptr));

    // a convertion
    printf("%p\n", ptr);
    printf("%p\n", aVal);
    printf("%p\n", &aVal[0]);
    printf("%p\n", &aVal);



}


void diff_constptr_with_ptrconst()
{
    printf("\n%s Run:%s():\n", __TIME__,__FUNCTION__);

    int a = 10;
    int b = 11;
    const int *p1 = &a;
    int * const p2 = &a;
    // *p1 = 12; // err
    p1 = &b;
    *p2 = 12;
    // p2 = &b;  //err
}


void test_array()
{
    printf("\n%s Run:%s():\n", __TIME__,__FUNCTION__);
    int a[]  = {1,2,3};

    printf("%d\n", a[1]);
    printf("%d\n", *(a + 1));
}


void test_ptr()
{
    printf("\n%s Run:%s():\n", __TIME__,__FUNCTION__);

    int iVal = 12;
    int iAnotherVal = 13;

    const int *ptr;
    ptr = &iVal;
    // *ptr = 13;  //*ptr is const

    int *const cptr = &iVal;
    *cptr = 23; // ok
    // cptr =  &iAnotherVal;  //err the ptr is const

    printf("%d\n",*ptr );
}


void test_swap_ptr()
{
    printf("\n%s Run:%s():\n", __TIME__,__FUNCTION__);

    int m = 1;
    int n = 2;
    int *p = &m;
    int *q = &n;
    printf("Before swap ptr : *p = %d *q = %d\n", *p, *q );
    swap_ptr(&p,&q);
    printf("After swap ptr : *p = %d *q = %d\n", *p, *q );
}


int sampleFun(const std::string &str)
{
    return str.length();
}


void test_func_ptr()
{
    printf("\n%s Run:%s():\n", __TIME__,__FUNCTION__);
    // int (*pfunc) (const std::string &);
    typedef int (*PFUN) (const std::string &);
    PFUN pfunc = sampleFun;
    printf("The length of str is %d\n",pfunc("hello") );
    printf("The length of str is %d\n",(*pfunc)("hello") );


}
int main(int argc, char const *argv[])
{

    diff_array_with_ptr();

    diff_constptr_with_ptrconst();
    
    test_array();

    test_enum();

    test_sizeof();    

    test_type_conversion();

    test_ptr();

    test_swap_ptr();

    test_func_ptr();

    return 0;
}




