## 写在前面

无论您是否使用过 v1.x 版本的 CountdownMaster，都建议您下载最新版。

下面的写的挺长，建议您直接前往 **[1.5 更新内容](#1.5-更新内容)**、**[2. 下载与安装](#2-下载与安装)**。

使用 Qt 重写了整个程序，程序的各方面都有显著提升。

- **当前版本：** 2.2

- **发布日期：** 2024-03-17

v2.2 版本安装包可从网盘下载：[网盘链接](https://wwb.lanzoul.com/b00sezpha) 密码：52pj

最新版本可以从 [Github Release](https://github.com/Burnling-gx/CountdownMaster/releases/tag/v2.2) 页面下载。

建议下载 `setup-v2.2.exe` ，可以直接设置开机自启。

## 目录

1. [概述](#1-概述)
2. [安装](#2-安装)
3. [快速入门](#3-快速入门)
4. [高级用法](#4-高级用法)

## 1. 概述

### 1.1 项目简介

倒数日程序是一个桌面应用，旨在帮助用户跟踪特定事件或目标日，显示距离目标日的天数。

### 1.2 主要特点

- 简单直观：通过直观的界面显示倒数日信息，方便用户快速了解距离目标日的时间。
- 自定义事件：用户可以添加、编辑和删除自定义事件，根据个人需求跟踪不同的重要日期。
- 桌面提醒：倒数日信息会显示在桌面上，提醒用户距离目标日的剩余时间。

### 1.3 适用场景

倒数日程序适用于个人、家庭、工作和学习等多种场景。用户可以用它来跟踪各种重要事件，如生日、节日、考试、工作截止日期等。

### 1.4 主要功能

- **添加事件：** 用户可以添加新的倒数日事件，包括事件名称和日期。

- **编辑事件：** 用户可以编辑已存在的倒数日事件，修改事件名称和日期。

- **删除事件：** 用户可以删除不再需要的倒数日事件。

- **显示倒数日：** 程序会显示距离目标日的剩余天数，并在桌面上进行显示提醒。

### 1.5 更新内容

- **更小的体积：** 安装后约 30MB。

- **更多的功能：** 支持**单独**自定义**每个事件**的背景颜色、字体、字号、文字颜色、边框效果等。

- **更完善的支持：** 右键托盘图标点击 “打开设置” 以编辑事件信息，自带 `shutdownApp.exe` 用于强制关闭程序。

### 1.6 版本信息

- **当前版本：** 2.2

- **发布日期：** 2024-03-17

### 1.7 开源许可

程序采用 MIT 开源许可。详情请查看 [LICENSE](https://github.com/Burnling-gx/CountdownMaster/blob/master/LICENSE) 文件。

[Github 仓库地址](https://github.com/Burnling-gx/CountdownMaster)


## 2. 下载与安装

### 2.1 下载安装包

v2.2 版本安装包可从网盘下载：[网盘链接](https://wwb.lanzoul.com/b00sezpha) 密码：52pj

最新版本可以从 [Github Release](https://github.com/Burnling-gx/CountdownMaster/releases/tag/v2.2) 页面下载。

建议下载 `setup-v2.2.exe` ，可以直接设置开机自启。

### 2.2 安装

下载完成后，使用支持 .7z 格式的解压工具（如 7-Zip、WinRAR 等），解压下载的压缩包。

如果下载的是 `setup-v2.2.exe` ，双击运行即可。

## 3. 快速入门

### 3.1 运行程序

双击 `CountdownMaster.exe` 即可启动程序。程序启动后，会在桌面上显示倒数日信息。

如果要编辑事件、设置位置等，请右键托盘图标，选择 “打开设置” 以进行配置。

### 3.2 添加新事件

1. 在程序界面上点击 “添加事件” 按钮。

2. 输入事件名称和日期。

3. 点击 “保存更改” 按钮，即可添加新的倒数日事件。

### 3.3 编辑事件

1. 在程序界面上点击已存在事件的名称。

2. 修改事件名称或日期。

3. 点击 “保存更改” 按钮，即可保存修改。

### 3.4 删除事件

1. 在程序界面上找到要删除的事件。

2. 点击事件右侧的“删除事件”按钮。

3. 点击 “保存更改” 按钮，即可保存修改。

### 3.5 移动位置

在控制区内拖动滑动条或直接输入数值即可。

数值皆为百分数，即占整个屏幕宽度 / 高度的百分比。

### 3.6 关闭程序

右键托盘内图标，点击 “退出程序” 即可关闭程序。

文件夹内自带 `shutdownApp.exe` ，双击运行即可关闭倒数日程序。

## 4. 高级用法

程序的事件信息皆从 `events.json` 读取。

如果程序目录下没有 `events.json` ，程序会自动创建。

通过直接编辑 `events.json` ，可以实现一些高级用法。

### 4.1 更进一步的编辑

支持单独设置各个事件的背景色、字体、字体大小、文字颜色等信息。

在设置程序内点击 “保存更改”后，**以下信息皆会被清除！**

#### 4.1.1 设置颜色

支持设置透明度。

使用 `color_eventName` / `color_eventCountdown` 设置文字的颜色。

使用 `color_background` 设置背景色。

颜色格式为 `#AARRGGBB`。

#### 4.1.2 设置字体

使用 `fontFamily_eventName` / `fontFamily_eventCountdown` 设置字体。默认值为 `微软雅黑`。

使用 `fontSize_eventName` 设置事件名称的字号。默认值为`25`。

使用 `fontSize_eventCountdown` 设置事件倒数日的字号。默认值为`30`。

使用 `bold_eventName` / `bold_eventCountdown` 设置事件名称的是否加粗。默认值为 `true`。

#### 4.1.3 设置边框

使用 `border` 设置边框。默认值为 `1px solid black`。

具体取值基本同 CSS。详见 [MDN](https://developer.mozilla.org/en-US/docs/Web/CSS/border#formal_syntax)。

#### 4.2 示例

```json
{
    "events": [
        {
            "eventDate": "2025-01-01",
            "eventName": "2025",
            "fontSize_eventName":40
        },
        {
            "eventDate": "2025-01-01",
            "eventName": "未来 2025",
            "border": "5px solid #0AFCCF",
            "bold_eventName": false,
            "fontFamily_eventName":"隶书"
        },
        {
            "eventDate": "2025-01-01",
            "eventName": "2025",
            "color_background": "#6600FF00",
            "color_eventName": "#FF00FF",
            "fontSize_eventCountdown": 10
        }
    ],
    "window": {
        "itemHeight": 0.15,
        "left": 0.875,
        "top": 0,
        "width": 0.125
    }
}
