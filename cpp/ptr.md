#指针

所有的变量都是分布在内存中的，现在的高级语言一般都会屏蔽对于内存的直接操作, C&CC强大的地方在于开发者可以自由的控制内存的使用。

###取地址

`&` 操作符表示取一个变量的地址。

    int iVal = 12;
    printf("%p", &iVal);




###概念

指针保存的是一个内存地址。

    int iVal = 23;
    int *ptr;
    ptr = &iVal;

上面的代码中进行了如下操作:

1. 定义了一个变量iVal, iVal为整型, 并且赋值为23.
2. 定义了一个变量ptr, *ptr为整型, ptr为指向整型的指针.
3. p赋值为变量i的内存地址.




###大小

指针保存的是一个内存地址，所以指针本身占用的空间大小和操作系统有关，32位上指针为4字节，而64位系统上为8字节。


###const

下面代码中 ptr 是一个指向const对象的整型指针，它的语法意义是 `*ptr`是一个const对象。如下面代码所示，通过`*ptr`试图对原始整型进行写操作的时候，会产生错误。但ptr本省并非const对象，所以可以修改自身的值从而指向别的对象。事实上，ptr所指向的对象并不要求是const对象。《C++ Primer》中的描述“自认为指向const对象的指针”更为恰当。

    int a = 0;
    int b = 1;

    const int *ptr = &a;
    *ptr = 12; // err
    ptr = &b;  // ok

    a = 3; // we can change a in some other way


另外一个种指针是 const 指针，cptr这个指针自身是const的，不可变，需要定义时初始化。其指向的内容不受限制。



    int *const cptr = &a;
    *cptr = 12;
    cptr = &b;  //err

###迷惑

const和指针的迷惑来源于`const`和类型之间的位置是可以互换的，例如下面两行代码声明的都是指向const对象的整型指针：

    int const *p1;
    const int *p2;  //same as code above






