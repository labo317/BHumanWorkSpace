# Note

Build，是生成的二进制文件和编译源代码期间创建的临时文件的目标目录。最初没有，将由生成系统创建。

Config，是一些配置信息，在官方文档的2.9章节可以找到。

Install，安装包含在NAO上设置b-human所需的所有文件。

Make，make包含make files、编译代码所需的其他文件、copyfiles工具和从nao下载日志文件的脚本。此外，还生成了为Xcode、Visual Studio和CodeLite创建项目文件的脚本。

Src，SRC包含b-human软件的源代码，包括b-human用户shell（在官方文档[4，第10.2章]）。

Util，Util包含辅助和第三方库（参见第5）以及模拟器Simrobot（在官方文档[4，第10.1章]）。

---

---

# BHumanCodeRelease2017

1. 介绍

   1.1 关于我们

   1.2 关于文档

   1.3 2016年以来的重大变化

2. 开始

   2.1 下载

   2.2 [组件和配置](./2017/2.2-Components-and-Configurations.md)

   2.3 构建代码

   + 2.3.1 项目生成

   + 2.3.2 Windows上的Visual Studio
   + 2.3.3 macOS上的Xcode
   + 2.3.4 Linux

   2.4 [设置NAO](./2017/2.4-Setting-Up-the-NAO.md)

   + 2.4.1 要求
   + 2.4.2 安装操作系统
   + 2.4.3 为NAO创建机器人配置文件
   + 2.4.5 管理无线配置	
   + 2.4.5 安装机器人

   2.5 [复制编译后的代码](./2017/2.5-Copying-the-Compiled-Code.md)

   2.6 [与NAO一起工作](./2017/2.6-Working-with-the-NAO.md)

   2.7 [启动SimRobot](./2017/2.7-Starting-SimRobot.md)

   2.8 [机器人校准](./2017/2.8-Calibrating-the-Robots.md)

   + 2.8.1 整体物理校准
   + 2.8.2 接头校准
   + 2.8.3 摄像机校准
   + 2.8.4 颜色校准

   2.9 [配置文件](./2017/2.9-Configuration-Files.md)

3. 构建

   3.1 绑定

   3.2 流程

   3.3 模块和表示

   + 3.3.1 黑板

   + 3.3.2 模块定义

   + 3.3.3 配置提供者

   + 3.3.4 伪模块默认

   + 3.3.5 参数化模块

   3.4 序列化

   + 3.4.1 流

   + 3.4.2 流式数据

   + 3.4.3 流式类

   + 3.4.4 生成可流化类

   + 3.4.5 配置映射

   + 3.4.6 枚举

   + 3.4.7 函数

   3.5 沟通

   + 3.5.1 进程间通信

   + 3.5.2 消息队列

   + 3.5.3 调试通信

   + 3.5.4 团队沟通

   3.6 调试支持

   + 3.6.1 调试请求

   + 3.6.2 调试图像

   + 3.6.3 调试图纸

   + 3.6.4 三维调试图纸

   + 3.6.5 小区

   + 3.6.6 修改

   + 3.6.7 秒表

   3.7 日志

   + 3.7.1 在线登录

   + 3.7.2 配置在线日志记录器

   + 3.7.3 远程日志记录

   + 3.7.4 日志文件格式

   + 3.7.5 回放日志文件

   + 3.7.6 注释

   + 3.7.7 缩略图

   + 3.7.8 图像补丁

4. 感知

   4.1 感知基础架构

   + 4.1.1 使用两个摄像头

   4.1.2 坐标系的定义

   + 4.1.3 身体轮廓

   + 4.1.4 颜色分类

   + 4.1.5 细分与区域建设

   + 4.1.6 检测现场边界

   4.2 检测黑白球

   + 4.2.1 寻找候选球

   + 4.2.2 拟合球轮廓

   + 4.2.3 过滤候选球

   + 4.2.4 检查表面花纹

   4.3 定位功能

   + 4.3.1 检测线路

   + 4.3.2 检测圆心圆

   + 4.3.3 行符合检测

   + 4.3.4 预处理线和交叉点

   + 4.3.5 罚分感知

   + 4.3.6 字段特性

   4.4 检测其他机器人和障碍物

5. 建模

   5.1 Self-Localization

   + 5.1.1 概率状态估计

   + 5.1.2 基于现场特征的传感器复位

   + 5.1.3 处理场的对称性

   5.2 球跟踪

   + 5.2.1 局部球模型

   + 5.2.2 摩擦与预测

   + 5.2.3 团队球模型

   5.3 障碍建模

   + 5.3.1 局部障碍模型

   + 5.3.2 全局障碍模型

   5.4 现场报道

   + 5.4.1 现场覆盖

   + 5.4.2 全球现场覆盖

   5.5 识别呢喃

   + 5.5.1 汽笛信号的相关性

   + 5.5.2 口哨识别过程中的声音回放

   + 5.5.3 多数票

