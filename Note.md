# Note

Build，是生成的二进制文件和编译源代码期间创建的临时文件的目标目录。最初没有，将由生成系统创建。

Config，是一些配置信息，在官方文档的2.9章节可以找到。

Install，安装包含在NAO上设置b-human所需的所有文件。

Make，make包含make files、编译代码所需的其他文件、copyfiles工具和从nao下载日志文件的脚本。此外，还生成了为Xcode、Visual Studio和CodeLite创建项目文件的脚本。

Src，SRC包含b-human软件的源代码，包括b-human用户shell（在官方文档[4，第10.2章]）。

Util，Util包含辅助和第三方库（参见第5）以及模拟器Simrobot（在官方文档[4，第10.1章]）。



# 2018 BHuman CodeRelease

1. Introduction（介绍）

2. Getting Started（开始）

   + Download（下载）

   + Components and Configurations（组建和配置）

   + Building the Code（构建代码）
     + Project Generation

     + Visual Studio on Windows

     + Xcode on macOS

       Note that the cross compiler actually builds code for Linux, although the scheme says “My Mac”. 

     + Linux

   + Setting Up the NAO（建立NAO）
     + Requirements（需求）
     + Installing the Operating System（安装操作系统）
     + Creating Robot Configuration Files for a NAO（为NAO创建机器人配置文件）
     + Managing Wireless Configurations（管理无线网络配置）
     + Installing the Robot（安装在机器人）

   + Copying the Compiled Code（复制已编译的代码）

   + Working with the NAO（与NAO合作）

   + Starting SimRobot（开始SimRobot）

   + Calibrating the Robots（校准机器人）
     + Overall Physical Calibration（整体物理校准）
     + Joint Calibration（联合标定）
     + Camera Calibration（摄像机标定）
     + Color Calibration（颜色校准）

   + Configuration Files（配置文件）

3. Changes Since 2017（自2017年以来的变化）

   + Infrastructure（基础设施）
     + Type Registration（类型注册）

     + Inference of Neural Networks（神经网络推理）

   + Perception（感知）
     + Controlling Camera Exposure（相机曝光控制）

     + Detecting the Field Boundary（检测场边界）

     + Detecting Obstacles（检测障碍）

     + Detecting the Ball（探测球）

   + Motion Control（运动控制）
     + Enhancement of the Kick Range（增加踢距）

     + Getup Motions（起身动作？）

   + Behavior Control（行为控制）
     + Behavior Infrastructure（行为基础设施）

     + Free Kick（任意球）

     + Kick Pose Provider（踢球提供程序）

4. Technical Challenge and Mixed-Team Competition（技术挑战和混合团队比赛）
   + General Penalty Kick Challenge（一般点球挑战）

   + B-Swift in the Mixed Team Competition（B-Swift在混合团体赛中）

5. Acknowledgements（鸣谢）

6. Bibliography（参考书目）