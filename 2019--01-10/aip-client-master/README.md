服务器命令格式

|功能名称解释|字节数|功能码|宏定义        |目标编号|数据|备注|
|----------|:---:|:---:|:------------|:----:|:--:|:-:|
|获取出厂编号|block|0x01 |getNumber    |X|X||
|获取硬件地址|block|0x02 |getHardware  |X|X||
|获取软件版本|block|0x03 |getVersion   |X|X||
|获取目标日期|block|0x04 |getDateTime  |X|X||
|获取目标时间|block|0x05 |getFileActive|X|X||
|获取目标状态|block|0x06 |getFileExist |X|X||
|获取目标配置|block|0x07 |getConfig    |X|X||
|获取目标配置|block|0x08 |getOnlineList|X|X||
|获取目标配置|block|0x09 |getFileLog   |X|X||
|
|发送出厂编号|block|0x21 |putNumber    |X|data||
|发送硬件地址|block|0x22 |putHardware  |X|data||
|发送软件版本|block|0x23 |putVersion   |X|data||
|发送目标日期|block|0x24 |putDateTime  |X|data||
|发送目标时间|block|0x25 |putFileActive|X|data||
|发送目标状态|block|0x26 |putFileExist |X|data||
|发送目标配置|block|0x27 |putConfig    |X|data||
|发送文件数据|block|0x28 |putOnlineList|X|data||
|发送文件名称|block|0x29 |putFileLog   |X|data||
|发送文件大小|block|0x41 |putFileData  |X|data||
|发送校验数据|block|0x42 |putFileName  |X|data||
|发送定时心跳|block|0x43 |putFileSize  |X|X||
|发送测试启动|block|0x44 |putFileVerify|X|X||
|发送错误信息|block|0x45 |putCmdHeart  |X|data||
|开启结果上传|block|0x46 |putCmdTest   |X|X||
|关闭结果上传|block|0x47 |putCmdError  |X|X|||

嵌入式程序移植到PC
    删除inputMethod.h inputMethod.c;
    main.c w.showMaximized改为w.show;
    CMainScreen.c 去除Qt::FramelessWindowHint;
