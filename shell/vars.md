#变量
shell在使用变量的时候，如果变量不存在，则可以使用默认值。

###使用默认值

`:-` 表示如果一个变量不存在或者为null,就会使用符号后面指定的默认值。`-`表示如果一个变量不存在的情况才会使用默认值。

    unset foo
    echo ${foo:-foos default value}
    echo ${foo-foos default value}

    foo=
    echo ${foo:-foos default value}
    echo ${foo-foos default value}
    
###用默认值赋值

`:=`表示如果一个变量不存在或者为null，就会把符号后面指定的默认值赋值给变量。`=`表示如果一个变量不存在的情况才会把默认值赋值给变量。

    unset foo
    echo ${foo:=foos default value}
    echo $foo


###数据类型

Shell内置了`declare`命令用来声明变量类型和为变量赋值。起命令格式为

    declare [-aAfFilrtux] [-p] [name[=value] …]

每一个name表示变量名，其中`-p`参数会打印出name对应的value，如果不提供name则默认打印所有的变量。通过declare可以声明几种不同的类型：

    declare -a a  #数组
    declare -A aa #关联数组
    declare -i i  #整型


###数组
Shell支持两种类型的数组：普通一维数组和关联数组（字典）。数组没有限制数组大小，并且允许数组中存在不同类型。使用`declare`来指明创建数组的类型:

    declare -a indexedArray
    indexedArray=(1 2 3)

    declare -A associativeArray
    associativeArray=([name]='tom' [age]=12)

> bash 和 zsh 对shell数组的支持不同，zsh的数组下标从1开始，不支持上面代码中关联数组的初始化方式。

###普通数组

普通的一维数组会在使用的时候自动创建，下面的代码就可以直接创建一个数组name：

    #automatically create an array
    name[index]=val
    
    #access an item 
    echo ${name[index]}

普通数组可以通过下标来进行访问，其中使用下标`@`或者`*`可以获取所有的元素。使用`#`获取数组中元素的个数.

    echo ${name[2]}  #get one item indexed 2
    echo ${name[@]}  #get all items
    echo ${name[*]}  #get all items
    echo ${#name[@]} #get numbers of items in the array

> @和\*的区别在于，当变量被双引号包围的时候，@得到的是多个元素，而\*将多个元素拼到了一起。

Shell数组还支持片段的选取，即`${name[startIndex:length]}`的形式：

    array=(1 2 3 4 5 6 7)
    echo ${array[4:2]}    #output 5 6


数组添加元素可以通过两种方式，一是直接对指定的位置赋值，而是通过复制原数组实现：

    array=(${array[@]} "new item")

从数组中删除元素使用`unset`关键字

    unset array[2]  #删除一个元素
    unset array     #删除整个数组

###关联数组
    
    echo ${!array[@]}   #获得所有的key
    echo ${array[@]}    #获得所有的value

 