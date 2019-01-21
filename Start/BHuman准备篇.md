BHuman项目：https://github.com/bhuman/BHumanCodeRelease

# 一、BHuman项目的创建和编译

1. 在软银官网下载Naoqi的C++SDK，下载地址：[https://community.ald.softbankrobotics.com](https://community.ald.softbankrobotics.com/)
2. 在官网下载alcommom包，无需解压，将其放置在Desktop目录下。

3. 安装必要的依赖项：`sudo apt install clang qtbase5-dev libqt5svg5-dev libglew-dev libxml2-dev graphviz xterm `

4. 在Install目录：`./installAlcommon ~/Desktop/naoqi-sdk-2.1.4.13-linux32.tar.gz`
5. 编译项目：进入make/linux目录，`make`，一段时间后整个项目部署在电脑中，在根目录下 多出了一个文件夹-build。

# 二、刷机（将BHuman部署到机器人上）

注意：在部署bhuman之前，确保机器人的系统为naoqi，版本号为2.1.4.13，如若不是，请[给机器人部署naoqi系统](#给机器人部署naoqi系统)。

## 给机器人部署BHuman系统

### 准备：

+ 电脑、网线、安装CodeLite

+ BHumanCodeRelease-master.zip
+ GameController-master.zip
+ naoqi-sdk-2.1.4.13-linux32.tar.gz

### 编译项目：

新建一个文件夹`robotcup`，将上面三个压缩包放到这个新建的目录下。

BHumanCodeRelease-master.zip解压，提取出来。把naoqi-sdk-2.1.4.13-linux32.tar.gz复制到robotcup/BHumanCodeRelease-master/Install路径下。

进入`/robotcup/BHumanCodeRelease-master/Install`执行`./installAlcommon naoqi-sdk-2.1.4.13-linux32.tar.gz`

进入`/robotcup/BHumanCodeRelease-master/Make/LinuxCodeLite`执行`./generate`

然后执行`codelite`，选中B-Human,右键选中Build->ReBuild Workspace

### 配置网络

进入`/robotcup/BHumanCodeRelease-master/Install/Network/Profiles`

编辑`default`文件，配置Wi-Fi信息。

### 拷贝编译好的文件到Nao

进入`/robotcup/BHumanCodeRelease-master/Install`执行`./createRobot -d -t 17 -r 2 roboname`（参数：-d为清空之前的，-t后跟team number，-r后跟机器人序号，roboname是设定机器人名字）

执行`./addRobotIds -ip 192.168.66.4 roboname`（192.168.66.4是让机器人自己报的现在的ip，roboname是设定的名字）

执行`./installRobot 192.168.66.4`（192.168.66.4同上）

执行完上述操作后，就成功将机器人的IP设置为：192.168.teamNumber.robotNumber（上述步骤会分别在代码的Config/Robots/下创建相应的内容，./createRobot -d -t 20 -r 10 dashu 会在Config/Robots/下穿件名为dashu的文件夹；./addRobotIds
-ip 169.254.210.108 dashu会在Config/Robots/robots.cfg中增加机器人的配置信息）

然后将电脑端连接的网络配置更改为192.168.xxx.xxx就可以了，或者在做完前面操作后，将机器人和电脑用网线连起来。

然后执行：`./copyfiles Release 192.168.17.2`。



## 给机器人部署naoqi系统

### 准备：

- U盘
- flasher-2.1.0.19-linux64
- opennao-atom-system-image-2.1.4.13_2015-08-27.opn

### 步骤如下：

在Ubuntu下，将U盘格式化。

解压flasher-2.1.0.19-linux64，cd到这个解压好的目录下，`l`查看当前目录下的文件（ps：如果文件名右上角有*，说明权限不够，`sudo`即可）。

`cd bin/`然后执行`sudo ./flasher`

输入nao的密码（0）

把u盘插入Nao的脑壳，按住胸前按钮直到次按钮不停的高频闪烁，释放按钮，Nao进入自动刷机状态，等待十几分钟，听到OGNAK后说明刷机完成，拔出U盘。

在 linux 下关闭Wi-Fi连接，用网线连接机器人和电脑,编辑一个新网络,断开并重新连接,此时按机器人胸前按钮，会得到一个 ip。(如果是虚拟机要更改成桥连模式,关闭外网)，有时会听到“I cannot connect to the network”，多按几次（一般是3次）可以成功报出 IP，如果还是不行，先将NAO随意连接到其他任意设置的网络，之后断开，再连接回预设网络，方可成功。（由于刷好机后的NAO的有线IP都是以169.254开头，所以可以将Ethernet网的IPv4设置成：Address: 169.254.xxx.xxx; Netmask: 255.255.0.0; Gateway: 169.254.xxx.xxx）

