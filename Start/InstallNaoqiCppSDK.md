# 在MacOS下安装Naoqi C++ SDK

## 安装qiBuild

您将（在您的计算机上）编译要在另一个操作系统（在机器人上）下运行的代码，因此您需要交叉编译。**qiBuild**是一个用于使用**CMake**生成跨平台项目的工具。**CMake**为任何操作系统生成makefile和工作区，使项目能够在Windows，Mac，Linux和NAOqi OS上进行简单编译。

**先决条件：** 

CMake3.2或更高版本(`cmake --version`)、Python 2.7(`python --version`)

> CMake官网：[http://www.cmake.org/cmake/resources/software.html](http://www.cmake.org/cmake/resources/software.htm)
>
> Python：[https://www.python.org/](https://www.python.org/)
>
> Pip：[http://www.pip-installer.org/en/latest/](http://www.pip-installer.org/en/latest/)

**安装：**

qibuild用pip安装：`pip install qibuild`

加入`$HOME/Library/Python/2.7/bin`你的`$PATH`，注意这里我装了zsh，将PATH添加到了~/.zshrc中，`export PATH=$HOME/Library/Python/2.7/bin:$PATH`

**配置：** 

`$ qibuild config --wizard`

系统将提示指定：

- CMake路径（如果没有自动找到），
- CMake发生器和
- 您将使用的IDE。

建议在Linux和Mac上使用“Unix Makefiles”，在Windows上使用“Visual Studio”。

请注意，你仍可以随时重新运行配置向导。

结果：生成一个文件`~/.config/qi/qibuild.xml`。它将由你将创建的所有工作树共享。

**初始化工作树：** 

创建一个EMPTY文件夹，它将是您的工作树。`/path/to/myWorktree`，cd到这个文件夹下输入：`$ qibuild init `进行初始化。

## 安装和配置NAOqi的SDK

下载C++ SDK，[下载和安装SoftBank Robotics软件](http://doc.aldebaran.com/2-5/dev/community_software.html#retrieving-software)。

在您的机器上提取它。我们假设提取的文件夹名为：*naoqi-sdk*。

创建工具链，输入此命令以使用C ++ SDK中的提要创建工具链：

```shell
$ qitoolchain create mytoolchain /path/to/naoqi-sdk/toolchain.xml
```

其中*mytoolchain*是你想给这个特定的工具链名称（你可以有几个）。

进入你的工作区：

```shell
$  cd / path / to / myWorktree
```

创建配置，键入此命令以创建与此工具链关联的构建配置，并确保此配置是此工作树的默认配置：

```shell
$ qibuild add-config myconfig -t mytoolchain --default
```

