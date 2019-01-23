# C ++ SDK - Hello world（自动生成）[¶](http://doc.aldebaran.com/2-5/dev/cpp/helloworld_auto.html#c-sdk-hello-world-auto-generated)

| 步   | 行动                                                         |
| ---- | ------------------------------------------------------------ |
| 1    | 在您的工作树中，键入：`$ qisrc创建myFirstExample `结果：`myfirstexample`已创建一个目录，其中已经实现了“hello world”。 |
| 2    | 进入这个目录：`$  cd myfirstexample `然后输入：`$ qibuild config `结果：`build-<myconfig>`已创建目录，其中`<myconfig>` 对应于当前配置。例如，如果在Linux 64位上配置，则配置文件将是`build-sys-linux-x86_64`。 |
| 3    | 要编译'hello world'程序，请输入：`$ qibuild make `           |
| 4    | 要运行'hello world'程序，例如使用以下命令：进入build- <myconfig> / sdk / bin目录：`$  cd build- <myconfig> / sdk / bin `然后输入：`$ ./my_first_example `注意在**苹果**，你应该设置环境变量`DYLD_LIBRARY_PATH`来 `myfirstexample/build-mytoolchain/sdk/lib`第一次。 |

# C ++ SDK - Hello world（一步一步）[¶](http://doc.aldebaran.com/2-5/dev/cpp/helloworld_detailed.html#c-sdk-hello-world-step-by-step)

## 先决条件

你应该在C ++中有一些很好的知识。但是，本教程中详细介绍了一些独立于NAOqi SDK的C ++ 11新功能。

## 设置你的环境

设置环境以准备编码：

| 步   | 行动                                                         |
| ---- | ------------------------------------------------------------ |
| 1    | **安装qiBuild。** 为什么？**qiBuild** 是用于构建软件的工具。*怎么样？*按照分步指南：[安装qiBuild](http://doc.aldebaran.com/2-5/dev/cpp/install_guide.html#inst-qibuild-4-naoqi)。 |
| 2    | **创建要在其中创建模块的目录。** 怎么样？*进入worktree目录，在其中创建另一个要编写新模块的目录。对于本教程，此目录名为：`octopus`。*结果*我们有这棵树：`my_worktree/octopus`。 |
| 3    | **创建qiproject.xml文件。** 为什么？**qiBuild** `qiproject.xml`使用该文件来了解如何管理项目使用的库之间的依赖关系。该文件的最小内容应为：项目的维护者您的项目名称。*怎么样？*在您的`octopus`目录中，`qiproject.xml` 使用如下组织的内容创建文件：`<project name =“octopus”>      <maintainer email =“jdoe@mycompany.com”> John DOE </ maintainer>  </ project> `注意：项目目录的名称和文件中的项目名称`qiproject.xml`不一定必须相同。 |
| 4    | **创建CMakeLists.txt文件。** 为什么？*该文件`CMakeLists.txt`用于了解如何构建与您自己的项目相对应的源代码。*怎么样？*在章鱼目录中，使用以下内容创建文件CMakeLists.txt：`cmake_minimum_required（VERSION 2.8） 项目（章鱼） `注意：CMakeLists.txt文件中项目的名称没有任何影响。 |
| 5    | **你的第一个配置** 为什么？*配置准备要构建您的项目。*怎么样？*要创建将在以后构建库和可执行文件的新构建目录，请在您的`octopus`目录中编写：`qibuild配置--release ``--release`在发布模式中指定的位置。如果您不精确`--release`，默认情况下将在调试模式下完成配置。*结果*查看您的项目目录，**qiBuild**刚刚为您创建了一个全新的：`build-<custom> directory`其中，`<custom>`对应于您的系统配置，例如，`sys-linux_x86_64`如果您使用的是Linux 64位。 |

## 你的第一个代码

在本部分中，您将学习如何使用qibuild编写和构建您的第一个“Hello World”。

| 步   | 行动                                                         |
| ---- | ------------------------------------------------------------ |
| 1    | **写下你的第一个代码**好吧，我们有一个目录，我们的代码将在未来建立，但目前我们根本没有代码。我们来写吧！因为我们非常原创，所以让我们写一个不错的Hello World！让我们创建一个`main.cpp`在新子目录中调用的以下文件：`src:`在`src`目录中，`main.cpp`使用以下内容创建文件：`＃包括<iostream的>  int main（） {    std :: cout <<“Hello，world！” << std :: endl;    返回0;  } ` |
| 2    | **构建你的第一个代码（第一次尝试）**只需写：`qibuild制作 `*结果*完美，没有错误。但是，等等，我无法在任何地方看到我的hello world程序！实际上，这是正常的，我们从来没有说过**qiBuild**它应该构建什么文件。为此，只需在文件中添加`CMakeLists.txt`以下行：`qi_create_bin（octopus-bin“src / main.cpp”） `这行**代表qiBuild**它应该构建一个`octopus-bin`从源文件命名的可执行 文件`src/main.cpp`。您的`CMakeLists.txt`文件现在应该如下所示：`cmake_minimum_required（VERSION 2.8） 项目（章鱼）  qi_create_bin（octopus-bin“src / main.cpp”） ` |
| 3    | **建立你的第一个代码（第二次尝试）**让我们再次编译：`qibuild制作 `不好了！**qiBuild**显示这个美丽的错误消息：[![../../_images/cpp_dummies_qibuilderror01.png](http://doc.aldebaran.com/2-5/_images/cpp_dummies_qibuilderror01.png)](http://doc.aldebaran.com/2-5/_images/cpp_dummies_qibuilderror01.png)听起来像**qiBuild**不能使用`qi_create_bin`命令。实际上这是正常的，因为**qiBuild**不知道这个命令可用的位置。要纠正这个问题，只需在`CMakeLists.txt`文件中添加以下行：`find_package（qibuild） `这行告诉**qiBuild**应该找到并使用包含命令的包 **qiBuild**`qi_create_bin`。您的文件`CMakeLists.txt`现在应该如下所示：`cmake_minimum_required（VERSION 2.8） 项目（章鱼） find_package（qibuild）  qi_create_bin（octopus-bin“src / main.cpp”） ` |
| 4    | **构建你的第一个代码（第三次和最后一次尝试**让我们再次编译：`qibuild制作 `这一次没关系，你会在`build-<custom>/sdk/bin`目录中找到你全新的可执行文件 ，其中： `<custom>`例如，对应于你的系统配置`sys-linux_x86_64`。恭喜！您可以通过编写来执行它：`./octopus-bin。 `恭喜！你用**qiBuild**写了第一个Hello World ！ |