#基础数据类型

常用的基础类型包括 char, int , long, float 和 double。其中char int long 还可以使用`unsigned` 指定为无符号类型，即非负的类型。

`datatypee.cc` 中展示了不同类型在具体机器上所占用的空间大小。

> char 和 int 进行运算会进行整型提升，将char转换为int。



### Enum


枚举表示一般用于表示一组状态值。例如定义一组表示速度的状态值。

    enum ESpeed
    {
        FAST,
        NORMAL,
        SLOW
    }

枚举中每一个元素是一个整型常量，默认第一个值为0，后面每一元素加1，当然也可以为每一个元素指定数值。如果其中一个元素被显示赋值，则后面的元素在此基础上依次加1，因此枚举值之间允许有相同的出现。


C++中枚举是一种强类型，属于POD, 不属于类类型，因此也无法限定常量的命名空间。不同枚举中定义的常量不能直接转换。
enum可以隐式转换为int, 反过来int需要强制转换为enum，但是这种行为是不安全的, 可能会导致枚举类型得到一个未定义的值。C++进行类型强制转换的时候并不会进行enum值的检查。

> C中的枚举是弱类型，本质上是个int型

枚举的意义在于节省空间，并且将一些列的数值建立起联系。尽量不要尝试与不同类型之间的转换。

枚举可以节省变量空间，具体实现没有固定的标准，可以是int, short, char实现,C++标准要求枚举的实现不超过int的大小。


###Array

数组是内存中连续的一段存储空间，数组中每个元素都具有相同的类型，相同的大小空间。访问数组中的每一个元素都是O(1)的时间。

    int a[] = {1,2,3}

数组名作为右值返回数组中首个元素的内存地址。下面代码中两种方式都以进行数组元素的访问。同时在函数传参数的时候也可以传递数组的首地址给一个指针。

    int a[]  = {1,2,3};
    printf("%d\n", a[1]);
    printf("%d\n", *(a + 1));


----------


#存储作用域 & 生命周期
不同类型的变量拥有不同的作用域和生命周期，不同类型的变量也存储在不同的区域。

局部变量作用域就是其定义所在的作用域。离开作用域后释放。例如一个函数内部定义变量只能在其函数内部访问。
全局变量作用域是整个程序，其他文件引用全局变量，

静态局部变量，生命周期扩大为所在文件的生命周期，作用域不变。
静态全局变量，作用域会缩小至其所在的文件。

> 类的静态成员有其他面向对象中的含义。

###栈
存储局部变量和函数参数。由编译器自动分配和释放。

进入局部作用域，局部变量进栈，离开作用域，对应的变量出栈，后进先出。

###堆
存储程序通过malloc函数或者new关键字动态申请的内存空间。需要程序通过free函数或者delete关键字主动释放。

###静态存储区 和 全局存储区
存储静态类型和全局类型。


-----------


#声明 & 定义

###声明式

声明式是向编译器(compiler)指明一个东西的名字的和类型, 可能是变量、函数、或者对象，使得编译器可以找到它。编译器无需关注实现细节。例如：

    extern int i;   // 声明一个整型变量
    int max_num(int x, int y);   //声明一个函数
    class MyClassType;    //声明一个类

###定义式

定义式用来实例化或者实现声明使得链接器(Linker)可以链接到，在这里进行内存分配等具体细节操作。例如:

    int i;    //定义一个整型变量
    int max_num(int x, int y){return x>y?x:y}
    class foo{}; 


###关联与区别

只要需要访问变量或者函数，就可以先声明。但是定义只能出现一次，否则linker就无法知道要链接哪一个。


###关于staic成员变量

    class X
    {
    public:
          static int i;
    };
    int X::i = 0; // definition outside class declaration

C++的静态成员列表, 不是定义而是声明。理解：类的静态成员是属于类而非对象，即使没有任何实例化对象，类的静态 成员也依然存在，而且只有一份，类内定义会导致重复定义。

**特例**:如果一个静态成员为const static 整型类型（包括 int, char, bool），并且没有取地址操作，可以直接在类成员列表中进行声明同时定义。

    class X
    {
    public:
          static const int i = 12;
    };




#运算符优先级
个人观点：请适当的用括号包裹表达式，消除一切不明确的运算符运算。




#参考资料

+ [Sina App Engine Blog](http://blog.sae.sina.com.cn/archives/3202)
+ [Effective C++]()
+ [IBM Knowledge Center](http://www-01.ibm.com/support/knowledgecenter/SSGH3R_8.0.0/com.ibm.xlcpp8a.doc/language/ref/cplr038.htm%23cplr038)
+ [What is the difference between a definition and a declaration?](http://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration)
