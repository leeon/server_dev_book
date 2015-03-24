# proc文件系统

procfs 是类UNIX系统中的一个特殊的文件系统，它以文件的形式存储着进程的运行信息以及一些系统的信息。它提供了一种方便的方式来动态的获取进程相关的内核数据。proc是一个虚拟的文件系统，并不占据具体的磁盘空间，它存在于内存中。内核可以通过它和用户进行通信。其中Linux中的`ps`命令就是通过proc来获取系统中的进程信息，而没有使用系统调用。

procfs在系统启动时挂在到`/proc`目录，目录中数字命名的文件夹对应了进程id下的信息。目录中还包括了系统的一些基本信息比如cpuinfo等。这些信息均为只读。还有一个特殊的子目录`/proc/sys`存储了一些系统内核参数，并允许root用户进行更改，从而实现系统内核参数的修改。





###cpuinfo


通过cpuinfo可以获取当前机器cpu的基本信息

一般说一个cpu "4核8线程" 代表其cpu是拥有4个core， 8 个 processor.

0. 把每一个processor理解为一个基本的处理单元。
1. 一个cpu拥有1..N个core.
2. 对于非超线程技术的cpu,每一个core拥有一个processor; 对于超线程技术cpu,每一个core拥有两个processor.


cpuinfo中记录了每一个processor的基本信息：

0. 同一个cpu下的processor拥有相同的 physical id.
1. 同一个core下的processor拥有相同的 core id.




下面是一些字段含义：

`processor` 逻辑处理核心的编号。其数量代表着cpu有多少个处理线程。查看逻辑核心数：

    cat cpuinfo | grep "processor" | wc -l


`physical id` cpu的标号，当前机器的物理cpu数量。查看cpu数目：

    cat cpuinfo | grep "physical id"| sort | uniq | wc -l

`core id` 一个cpu中核心的编号。

`cpu cores` 一个cpu中 core的数量。

`siblings` 一个cpu中processor的数量。










###参考资料

+ [wikipedia](http://en.wikipedia.org/wiki/Procfs#Linux)