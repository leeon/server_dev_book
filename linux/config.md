#配置手册

###Java开发环境

选择Java SE JDK 7,下载 rpm包

    http://www.oracle.com/technetwork/java/javase/downloads/jdk7-downloads-1880260.html

安装
    
    rpm -ivh jdk-7-linux-x64.rpm

配置`/etc/profile`

    JAVA_HOME=/usr/java/jdk1.7.0_55
    JRE_HOME=/usr/java/jdk1.7.0_55jre
    PATH=$PATH:$JAVA_HOME/bin:$JRE_HOME/bin
    CLASSPATH=.:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar:$JRE_HOME/lib
    export JAVA_HOME JRE_HOME PATH CLASSPATH

###Python开发环境

确保安装gcc
    
    yum -y install gcc

下载资源文件

    wget http://python.org/ftp/python/2.7.5/Python-2.7.5.tar.bz2 

解压

    tar -jxvf Python-2.7.5.tar.bz2

安装
    
    cd Pyhton-2.7.5
    ./configure
    make all
    make install
    make clean
    make distclean

备份原有Python版本，并且设置新安装的Python为默认

    mv /usr/bin/python /usr/bin/python2.x
    ln -s /usr/local/bin/python /usr/bin/python

> yum不支持Python2.7 可以修改/usr/bin/yum文件


###配置vsftp

使用yum命令安装vsftp
    
    yum install vsftpd -y

先检查一下nologin的位置，通常在/usr/sbin/nologin或者/sbin/nologin下。
使用下面的命令创建帐户，该命令指定了/home/data为用户pwftp的家目录，您可以自己定义帐户名和目录：
    
    useradd -d /home/data -s /sbin/nologin pwftp

修改该帐户密码:
    
    passwd pwftp

修改指定目录的权限
    
    chown -R pwftp.pwftp /home/data

编辑vsftp配置文件，命令如下：
    
    vi /etc/vsftpd/vsftpd.conf

将配置文件中`anonymous_enable=YES`改为 `anonymous_enable=NO`
取消如下配置前的注释符号：
    
    local_enable=YES
    write_enable=YES
    chroot_local_user=YES

保存修改，按ESC键，输入：wq

修改shell配置

vi编辑/etc/shells，如果该文件里没有/usr/sbin/nologin或者/sbin/nologin（具体看当前系统配置）则追加进去

启动vsftp服务并测试登录，使用命令启动vsftp服务：

    service vsftpd start

然后用帐号pwftp测试下是否可以登陆ftp。目录是/home/data。