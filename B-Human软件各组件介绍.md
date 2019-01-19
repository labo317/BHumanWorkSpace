# B-Human软件各组件介绍 

B-Human软件可以在Windows，Linux和OS X上运行，此软件分为以下组件：

* bush: 用来同时配置和管理多个机器人的工具。 
* Controller: 包含NAO特殊模拟器拓展和机器人代码框架接口的一个静态库，在控制和高级调试NAO中代码时要用到。 
* Libbhuman：一个共享库，B-Human可执行文件用来与NAOqi进行交互。 
* Libgamectrl: 一个与GameController交互的NAOqi共享库。此外，它实现了官方按钮接口，并按指定规则设置LED灯。此组建更多信息见2013 code release[8,Chapter 3.1]。 
* Libqxt: 给Windows和Linux下Qt提供附加工具的的一个静态库。 
* Nao： B-Human给NAO的可执行文件。它依赖于SpecialActions,libbuman,和libgamectrl。 
* Qtpropertybrowser: 在Qt中实现属性浏览器的一个静态库。 
* SimRobot：运行和控制B-Human机器人代码的模拟器可执行文件。它动态连接到SimRobotCore2,SimRobotHelp,SimulatedNao组件，和一些第三方库。它同样依赖于SpecialActions，即机器人代码加载的结果。SimRobot可以以Release,Develop和Debug配置编译。所有配置均包含调试代码，但Release表现出优化，并去掉了debug标志。Develop生成可调试的机器人代码，同时链接到不可调试但运行更快的Release库。 
* SimRobotCore2:包含SimRobot模拟器引擎的一个共享库。 
* SimRobotEditor:包含模拟器编辑工具的的一个共享库。 
* SimRobotHelp:包含模拟器帮助工具的一个共享库。 
* SimulatedNao:包含模拟器B-Human代码的一个共享库。依赖于Controller,qtpropertybrowser,和libqxt。它静态的链接到这些组件。 
* SpecialActions:用URC按内部格式编译的运动模式(.mof文件)。 
* URC:表示全局资源编译器(Universal Resource Compiler)，一个编译特殊动作的编译器。


>2015年
