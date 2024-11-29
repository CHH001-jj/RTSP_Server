# RTSP 流媒体服务器

这是一个基于 **RTSP**（实时流协议）和 **RTP**（实时传输协议）的流媒体服务器，能够接收客户端的请求并发送视频和音频流。它支持常见的 RTSP 请求方法，如 `OPTIONS`、`DESCRIBE`、`SETUP`、`PLAY`，并通过 RTP 协议将视频和音频流实时传输给客户端。

## 项目功能

- **RTSP 请求处理**：
  - 支持 `OPTIONS`、`DESCRIBE`、`SETUP`、`PLAY` 请求。
  - 提供支持的传输协议和流信息。
  
- **视频流和音频流处理**：
  - 支持读取本地的视频文件（MP4 格式），并将其转换为 H.264 和 AAC 格式。
  - 使用 RTP 协议将 H.264 视频帧和 AAC 音频帧发送给客户端。

- **并行视频和音频流传输**：
  - 视频和音频流分别在不同的线程中传输，确保流的同步和流畅性。

## 项目结构
```
├── CMakeLists.txt          # CMake 构建配置文件
├── main.cpp                # 主程序入口
├── rtp.h                   # RTP 相关结构体和函数
├── rtp.cpp                 # RTP 相关结构体和函数
├── utils.h                 # 辅助函数
├── utils.cpp               # 辅助函数
└── README.md               # 项目的 README 文件

```
## 项目依赖

- **FFmpeg**：用于将输入的 MP4 文件转换为 H.264 视频流和 AAC 音频流。
- **Linux 环境**：本项目在 Linux 系统上开发和测试，使用了 socket 编程来处理网络通信。

## 安装和构建

1. **安装依赖项**：
   - 需要在系统中安装 **FFmpeg** 来进行 MP4 转码。

   ```bash
   sudo apt-get update
   sudo apt-get install ffmpeg
2. **构建项目（也可以直接使用编译过的build文件夹）**：
    ```
    mkdir build
    cd build
    cmake ..
    make
3. **运行项目**：
    ```
    ./RTSP_Server
