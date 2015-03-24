#一些Tips


###取代define

+ 对于常量，使用const或者enum替换define
+ 用inline函数取代宏函数

理由：

+ macros 没有作用域的限制，不便于封装
+ 使用宏函数存在着很多不容易发现bug
+ 宏在编译阶段出错难以清晰的看到问题(预处理阶段已经完成替换)



###参考资料

+ [Effective C++]()