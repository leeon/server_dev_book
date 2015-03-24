#编译

C++语言从编译到执行需要以下几个流程：

1. 预处理得到.ii文件
2. 编译得到 .s文件
3. 汇编得到 .o文件
4  链接得到 .out文件

例如编译一个最简单的文件：

    g++ -o main main.c -Wall --save-temps

其中，`-o`表示要生成的目标，`-Wall`表示显示所有的warning信息，`--save-temps`表示保存编译过程中所有的中间文件，主要是方便学习编译的过程。

###常用参数

**-g** 生成支持gdb调试的信息
**-l** 指定程序要连接的库，例如线程支持`gcc main.c -lpthread`
**-L** 指定链接库的搜索路径
**-I** 指定头文件的目录


###gcc和g++
gcc和g++都可以编译c和c++语言，区别是遇到一个`.c`文件，gcc当做C语言编译，而g++当做C++语言编译。同时gcc无法自动链接C++，所以一般编译C++就直接使用g++了。


###编译进化

假设有下面的项目代码需要编译：项目文件夹
    
    complile/
        main.cpp
        myclass/
            apple.h
            apple.cpp

其中client.cpp内容如下，这里要引用自定义apple类。

    #include "myclass/apple.h"

    int main(int argc, char const *argv[])
    {
        apple myapple("red");
        myapple.info();
        return 0;
    }

apple.h文件包含了一个apple类的声明


    #include <iostream>

    #ifndef APPLE_H
    #define APPLE_H value

    using namespace std;

    class apple
    {
    public:
        apple();
        apple(const string color):color(color),weight(200){}
        void info();    
        ~apple();
    private:
        string color;
        int weight;
    };

    #endif

apple.cpp文件中为类成员函数的具体定义


    #include "apple.h"
    apple::apple(){}

    apple::~apple(){}

    void apple::info()
    {
        cout<<"This is a "<<color<<" apple."<<endl;
    }



###基本的编译方式

因为main.cpp中已经include了apple.h，所以直接编译相关的cpp文件即可

    g++ main.cpp myclass/apple.cpp -o main

###编译选项

前面提到的`-I`命令可以将一个目录包含到h文件查找路径中，在此路径下的h文件就可以通过下面的方式引用

    #include<apple.h>

就像引用系统的头文件一样，需要使用下面的编译命令

    g++ main.cpp myclass/apple.cpp -I ./myclass -o main

###分步编译链接

上面的编译方式，其实隐藏了具体的编译和链接的细节，我们可以分别编译cpp文件到.o，然后再执行链接操作：

    g++ -c myclass/apple.cpp //compile
    g++ -c main.cpp  //compile
    g++ main.o apple.o -o main  //link

###使用静态库

首先理解静态库的概念，**库**的意思就是一组.o/.obj文件的集合，和其他编程语言中的库差不多，**静态**的意思是在链接阶段和当前的程序一起打包到可执行文件中，因此带来的好处是程序具有更好的可移植性，缺点则是浪费空间不够灵活，比如一些庞大的库，如果采用静态库的方式，那么程序就会很占用空间。

这个例子中myclass下只有一个类，再增加一个orange类，就可以将这些水果打包了：-）

Linux下静态库文件扩展名是.a（Linux）或者.lib（Windows）。那么制作一个水果静态包的过程如下：

    g++ -c myclass/apple.cpp myclass/orange.cpp  //get .o
    ar -crv libfruit.a apple.o orange.o

ar是Linux创建静态库的命令，`-c`表示创建.a文件`-r`表示替换现有同名库，`-v`显示库里的内容。

接下来使用刚刚创建的静态库，前面提到了两个重要命令。`-L`指定库的搜索目录，`-l`指定具体库，格式是-lname,其中libfruit.a就是lfruit.

    g++ main.cpp -L./ -lfruit -o main

###使用动态库
静态库使用占用空间比较大，同时库进行更新，则所有依赖的程序都需要重新编译，使用动态库可以解决这些问题，所谓动态就是在程序运行时才进行加载。这样多个程序可以在内存中共享同一个库。

创建一个动态库需要使用下面的命令：

    g++ -c -fPIC apple.cpp orange.cpp //gen Position Independence Code
    g++ -shared -o libdfruit.so apple.o orange.o

引用动态链接库

    g++ main.cpp -L./myclass -ldfruit

直接执行的时候，会发现找不到动态链接库，原因是Linux加载动态库会依次寻找：

1. 50LD_LIBRARY_PATH指定的目录
2. /etc/ld.so.cache 指定目录
3. /usr/lib

可以将动态链接库放在上面路径中。

> 注意所谓链接库都是在链接的时候作用，所以程序首先需要找对应的.h文件



