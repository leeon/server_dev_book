#代码风格

###匈牙利命名法

匈牙利命名法流行于微软的MFC，最大的特点就是变量拥有一个表示类型的前缀。这个前缀可以只是表示变量的基本类型，例如`iVal`表示一个整型变量；也可以表示一个特定的组件，比如`wndowSize`表示窗体高度等，可以根据具体的业务去规范。


    st  struct
    i   int
    l   long
    f   float
    d   double 
    c   char
    str string
    m   map
    vec vector

    p   pointer

    m_  Class Member
    g_  Global var



#####适用

+ 非IDE开发环境，可以通过变量名快速的获知变量类型。
+ 业务组件较多的时候，区分变量作用范围。



-----------



###括号风格

A
    
    func()
    {
        // do something
    }

B

    func(){
        // do something 
    }



个人在C++项目中使用A风格，代码的段落感看起来更强，对应的控制流逻辑更加清晰。