6. 行为控制

   6.1 CABSL

   6.2 2017机器人世界杯使用的行为

   + 6.2.1 角色与策略

   + 6.2.2 前锋

   + 6.2.3 支持者

   + 6.2.4 后卫

   + 6.2.5 门将

   + 6.2.6 开球

   + 6.2.7 头控制

   6.3 罚球行为

   6.4 路径规划

   + 6.4.1 方法

   + 6.4.2 避免振荡

   + 6.4.3 障碍物圆重叠

   + 6.4.4 禁止区域

   + 6.4.5 避免不可能的计划

   6.5 踢位提供器

   6.6 摄像头控制引擎

   6.7 领导处理程序

7. 本体感觉(传感)

   7.1 接地检测

   7.2 机器人模型生成

   7.3 惯性传感器数据滤波

   7.4 躯干矩阵7.5检测跌落

   7.6 手臂接触识别

8. 运动控制

   8.1 运动的选择

   8.2 运动相结合

   8.3 走

   + 8.3.1 Walk2014Generator

   + 8.3.2 改进

   + 8.3.3 步行踢腿

   + 8.3.4 逆运动学

   8.4 下降

   8.5 特殊行为

   8.6 起床运动

   + 8.6.1 修改起床动作

   8.7 ZMP平衡

   8.8 头的运动

   8.9 臂动作

9. 技术挑战和混合团队比赛

   9.1 罚球挑战

   9.2 混合团体赛中的b组

10. 工具

  10.1 SimRobot

  + 10.1.1 架构

  + 10.1.2 B-Human工具栏

  + 10.1.3 场景视图

  + 10.1.4 信息视图

  + 10.1.5 场景描述文件

  + 10.1.6 控制台命令

  + 10.1.7 记录远程日志文件

  10.2 B-Human用户Shell

  + 10.2.1 配置

  + 10.2.2 命令

  + 10.2.3 向机器人部署代码

  + 10.2.4 管理多个无线配置

  + 10.2.5 地点和场景

  + 10.2.6 用机器人

  + 10.2.7 监控机器人

  10.3 GameController

  + 10.3.1 架构

  + 10.3.2 UI设计

  + 10.3.3 日志

  + 10.3.4 Log Analyzer

  10.4 团队沟通监控

  + 10.4.1 功能

  + 10.4.2 游戏状态可视化

  10.5 事件记录器



---

---

# BHumanCodeRelease2018

1. Introduction（介绍）

2. Getting Started（开始）

   - Download（下载）

   - Components and Configurations（组建和配置）

   - Building the Code（构建代码）

     - Project Generation

     - Visual Studio on Windows

     - Xcode on macOS

       Note that the cross compiler actually builds code for Linux, although the scheme says “My Mac”. 

     - Linux

   - Setting Up the NAO（建立NAO）

     - Requirements（需求）
     - Installing the Operating System（安装操作系统）
     - Creating Robot Configuration Files for a NAO（为NAO创建机器人配置文件）
     - Managing Wireless Configurations（管理无线网络配置）
     - Installing the Robot（安装在机器人）

   - Copying the Compiled Code（复制已编译的代码）

   - Working with the NAO（与NAO合作）

   - Starting SimRobot（开始SimRobot）

   - Calibrating the Robots（[校准机器人](./2018/机器人校准.md)）

     - Overall Physical Calibration（整体物理校准）
     - Joint Calibration（联合标定）
     - Camera Calibration（摄像机标定）
     - Color Calibration（颜色校准）

   - Configuration Files（配置文件）

3. Changes Since 2017（自2017年以来的变化）

   - Infrastructure（基础设施）
     - Type Registration（类型注册）
     - Inference of Neural Networks（神经网络推理）
   - Perception（感知）
     - Controlling Camera Exposure（相机曝光控制）
     - Detecting the Field Boundary（检测场边界）
     - Detecting Obstacles（检测障碍）
     - Detecting the Ball（探测球）
   - Motion Control（运动控制）
     - Enhancement of the Kick Range（增加踢距）
     - Getup Motions（起身动作？）
   - Behavior Control（行为控制）
     - Behavior Infrastructure（行为基础设施）
     - Free Kick（任意球）
     - Kick Pose Provider（踢球提供程序）

4. Technical Challenge and Mixed-Team Competition（技术挑战和混合团队比赛）

   - General Penalty Kick Challenge（一般点球挑战）
   - B-Swift in the Mixed Team Competition（B-Swift在混合团体赛中）

5. Acknowledgements（鸣谢）

6. Bibliography（参考书目）

---

---

# EOF

