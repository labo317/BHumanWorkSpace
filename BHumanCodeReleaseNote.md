# BHumanCodeRelease

Build，是生成的二进制文件和编译源代码期间创建的临时文件的目标目录。最初没有，将由生成系统创建。

Config，是一些配置信息，在官方文档的2.9章节可以找到。

Install，安装包含在NAO上设置b-human所需的所有文件。

Make，make包含make files、编译代码所需的其他文件、copyfiles工具和从nao下载日志文件的脚本。此外，还生成了为Xcode、Visual Studio和CodeLite创建项目文件的脚本。

Src，SRC包含b-human软件的源代码，包括b-human用户shell（在官方文档[4，第10.2章]）。

Util，Util包含辅助和第三方库（参见第5）以及模拟器Simrobot（在官方文档[4，第10.1章]）。