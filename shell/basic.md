#Quick Start

shell使用`#` 注释

###执行方式

Shell脚本可以直接调用Unix/Linux的很多命令来执行程序，它可以在bash环境中直接**交互式**的执行，也可以先编写文件再**批量**执行语句。

例如可以直接在终端输入下面的命令，会输出一句“hello shell”

    echo "hello shell"


换另一种方式，创建一个文件，扩展名没有显示，习惯常用`.sh`。

    #!/bin/bash
    echo "hello shell"

其中`#!` 指明了脚本的解释器，将保存文件为`hello.sh`,增加执行权限后，然后使用`./`执行：

    chmod +x hello.sh
    ./hello.sh


`hello.sh`中包含了shell脚本示例
